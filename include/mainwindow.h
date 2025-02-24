#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "secdialog.h"
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Login_clicked();
    void openSecDialog();
    //void on_checkBox_ShowPassword_toggled(bool checked);
    void togglePasswordVisibility(bool checked);

private:
    Ui::MainWindow *ui;
    SecDialog *secDialog;
    QString mUsername;
    QString mPassword;
    bool passwordVisible = false;
    QCheckBox *checkBox_ShowPassword;
    QLineEdit *lineEdit_Password;

};
#endif // MAINWINDOW_H
