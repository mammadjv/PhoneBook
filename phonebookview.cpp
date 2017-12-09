#include "phonebookview.h"
#include "ui_phonebookview.h"
#include <QHeaderView>
#include <QString>
#include <QDebug>



PhoneBookView::PhoneBookView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PhoneBookView)
{
    ui->setupUi(this);
    QHeaderView* header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    this->show();
}

PhoneBookView::~PhoneBookView()
{
    delete ui;
}

void PhoneBookView::on_save_clicked(){
    QString name = ui->name->text();
    QString phone_number = ui->phone_number->text();
    emit send_user_data(name,phone_number);
    qDebug() << "shit!";
}

void PhoneBookView::database_updated(){
    qDebug() << "database updated!";
}
