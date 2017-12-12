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
//      QSqlQuery qry;
//      qry.prepare( "CREATE TABLE names (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30))" );
//      qry.exec();
//      qry.exec();
//        qry.prepare("insert into names values(10,\"mammad\",\"javadi\")");
//      qry.prepare("select * from names");
//      qry.prepare( "CREATE TABLE data (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30))" );
//       qry.prepare("USE users; SELECT COUNT(name) FROM sys.Tables");
    return;
      QSqlRecord rec = qry.record();
      int cols = rec.count();
      QString temp;
      while( qry.next() )
          {
            temp = "";
            for( int c=0; c<cols; c++ )
              temp += qry.value(c).toString() + ((c<cols-1)?"\t":"");
            qDebug() << temp;
          }

      if( !qry.exec() )
        qDebug() << "qry.lastError()";
      else
        qDebug() << "Table created!";

}


void DataBaseManager::data_received(QString name, QString phone_number){
    qDebug() << "name = " << name << "  phone number= " << phone_number;
}
