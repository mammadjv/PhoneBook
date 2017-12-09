#ifndef PHONEBOOKCONTROLLER_H
#define PHONEBOOKCONTROLLER_H

#include <databasemanager.h>
#include <phonebookview.h>
#include <QObject>

class phoneBookController : public QObject
{
//Q_OBJECT
public:
    phoneBookController();
    DataBaseManager* database_manager;
    PhoneBookView* phonebook_view;

};

#endif // PHONEBOOKCONTROLLER_H
