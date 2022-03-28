#include <QDialog>
#include "ui_UserDialog1.h"
#include "UserDialog1.h"
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
#include "Login.h"
#include "user.h"

UserDialog1::UserDialog1(QWidget *parent) : QDialog(parent),ui(new Ui::UserDialog1){
    ui->setupUi(this);

    Login conn;
    if(!conn.connOpen()){
        ui->label_userP1->setText("Failed to Connect database!");
        qDebug()<<"The database Not connected with UserDialog1 page.";
    }else{
        ui->label_userP1->setText("Connected database........");
        qDebug()<<"The database connected with UsserDialog1 page.";
    }
}
QString age;
QString courses;
QString gender;
QString date;
QString prov;

UserDialog1::~UserDialog1(){
    delete ui;
}


void UserDialog1::on_pushButton_userNextPage_clicked(){
    Login conn;
    User user;
    user.username = user_name;
    user.password = pw;
    user.studentid = ui->lineEdit_studentid->text();
    user.firstName = ui->lineEdit_fName->text();
    user.lastName = ui->lineEdit_lName->text();
    user.age = age;
    user.courses = courses;
    user.gender = gender;
    user.date = ui->dateEdit->text();
    user.province = prov;

    if(!conn.connOpen()){
        qDebug() <<"Failed to connect database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;

    qry.prepare("update StudentInfo set username='"+user.username+"',password='"+user.password+"',studentid='"+user.studentid+"',firstName='"+user.firstName+"',lastName='"+user.lastName+"'"
             ",age='"+user.age+"',courses='"+user.courses+"',gender='"+user.gender+"',date='"+user.date+"',province='"+user.province+"' where username='"+user.username+"'");

    qDebug()<<qry.executedQuery();
    if(qry.exec()) {
        QMessageBox::information(this,tr("Save"),tr("Data Saved!"));
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }

    window()->hide();

    qDebug()<< user.username + " saved infomation: ";
    qDebug()<< user.username + " , " + user.password + " , " + user.studentid + " , " + user.firstName + " , " + user.lastName +
               " , " + user.age + " , " + user.courses + " , " + user.gender + " , " + user.date + " , " + user.province;

}





// for Radio Buttom, choose age, only can choose one
void UserDialog1::on_radioButton_under18_clicked(){
    age = "Under 18";
}

void UserDialog1::on_radioButton_over18_clicked(){
    age = "Between 18~24";
}

void UserDialog1::on_radioButton_over50_clicked(){
    age = "Between 24~30";
}

void UserDialog1::on_radioButton_over65_clicked(){
    age = "Over 30";
}


// for Radio Buttom, choose Gender, Men or Women or other
void UserDialog1::on_radioButton_Men_clicked()
{
    gender = "Men";
}


void UserDialog1::on_radioButton_Women_clicked()
{
     gender = "Women";
}


void UserDialog1::on_radioButton_others_clicked()
{
     gender = "Others";
}

// for Radio Buttom, choose vaccine, user can only choose one kind of vaccine
void UserDialog1::on_radioButton_Business_clicked()
{
  courses = "Business";
}


void UserDialog1::on_radioButton_Computing_clicked()
{
    courses = "Computing";
}


void UserDialog1::on_radioButton_Engineering_clicked()
{
    courses = "Engineering";
}


void UserDialog1::on_radioButton_Science_clicked()
{
     courses = "Science";
}


void UserDialog1::on_radioButton_Postgraduate_clicked()
{
     courses = "Postgraduate studies";
}


void UserDialog1::on_comboBox_Province_activated(const QString &arg1)
{
    prov = arg1;
   //QString prov = ui->comboBox_Province->currentText();
}

