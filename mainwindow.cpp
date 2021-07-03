#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include "dataGetter.h"
#include "harmonicdata.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->addGraph();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    const double STEP = ui->doubleSpinBox_4->value();
    const int DURATION = ui->spinBox->value();

    ui->widget->clearGraphs();
    ui->widget->addGraph();
    x.clear();

    HarmonicData* dat = dynamic_cast<HarmonicData*>(generateTestData(HARMONIC, STEP, DURATION));
    double yMax = *std::max_element(dat->phaseData->begin(), dat->phaseData->end());
    double yMin = *std::min_element(dat->phaseData->begin(), dat->phaseData->end());
    for (X = STEP; X < DURATION; X += STEP)
        x.push_back(X);
    ui->widget->yAxis->setRange(yMin, yMax);
    ui->widget->xAxis->setRange(0, DURATION);
    ui->widget->graph(0)->addData(x,*dat->phaseData);
    ui->widget->replot();



}

void MainWindow::on_radioButton_clicked() //  случайная генерация данных для hurmonic
{
    ui->radioButton_3->setEnabled(false);
    ui->radioButton_4->setEnabled(false);
    ui->doubleSpinBox->setEnabled(false);
    ui->doubleSpinBox_2->setEnabled(false);
    ui->doubleSpinBox_5->setEnabled(false);
    ui->doubleSpinBox_6->setEnabled(false);
    ui->doubleSpinBox_7->setEnabled(false);
    ui->doubleSpinBox_8->setEnabled(false);
    ui->checkBox->setEnabled(true);
}

void MainWindow::on_radioButton_2_clicked() //  заданные для hurmonic
{
    ui->radioButton_3->setEnabled(true);
    ui->radioButton_4->setEnabled(true);
    ui->doubleSpinBox->setEnabled(false);
    ui->doubleSpinBox_2->setEnabled(false);
    ui->doubleSpinBox_5->setEnabled(false);
    ui->doubleSpinBox_6->setEnabled(true);
    ui->doubleSpinBox_7->setEnabled(true);
    ui->doubleSpinBox_8->setEnabled(true);

    if (ui->radioButton_2->isChecked())
    {
        ui->checkBox->setChecked(false);
        ui->checkBox->setEnabled(false);
    }



}

void MainWindow::on_radioButton_5_clicked() //  случайная генерация данных для car
{
    ui->doubleSpinBox_9->setEnabled(false);
    ui->doubleSpinBox_10->setEnabled(false);
    ui->doubleSpinBox_11->setEnabled(false);
    ui->doubleSpinBox_12->setEnabled(false);
    ui->doubleSpinBox_13->setEnabled(false);
    ui->doubleSpinBox_14->setEnabled(false);
    ui->doubleSpinBox_15->setEnabled(false);
    ui->doubleSpinBox_3->setEnabled(false);
    ui->checkBox_2->setEnabled(true);
}


void MainWindow::on_radioButton_6_clicked() //  заданные для car
{
    ui->doubleSpinBox_9->setEnabled(false);
    ui->doubleSpinBox_10->setEnabled(true);
    ui->doubleSpinBox_11->setEnabled(false);
    ui->doubleSpinBox_12->setEnabled(true);
    ui->doubleSpinBox_13->setEnabled(false);
    ui->doubleSpinBox_14->setEnabled(true);
    ui->doubleSpinBox_15->setEnabled(false);
    ui->doubleSpinBox_3->setEnabled(true);

    if (ui->radioButton_6->isChecked())
    {
        ui->checkBox_2->setChecked(false);
        ui->checkBox_2->setEnabled(false);
    }
}

void MainWindow::on_checkBox_stateChanged(int checkState) // ограничить для hurmonic
{
    switch (checkState)
    {
    case Qt::Checked:
        ui->doubleSpinBox->setEnabled(true);
        ui->doubleSpinBox_2->setEnabled(true);
        ui->doubleSpinBox_5->setEnabled(true);
        ui->doubleSpinBox_6->setEnabled(true);
        ui->doubleSpinBox_7->setEnabled(true);
        ui->doubleSpinBox_8->setEnabled(true);
        ui->radioButton_3->setEnabled(false);
        ui->radioButton_4->setEnabled(false);
        break;
    case Qt::Unchecked:
        ui->doubleSpinBox->setEnabled(false);
        ui->doubleSpinBox_2->setEnabled(false);
        ui->doubleSpinBox_5->setEnabled(false);
        ui->doubleSpinBox_6->setEnabled(false);
        ui->doubleSpinBox_7->setEnabled(false);
        ui->doubleSpinBox_8->setEnabled(false);
        break;
    default:
        break;
    }
}

void MainWindow::on_checkBox_2_stateChanged(int checkState) // ограничить для car
{
    switch (checkState)
    {
    case Qt::Checked:
        ui->doubleSpinBox_3->setEnabled(true);
        ui->doubleSpinBox_9->setEnabled(true);
        ui->doubleSpinBox_10->setEnabled(true);
        ui->doubleSpinBox_11->setEnabled(true);
        ui->doubleSpinBox_12->setEnabled(true);
        ui->doubleSpinBox_13->setEnabled(true);
       ui->doubleSpinBox_14->setEnabled(true);
       ui->doubleSpinBox_15->setEnabled(true);
        break;
    case Qt::Unchecked:
        ui->doubleSpinBox_3->setEnabled(false);
        ui->doubleSpinBox_9->setEnabled(false);
        ui->doubleSpinBox_10->setEnabled(false);
        ui->doubleSpinBox_11->setEnabled(false);
        ui->doubleSpinBox_12->setEnabled(false);
        ui->doubleSpinBox_13->setEnabled(false);
       ui->doubleSpinBox_14->setEnabled(false);
       ui->doubleSpinBox_15->setEnabled(false);
        break;
    default:
        break;
    }
}

