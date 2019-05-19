#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QString>

#include <iostream>
#include <stdio.h>
#include <bearparser.h>

#include <limits>
using namespace std;





int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);
    QApplication app(argc, argv);
    ExeFactory::init();

    MainWindow *w = new MainWindow();
    w->show();

    if(argc != 3){
    	cout<<"must provide 2 arguments!\n";
    }
    w->load_malware_file(argv[1], argv[2]);

    return app.exec();
}
