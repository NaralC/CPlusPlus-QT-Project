#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QFrame>
#include <QLabel>
#include <QCheckBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QMessageBox>
#include "GeneratedCodeWindow.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

public slots:
    void GenerateCode();

private:
    QLabel *defLabel;

    QLineEdit *className;
    QLineEdit *parentClass;
    QCheckBox *checkHeader;
    QCheckBox *checkConstructor;
    QCheckBox *checkDestructor;
    QGroupBox *activateComments;
    QLineEdit *author;
    QDateEdit *date;
    QTextEdit *purpose;

    QPushButton *generateButton;
    QPushButton *quitButton;

    GeneratedCodeWindow *codeWindow;

    QGroupBox* createClassDefGroup();
    QGroupBox* createOptionsGroup();
    QGroupBox* createCommentsGroup();
    QHBoxLayout* createButtonsGroup();

    QString GenerateHeaderCode();
    QString GenerateCppCode();
};

#endif // MAINWINDOW_H
// NARAL CHALERMCHAIKOSOL 63011193
