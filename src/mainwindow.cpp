#include "../include/mainwindow.h"
#include "forms/ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QThread>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , checkBox_ShowPassword(new QCheckBox(this))  // Initialize checkbox
    , secDialog(nullptr)                          // Initialize to nullptr to avoid memory issues
{
    ui->setupUi(this);

    // Ensure lineEdit_Password is pointing to the correct QLineEdit from the UI
    lineEdit_Password = ui->lineEdit_Password;

    checkBox_ShowPassword->setObjectName("checkBox_ShowPassword");
    lineEdit_Password->clear();
    lineEdit_Password->setStyleSheet("font-size: 14px; padding: 5px; border: 1px solid gray; border-radius: 5px;");
    // Set background color
    setStyleSheet("background-color: #f1f1f1;");

    // Set up the username and password input fields
    ui->lineEdit_UserName->setStyleSheet("font-size: 14px; padding: 5px; border: 1px solid gray; border-radius: 5px;");
    ui->lineEdit_Password->setStyleSheet("font-size: 14px; padding: 5px; border: 1px solid gray; border-radius: 5px;");
    lineEdit_Password->setEchoMode(QLineEdit::Password);  // Default: Hide password

    // Set up the login button
    ui->pushButton_Login->setStyleSheet(
        "background-color: #4CAF50; color: white; border: none; padding: 10px 20px; font-size: 16px; border-radius: 5px;"
        );
    ui->pushButton_Login->setFixedHeight(40);

    // Initialize the show/hide password checkbox
    checkBox_ShowPassword->setText("Show Password");
    checkBox_ShowPassword->setStyleSheet("font-size: 14px;");
    checkBox_ShowPassword->setChecked(false);

    // Create a horizontal layout for the password field and checkbox
    QHBoxLayout *passwordLayout = new QHBoxLayout();
    passwordLayout->addWidget(lineEdit_Password);
    passwordLayout->addWidget(checkBox_ShowPassword);
    passwordLayout->setStretch(0, 4);  // Password field takes more space
    passwordLayout->setStretch(1, 1);  // Checkbox takes less space

    // Create a vertical layout for the entire login form
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setSpacing(10);  // Space between widgets
    mainLayout->setContentsMargins(50, 50, 50, 50);  // Set margins to center the form

    // Add widgets to layout
    mainLayout->addWidget(new QLabel("Username:", this));
    mainLayout->addWidget(ui->lineEdit_UserName);
    mainLayout->addWidget(new QLabel("Password:", this));
    mainLayout->addLayout(passwordLayout);  // Add password field + checkbox
    mainLayout->addWidget(ui->pushButton_Login);
    mainLayout->setAlignment(Qt::AlignCenter);

    // Apply the layout to the central widget
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Connect the checkbox signal to toggle password visibility
    connect(checkBox_ShowPassword, &QCheckBox::toggled, this, &MainWindow::togglePasswordVisibility);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (secDialog) {
        delete secDialog;
        secDialog = nullptr;
    }
}

void MainWindow::on_pushButton_Login_clicked()
{
    qDebug() << "Login button clicked";

    QString username = ui->lineEdit_UserName->text();
    QString password = lineEdit_Password->text();

    qDebug() << "Entered Username: " << username;
    qDebug() << "Entered Password: " << password;

    // Check for empty fields
    // Check if the credentials are valid
    if (username == "test" && password == "test") {
        // Correct credentials, opening SecDialog
        qDebug() << "Correct credentials, opening SecDialog";
        ui->statusbar->showMessage("Username and Password are correct", 2000);

        // Cleanup any existing SecDialog
        if (secDialog) {
            delete secDialog;
            secDialog = nullptr;
            qDebug() << "Previous SecDialog deleted.";
        }

        // Create and show the SecDialog
        secDialog = new SecDialog(this, username);
        secDialog->show();
        qDebug() << "SecDialog successfully created!";
    } else {
        qDebug() << "Incorrect credentials";
        QMessageBox::warning(this, "Login Failed", "Username or Password is incorrect.");
        ui->statusbar->showMessage("Username or Password is incorrect", 2000);

        // Do not open SecDialog
        if (secDialog) {
            delete secDialog;
            secDialog = nullptr;
        }
    }

}

void MainWindow::togglePasswordVisibility(bool checked)
{
    if (!lineEdit_Password)
        return;

    lineEdit_Password->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
}

void MainWindow::openSecDialog()
{
    QString username = ui->lineEdit_UserName->text();

    if (!secDialog)  // Nur erstellen, wenn sie noch nicht existiert
    {
        secDialog = new SecDialog(this, username);
    }

    secDialog->show();
}
