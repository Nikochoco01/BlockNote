#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BlockNote.h"

class BlockNote : public QMainWindow
{
    Q_OBJECT

public:
    BlockNote(QWidget *parent = nullptr);
    ~BlockNote();

private:
    Ui::BlockNoteClass ui;
    QString currentFile;

private slots:

    // File Menu
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_as_triggered();
    void on_actionExit_triggered();

    // File edit

    void on_actionColor_triggered();
    void on_actionFont_triggered();
    void setItalic(bool);
    void setBold(bool);
    void setUnderline(bool);

    void on_actionCopy_triggered();
    void on_actionCut_triggered();
    void on_actionPaste_triggered();

    //void on_actionPaste_triggered();
    //void on_actionPaste_triggered();
};
