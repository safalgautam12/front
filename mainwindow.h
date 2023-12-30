#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVariant>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private slots:
    void on_pushButton_2_clicked();


    void on_pushButton_4_clicked();
    void on_check_your_work_clicked();
    void on_lineEdit_username_textChanged(const QString &arg1);


    void on_lineEdit_password_textChanged(const QString &arg1);

    void updateSubmitButtonState();

    void on_lineEdit_Email_textChanged(const QString &text);


    void on_pushButton_signup_clicked();

    void on_pushButton_clicked();

    void on_actionDashboard_triggered();

    void on_actionProducts_triggered();

    void on_actionUsers_triggered();

    void on_actionVehicles_triggered();

    void on_pushButton_3_clicked();
    void on_lineEdit_6_textChanged(const QString &text);


    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();


    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::MainWindow *ui;
    QString validIds;
signals:
    void setCenter(QVariant, QVariant);
    void addMarker(QVariant, QVariant);

};
#endif // MAINWINDOW_H
