#include "GeneratedCodeWindow.h"

GeneratedCodeWindow::GeneratedCodeWindow(QString _headerCode, QString _cppCode) : QDialog()
{
    //1: Create a tab widget
    QTabWidget *tabs = new QTabWidget(this);

    //2: Create 1 widget for each tab (2 here)
    QWidget *headerWidget = CreateCodeWidget(_headerCode);
    QWidget *cppWidget = CreateCodeWidget(_cppCode);

    //3: Add tabs to QTabWidget with their respective QWidget
    tabs->addTab(headerWidget, "Header file");
    tabs->addTab(cppWidget, "Cpp file");

    //4: Create close button
    closeButton = new QPushButton("Close");
    connect(closeButton, SIGNAL(clicked()), this, SLOT(accept()));

    //5: Use layouts to place elements
    QHBoxLayout *hBox = new QHBoxLayout;
    tabs->setLayout(hBox);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabs);
    mainLayout->addWidget(closeButton);

    this->setLayout(mainLayout);
    resize(400, 525);
}

QWidget* GeneratedCodeWindow::CreateCodeWidget(QString _code)
{
    QWidget *widget = new QWidget;
    QVBoxLayout *vBox = new QVBoxLayout;


    QTextEdit *generatedCode = new QTextEdit;
    generatedCode->setReadOnly(true);
    generatedCode->setFont(QFont("Courrier"));
    generatedCode->setLineWrapMode(QTextEdit::NoWrap);
    generatedCode->setPlainText(_code);

    vBox->addWidget(generatedCode);

    widget->setLayout(vBox);
    return widget;
}
// NARAL CHALERMCHAIKOSOL 63011193
