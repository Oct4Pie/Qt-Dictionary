#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    keys = new BST<string>();
    values = new BST<string>();
    QFile file(":/dict");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error: " << file.errorString();
    }
    QTextStream inf(&file);
    QString line = inf.readLine();

    while (!line.isNull()) {
        string sa = line.toStdString();
        // TODO split using QLatin1Char
        stringstream sas(sa);
        string key, val;
        sas >> key;
        while (!sas.eof()) {
            sas >> sa;
            val += sa;
        }
        Node<string>* n = values->add(val);
        Node<string>* k = keys->add(key, n);
        if (k && n) {
            n->dict = k;
        }

        line = inf.readLine();
    }
    model = new QStandardItemModel(keys->count + 1, 1, this);
    model->setHeaderData(0, Qt::Vertical, tr("Words"));
    Node<string>** n = keys->nodes();
     // TODO check tree's time complexity & size
    for (int i = 0; i < keys->count; i++) {
        model->setData(model->index(i, 0, QModelIndex()),
                       n[i]->value.c_str());
    }
    model->setProperty("lang", "en");

    ui->listView->setModel(model);
    ui->pushButton->setIcon(QIcon(":/swap-icon"));
    ui->label->setPixmap(QPixmap(":/magnify"));
    //    ui->retranslateUi(Thesaurus);
    // TODO add navigation for other screens
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_listView_activated(const QModelIndex& index) {
    Node<string>* n = *(keys->a + index.row());
    ui->textEdit->setHtml(n->dict->value.c_str());
}

void MainWindow::on_listView_clicked(const QModelIndex& index) {
    Node<string>* n = *(keys->a + index.row());
    ui->textEdit->setHtml(n->dict->value.c_str());
}

void MainWindow::on_pushButton_clicked() {
    QString tmp = ui->lineEdit_2->text();
    ui->lineEdit_2->setText(ui->lineEdit->text());
    ui->lineEdit->setText(tmp);
    Node<string>** n = model->property("lang") == "zh" ? keys->nodes() : values->nodes();
    for (int i = 0; i < values->count; i++) {
        model->setData(model->index(i, 0, QModelIndex()),
                       n[i]->value.c_str());
    }
    model->setProperty("lang", model->property("lang") == "zh" ? "en" : "zh");
}
