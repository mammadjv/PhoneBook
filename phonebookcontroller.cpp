#include "phonebookcontroller.h"

phoneBookController::phoneBookController()
{
    database_manager = new DataBaseManager();
    phonebook_view = new PhoneBookView();
    connect(database_manager,SIGNAL(database_updated()),phonebook_view,SLOT(database_updated()));
    connect(phonebook_view,SIGNAL(send_user_data(QString,QString)),database_manager,SLOT(data_received(QString,QString)));
}