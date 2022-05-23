#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <map>

std::map<int, int> enumNumberSystemWithBnts = {{HEX, 16}, {OCT, 8}, {BIN, 2}, {DEC, 10}};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->converter = new Converter();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete converter;
}



void MainWindow::on_num7_btn_clicked()
{
    *(this->converter) += QString("7");
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_num8_btn_clicked()
{
    *(this->converter) += QString("8");
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_num9_btn_clicked()
{
    *(this->converter) += QString("9");
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_num4_btn_clicked()
{
    *(this->converter) += QString("4");
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_num5_btn_clicked()
{
    *(this->converter) += QString("5");
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_num6_btn_clicked()
{
    *(this->converter) += QString("6");
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_num1_btn_clicked()
{
    *(this->converter) += QString("1");
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_num2_btn_clicked()
{
    *(this->converter) += QString("2");
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_num3_btn_clicked()
{
    *(this->converter) += QString("3");
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_convertFromGroupBox_activated(int index)
{
    this->setAllActive();
    this->converter->clear();
    this->converter->setOriginNumberSystem(enumNumberSystemWithBnts[index]);
    switch (index) {
    case HEX:
        break;
    case DEC:
        this->ui->numA_btn->setDisabled(true);
        this->ui->numB_btn->setDisabled(true);
        this->ui->numC_btn->setDisabled(true);
        this->ui->numD_btn->setDisabled(true);
        this->ui->numE_btn->setDisabled(true);
        this->ui->numF_btn->setDisabled(true);
        break;
    case OCT:
        this->ui->numA_btn->setDisabled(true);
        this->ui->numB_btn->setDisabled(true);
        this->ui->numC_btn->setDisabled(true);
        this->ui->numD_btn->setDisabled(true);
        this->ui->numE_btn->setDisabled(true);
        this->ui->numF_btn->setDisabled(true);
        this->ui->num8_btn->setDisabled(true);
        this->ui->num9_btn->setDisabled(true);
        break;

    case BIN:
        this->ui->numA_btn->setDisabled(true);
        this->ui->numB_btn->setDisabled(true);
        this->ui->numC_btn->setDisabled(true);
        this->ui->numD_btn->setDisabled(true);
        this->ui->numE_btn->setDisabled(true);
        this->ui->numF_btn->setDisabled(true);
        this->ui->num2_btn->setDisabled(true);
        this->ui->num3_btn->setDisabled(true);
        this->ui->num4_btn->setDisabled(true);
        this->ui->num5_btn->setDisabled(true);
        this->ui->num6_btn->setDisabled(true);
        this->ui->num7_btn->setDisabled(true);
        this->ui->num8_btn->setDisabled(true);
        this->ui->num9_btn->setDisabled(true);
        break;
    }
    this->ui->textEditDisplay->setText(this->converter->getData());

    qDebug() << this->converter->getOriginNumberSystem();
}

void MainWindow::setAllActive()
{
    this->ui->num0_btn->setEnabled(true);
    this->ui->num1_btn->setEnabled(true);
    this->ui->num2_btn->setEnabled(true);
    this->ui->num3_btn->setEnabled(true);
    this->ui->num4_btn->setEnabled(true);
    this->ui->num5_btn->setEnabled(true);
    this->ui->num6_btn->setEnabled(true);
    this->ui->num7_btn->setEnabled(true);
    this->ui->num8_btn->setEnabled(true);
    this->ui->num9_btn->setEnabled(true);
    this->ui->numA_btn->setEnabled(true);
    this->ui->numB_btn->setEnabled(true);
    this->ui->numC_btn->setEnabled(true);
    this->ui->numD_btn->setEnabled(true);
    this->ui->numE_btn->setEnabled(true);
    this->ui->numF_btn->setEnabled(true);

}


void MainWindow::on_convertToGroupBox_activated(int index)
{
    this->converter->setDerivNumberSystem(enumNumberSystemWithBnts[index]);

    qDebug() << this->converter->getDerivNumberSystem();
}


void MainWindow::on_convert_btn_clicked()
{
    this->converter->operator()();
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_numA_btn_clicked()
{
    *(this->converter) += QString("A");
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_numB_btn_clicked()
{
    *(this->converter) += QString("B");
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_numC_btn_clicked()
{
    *(this->converter) += QString("C");
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_numD_btn_clicked()
{
    *(this->converter) += QString("D");
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_numE_btn_clicked()
{
    *(this->converter) += QString("E");
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_numF_btn_clicked()
{
    *(this->converter) += QString("F");
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_num0_btn_clicked()
{
    *(this->converter) += QString("0");
    this->ui->textEditDisplay->setText(this->converter->getData());
}


void MainWindow::on_pushButton_clicked()
{
    this->converter->clear();
    this->ui->textEditDisplay->setText(this->converter->getData());
}

