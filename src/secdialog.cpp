#include "../include/secdialog.h"
#include <QLabel>
#include <QVBoxLayout>

SecDialog::SecDialog(QWidget *parent, const QString username) :
    QDialog(parent)
{
    qDebug() << "SecDialog constructor called with username: " << username;
    // Create the layout for the dialog
    layout = new QVBoxLayout(this);

    // Create the welcome label with the username
    label_welcome = new QLabel("Welcome, " + username + "!", this);
    label_welcome->setObjectName("label_welcome");
    label_welcome->setStyleSheet("font-size: 20px; font-weight: bold; color: #4CAF50; padding: 20px;");

    // Add the welcome label to the layout
    layout->addWidget(label_welcome);

    // Set the dialog layout
    setLayout(layout);

    // Adjust the window size and title (optional)
    setWindowTitle("Welcome Dialog");
    setFixedSize(300, 200);  // Adjust as needed

    show();
}

SecDialog::~SecDialog()
{
    // Qt will clean up the layout and widgets automatically, no need to manually delete them.
}
