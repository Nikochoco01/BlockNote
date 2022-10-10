#include "BlockNote.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BlockNote w;
    w.show();
    return a.exec();
}
