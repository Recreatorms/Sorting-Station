#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SortingStation.h"

class SortingStation : public QMainWindow
{
	Q_OBJECT

public:
	SortingStation(QWidget *parent = Q_NULLPTR);

private:
	Ui::SortingStationClass ui;
};
