#include "databasemanager.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>

DataBaseManager::DataBaseManager()
{
    database_interface = QSqlDatabase::addDatabase("QMYSQL");
    //    database_interface.setHostName("localhost");
    database_interface.setConnectOptions("UNIX_SOCKET=/Applications/MAMP/tmp/mysql/mysql.sock");
    database_interface.setDatabaseName("users");
    database_interface.setUserName("root");
    database_interface.setPassword("root");
    database_interface.setPort(8889);
    if(!database_interface.open()){
        qFatal( "Failed to connect." );
        return;
    }

//    QSqlQuery query;
//    query.exec("CREATE TABLE Persons (PersonID int,LastName varchar(255),FirstName varchar(255),Address varchar(255),City varchar(255) );");
//    qDebug() << query.exec("select * from Persons");
//        query.exec("insert into Persons values(1,\"mammad\",\"reza\",\"yes\",\"tehran\");");
//    QString str = query.lastQuery();
//    QMapIterator<QString, QVariant> it(query.boundValues());
//     while (it.hasNext()){
//      it.next();
//      str.replace(it.key(),it.value().toString());
//     }
//     qDebug() << str;
}


void DataBaseManager::data_received(QString command, QString last_name, QString last_phone_number, QString name, QString phone_number){
    qDebug() << "name = " << name << "  phone number= " << phone_number;
}
