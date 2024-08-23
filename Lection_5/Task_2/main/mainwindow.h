#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_searchTextChanged(const QString &text);

private:
    Ui::MainWindow *ui;
    void saveRecords();
    void loadRecords();
    void displayRecording(const QString &info);
    void filterList(const QString &text);
};

#endif
