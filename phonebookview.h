#ifndef PHONEBOOKVIEW_H
#define PHONEBOOKVIEW_H

#include <QWidget>
#include <QTableWidgetItem>

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
    void send_user_data(QString command,QString last_name, QString last_phone_number, QString name, QString phone_number);


public slots:
    void database_updated();

private:
    Ui::PhoneBookView *ui;
    QString current_name;
    QString current_phone_number;
    int selected_row, selected_column;
    bool update_mode;

private slots:
    void on_save_clicked();
    void on_update_clicked();
    void item_clicked(QTableWidgetItem*);
};

#endif // PHONEBOOKVIEW_H
