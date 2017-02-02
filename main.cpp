#include "mainwindow.h"
#include <QApplication>
#include "Game.h"
#include "ConsolePlayer.h"
#include <cstdio>

using namespace std;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow * w = new MainWindow;
    CGlobal::ww=w;

    //w->show();



    return a.exec();
}



