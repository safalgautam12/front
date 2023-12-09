#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    // this will hide the push button " check your work"
    ui->check_your_work->hide();
    // these two lines are for adding picture
    QPixmap pix("C:/Users/safal/OneDrive/Desktop/BazarMilo/Assets/front_image.png");
    ui->label_pic->setPixmap(pix);

    // Connect signals of LineEdits to updateSubmitButtonState slot
    connect(ui->lineEdit_username, &QLineEdit::textChanged, this, &MainWindow::updateSubmitButtonState);
    connect(ui->lineEdit_password, &QLineEdit::textChanged, this, &MainWindow::updateSubmitButtonState);
    connect(ui->lineEdit_Email, &QLineEdit::textChanged, this, &MainWindow::updateSubmitButtonState);
    connect(ui->checkBox, &QCheckBox::stateChanged, this, &MainWindow::updateSubmitButtonState);


    // Initially disable the submit button
    ui->pushButton_2->setEnabled(false);

    // Set border radius for LineEdit widgets
    QString lineEditStyle = "QLineEdit { border-radius: 10px; border: 2px solid #555555;  padding: 5px; }";
    ui->lineEdit_username->setStyleSheet(lineEditStyle);
    ui->lineEdit_password->setStyleSheet(lineEditStyle);
    ui->lineEdit_Email->setStyleSheet(lineEditStyle);

    QString buttonStyle = "QPushButton { border-radius: 10px; border: 2px solid #555555;  padding: 5px; }";
    ui->pushButton_2->setStyleSheet(buttonStyle);
    ui->pushButton_4->setStyleSheet(buttonStyle);
    ui->check_your_work->setStyleSheet(buttonStyle);
    ui->pushButton_signup->setStyleSheet(buttonStyle);

    // Set up a regular expression validator for email input
    QRegularExpression emailRegex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}");

    // Set the regular expression validator for the email line edit
    QValidator *emailValidator = new QRegularExpressionValidator(emailRegex, this);
    ui->lineEdit_Email->setValidator(emailValidator);

    QString groupBoxStyle = "QGroupBox { background-color: #FFE4C4; border:  border-radius: 2px; }";
    ui->groupBox->setStyleSheet(groupBoxStyle);
}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_actionNavigate_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
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
    }
    else
    {
        QMessageBox::warning(this,"login","username and password is not correct");
    }
}



void MainWindow::on_pushButton_4_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_check_your_work_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_lineEdit_Email_textChanged(const QString &) {
    // Perform email validation or any required actions when the text changes
    updateSubmitButtonState(); // Call your validation logic

}

