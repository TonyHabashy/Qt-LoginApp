#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr, const QString username = "");  // New constructor
    ~SecDialog();

private:
    QLabel *label_welcome;  // Label for the welcome message
    QLabel *label_Pic2;     // Label for the image
    QVBoxLayout *layout;     // Layout to hold widgets
};

#endif // SECDIALOG_H
