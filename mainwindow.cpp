#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QRegularExpressionValidator>
#include <QQuickItem>
#include <QIcon>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();

    auto obj = ui->quickWidget->rootObject();
    connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));
    connect(this, SIGNAL(addMarker(QVariant, QVariant)), obj, SLOT(addMarker(QVariant, QVariant)));

    emit setCenter(25.000, 50.000);
    emit addMarker(25.000, 50.000);

    ui->stackedWidget->setCurrentIndex(0);
    // this will hide the push button " check your work"
    ui->check_your_work->hide();
    // these two lines are for adding picture
    QVBoxLayout *mainLayout = new QVBoxLayout(ui->centralwidget);

    QGroupBox *groupBox = new QGroupBox("Group Box");
    groupBox->setStyleSheet("QGroupBox { background-color: #FFE4C4; border: 2px solid #555555; border-radius: 2px; }");
    QVBoxLayout *groupBoxLayout = new QVBoxLayout(groupBox);


    QPushButton *checkYourWork = new QPushButton("Check Your Work");

    groupBoxLayout->addWidget(checkYourWork, 0, Qt::AlignCenter); // Set alignment for button

    groupBox->setLayout(groupBoxLayout); // Set layout for group box

    mainLayout->addWidget(groupBox); // Add group box to main layout

    // Set stretch factors for the main layout to control resizing behavior
    mainLayout->setStretchFactor(groupBox, 1);
    ui->pushButton->setIcon(QIcon("qrc:/new/prefix1/Assets/home.png"));
    ui->pushButton->setCheckable(true);


    ui->groupBox_4->hide();
    ui->groupBox_5->hide();
    ui->groupBox_7->hide();


    //Assigning list of ids for validification
    validIds.append("1234h");
    validIds.append("5678h");
    validIds.append("9012h");
    // Connect signals of LineEdits to updateSubmitButtonState slot
    connect(ui->lineEdit_username, &QLineEdit::textChanged, this, &MainWindow::updateSubmitButtonState);
    connect(ui->lineEdit_password, &QLineEdit::textChanged, this, &MainWindow::updateSubmitButtonState);
    connect(ui->lineEdit_Email, &QLineEdit::textChanged, this, &MainWindow::updateSubmitButtonState);
    connect(ui->checkBox, &QCheckBox::stateChanged, this, &MainWindow::updateSubmitButtonState);
    connect(ui->pushButton_signup, SIGNAL(clicked()), this, SLOT(on_pushButton_signup_clicked()));
    connect(ui->lineEdit_6, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_6_textChanged);

    // Hide groupBox_3 by default
    ui->groupBox_3->hide();
    ui->label_17->hide();



    // Initially disable the submit button
    ui->pushButton_2->setEnabled(false);

    // Set border radius for LineEdit widgets
    QString lineEditStyle = "QLineEdit { border-radius: 15px; border: 2px solid #555555;  padding: 5px; }";
    ui->lineEdit_username->setStyleSheet(lineEditStyle);
    ui->lineEdit_password->setStyleSheet(lineEditStyle);
    ui->lineEdit_Email->setStyleSheet(lineEditStyle);
    ui->lineEdit_SignUp_Email->setStyleSheet(lineEditStyle);
    ui->lineEdit_signUp_userName->setStyleSheet(lineEditStyle);
    ui->linEdit_signUp_Password->setStyleSheet(lineEditStyle);

    QString buttonStyle = "QPushButton { border-radius: 15px; border: 2px solid #555555;  padding: 5px; }";
    ui->pushButton_2->setStyleSheet(buttonStyle);
    ui->pushButton_4->setStyleSheet(buttonStyle);
    ui->check_your_work->setStyleSheet(buttonStyle);
    ui->pushButton_signup->setStyleSheet(buttonStyle);
    ui->pushButton->setStyleSheet(buttonStyle);
    ui->submit_signUp->setStyleSheet(buttonStyle);
    ui->pushButton_2->setStyleSheet(buttonStyle);


    // Set up a regular expression validator for email input
    QRegularExpression emailRegex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}");

    // Set the regular expression validator for the email line edit
    QValidator *emailValidator = new QRegularExpressionValidator(emailRegex, this);
    ui->lineEdit_Email->setValidator(emailValidator);

    QString groupBoxStyle = "QGroupBox { background-color: #FFE4C4; border:  border-radius: 15px; }";
    ui->groupBox->setStyleSheet(groupBoxStyle);
    QIcon icon("qrc:/new/prefix1/Assets/home.png");  // Replace with your resource path
    ui->pushButton->setIcon(icon);

    // disabling the menubar
    ui->actionDashboard->setEnabled(false);
     ui->actionProducts->setEnabled(false);
    ui->actionUsers->setEnabled(false);
     ui->actionVehicles->setEnabled(false);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_username_textChanged(const QString &arg1) {
    Q_UNUSED(arg1);
    updateSubmitButtonState();
}

void MainWindow::on_lineEdit_password_textChanged(const QString &arg1) {
    Q_UNUSED(arg1);
    updateSubmitButtonState();
}

void MainWindow::updateSubmitButtonState() {
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString enteredEmail = ui->lineEdit_Email->text();
    // Check if entered email is not empty
    bool isEmailValid = !enteredEmail.isEmpty() && enteredEmail.contains('@');
    bool isCheckBoxChecked = ui->checkBox->isChecked();

    ui->pushButton_2->setEnabled(!username.isEmpty() && !password.isEmpty() && isEmailValid && isCheckBoxChecked);





}



void MainWindow::on_pushButton_2_clicked()
{
    QString username=ui->lineEdit_username->text();
    QString password =ui->lineEdit_password->text();
    if(username=="driver" && password=="admin")
    {
        QMessageBox::information(this,"login","username and password is correct");
        ui->check_your_work->show();
        ui->actionDashboard->setEnabled(true);
        ui->actionProducts->setEnabled(true);
        ui->actionUsers->setEnabled(true);
        ui->actionVehicles->setEnabled(true);
    }
    else
    {
        QMessageBox::warning(this,"login","username and password is not correct");

    }
}



void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}



void MainWindow::on_check_your_work_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_lineEdit_Email_textChanged(const QString &) {
    // Perform email validation or any required actions when the text changes
    updateSubmitButtonState(); // Call your validation logic

}


void MainWindow::on_pushButton_signup_clicked()
{

    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void MainWindow::on_actionDashboard_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_actionProducts_triggered()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_actionUsers_triggered()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_actionVehicles_triggered()
{
    ui->stackedWidget->setCurrentIndex(5);

}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_lineEdit_6_textChanged(const QString &text)
{
    QString enteredId = text.trimmed(); // Remove leading/trailing spaces if necessary
    int requiredLength=5;
    // Check if enteredId exists in the array of valid IDs (checking for complete matches)
    bool idFound = false;

    if (requiredLength > 0 && enteredId.length() == requiredLength) {
          idFound = validIds.contains(enteredId);




    // Show or hide groupBox_3 based on whether a matching ID was found
    if (idFound) {
        // Hardcoded information
        QString status = "Pending";
        QString addedOn = "2023-01-01"; // Added date
        QString name = "John Doe";
        QString deliveredOn = "2023-01-05"; // Delivered date
        QString location = "Sample Location";


        ui->lineEdit->setText(enteredId);
        ui->lineEdit_2->setText(status);
        ui->lineEdit_3->setText(addedOn);
        ui->lineEdit_4->setText(deliveredOn);
        ui->lineEdit_5->setText(location);


        ui->label_17->hide();
        ui->groupBox_3->show();
     }

    else {
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->groupBox_3->hide();
        ui->label_17->show();
    }
    }

}



void MainWindow::on_pushButton_6_clicked()
{
    ui->groupBox_4->show();
    ui->pushButton_6->setEnabled(false);

}


void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
    ui->lineEdit_12->clear();
    ui->groupBox_4->hide();
    ui->pushButton_6->setEnabled(true);
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->groupBox_5->show();
    ui->pushButton_8->setEnabled(false);

}


void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->pushButton->setEnabled(true);
}


void MainWindow::on_pushButton_10_clicked()
{

}


void MainWindow::on_pushButton_13_clicked()
{
    QString enteredId = ui->lineEdit_18->text();
    QString correctId="123456";
    if(        enteredId==correctId)
    {
         QMessageBox::information(this," ","Vehicl_Id is correct");
    }
else
    {
        ui->groupBox_7->show();
    }

}

