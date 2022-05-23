#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "converter.h"

#include <map>



enum NumberSystem
{
    HEX,
    DEC,
    OCT,
    BIN,
};

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
    void on_num7_btn_clicked();

    void on_num8_btn_clicked();

    void on_num9_btn_clicked();

    void on_num4_btn_clicked();

    void on_num5_btn_clicked();

    void on_num6_btn_clicked();

    void on_num1_btn_clicked();

    void on_num2_btn_clicked();

    void on_num3_btn_clicked();

    void on_convertFromGroupBox_activated(int index);

    void on_convertToGroupBox_activated(int index);

    void on_convert_btn_clicked();


    void on_numA_btn_clicked();

    void on_numB_btn_clicked();

    void on_numC_btn_clicked();

    void on_numD_btn_clicked();

    void on_numE_btn_clicked();

    void on_numF_btn_clicked();

    void on_num0_btn_clicked();

    void on_pushButton_clicked();

public:
    void setAllActive();

private:
    Ui::MainWindow *ui;
    Converter* converter;
};
#endif // MAINWINDOW_H
