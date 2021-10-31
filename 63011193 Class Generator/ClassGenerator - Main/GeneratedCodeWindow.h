#ifndef GENERATEDCODEWINDOW_H
#define GENERATEDCODEWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QString>
#include <QPushButton>
#include <QTabWidget>

class GeneratedCodeWindow : public QDialog
{
public:
    GeneratedCodeWindow(QString _headerCode, QString _cppCode);

private:
    QPushButton *closeButton;

    QWidget* CreateCodeWidget(QString _code);
};

#endif // GENERATEDCODEWINDOW_H
// NARAL CHALERMCHAIKOSOL 63011193
