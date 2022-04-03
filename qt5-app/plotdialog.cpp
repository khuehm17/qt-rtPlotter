#include "plotdialog.h"
#include "ui_plotdialog.h"

#define NUM_PTS_TIME_PLOT        (256)

plotDialog::plotDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::plotDialog)
{
    ui->setupUi(this);

    QPen myPen;
    myPen.setWidth(1);    // Width greater than 1 considerably slows down the application
    myPen.setColor(Qt::blue);

    ui->customPlot->addGraph(0);
    ui->customPlot->setBackground(this->palette().window().color());
    ui->customPlot->axisRect()->setBackground(this->palette().window().color());
    ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->xAxis->setRange(0, NUM_PTS_TIME_PLOT);
    ui->customPlot->graph(0)->setPen(myPen);

    makePlot();
}

plotDialog::~plotDialog()
{
    delete ui;
}

void plotDialog::SetData(const QVector<double> &x, const QVector<double> &y)
{
    ui->customPlot->graph(0)->setData(x, y);
}
void plotDialog::makePlot()
{
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i];  // let's plot a quadratic function
    }
    // create graph and assign data to it:
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(-1, 1);
    ui->customPlot->yAxis->setRange(0, 1);
//    ui->customPlot->yAxis->setRange(0, NUM_PTS_TIME_PLOT);
//    ui->customPlot->xAxis->setRange(0, NUM_PTS_TIME_PLOT);
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->yAxis->rescale();
    ui->customPlot->replot();
}
