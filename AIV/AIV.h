#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AIV.h"

class AIV : public QMainWindow
{
	Q_OBJECT

public:
	AIV(QWidget *parent = Q_NULLPTR);

private:
	Ui::AIVClass ui;
};
