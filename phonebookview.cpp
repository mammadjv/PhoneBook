#include "phonebookview.h"
#include "ui_phonebookview.h"
#include <QHeaderView>
#include <QString>
#include <QDebug>
#include <stdlib.h>


PhoneBookView::PhoneBookView(QWidget *parent) : QWidget(parent),
    ui(new Ui::PhoneBookView){
    ui->setupUi(this);

    update_mode = false;
    QHeaderView* header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->show();
    connect(ui->tableWidget,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(item_clicked(QTableWidgetItem*)));
}

PhoneBookView::~PhoneBookView()
{
    delete ui;
}

void PhoneBookView::select_query_result(QString name, QString phone_number){
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    QTableWidgetItem* name_item = new QTableWidgetItem(name);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,name_item);
    QTableWidgetItem* phone_number_item = new QTableWidgetItem(phone_number);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,phone_number_item);
}

void PhoneBookView::item_clicked(QTableWidgetItem *item){
    if(update_mode == false){
        return;
    }
    selected_row = item->row();
    this->current_name = ui->tableWidget->item(selected_row, 0)->text();
    this->current_phone_number = ui->tableWidget->item(selected_row, 1)->text();
    ui->name->setText(this->current_name);
    ui->phone_number->setText(this->current_phone_number);
}

void PhoneBookView::on_save_clicked(){

    QString name = ui->name->text();
    QString phone_number = ui->phone_number->text();

    // send to database
    if (update_mode == true) {
        ui->tableWidget->item(this->selected_row,0)->setText(name);
        ui->tableWidget->item(this->selected_row,1)->setText(phone_number);
        ui->name->setText("");
        ui->phone_number->setText("");
        update_mode = false;
        emit send_user_data("update", this->current_name, this->current_phone_number, name, phone_number);
        return;
    }
    // change the gui
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    QTableWidgetItem* name_item = new QTableWidgetItem(name);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,name_item);
    QTableWidgetItem* phone_number_item = new QTableWidgetItem(phone_number);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,phone_number_item);
    ui->name->setText("");
    ui->phone_number->setText("");
    emit send_user_data("insert", "", "", name, phone_number);
}


void PhoneBookView::on_update_clicked(){
    update_mode = true;
}

void PhoneBookView::on_cancel_clicked(){
    std::exit(0);
}


void PhoneBookView::database_updated(){
    qDebug() << "database updated!";
}
