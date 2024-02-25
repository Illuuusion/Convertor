#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    param = (AppParams*) malloc(sizeof(AppParams));
    param->numberValue = 0;
    param->system1Value = 2;
    param->system2Value = 2;
    doOperation(Default, &context, param);
    connect(ui->number, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::onSpinBoxValueChanged);
    connect(ui->startNumberSystem, &QComboBox::currentTextChanged, this, &MainWindow::onStartNumberSystemCurrentTextChanged);
    connect(ui->finalNumberSystem, &QComboBox::currentTextChanged, this, &MainWindow::onFinalNumberSystemCurrentTextChanged);
    connect(ui->convertButton, &QPushButton::clicked, this, &MainWindow::onConvertButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    free(param);
}

void MainWindow::onConvertButtonClicked()
{
    doOperation(Convert, &context, nullptr);
    ui->convertedNumber->setText(context.result);
}

void MainWindow::onStartNumberSystemCurrentTextChanged()
{
    param->system1Value = ui->startNumberSystem->currentText().toInt();
    doOperation(UpdateCurrentNumberSystem, &context, param);
}

void MainWindow::onFinalNumberSystemCurrentTextChanged()
{
    param->system2Value = ui->finalNumberSystem->currentText().toInt();
    doOperation(UpdateNewNumberSystem, &context, param);
}

void MainWindow::onSpinBoxValueChanged()
{
    param->numberValue = ui->number->value();
    doOperation(UpdateNumber, &context, param);
}
