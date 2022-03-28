#ifndef REGISTER_H
#define REGISTER_H
#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQuery>
#include <QObject>

class Register : public QObject{

    Q_OBJECT

private:
    QString firstName;
    QString lastName;
    QString username;
    QString password;

    int workCode;

public:
    Register(QString firstName,QString lastName,QString username,QString password);


    QString getFirstName();
    QString getLastName();
    QString getUsername();
    QString getPassword();


    void setFirstName(QString firstName);
    void setLastName(QString lastName);
    void stUsername(QString username);
    void setPassword(QString password);


    bool isUser(QString username,QString password);


    bool isAdmin(QString username,QString password,int workCode);



};

#endif // REGISTER_H

