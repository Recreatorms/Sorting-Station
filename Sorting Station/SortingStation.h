#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SortingStation.h"
#include "Structure.h"
#include "Calculator.h"
#include <QTextEdit>

class SortingStation : public QMainWindow
{
	Q_OBJECT

public:
	SortingStation(QWidget *parent = Q_NULLPTR);
	~SortingStation();
private slots:
	void calculateSlot();
private:
	Ui::SortingStationClass* ui;
	Calculator* pCalc;
};
