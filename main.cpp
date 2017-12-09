#include <iostream>
#include <QApplication>
#include <phonebookcontroller.h>

using namespace std;

int main(int argc,char **argv)
{
    QApplication* app = new QApplication(argc, argv);
    phoneBookController* phonebook_controller = new phoneBookController();

    return app->exec();
}

