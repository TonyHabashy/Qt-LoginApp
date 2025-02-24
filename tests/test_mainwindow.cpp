#include <gtest/gtest.h>
#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QTest>  // For QTest functions
#include "../include/mainwindow.h"

// Global QApplication for Qt event loop
int argc = 1;
char *argv[] = {(char *)"test"};
QApplication app(argc, argv);

class MainWindowTest : public ::testing::Test {
protected:
    void SetUp() override {
        mainWindow = new MainWindow();
        mainWindow->show();  // Show the window so that widgets are initialized
    }

    void TearDown() override {
        delete mainWindow;
    }

    MainWindow *mainWindow;
};

// Test default UI state
TEST_F(MainWindowTest, UIInitialState) {
    auto *checkBox = mainWindow->findChild<QCheckBox *>("checkBox_ShowPassword");
    ASSERT_NE(checkBox, nullptr);
    ASSERT_FALSE(checkBox->isChecked());

    auto *lineEditPassword = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    ASSERT_NE(lineEditPassword, nullptr);
    ASSERT_EQ(lineEditPassword->echoMode(), QLineEdit::Password);
}

// Test Password Visibility Toggle with Valid Password
TEST_F(MainWindowTest, PasswordVisibilityToggleWithValidPassword) {
    auto *passwordField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *checkBox = mainWindow->findChild<QCheckBox *>("checkBox_ShowPassword");

    passwordField->setText("test");
    checkBox->setChecked(true);

    ASSERT_EQ(passwordField->echoMode(), QLineEdit::Normal);  // Check that password is visible

    checkBox->setChecked(false);
    ASSERT_EQ(passwordField->echoMode(), QLineEdit::Password);  // Check that password is hidden
}

// Test Multiple Login Windows Opened
TEST_F(MainWindowTest, MultipleLoginWindows) {
    MainWindow *anotherWindow = new MainWindow();
    anotherWindow->show();
    QCoreApplication::processEvents();

    ASSERT_NE(mainWindow, anotherWindow) << "Each instance should be unique";

    delete anotherWindow;
}

// Test correct login with valid credentials
TEST_F(MainWindowTest, CorrectLogin) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    ASSERT_NE(userField, nullptr);
    ASSERT_NE(passField, nullptr);
    ASSERT_NE(loginButton, nullptr);

    userField->setText("test");  // Correct username
    passField->setText("test");  // Correct password

    QTest::mouseClick(loginButton, Qt::LeftButton);

    QCoreApplication::processEvents();

    // Add delay to ensure event processing
    QTest::qWait(100);

    auto *dialog = mainWindow->findChild<SecDialog *>();
    ASSERT_NE(dialog, nullptr) << "SecDialog should be created and found.";
}

// Test incorrect login
TEST_F(MainWindowTest, IncorrectLogin) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    ASSERT_NE(userField, nullptr);
    ASSERT_NE(passField, nullptr);
    ASSERT_NE(loginButton, nullptr);

    userField->setText("wrong");
    passField->setText("wrong");

    // Simulate a button click
    QTest::mouseClick(loginButton, Qt::LeftButton);

    // Wait for event processing
    QCoreApplication::processEvents();

    // Add delay to ensure the dialog is not opened
    QTest::qWait(200);

    // Assert that the dialog is NOT created
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on incorrect credentials.";
}

// Test Show/Hide Password functionality
TEST_F(MainWindowTest, ShowHidePassword) {
    auto *passwordField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *checkBox = mainWindow->findChild<QCheckBox *>("checkBox_ShowPassword");

    ASSERT_NE(passwordField, nullptr);
    ASSERT_NE(checkBox, nullptr);

    checkBox->setChecked(true);
    ASSERT_EQ(passwordField->echoMode(), QLineEdit::Normal);

    checkBox->setChecked(false);
    ASSERT_EQ(passwordField->echoMode(), QLineEdit::Password);
}

// Test empty username/password
TEST_F(MainWindowTest, EmptyUsernamePassword) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->clear();
    passField->clear();

    // Simulate a button click
    QTest::mouseClick(loginButton, Qt::LeftButton);

    // Wait for event processing
    QCoreApplication::processEvents();

    // Verify that no dialog is shown when fields are empty
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on empty fields";
}

// Test Empty Username, Non-empty Password
TEST_F(MainWindowTest, EmptyUsernameNonEmptyPassword) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->clear();
    passField->setText("test");

    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();

    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open when username is empty";
}

// Test Non-empty Username, Empty Password
TEST_F(MainWindowTest, NonEmptyUsernameEmptyPassword) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("test");
    passField->clear();

    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();

    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open when password is empty";
}

// Test Empty Fields with Show Password Checkbox Checked
TEST_F(MainWindowTest, EmptyFieldsWithShowPasswordChecked) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *checkBox = mainWindow->findChild<QCheckBox *>("checkBox_ShowPassword");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->clear();
    passField->clear();
    checkBox->setChecked(true);

    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();

    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on empty fields even with Show Password checked";
}

// Test username/password with maximum length
TEST_F(MainWindowTest, LongUsernamePassword) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    QString longUsername = QString(255, 'a');
    QString longPassword = QString(255, 'b');

    userField->setText(longUsername);
    passField->setText(longPassword);

    // Simulate a button click
    QTest::mouseClick(loginButton, Qt::LeftButton);

    // Wait for event processing
    QCoreApplication::processEvents();

    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on too long username/password";
}

// Test username/password with a single character
TEST_F(MainWindowTest, SingleCharacterUsernamePassword) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("a");
    passField->setText("b");

    // Simulate a button click
    QTest::mouseClick(loginButton, Qt::LeftButton);

    // Wait for event processing
    QCoreApplication::processEvents();

    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should open on valid single-character credentials";
}

// Test multiple failed login attempts
TEST_F(MainWindowTest, MultipleFailedLoginAttempts) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    // First attempt
    userField->setText("wrong1");
    passField->setText("wrong1");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on wrong credentials";

    // Second attempt
    userField->setText("wrong2");
    passField->setText("wrong2");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on wrong credentials";
}

// Test successful login after failed attempts
TEST_F(MainWindowTest, SuccessfulLoginAfterFailedAttempts) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    // Failed attempt
    userField->setText("wrong");
    passField->setText("wrong");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on wrong credentials";

    // Successful attempt
    userField->setText("test");
    passField->setText("test");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_TRUE(mainWindow->findChild<SecDialog *>()) << "SecDialog should open on correct credentials";
}

// Test handling of leading and trailing spaces
TEST_F(MainWindowTest, LeadingTrailingSpaces) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText(" test");
    passField->setText("test ");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on leading/trailing spaces";

    userField->setText("test");
    passField->setText(" test ");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on untrimmed credentials";

    userField->setText("test");
    passField->setText(" test");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on untrimmed credentials";

    userField->setText(" test ");
    passField->setText("test");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on untrimmed credentials";

    userField->setText(" test");
    passField->setText("test");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on untrimmed credentials";

    userField->setText("test ");
    passField->setText("test");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on untrimmed credentials";
}

// Test case sensitivity
TEST_F(MainWindowTest, CaseSensitivity) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("Test");
    passField->setText("Test");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on case-sensitive mismatch";

    userField->setText("tEst");
    passField->setText("tEst");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on case-sensitive mismatch";

    userField->setText("teSt");
    passField->setText("Test");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on case-sensitive mismatch";

    userField->setText("test");
    passField->setText("tesT");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on case-sensitive mismatch";
}

// Test special characters in credentials
TEST_F(MainWindowTest, SpecialCharacters) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("te$t");
    passField->setText("t@est");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on special characters";


    userField->setText("t#st");
    passField->setText("p@ssword!");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on special characters";

    userField->setText("t#st");
    passField->setText("test");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on special characters";

    userField->setText("te$t");
    passField->setText("test");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on special characters";

    userField->setText("@#$%^");
    passField->setText("&*()_");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on special characters";
}

// Test SQL Injection or Code Injection attempts
TEST_F(MainWindowTest, SQLInjection) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText(" OR 1=1;--");
    passField->setText(" OR 1=1;--");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on SQL Injection attempt";

    userField->setText("' OR '1'='1");
    passField->setText("test");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on SQL Injection attempt";

    userField->setText("test");
    passField->setText("' OR '1'='1");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on SQL Injection attempt";
}

// Test multiple rapid failed login attempts
TEST_F(MainWindowTest, RapidFailedLoginAttempts) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    for (int i = 0; i < 10; ++i) {
        userField->setText("wrong" + QString::number(i));
        passField->setText("wrong" + QString::number(i));
        QTest::mouseClick(loginButton, Qt::LeftButton);
        QCoreApplication::processEvents();
    }
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open after multiple failed attempts";
}

// Test Unicode Characters in Username/Password
TEST_F(MainWindowTest, UnicodeCharacterCredentials) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("äöüßéçñ");
    passField->setText("äöüßéçñ");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on Unicode credentials";
}

// Test Partial Correct Credentials
TEST_F(MainWindowTest, PartialCorrectCredentials) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("test");
    passField->setText("wrong");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open when only username is correct";

    userField->setText("wrong");
    passField->setText("test");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open when only password is correct";
}

// Newline Character in Username/Password
TEST_F(MainWindowTest, NewlineCharacterCredentials) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("\n");
    passField->setText("\r");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on newline character credentials";
}

// Newline Character in Username using \n
TEST_F(MainWindowTest, NewlineCharacterUsername1) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("\n");
    passField->setText("test");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on newline character credentials";
}

// Newline Character in Username using \r
TEST_F(MainWindowTest, NewlineCharacterUsername2) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("\r");
    passField->setText("test");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on newline character credentials";
}

// Newline Character in Password using \n
TEST_F(MainWindowTest, NewlineCharacterPassword1) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("test");
    passField->setText("\n");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on newline character credentials";
}

// Newline Character in Password using \r
TEST_F(MainWindowTest, NewlineCharacterPassword2) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("test");
    passField->setText("\r");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on newline character credentials";
}

// Test Tab Character in Username and Password
TEST_F(MainWindowTest, TabCharacterCredentials) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("\t");
    passField->setText("\t");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on tab character credentials";
}

// Test Tab Character in Username
TEST_F(MainWindowTest, TabCharacterUsername) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("\t");
    passField->setText("test");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on tab character credentials";
}

// Test Tab Character in Password
TEST_F(MainWindowTest, TabCharacterPassword) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("test");
    passField->setText("\t");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on tab character credentials";
}

// Test Only Spaces in Username and Password
TEST_F(MainWindowTest, WhitespaceOnlyCredentials) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("   ");
    passField->setText("   ");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();
    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on whitespace-only credentials";
}

// Test Username and Password Containing Only Numbers
TEST_F(MainWindowTest, NumericOnlyCredentials) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("12345");
    passField->setText("67890");

    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();

    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on numeric credentials";
}

// Test Only Special Characters in Username and Password
TEST_F(MainWindowTest, SpecialCharactersOnlyCredentials) {
    auto *userField = mainWindow->findChild<QLineEdit *>("lineEdit_UserName");
    auto *passField = mainWindow->findChild<QLineEdit *>("lineEdit_Password");
    auto *loginButton = mainWindow->findChild<QPushButton *>("pushButton_Login");

    userField->setText("@#$%^");
    passField->setText("&*()_");

    QTest::mouseClick(loginButton, Qt::LeftButton);
    QCoreApplication::processEvents();

    ASSERT_FALSE(mainWindow->findChild<SecDialog *>()) << "SecDialog should NOT open on special characters only credentials";
}
