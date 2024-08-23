#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadRecords();

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &MainWindow::on_searchTextChanged);
}

MainWindow::~MainWindow()
{
    saveRecords();
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    QString type = ui->typeLineEdit->text().trimmed();
    QString name = ui->nameLineEdit->text().trimmed();
    QString author = ui->authorLineEdit->text().trimmed();
    QString address = ui->addressLineEdit->text().trimmed();
    QString dateOfCreation = ui->dateLineEdit->text().trimmed();

    if (type.isEmpty() || name.isEmpty() || author.isEmpty() || address.isEmpty() || dateOfCreation.isEmpty()) {
        return;
    }

    QString info = QString("Type: %1\nName: %2\nAuthor: %3\nAddress: %4\nDate: %5")
                       .arg(type)
                       .arg(name)
                       .arg(author)
                       .arg(address)
                       .arg(dateOfCreation);

    ui->listWidget->addItem(info);
    ui->typeLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->authorLineEdit->clear();
    ui->addressLineEdit->clear();
    ui->dateLineEdit->clear();

    saveRecords();
}

void MainWindow::on_deleteButton_clicked()
{
    QListWidgetItem* selectedItem = ui->listWidget->currentItem();

    if (selectedItem) {
        delete selectedItem;

        saveRecords();
    } else {
        QMessageBox::warning(this, "Selection Error", "No item selected.");
    }
}

void MainWindow::on_searchTextChanged(const QString &text)
{
    filterList(text);
}

void MainWindow::filterList(const QString &text)
{
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem* item = ui->listWidget->item(i);
        if (item->text().contains(text, Qt::CaseInsensitive)) {
            item->setHidden(false);
        } else {
            item->setHidden(true);
        }
    }
}


void MainWindow::saveRecords()
{
    QFile file("records.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);

        for (int i = 0; i < ui->listWidget->count(); ++i) {
            QString itemText = ui->listWidget->item(i)->text().trimmed();
            if (!itemText.isEmpty()) {
                out << itemText << "\n";
            }
        }
        file.close();
    }
}

void MainWindow::loadRecords()
{
    QFile file("records.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);

        ui->listWidget->clear();

        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (!line.isEmpty()) {
                ui->listWidget->addItem(line);
            }
        }
        file.close();
    }
}
