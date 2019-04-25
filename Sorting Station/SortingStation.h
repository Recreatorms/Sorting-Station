#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SortingStation.h"
#include "Structure.h"
#include "Calculator.h"

class SortingStation : public QMainWindow
{
	Q_OBJECT

public:
	SortingStation(QWidget *parent = Q_NULLPTR);

private:
	Ui::SortingStationClass ui;
};
