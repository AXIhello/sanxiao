#pragma once

#include <QWidget>
#include "ui_GamePanelWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GamePanelWidgetClass; };
QT_END_NAMESPACE

class QTimer;
class GamePanelWidget : public QWidget
{
public:
	GamePanelWidget(QWidget* parent = nullptr);
	~GamePanelWidget();

	void newGame();//新游戏
	void pauseGame();
	void saveGame();
	void rankGame();

private:
	Ui::GamePanelWidgetClass* ui;
	QString _userName;
	int _score{ 0 };
	QTimer* timer;
	int _lastMinutes;
	int _lastSeconds;
	bool _isRunning{ false };
	QMap<QString, int> _scoreMap;
};
