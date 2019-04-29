#include "SortingStation.h"

SortingStation::SortingStation(QWidget *parent)
	: QMainWindow(parent)
{
	ui->setupUi(this);
	pCalc = new Calculator();
	connect(ui->SolveButton, &QPushButton::clicked, this, &SortingStation::calculateSlot);
}

SortingStation::~SortingStation()
{
	delete pCalc;
}

void SortingStation::calculateSlot()
{
	QString text = ui->inputText->toPlainText();
	int result = 1337;
	ui->outputText->setPlainText(text.setNum(result));
}


