#include "MainWindow.h"

MainWindow::MainWindow(): QWidget()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(createClassDefGroup());
    mainLayout->addWidget(createOptionsGroup());
    mainLayout->addWidget(createCommentsGroup());
    mainLayout->addLayout(createButtonsGroup());

    this->setLayout(mainLayout);

    QObject::connect(generateButton, SIGNAL(clicked()), this, SLOT(GenerateCode()));
    QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

QGroupBox* MainWindow::createClassDefGroup()
{
    QGroupBox *groupBox = new QGroupBox("Class definition");

    QFormLayout *formLayout = new QFormLayout;
    className = new QLineEdit;
    parentClass = new QLineEdit;
    formLayout->addRow("Name", className);
    formLayout->addRow("Parent class", parentClass);

    groupBox->setLayout(formLayout);
    return groupBox;
}

QGroupBox* MainWindow::createOptionsGroup()
{
    QGroupBox* groupBox = new QGroupBox("Options");

    checkHeader = new QCheckBox("Protect header from multiple inclusions");
    checkConstructor = new QCheckBox("Generate default constructor");
    checkDestructor = new QCheckBox("Generate destructor");
    checkHeader->setChecked(true);
    checkConstructor->setChecked(true);

    QVBoxLayout *vBox = new QVBoxLayout;
    vBox->addWidget(checkHeader);
    vBox->addWidget(checkConstructor);
    vBox->addWidget(checkDestructor);

    groupBox->setLayout(vBox);
    return groupBox;
}

QGroupBox* MainWindow::createCommentsGroup()
{

    activateComments = new QGroupBox("Comments");
    activateComments->setCheckable(true);
    activateComments->setChecked(false);

    QFormLayout *formLayout = new QFormLayout;
    author = new QLineEdit;
    date = new QDateEdit;
    date->setDate(QDate::currentDate());
    purpose = new QTextEdit;
    formLayout->addRow("Name", author);
    formLayout->addRow("Creation date", date);
    formLayout->addRow("Class purpose", purpose);

    activateComments->setLayout(formLayout);
    return activateComments;
}

QHBoxLayout* MainWindow::createButtonsGroup()
{
    QHBoxLayout* hBox = new QHBoxLayout;
    generateButton = new QPushButton("Generate");
    quitButton = new QPushButton("Quit");

    hBox->addWidget(generateButton);
    hBox->addWidget(quitButton);
    return hBox;
}

void MainWindow::GenerateCode()
{
    if(className->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "Please enter at least a class name");
        return;
    }

    // Generate text code
    QString headerCode = GenerateHeaderCode();
    QString cppCode = GenerateCppCode();

    // Create QDialog Window and  displays it
    codeWindow = new GeneratedCodeWindow(headerCode, cppCode);
    codeWindow->exec();
}

QString MainWindow::GenerateHeaderCode()
{
    QString codeString;

    // COMMENTS IF NEEDED
    if(activateComments->isChecked())
    {
        codeString += "/*\n Author : " + author->text() + "\n Date of creation : " + date->text() +
                        "\n\n Class purpose : \n"
                        + purpose->toPlainText()
                        + "\n\\*";
    }

    // HEADER GUARD IF NEEDED
    if(checkHeader->isChecked())
    {
        codeString += "\n\n\n#ifndef HEADER_" + className->text().toUpper() + "\n"
                        "#define HEADER_" + className->text().toUpper() + "\n\n";
    }

    codeString += "class " + className->text();

    // PARENT CLASS IF NEEDED
    if(!parentClass->text().isEmpty()) //means a parent class has been specified
    {
        codeString += " : public " + parentClass->text();
    }

    codeString += "\n{\n"
                    "\tpublic: \n";

    // CONSTRUCTOR IF NEEDED
    if(checkConstructor->isChecked())
    {
       codeString +=  "\t\t" + className->text() + "();\n";
    }
    // DESTRUCTOR IF NEEDED
    if(checkDestructor->isChecked())
    {
        codeString += "\t\t~" + className->text() + "();\n";
    }

    codeString += "\n\n\tprotected:\n\n\n"
                    "\tprivate:\n\n\n"
                    "};\n\n";

    //END OF HEADER IF NEEDED
    if(checkHeader->isChecked())
    {
        codeString += "#endif // HEADER_" + className->text().toUpper() + "\n";
    }

    return codeString;
}

QString MainWindow::GenerateCppCode()
{
    QString cppString;

    cppString += "#include \"" + className->text() + "\"\n\n";

    if(checkConstructor->isChecked())
    {
        cppString += className->text() + "::" + className->text() + "()\n"
                    "{\n\n\n\n"
                    "}\n";
    }

    if(checkDestructor->isChecked())
    {
        cppString += "\n" + className->text() + "::~" + className->text() + "()\n"
                    "{\n\n\n\n"
                    "}\n";
    }

    return cppString;
}
// NARAL CHALERMCHAIKOSOL 63011193
