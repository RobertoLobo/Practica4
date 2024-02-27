#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Clases.h"
#include <QFileDialog>
#include <fstream>

//QLineEdit *lineEdit = new QLineEdit();
AdminNeuronas * adminNeuronas = new AdminNeuronas();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbrir_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"./",tr("Text (*.txt)"));
    QString text;
    ui->cSalida->clear();
    adminNeuronas->cargarNeuronas(fileName.toStdString());
    for (Neurona *n : adminNeuronas->dameNeuronas()){
        text.append("ID: " + std::to_string(n->getId()) + "\n");
        text.append("Voltaje: " + std::to_string(n->getVoltaje()) + "\n");
        text.append("Cord X: " + std::to_string(n->getX()) + "\n");
        text.append("Cord Y: " + std::to_string(n->getY()) + "\n");
        text.append("Red: " + std::to_string(n->getRed()) + "\n");
        text.append("Green: " + std::to_string(n->getGreen()) + "\n");
        text.append("Blue: " + std::to_string(n->getBlue()) + "\n###\n");
    }
    //n2 = adminNeuronas->dameNeurona();
    ui->cSalida->appendPlainText(text);
}


void MainWindow::on_actionGuardar_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"./untitled.png",
                                                    tr("Text (*.txt)"));
    adminNeuronas->guardarNeuronas(fileName.toStdString());
}


void MainWindow::on_btnACola_clicked()
{
    auto neurona = new Neurona();
    neurona->putId(ui->lineEdit->text().toInt());
    neurona->putVoltaje(ui->lineEdit_2->text().toFloat());
    neurona->putX(ui->lineEdit_3->text().toInt());
    neurona->putY(ui->lineEdit_4->text().toInt());
    neurona->putRed(ui->lineEdit_5->text().toInt());
    neurona->putGreen(ui->lineEdit_6->text().toInt());
    neurona->putBlue(ui->lineEdit_7->text().toInt());
    adminNeuronas->agregarCola(neurona);
}


void MainWindow::on_btnAPila_clicked()
{
    auto neurona = new Neurona();
    neurona->putId(ui->lineEdit->text().toInt());
    neurona->putVoltaje(ui->lineEdit_2->text().toFloat());
    neurona->putX(ui->lineEdit_3->text().toInt());
    neurona->putY(ui->lineEdit_4->text().toInt());
    neurona->putRed(ui->lineEdit_5->text().toInt());
    neurona->putGreen(ui->lineEdit_6->text().toInt());
    neurona->putBlue(ui->lineEdit_7->text().toInt());
    adminNeuronas->agregarPila(neurona);
}


void MainWindow::on_btnListar_clicked()
{
    QString text;
    ui->cSalida->clear();
    for (Neurona *n : adminNeuronas->dameNeuronas()){
        text.append("ID: " + std::to_string(n->getId()) + "\n");
        text.append("Voltaje: " + std::to_string(n->getVoltaje()) + "\n");
        text.append("Cord X: " + std::to_string(n->getX()) + "\n");
        text.append("Cord Y: " + std::to_string(n->getY()) + "\n");
        text.append("Red: " + std::to_string(n->getRed()) + "\n");
        text.append("Green: " + std::to_string(n->getGreen()) + "\n");
        text.append("Blue: " + std::to_string(n->getBlue()) + "\n###\n");
    }
    //n2 = adminNeuronas->dameNeurona();
    ui->cSalida->appendPlainText(text);
}

