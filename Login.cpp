#include "Login.h"
#include "ui_Login.h"
#include "UserDialog1.h"
#include <QMessageBox>
#include "userMain.h"
#include "user.h"
#include "user.cpp"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QException>
#include <QDateTime>

Login::Login(QWidget *parent): QMainWindow(parent), ui(new Ui::Login){  
    ui->setupUi(this);
    if(!connOpen()){
        ui->label->setText("Failed to Connected database");
        qDebug()<<"The database Not connected ";
    }else{
        ui->label->setText("database Connected ......");
        qDebug()<<"The database connected ";
    }

    // for timer............

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
    timer->start(1000);

}

Login::~Login(){
    delete ui;
}

void Login::on_pushButton_adminRegister_clicked(){   
    Login conn;
    QString adminUsername, adminPassword, adminCode;

    adminUsername = ui->lineEdit_adminUsername->text();
    adminPassword = ui->lineEdit_adminPW->text();
    adminCode = ui->lineEdit_adminCode->text();

    if(!connOpen()){
        qDebug() <<"Failed to Connected database";
        return;
    }
    connOpen();
    QSqlQuery qry;
    qry.prepare("insert into admin (adminName,adminPassword,adminCode) values ('"+adminUsername+"','"+adminPassword+"','"+adminCode+"')" );

    qDebug()<<qry.executedQuery();
    if(qry.exec()) {
        QMessageBox::information(this,tr("Save"),tr("Admin Data Saved!"));
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}


void Login::on_pushButton_adminLogin_clicked(){  
    int count = 0;

    try {
        QString adminUsername = ui ->lineEdit_adminUsername->text();
        QString adminPassword = ui->lineEdit_adminPW->text();
        QString adminCode = ui->lineEdit_adminCode->text();
        connOpen();
        QSqlQuery qry;
        qry.prepare("select* from admin where adminName='"+adminUsername + "'and adminPassword = '"+adminPassword+"'and adminCode = '"+adminCode+"'");

        if(qry.exec()) {
            while(qry.next()){
                count++;
            }

            qDebug() << count;
            if(count==1){
                connClose();
                this->hide();
                adminP1 = new AdminDialog1(this);
                adminP1->show();
            }else{
                throw("Error");
            }
        }
    }
    catch (...) {
        ui->label ->setText("Admin Name or password or work code is NOT correct.");
        qDebug() << "Catch Error： adimin Name or password or work code is NOT correct. ";
    }

}


void Login::on_pushButton_userLogin_clicked(){  
    int count = 0;

    try {
        QString userUsername = ui ->lineEdit_userUsername->text();
        QString userPassword = ui->lineEdit_userPW->text();
        connOpen();
        QSqlQuery qry;
        qry.prepare("select* from StudentInfo where username='"+userUsername+ "' and password = '"+userPassword+"'" );

        if(qry.exec()) {
            while(qry.next()){
                count++;
            }
            qDebug() << count;
            if(count==1){
                ui->label ->setText("Student Name and password is correct.");
                connClose();
                this->hide();
                userP1 = new UserDialog1(this);
                userP1->user_name = userUsername;
                userP1->pw = userPassword;

                qDebug() << userP1->user_name + " has logged in";
                userP1->show();
            }
            else if (count == 0) {
                throw("Error");
            }
        }
    }
    catch (...) {
        ui->label ->setText("Student Name or password is NOT correct.");
        qDebug() << "Catch Error： StudentName or password is NOT correct. ";
    }
}


void Login::myfunction()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    if((time.second() %2)==0){
        time_text[3] = ' ';
        time_text[8] = ' ';
    }
    ui->label_date_time->setText(time_text);
}

void Login::on_pushButton_loginEXIT_clicked()
{

    QMessageBox::StandardButton reply = QMessageBox::question(this,"EXIT MESSAGE","Are you sure to Exit this page? ", QMessageBox::Yes| QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }else{
        qDebug() << "Answer 'NO' Button is clicked";
    }
}


void Login::on_pushButton_user_Register_clicked()
{
    Login conn;
    User curUser;
    curUser.username = ui->lineEdit_userUsername->text();
    curUser.password = ui->lineEdit_userPW->text();

    if(!connOpen()){
        qDebug() <<"Failed to connect database";
        return;
    }
    connOpen();
    QSqlQuery qry;
    qry.prepare("insert into StudentInfo (username,password) values ('"+curUser.username+"','"+curUser.password+"')" );
    qDebug()<<qry.executedQuery();

    if(qry.exec()) {
        QMessageBox::information(this,tr("Save"),tr("User Data Saved!"));
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}

