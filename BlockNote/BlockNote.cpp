#include "BlockNote.h"
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <QFontDialog>

BlockNote::BlockNote(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.actionNew, &QAction::triggered, this, &BlockNote::setItalic);
    connect(ui.actionNew, &QAction::triggered, this, &BlockNote::setBold);
    connect(ui.actionNew, &QAction::triggered, this, &BlockNote::setUnderline);
}

BlockNote::~BlockNote()
{}

void BlockNote::on_actionNew_triggered() {
    currentFile.clear();
    ui.textEdit->setText(QString());
}

void BlockNote::on_actionOpen_triggered(){
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " +
            file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui.textEdit->setText(text);
    file.close();
}

void BlockNote::on_actionSave_triggered() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save the file");
    //if (fileName.isEmpty())
    //    return;
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " +
            file.errorString());
        return;
    }
    QTextStream out(&file);
    out << ui.textEdit->toPlainText();
    out.flush(); // pas obligatoire car le close fait le flush
    file.close();
}

void BlockNote::on_actionSave_as_triggered() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save the file");
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " +
            file.errorString());
        return;
    }
    QTextStream out(&file);
    out << ui.textEdit->toPlainText();
    out.flush(); // pas obligatoire car le close fait le flush
    file.close();
}

void BlockNote::on_actionExit_triggered() {
    this->close();
}

/* Edit File */

void BlockNote::on_actionColor_triggered() {
    
}

void BlockNote::on_actionFont_triggered() {
    bool fontSelected;
    QFont changeFont = QFontDialog::getFont(&fontSelected, this);
    if (fontSelected) {
        ui.textEdit->setFont(changeFont);
    }
}

void BlockNote::setItalic(bool italic) {
    ui.textEdit->setFontItalic(italic);
}

void BlockNote::setBold(bool bold) {
    ui.textEdit->setFontBold(bold);
}

void BlockNote::setUnderline(bool underline) {
    ui.textEdit->setFontUnderline(underline);
}

void BlockNote::on_actionCopy_triggered() {
    ui.textEdit->copy();
}

void BlockNote::on_actionCut_triggered() {
    ui.textEdit->cut();
}

void BlockNote::on_actionPaste_triggered() {
    ui.textEdit->paste();
}
