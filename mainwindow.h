#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <sqlite3.h>
#include <QMainWindow>
#include <QStandardItemModel>
#include <QStringListModel>
#include "search.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

   private slots:
    void on_listView_activated(const QModelIndex& index);

    void on_listView_clicked(const QModelIndex& index);

    void on_pushButton_clicked();

   private:
    Ui::MainWindow* ui;
    QStandardItemModel* model;
    QAbstractListModel* m;
    BST<string>* keys;
    BST<string>* values;
};
#endif  // MAINWINDOW_H
