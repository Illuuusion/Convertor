#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "appcontext.h"
#include "entrypoint.h"

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


private:
    Ui::MainWindow *ui;
    AppContext context;
    AppParams* param;
    void onConvertButtonClicked();
    void onStartNumberSystemCurrentTextChanged();
    void onFinalNumberSystemCurrentTextChanged();
    void onSpinBoxValueChanged();
};

#endif
