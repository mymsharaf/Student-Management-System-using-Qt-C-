#ifndef LOGIN_H
#define LOGIN_H
#include <QMainWindow>
#include "UserDialog1.h"
#include "AdminDialog1.h"
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;

    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen(){
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("E:/NSBM/3rd-year/1st semester/C++/StudentManagementSystem/mydb.db");
        if(!mydb.open()){
            qDebug()<<("Failed to Connect database!");
            return false;
        }else{
            qDebug()<<("Connected database........");
            return true;
        }
    }

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_userLogin_clicked();
    void on_pushButton_adminLogin_clicked();
    void on_pushButton_adminRegister_clicked();
    void myfunction();
    void on_pushButton_loginEXIT_clicked();
    void on_pushButton_user_Register_clicked();

private:
    Ui::Login *ui;
    UserDialog1 *userP1;
    AdminDialog1 *adminP1;
    QTimer * timer;
};
#endif // LOGIN_H
