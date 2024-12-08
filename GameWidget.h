#pragma once

#include <QtWidgets/QMainWindow>
#include "GameWidget.h"
#include "Map.h"



struct ClickIndex
{
	bool flag_{ false };
	int i{ -1 }, j{ -1 };
};

class GameWidget : public QWidget
{
	Q_OBJECT

public:
	GameWidget(QWidget* parent = nullptr);
	~GameWidget();
	void setName(const QString& name);
	void reset();

signals:
	void sig_score(int);

protected:
	void mousePressEvent(QMouseEvent* event);


private:
	QString _userName{ "root" };
	Map* map_;
	ClickIndex clickIndex_;

};
