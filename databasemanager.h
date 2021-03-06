#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QObject>

class DataBaseManager: public QObject{
Q_OBJECT
public:
    DataBaseManager();
    QSqlDatabase database_interface;
    void select_from_table();
public slots:
    void data_received(QString command, QString last_name, QString last_phone_number, QString name, QString phone_number);
signals:
    void database_updated();
    void select_result(QString name , QString phone_number);

};

#endif // DATABASEMANAGER_H
