#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QObject>

class DataBaseManager: public QObject{
Q_OBJECT
public:
    DataBaseManager();
    QSqlDatabase* database_interface;
public slots:
    void data_received(QString name, QString phone_number);
signals:
    void database_updated();

};

#endif // DATABASEMANAGER_H
