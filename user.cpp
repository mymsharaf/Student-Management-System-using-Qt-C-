#include "user.h"
#include "Login.h"
#include <iostream>
#include <QString>
using namespace std;

// Default constructor
User::User() {
    QString username = NULL,
            password = NULL,
            studentid = NULL,
            firstName = NULL,
            lastName = NULL,
            age = NULL,
            courses = NULL,
            gender = NULL,
            date = NULL,
            province = NULL;
}


User::User(QString un, QString pw){
    this->username = un;
    this->password = pw;
    this->studentid = "0";
    this->firstName = "NULL",
            this->lastName = "NULL",
            this->age = "0",
            this->courses = "NULL",
            this->gender = "0",
            this->date = "xx-xx-xxxx",
            this->province = "NULL";
}

User::User(QString un, QString pw, QString studentid, QString fn, QString ln, QString age, QString cour, QString gender, QString date, QString province){
    this->username = un;
    this->password = pw;
    this->studentid = studentid;
    this->firstName = fn;
    this->lastName = ln;
    this->age = age;
    this->courses = cour;
    this->gender = gender;
    this->date = date;
    this->province = province;
}






