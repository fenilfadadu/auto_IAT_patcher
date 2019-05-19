/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAdd_new_section;
    QAction *actionAdd_imports;
    QAction *actionOpen;
    QAction *actionSave_as;
    QAction *action;
    QAction *actionOpen_hooking_schema;
    QAction *actionSave_hooking_schema;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *fileEdit;
    QPushButton *pushButton;
    QPushButton *reloadButton;
    QPushButton *clearAllButton;
    QLabel *label_2;
    QSplitter *splitter_2;
    QTableView *outputTable;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *filterLibEdit;
    QLineEdit *filterProcEdit;
    QTableView *importsTable;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *hookButton;
    QPushButton *saveButton;
    QMenuBar *menuBar;
    QMenu *menuAbout;
    QMenu *menuSettings;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(731, 522);
        MainWindow->setMinimumSize(QSize(100, 300));
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/favicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(1);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAdd_new_section = new QAction(MainWindow);
        actionAdd_new_section->setObjectName(QStringLiteral("actionAdd_new_section"));
        actionAdd_new_section->setCheckable(true);
        actionAdd_new_section->setChecked(true);
        actionAdd_imports = new QAction(MainWindow);
        actionAdd_imports->setObjectName(QStringLiteral("actionAdd_imports"));
        actionAdd_imports->setCheckable(true);
        actionAdd_imports->setChecked(true);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        actionOpen_hooking_schema = new QAction(MainWindow);
        actionOpen_hooking_schema->setObjectName(QStringLiteral("actionOpen_hooking_schema"));
        actionSave_hooking_schema = new QAction(MainWindow);
        actionSave_hooking_schema->setObjectName(QStringLiteral("actionSave_hooking_schema"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        fileEdit = new QLineEdit(centralWidget);
        fileEdit->setObjectName(QStringLiteral("fileEdit"));
        fileEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(fileEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/Add.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(24, 24));
        pushButton->setFlat(false);

        horizontalLayout_2->addWidget(pushButton);

        reloadButton = new QPushButton(centralWidget);
        reloadButton->setObjectName(QStringLiteral("reloadButton"));
        sizePolicy.setHeightForWidth(reloadButton->sizePolicy().hasHeightForWidth());
        reloadButton->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/reload.ico"), QSize(), QIcon::Normal, QIcon::Off);
        reloadButton->setIcon(icon2);
        reloadButton->setIconSize(QSize(24, 24));
        reloadButton->setFlat(false);

        horizontalLayout_2->addWidget(reloadButton);

        clearAllButton = new QPushButton(centralWidget);
        clearAllButton->setObjectName(QStringLiteral("clearAllButton"));
        sizePolicy.setHeightForWidth(clearAllButton->sizePolicy().hasHeightForWidth());
        clearAllButton->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/DeleteAll.ico"), QSize(), QIcon::Normal, QIcon::Off);
        clearAllButton->setIcon(icon3);
        clearAllButton->setIconSize(QSize(24, 24));
        clearAllButton->setFlat(false);

        horizontalLayout_2->addWidget(clearAllButton);


        verticalLayout->addLayout(horizontalLayout_2);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        outputTable = new QTableView(splitter_2);
        outputTable->setObjectName(QStringLiteral("outputTable"));
        outputTable->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(outputTable->sizePolicy().hasHeightForWidth());
        outputTable->setSizePolicy(sizePolicy1);
        outputTable->setAutoFillBackground(true);
        outputTable->setFrameShape(QFrame::StyledPanel);
        outputTable->setAlternatingRowColors(true);
        outputTable->setSortingEnabled(true);
        splitter_2->addWidget(outputTable);
        outputTable->horizontalHeader()->setStretchLastSection(true);
        frame = new QFrame(splitter_2);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setMinimumSize(QSize(0, 40));
        frame->setMaximumSize(QSize(16777215, 38));
        horizontalLayout_4 = new QHBoxLayout(frame);
        horizontalLayout_4->setSpacing(1);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 1);
        filterLibEdit = new QLineEdit(frame);
        filterLibEdit->setObjectName(QStringLiteral("filterLibEdit"));
        sizePolicy2.setHeightForWidth(filterLibEdit->sizePolicy().hasHeightForWidth());
        filterLibEdit->setSizePolicy(sizePolicy2);
        filterLibEdit->setAcceptDrops(false);
        filterLibEdit->setReadOnly(false);

        horizontalLayout_4->addWidget(filterLibEdit);

        filterProcEdit = new QLineEdit(frame);
        filterProcEdit->setObjectName(QStringLiteral("filterProcEdit"));
        sizePolicy2.setHeightForWidth(filterProcEdit->sizePolicy().hasHeightForWidth());
        filterProcEdit->setSizePolicy(sizePolicy2);
        filterProcEdit->setAcceptDrops(false);
        filterProcEdit->setReadOnly(false);

        horizontalLayout_4->addWidget(filterProcEdit);

        splitter_2->addWidget(frame);
        importsTable = new QTableView(splitter_2);
        importsTable->setObjectName(QStringLiteral("importsTable"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(importsTable->sizePolicy().hasHeightForWidth());
        importsTable->setSizePolicy(sizePolicy3);
        importsTable->setLayoutDirection(Qt::LeftToRight);
        importsTable->setAutoFillBackground(true);
        importsTable->setAlternatingRowColors(true);
        splitter_2->addWidget(importsTable);
        importsTable->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(splitter_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        hookButton = new QPushButton(centralWidget);
        hookButton->setObjectName(QStringLiteral("hookButton"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/apply.ico"), QSize(), QIcon::Normal, QIcon::Off);
        hookButton->setIcon(icon4);

        horizontalLayout_3->addWidget(hookButton);

        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/save_black.ico"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon5);

        horizontalLayout_3->addWidget(saveButton);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 731, 21));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuAbout->addAction(actionAbout);
        menuSettings->addAction(actionAdd_new_section);
        menuSettings->addAction(actionAdd_imports);

        retranslateUi(MainWindow);

        pushButton->setDefault(true);
        reloadButton->setDefault(true);
        clearAllButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "IAT Patcher", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        actionAdd_new_section->setText(QApplication::translate("MainWindow", "Add new section", Q_NULLPTR));
        actionAdd_imports->setText(QApplication::translate("MainWindow", "Reuse imports", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open PE", Q_NULLPTR));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save PE as..", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        actionOpen_hooking_schema->setText(QApplication::translate("MainWindow", "Open hooking schema", Q_NULLPTR));
        actionSave_hooking_schema->setText(QApplication::translate("MainWindow", "Save hooking schema", Q_NULLPTR));
        fileEdit->setPlaceholderText(QApplication::translate("MainWindow", "Selected executable", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("MainWindow", "Open file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        reloadButton->setToolTip(QApplication::translate("MainWindow", "Reload all", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        reloadButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        clearAllButton->setToolTip(QApplication::translate("MainWindow", "Unload all", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        clearAllButton->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Preview:", Q_NULLPTR));
        filterLibEdit->setPlaceholderText(QApplication::translate("MainWindow", "Filter libraries", Q_NULLPTR));
        filterProcEdit->setPlaceholderText(QApplication::translate("MainWindow", "Filter functions", Q_NULLPTR));
        hookButton->setText(QApplication::translate("MainWindow", "Hook!", Q_NULLPTR));
        saveButton->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "Info", Q_NULLPTR));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
