#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentValue(0.0)
    , waitingForOperand(true)
{
    ui->setupUi(this);

    connect(ui->PB0, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->PB1, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->PB2, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->PB3, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->PB4, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->PB5, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->PB6, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->PB7, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->PB8, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->PB9, &QPushButton::clicked, this, &MainWindow::digitClicked);

    connect(ui->plus, &QPushButton::clicked, this, &MainWindow::binaryOperatorClicked);
    connect(ui->minus, &QPushButton::clicked, this, &MainWindow::binaryOperatorClicked);
    connect(ui->multiply, &QPushButton::clicked, this, &MainWindow::binaryOperatorClicked);
    connect(ui->divide, &QPushButton::clicked, this, &MainWindow::binaryOperatorClicked);

    connect(ui->squareRoot, &QPushButton::clicked, this, &MainWindow::unaryOperatorClicked);
    connect(ui->degree, &QPushButton::clicked, this, &MainWindow::unaryOperatorClicked);

    connect(ui->equals, &QPushButton::clicked, this, &MainWindow::equalClicked);
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearClicked);
    connect(ui->delete1, &QPushButton::clicked, this, &MainWindow::deleteClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    int digitValue = clickedButton->text().toInt();

    if (ui->field->text() == "0" && digitValue == 0)
        return;

    if (waitingForOperand) {
        ui->field->clear();
        waitingForOperand = false;
    }
    ui->field->setText(ui->field->text() + QString::number(digitValue));
}

void MainWindow::binaryOperatorClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = ui->field->text().toDouble();

    if (!pendingOperator.isEmpty()) {
        currentValue = calculate(currentValue, pendingOperator);
        ui->field->setText(QString::number(currentValue));
    } else {
        currentValue = operand;
    }

    pendingOperator = clickedOperator;
    waitingForOperand = true;
}

void MainWindow::unaryOperatorClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = ui->field->text().toDouble();
    double result = 0.0;

    if (clickedOperator == "Square root") {
        if (operand < 0.0) {
            ui->field->setText("Invalid Input");
            return;
        }
        result = qSqrt(operand);
    } else if (clickedOperator == "Degree") {
        result = qPow(operand, 2);
    }

    ui->field->setText(QString::number(result));
    waitingForOperand = true;
}

void MainWindow::equalClicked()
{
    double operand = ui->field->text().toDouble();

    if (!pendingOperator.isEmpty()) {
        currentValue = calculate(currentValue, pendingOperator);
        pendingOperator.clear();
    } else {
        currentValue = operand;
    }

    ui->field->setText(QString::number(currentValue));
    waitingForOperand = true;
}

void MainWindow::clearClicked()
{
    currentValue = 0.0;
    pendingOperator.clear();
    ui->field->setText("0");
    waitingForOperand = true;
}

void MainWindow::deleteClicked()
{
    QString text = ui->field->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }
    ui->field->setText(text);
}

double MainWindow::calculate(double left, const QString &operator_) const
{
    double right = ui->field->text().toDouble();

    if (operator_ == "+")
        return left + right;
    else if (operator_ == "-")
        return left - right;
    else if (operator_ == "*")
        return left * right;
    else if (operator_ == "/") {
        if (right == 0.0) {
            return 0.0;
        }
        return left / right;
    }

    return 0.0;
}
