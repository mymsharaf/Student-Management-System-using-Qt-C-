#pragma once
#ifndef USER_H
#define USER_H
#include <iostream>
#include <QString>
using namespace std;

class User{
private:

public:
    QString username,password,studentid,firstName,lastName,age,courses,gender,date,province;

    // constructors
    User();
    User(QString un, QString pw);
    User(QString un, QString pw, QString studentid, QString fn, QString ln, QString age, QString cour, QString gender, QString date, QString province);


    // ******* Mutators
    void setUsername(QString un);
    void setPassword(QString pw);
    void setStudentid(QString studentid);
    void setFirstName(QString fn);
    void setLastName(QString ln);
    void setAge(QString age);
    void setCourses(QString cour);
    void setGender(QString gender);
    void setDate(QString date);
    void setProvince(QString province);

    // ********* Accessors
    QString getUsername();
    QString getPassword();
    QString getStudentid();
    QString getFirstName();
    QString getLastName();
    QString getAge();
    QString getCourses();
    QString getGender();
    QString getDate();
    QString getProvince();

};
































#endif // USER_H
