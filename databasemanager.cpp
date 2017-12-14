#include "databasemanager.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>

DataBaseManager::DataBaseManager()
{
    database_interface = QSqlDatabase::addDatabase("QMYSQL");
    database_interface.setConnectOptions("UNIX_SOCKET=/Applications/MAMP/tmp/mysql/mysql.sock");
    database_interface.setDatabaseName("mysql");
    database_interface.setUserName("root");
    database_interface.setPassword("root");
    database_interface.setPort(8889);

    if(!database_interface.open()){
        qFatal( "Failed to connect." );
        return;
    }
    QSqlQuery create_query("CREATE TABLE IF NOT EXISTS users ( name varchar(255), phone varchar(255)) ",database_interface);
    QSqlQuery select_query("select * from users",database_interface);

    // read the result of select query
    while (select_query.next()) {
             QString name = select_query.value(0).toString();
             QString phone_numer = select_query.value(1).toString();
             qDebug() << name  << "   " << phone_numer;
    }
}


void DataBaseManager::data_received(QString command, QString last_name, QString last_phone_number, QString name, QString phone_number){
    if(command == "insert"){
        QString query_str = "insert into users values( \"" + name + "\" , \"" + phone_number + "\" )";
        QSqlQuery query(query_str,database_interface);
    }
    if(command == "update"){
        QString query_str = "update users set name = \"" + name + "\" , phone = \"" + phone_number + "\" where "+ "name = \"" + last_name+ "\" AND phone = \"" + last_phone_number + "\"" ;
        QSqlQuery query(query_str,database_interface);
    }
}
