#include "mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <stdexcept>

//added
#include <fstream>
#include <iostream>

#include "ExeHandlerLoader.h"
#include "ImportsTableModel.h"
#include "StubMaker.h"

bool my_save_exe = false;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), m_replacementsDialog(NULL), exeController(this),
    infoModel(NULL), m_libsModel(NULL), m_functModel(NULL),
    m_ExeSelected(NULL), customMenu(NULL), functionsMenu(NULL)
{
    m_ui.setupUi(this);
    initReplacementsDialog();

    makeCustomMenu();
    makeFunctionsMenu();
    makeFileMenu();
    this->setWindowTitle("IAT Patcher v " + QString(VERSION));

    this->infoModel = new InfoTableModel(m_ui.outputTable);
    infoModel->setExecutables(&m_exes);

    m_ui.outputTable->setModel(infoModel);
    m_ui.outputTable->setSortingEnabled(false);
    m_ui.outputTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    m_ui.outputTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    m_ui.outputTable->verticalHeader()->show();

    m_ui.outputTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_ui.outputTable->setSelectionMode(QAbstractItemView::SingleSelection);
    m_ui.outputTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    m_ui.statusBar->addPermanentWidget(&urlLabel);
    urlLabel.setTextFormat(Qt::RichText);
    urlLabel.setTextInteractionFlags(Qt::TextBrowserInteraction);
    urlLabel.setOpenExternalLinks(true);
    urlLabel.setText("<a href=\""+ QString(SITE_LINK) +"\">"+SITE_LINK+"</a>");

    this->setAcceptDrops(true);

    this->impModel = new ImportsTableModel(m_ui.outputTable);
    this->m_filteredImpModel = new QSortFilterProxyModel(this);
    m_filteredImpModel->setDynamicSortFilter(true);
    m_filteredImpModel->setSourceModel(impModel);

    m_ui.importsTable->setModel(m_filteredImpModel);
    m_ui.importsTable->setSortingEnabled(true);
    m_ui.importsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_ui.importsTable->setSelectionMode(QAbstractItemView::SingleSelection);
    m_ui.importsTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

    connect( m_ui.filterLibEdit, SIGNAL( textChanged (const QString &)), this, SLOT( filterLibs(const QString &)) );
    connect( m_ui.filterProcEdit, SIGNAL( textChanged (const QString &)), this, SLOT( filterFuncs(const QString &)) );
    m_ui.outputTable->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(m_ui.outputTable, SIGNAL(customContextMenuRequested(QPoint)), SLOT(customMenuRequested(QPoint)));

    m_ui.importsTable->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(m_ui.importsTable, SIGNAL(customContextMenuRequested(QPoint)), SLOT(functionsMenuRequested(QPoint)));

    connect( m_ui.outputTable->selectionModel(), SIGNAL( currentRowChanged(QModelIndex,QModelIndex)), this, SLOT( rowChangedSlot(QModelIndex,QModelIndex) ) );
    connect( this, SIGNAL( exeSelected(ExeHandler*)), impModel, SLOT( setExecutable(ExeHandler*) ) );
    connect( this, SIGNAL( exeSelected(ExeHandler*)), this, SLOT( refreshExeView(ExeHandler*) ) );

    connect( this, SIGNAL( exeUpdated(ExeHandler*)), impModel, SLOT( setExecutable(ExeHandler*) ) );
    connect( this, SIGNAL( exeUpdated(ExeHandler*)), infoModel, SLOT( onExeListChanged() ) );
    connect( &this->exeController, SIGNAL( exeUpdated(ExeHandler*)), this, SLOT( refreshExeView(ExeHandler*)) );

    connect( &this->exeController, SIGNAL(exeUpdated(ExeHandler*)), infoModel, SLOT(onExeListChanged()) );

    connect(&m_LoadersCount, SIGNAL(counterChanged()), this, SLOT(loadingStatusChanged() ));
    connect(this, SIGNAL(hookRequested(ExeHandler* )), this, SLOT(onHookRequested(ExeHandler* ) ));
    connect(infoModel, SIGNAL(hookRequested(ExeHandler* )), this, SLOT(onHookRequested(ExeHandler* )) );

    connect(this, SIGNAL(thunkSelected(offset_t)), this, SLOT(setThunkSelected(offset_t)) );
}

MainWindow::~MainWindow()
{
    clear();
}

void MainWindow::initReplacementsDialog()
{
    m_replacementsDialog = new ReplacementsDialog(this);
    connect(m_replacementsDialog, SIGNAL(setReplacement(QString, QString)), this, SLOT(updateReplacement(QString, QString)) );
    connect(this, SIGNAL(replacementAccepted()), m_replacementsDialog, SLOT(hide()));

}

void MainWindow::filterLibs(const QString &str)
{
    m_filteredImpModel->setFilterRegExp(QRegExp(str, Qt::CaseInsensitive, QRegExp::FixedString));
    m_filteredImpModel->setFilterKeyColumn(1);
}

void MainWindow::filterFuncs(const QString &str)
{
    m_filteredImpModel->setFilterRegExp(QRegExp(str, Qt::CaseInsensitive, QRegExp::FixedString));
    m_filteredImpModel->setFilterKeyColumn(2);
}

void MainWindow::refreshExeView(ExeHandler* exe)
{
    if (m_ExeSelected == exe) {
        QString fName = "";
        if (exe) fName = exe->getFileName();
        this->m_ui.fileEdit->setText(fName);
    }
}

void MainWindow::loadingStatusChanged()
{
    size_t count = m_LoadersCount.getCount();
    if (count == 0) {
        this->m_ui.statusBar->showMessage("");
        return;
    }
    QString ending = "s";
    if (count == 1) ending = "";
    this->m_ui.statusBar->showMessage("Loading: " + QString::number(count) + " file" + ending);
}

void MainWindow::dropEvent(QDropEvent* ev)
{
    QList<QUrl> urls = ev->mimeData()->urls();
    QList<QUrl>::Iterator urlItr;
    QCursor cur = this->cursor();
    this->setCursor(Qt::BusyCursor);

    for (urlItr = urls.begin() ; urlItr != urls.end(); urlItr++) {
        QString fileName = urlItr->toLocalFile();
        if (fileName == "") continue;
        if (parse(fileName)) {
            m_ui.fileEdit->setText(fileName);
        }
    }
    this->setCursor(cur);
}

void MainWindow::closeEvent ( QCloseEvent * event )
{
    const size_t loadedCount = this->m_exes.size();
    if (loadedCount == 0) {
        event->accept();
        return;
    }
    event->ignore();
    bool hasModified = false;
    for (int i = 0; i < loadedCount; i++) {
        ExeHandler *hndl = this->m_exes.at(i);
        if (hndl->getModifiedState() || hndl->getUnappliedState()) {
            hasModified = true;
            break;
        }
    }
    if (!hasModified) {
        event->accept();
        return;
    }
    
    //commented
    // if (QMessageBox::Yes == QMessageBox::question(this, "Exit confirmation",
    //     "You made some unsaved changes, do you really want to exit?", 
    //     QMessageBox::Yes|QMessageBox::No))
    // {
    //     event->accept();
    // }
    
    //added
    event->accept();
}

void MainWindow::on_pushButton_clicked()
{
    return openExe();
}

void MainWindow::openExe()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open executable"),
        QDir::homePath(),
        "Exe Files (*.exe);;DLL Files (*.dll);;All files (*)"
        );

    // printf("%s :: %s\n",fileName.toUtf8().constData(), sfileName.toUtf8().constData());
    if (fileName != "") {
    	// printf("!%s!\n",fileName.toUtf8().constData());
        this->parse(fileName);
    }
}

void MainWindow::removeExe(ExeHandler* exe)
{
    selectExe(NULL);
    this->m_exes.removeExe(exe);
    delete exe;
    exe = NULL;
}

void MainWindow::on_reloadButton_clicked()
{
    QStringList files = this->m_exes.listFiles();
    clear();
    QStringList::iterator itr;
    for (itr = files.begin(); itr != files.end(); itr++) {
        QString fileName = *itr;
        this->parse(fileName);
    }
}

void MainWindow::reloadExe(ExeHandler* exe)
{
    QString fName = "";
    if (exe && exe->getExe())
        fName = exe->getFileName();
    this->removeExe(exe);
    this->parse(fName);
}

void MainWindow::saveRequested(ExeHandler* exeHndl)
{
    if (exeHndl == NULL) {
        QMessageBox::warning(this, "Cannot save!", "No executable selected!");
        return;
    }

    Executable *exe = exeHndl->getExe();
    if (exe == NULL) return;

    if (exeHndl->getUnappliedState()) {
        QMessageBox::warning(this, "Unapplied replacements!",
            "The file has unapplied replacements. Hook the file to apply them.");
        return;

    }
    if (exeHndl->getHookedState() == false) {

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Unhooked file!",
            "You are trying to save unhooked file. Do you really want?",
            QMessageBox::Yes | QMessageBox::No
        );

        if (reply == QMessageBox::No) {
            return;
        }
    }
    QFileInfo inputInfo(exeHndl->getFileName());

    QString infoStr = "Save executable as:";
    QString fileName = QFileDialog::getSaveFileName(
        this,
        infoStr,
        inputInfo.absoluteDir().path(),
        "Exe Files (*.exe);;DLL Files (*.dll);;All files (*.*)"
    );
    if (fileName.length() == 0) return;

    try {
        this->exeController.saveExecutable(exeHndl, fileName);
    }
    catch (CustomException &e) {
        QMessageBox::warning(this, "Error!", e.getInfo());
    }
}

void MainWindow::hookExecutable(ExeHandler* exeHndl, StubSettings &settings)
{
    if (exeHndl == NULL) return;

    Executable *exe = exeHndl->getExe();
    if (exe == NULL) return;

    bool isHooked = exeHndl->getHookedState();
    PEFile *pe = dynamic_cast<PEFile*>(exe);
    if (pe == NULL) {
        QMessageBox::warning(this, "Cannot hook!", "It is not a PE File!");
        return;
    }
    if (isHooked) {
        if (exeHndl->getUnappliedState() == false) {
            QMessageBox::information(NULL, "No changes!", "No changes to be applied");
            return;
        }
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Already hooked!",
            "This file is already hooked.\nDo you want to modify the existing stub?",
            QMessageBox::Yes | QMessageBox::No
        );

        if (reply == QMessageBox::No) {
            return;
        }
    }

    if (exeHndl->hasReplacements() == false && exeHndl->getHookedState() == false) {
        // QMessageBox::StandardButton reply;
        // reply = QMessageBox::question(this, "No replacements!",
        //     "You haven't defined any replacement functions.\nDo you really want to add an empty stub?",
        //     QMessageBox::Yes | QMessageBox::No
        // );

        // if (reply == QMessageBox::No) {
        //     return;
        // }
        return;
    }
    my_save_exe = true;

    if (!isHooked && pe->canAddNewSection() == false && settings.getAddNewSection()) {
        // QMessageBox::information(this, "Warning", "Cannot add new section in this file!\nProceed by extending last section...");        my_save_exe - true;
    }
    try {
        if (this->exeController.hookExecutable(exeHndl, settings)) {
            // QMessageBox::information(this, "Done!", "Hooked!\nNow you can save and test the file!");
            return;
        }
        else {
            // QMessageBox::warning(this, "Failed", "Cannot hook!");
            my_save_exe = false;
        }
    }
    catch (CustomException &e) {
        QMessageBox::warning(this, "Error!", e.getInfo());
        my_save_exe = false;
    }
}

void MainWindow::clear()
{
    selectExe(NULL);
    this->m_exes.clear();
}

void MainWindow::on_hookButton_clicked()
{
    emit hookRequested(this->m_ExeSelected);
}

QAction* MainWindow::addExeAction(QMenu *customMenu, QString text, ExeController::EXE_ACTION a)
{
    QAction *action = new QAction(text, customMenu);
    action->setData(a);
    customMenu->addAction(action);
    connect(action, SIGNAL(triggered()), this, SLOT(takeAction()));
    return action;
}

void MainWindow::makeCustomMenu()
{
    this->customMenu = new QMenu(this);

    addExeAction(customMenu, "Hook", ExeController::ACTION_HOOK)->setIcon(QIcon(":/icons/apply.ico"));
    addExeAction(customMenu, "Save as...", ExeController::ACTION_SAVE)->setIcon(QIcon(":/icons/save_black.ico"));
    addExeAction(customMenu, "Reload", ExeController::ACTION_RELOAD)->setIcon(QIcon(":/icons/reload.ico"));
    addExeAction(customMenu, "Unload", ExeController::ACTION_UNLOAD)->setIcon(QIcon(":icons/Delete.ico"));
    customMenu->addSeparator();
    addExeAction(customMenu, "Export replacements", ExeController::ACTION_EXPORT_REPL)->setIcon(QIcon(":icons/export.ico"));
    addExeAction(customMenu, "Import replacements", ExeController::ACTION_IMPORT_REPL)->setIcon(QIcon(":icons/import.ico"));
}

void MainWindow::makeFunctionsMenu()
{
    this->functionsMenu = new QMenu(this);

    QAction *settingsAction = new QAction("Define replacement", functionsMenu);
    settingsAction->setIcon(QIcon(":icons/edit.ico"));
    connect(settingsAction, SIGNAL(triggered()), this->m_replacementsDialog, SLOT(show()));
    functionsMenu->addAction(settingsAction);
}

void MainWindow::makeFileMenu()
{
    QMenu *menu = this->m_ui.menuFile;

    QAction *openAction = new QAction("Open executable", menu);
    openAction->setIcon(QIcon(":/icons/Add.ico"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(openExe()));
    menu->addAction(openAction);

    addExeAction(menu, "Hook selected", ExeController::ACTION_HOOK)->setIcon(QIcon(":/icons/apply.ico"));
    addExeAction(menu, "Save selected as...", ExeController::ACTION_SAVE)->setIcon(QIcon(":/icons/save_black.ico"));
}

void MainWindow::customMenuRequested(QPoint pos)
{
    QTableView *table = this->m_ui.outputTable;

    QModelIndex index = table->indexAt(pos);
    if (index.isValid() == false) return;

    this->customMenu->popup(table->viewport()->mapToGlobal(pos));
}

void MainWindow::functionsMenuRequested(QPoint pos)
{
    QTableView *table = this->m_ui.importsTable;
    if (table == NULL ) return;
    if (this->m_ExeSelected == NULL) return;

    QModelIndex index = table->indexAt(pos);
    if (index.isValid() == false) return;

    bool isOk;
    long long offset = m_filteredImpModel->data(index, Qt::UserRole).toLongLong(&isOk);
    m_ThunkSelected = isOk ? offset : INVALID_ADDR;
    emit thunkSelected(m_ThunkSelected);

    FuncDesc replName = this->m_ExeSelected->getReplAt(m_ThunkSelected);
    this->m_replacementsDialog->displayReplacement(replName);

    this->functionsMenu->popup(table->viewport()->mapToGlobal(pos));
}

void MainWindow::setThunkSelected(offset_t thunk)
{
    QString libName = this->m_ExeSelected->m_FuncMap.thunkToLibName(thunk);
    QString funcName = this->m_ExeSelected->m_FuncMap.thunkToFuncName(thunk);
    this->m_replacementsDialog->displayFuncToReplace(thunk, libName, funcName);
}

void MainWindow::updateReplacement(QString libName, QString funcName)
{
    QString substName = "";

    if (libName.length() != 0 && funcName.length() != 0) {
        substName = libName + "." + funcName;
    }
    if (this->m_ExeSelected->m_Repl.getAt(m_ThunkSelected) == substName) {
        emit replacementAccepted();
        return;
    }
    if (this->m_ExeSelected->defineReplacement(m_ThunkSelected, substName) == false) {
        QMessageBox::warning(this, "Error", "Invalid replacement definition!");
        return;
    }
    emit replacementAccepted();
}

void MainWindow::onImportReplacements(ExeHandler* exeHndl)
{
    if (exeHndl == NULL) return;

    QString infoStr = "Import replacements";
    QFileInfo inputInfo(exeHndl->getFileName());

    QString fileName = QFileDialog::getOpenFileName(
        this,
        infoStr,
        inputInfo.absoluteDir().path(),
        "Config file (*.txt);;Config file (*.cfg);;All files (*.*)"
    );
    if (fileName.length() == 0) return;

    size_t counter = this->exeController.loadReplacementsFromFile(exeHndl, fileName);
    if (counter == 0) {
        QMessageBox::warning(NULL, "Error!", "Cannot import!");
        return;
    }

    if (counter > 0) {
        QString ending = (counter > 1) ? "s" : " ";
        QMessageBox::information(NULL, "Done!", "Imported: " + QString::number(counter) + " replacement" + ending);
        
    }
}

void MainWindow::onExportReplacements(ExeHandler* exeHndl)
{
    if (exeHndl == NULL) return;

    if (exeHndl->hasReplacements() == false) {
        QMessageBox::warning(NULL, "Cannot save!", "The file have NO replacements defined!");
        return;
    }
    QString infoStr = "Save replacements as...";
    QFileInfo inputInfo(exeHndl->getFileName());

    QString fileName = QFileDialog::getSaveFileName(
        this,
        infoStr,
        inputInfo.absoluteDir().path(),
        "Config file (*.txt);;Config file (*.cfg);;All files (*.*)"
    );
    if (fileName.length() == 0) return;

    size_t counter = this->exeController.saveReplacementsToFile(exeHndl, fileName);
    if (counter == 0) {
        QMessageBox::warning(NULL, "Error!", "Cannot export!");
    }
    else {
        QString ending = (counter > 1) ? "s" : " ";
        QMessageBox::information(NULL, "Done!", "Exported: " + QString::number(counter) + " replacement" + ending);
    }
}

void MainWindow::takeAction()
{
    QAction *action = qobject_cast<QAction *>(sender());
    //TODO : refactor it
    if (action->data() == ExeController::ACTION_HOOK) {
        emit hookRequested(this->m_ExeSelected);
        return;
    }
    if (action->data() == ExeController::ACTION_SAVE) {
        this->saveRequested(this->m_ExeSelected);
        return;
    }
    if (action->data() == ExeController::ACTION_UNLOAD) {
        this->removeExe(this->m_ExeSelected);
        return;
    }
    if (action->data() == ExeController::ACTION_RELOAD) {
        this->reloadExe(this->m_ExeSelected);
        return;
    }
    if (action->data() == ExeController::ACTION_IMPORT_REPL) {
        this->onImportReplacements(this->m_ExeSelected);
        return;
    }
    if (action->data() == ExeController::ACTION_EXPORT_REPL) {
        this->onExportReplacements(this->m_ExeSelected);
        return;
    }
}

void MainWindow::onHookRequested(ExeHandler* exeHndl)
{
    StubSettings settings;
    settings.setAddNewSection(this->m_ui.actionAdd_new_section->isChecked());
    settings.setReuseImports(this->m_ui.actionAdd_imports->isChecked());
    QString settingsStr = "Settings: ";
    if (settings.getAddNewSection()) {
        settingsStr += "add new section ;";
    }
    if (settings.getReuseImports()) {
        settingsStr += "reuse imports";
    }
    this->m_ui.statusBar->showMessage(settingsStr);
    
    this->hookExecutable(exeHndl, settings);
}

void MainWindow::on_saveButton_clicked()
{
    saveRequested(this->m_ExeSelected);
}

void MainWindow::onLoadingFailed(QString fileName)
{
    QMessageBox::warning(this, "Error!", "Cannot load the file: " + fileName);
}

void MainWindow::onLoaderThreadFinished()
{
    delete QObject::sender();
    m_LoadersCount.dec();
    this->repaint();

    //added
    ExeHandler *exe = this->m_exes.at(this->m_exes.size()-1);
    selectExe(exe);
    hook_malware_file();
}

void MainWindow::rowChangedSlot(QModelIndex curr, QModelIndex prev)
{
    bool isOk = false;
    size_t index =  this->infoModel->data(curr, Qt::UserRole).toUInt(&isOk);
    if (!isOk) return;
    ExeHandler *exe = this->m_exes.at(index);
    selectExe(exe);
}

bool MainWindow::parse(QString &fileName)
{
    if (fileName == "") return false;

    QString link = QFile::symLinkTarget(fileName);
    if (link.length() > 0) fileName = link;

    bufsize_t maxMapSize = FILE_MAXSIZE;
    try {
        FileView fileView(fileName, maxMapSize);
        ExeFactory::exe_type exeType = ExeFactory::findMatching(&fileView);
        if (exeType == ExeFactory::NONE) {
            QMessageBox::warning(this, "Cannot parse!", "Cannot parse the file: \n"+fileName+"\n\nType not supported.");
            return false;
        }
        ExeHandlerLoader *loader = new ExeHandlerLoader(fileName);
        QObject::connect(loader, SIGNAL( loaded(ExeHandler*) ), &m_exes, SLOT( addExe(ExeHandler*) ) );
        QObject::connect(loader, SIGNAL( loadingFailed(QString ) ), this, SLOT( onLoadingFailed(QString ) ) );
        QObject::connect(loader, SIGNAL(finished()), this, SLOT( onLoaderThreadFinished() ) );
        m_LoadersCount.inc();
        loader->start();

    } catch (CustomException &e) {
        QMessageBox::warning(this, "ERROR", e.getInfo());
        return false;
    }
    return true;
}

char filename[PATH_MAX];

void MainWindow::load_malware_file(char * file, char * rep_list){
	
    //parse requires absolute filename
	realpath(file, filename);
    // printf("file::::     %s", file);
	QString s = QString::fromUtf8(filename);
	this->rep_list = rep_list;
	// QString s = QString::fromStdString("/home/fenil/Desktop/thesis/ignore_it/auto_IAT_patcher/build/patcher/wannacry.exe");
	// printf("!%s!\n",s.toUtf8().constData());
    parse(s);
}

void MainWindow::hook_malware_file(void){
	// QString libname = QString::fromStdString("KERNEL32.dll");
	// QString funcname = QString::fromStdString("GetProcAddress");
	std::ifstream rep_f(rep_list);
	int count = 0;
	int hcount = 0;
	rep_f>>count;
	for(int i=0;i<count;i++){
		std::string fromfunc, fromlib, tofunc, tolib;
		rep_f>>fromfunc>>fromlib>>tofunc>>tolib;
		// std::cout<<fromfunc<<":"<<fromlib<<":"<<tofunc<<":"<<tolib<<"\n";
		QString Qfromfunc = QString::fromStdString(fromfunc);
		QString Qfromlib = QString::fromStdString(fromlib);
		QString Qtofunc = QString::fromStdString(tofunc);
		QString Qtolib = QString::fromStdString(tolib);
		offset_t thunk = this->m_ExeSelected->m_FuncMap.findThunk(Qfromlib, Qfromfunc);	
		if(thunk != INVALID_ADDR){
			//nuke it...i mean...hook it!
			QString substname = Qtolib + "." + Qtofunc;
			if (this->m_ExeSelected->defineReplacement(thunk, substname) == false) {
				printf("invalid replacement definition for %s", Qfromfunc.toUtf8().constData());
	        	// QMessageBox::warning(this, "Error", "Invalid replacement definition!");
	    	}
	    	else{
	    		printf("replacement defined for %s\n", Qfromfunc.toUtf8().constData());
	    		
	    	}

		}
		else{
			// printf("thunk invalid for  %s\n", Qfromfunc.toUtf8().constData());
		} 
		// if(m_ExeSelected->m_FuncMap.hasFunc(QString::fromStdString("GetProcAddress"))){
		 //    	printf("yay\n");

		 //    }
		 //    else{
		 //    	printf("nay\n");
	 	 //    }
	}
	StubSettings settings;
	settings.setAddNewSection(true);
	settings.setReuseImports(true);
	this->hookExecutable(this->m_ExeSelected, settings);
    if(my_save_exe){
    	QString newfilename = QString::fromStdString(filename);
        newfilename = newfilename.append(QString("_new"));
    	this->exeController.saveExecutable(this->m_ExeSelected, newfilename);
    }
    this->close();

	
	
}


void MainWindow::info()
{
    int ret = 0;
    int count = 0;
    QPixmap p(":/favicon.ico");
    QString msg = "<b>IAT Patcher</b> - tool for persistent IAT hooking<br/>";
    msg += "author: hasherezade<br/><br/>";
    msg += "using: Qt5<br/><br/>";
    msg += "THIS TOOL IS PROVIDED \"AS IS\" WITHOUT WARRANTIES OF ANY KIND. <br/>\
        Use it at your own risk and responsibility.<br/>\
        Only for research purpose. Do not use it to break the law!<br/><br/>";
    msg += "<a href='" + QString(SITE_LINK) + "'>Sourcecode & more info</a><br/>";
    msg += "<a href='" + QString(ISSUES_LINK) + "'>Report issue</a>";

    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setAttribute(Qt::WA_DeleteOnClose);

    msgBox->setWindowTitle("Info");
    msgBox->setTextFormat(Qt::RichText);

    msgBox->setText(msg);
    msgBox->setAutoFillBackground(true);
    msgBox->setIconPixmap(p);

    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->exec();
}