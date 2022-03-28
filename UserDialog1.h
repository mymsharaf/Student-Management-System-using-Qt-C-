#ifndef USERDIALOG1_H
#define USERDIALOG1_H

#include <QDialog>


namespace Ui {
class UserDialog1;
}

class UserDialog1 : public QDialog
{
    Q_OBJECT

public:

    explicit UserDialog1(QWidget *parent = nullptr);
    ~UserDialog1();

    QString user_name;
    QString pw;

private slots:

    void on_pushButton_userNextPage_clicked();


    void on_radioButton_under18_clicked();

    void on_radioButton_over18_clicked();

    void on_radioButton_over50_clicked();

    void on_radioButton_over65_clicked();


    void on_radioButton_Men_clicked();

    void on_radioButton_Women_clicked();

    void on_radioButton_others_clicked();


    void on_radioButton_Business_clicked();

    void on_radioButton_Computing_clicked();

    void on_radioButton_Engineering_clicked();

    void on_radioButton_Science_clicked();

    void on_radioButton_Postgraduate_clicked();

    void on_comboBox_Province_activated(const QString &arg1);

private:
    Ui::UserDialog1 *ui;

};

#endif // USERDIALOG1_H
