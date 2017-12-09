#ifndef PHONEBOOKVIEW_H
#define PHONEBOOKVIEW_H

#include <QWidget>

namespace Ui {
class PhoneBookView;
}

class PhoneBookView : public QWidget
{
    Q_OBJECT

public:
    explicit PhoneBookView(QWidget *parent = 0);
    ~PhoneBookView();
signals:
    void send_user_data(QString name, QString phone_number);


public slots:
    void database_updated();

private:
    Ui::PhoneBookView *ui;

private slots:
    void on_save_clicked();
};

#endif // PHONEBOOKVIEW_H
