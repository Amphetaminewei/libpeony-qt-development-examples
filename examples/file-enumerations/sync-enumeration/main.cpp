#include "mainwindow.h"
#include <QApplication>
#include <PeonyFileEnumerator>
#include <PeonyFileInfo>
#include <QTextEdit>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QTextEdit t;
    w.setCentralWidget(&t);

    Peony::FileEnumerator e;
    e.setEnumerateDirectory("computer:///");
    e.enumerateSync();

    QList<std::shared_ptr<Peony::FileInfo>> infos = e.getChildren();
    for (std::shared_ptr<Peony::FileInfo> info : infos) {
        qDebug()<<info->uri();
        t.append(info->uri());
        t.append("\n");
    }

    w.show();

    return a.exec();
}
