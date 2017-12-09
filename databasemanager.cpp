#include "databasemanager.h"
#include <QDebug>

DataBaseManager::DataBaseManager()
{
    database_interface = new QSqlDatabase();
}


void DataBaseManager::data_received(QString name, QString phone_number){
    qDebug() << "name = " << name << "  phone number= " << phone_number;
}
