#include "GamePanelWidget.h"
#include <QTimer>
#include <qdebug.h>
#include <QMessageBox>
#include <QListWidget>
//#include "MainMenuWidget.h"
GamePanelWidget::GamePanelWidget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::GamePanelWidgetClass())
{
	ui->setupUi(this);

	ui->timeNum->setDigitCount(5);
	QPalette lcdpat = ui->timeNum->palette();

	lcdpat.setColor(QPalette::Normal, QPalette::WindowText, Qt::red);//设置计时器为红色
	ui->timeNum->setSegmentStyle(QLCDNumber::Flat);
	ui->timeNum->setPalette(lcdpat);
	ui->widget->setDisabled(true);
	connect(ui->btnStart, &QPushButton::clicked, this, &GamePanelWidget::newGame);
	connect(ui->btnPause, &QPushButton::clicked, this, &GamePanelWidget::pauseGame);
	ui->widget->setDisabled(true);
	connect(ui->widget, &GameWidget::sig_score, this, [=](int v) {
		_score += v;
		ui->labelScore->setText(QString::number(_score));
		});
	connect(ui->btnSave, &QPushButton::clicked, this, &GamePanelWidget::saveGame);
	connect(ui->btnRank, &QPushButton::clicked, this, &GamePanelWidget::rankGame);


}

GamePanelWidget::~GamePanelWidget()
{
	delete ui;
}

void GamePanelWidget::newGame()
{
	ui->widget->hide();
	ui->widget->reset();
	ui->widget->show();
	ui->widget->setEnabled(true);

	_isRunning = true;
	_score = 0;
	ui->labelScore->setText(QString::number(_score));
	timer = new QTimer(this);
	_lastMinutes = 2;
	_lastSeconds = 0;
	connect(timer, &QTimer::timeout, this, [=]() {

		if (_lastMinutes == 0 && _lastSeconds == 0) {
			timer->stop();
			ui->widget->setDisabled(true);//画面变成灰色
			return;
		}
		if (_lastSeconds == 0) {
			_lastMinutes--;
			_lastSeconds = 59;
		}
		else {
			_lastSeconds--;
		}
		//计时器的文本数据
		ui->timeNum->display(QString("%1:%2").arg(_lastMinutes).arg(_lastSeconds));

		});

	timer->start(1000);
}

void GamePanelWidget::pauseGame()
{
	if (timer == nullptr)
	{
		return;
	}
	if (_isRunning)
	{
		timer->stop();
		//ui->widget->setDisabled(true);
		ui->widget->hide();
		_isRunning = false;
		ui->btnPause->setText("继续");
	}
	else
	{

		timer->start();
		//ui->widget->setDisabled(false);
		ui->widget->show();
		ui->btnPause->setText("暂停");
		_isRunning = true;

	}
}

void GamePanelWidget::saveGame()//保存成绩
{
	_userName = ui->editName->text();
	if (_userName.isEmpty())
	{
		QMessageBox::warning(NULL, "警告", "未设置用户名");
		return;
	}
	_scoreMap[_userName] = _score;//哈希Map
	_score = 0;//重置得分
	ui->labelScore->setText(QString::number(_score));
	QMessageBox::information(NULL, "提示", "保存成功");

}

void GamePanelWidget::rankGame()//成绩排名
{

	QMap<int, QString> sortedScores;
	for (auto it = _scoreMap.begin(); it != _scoreMap.end(); ++it) {
		sortedScores.insert(-it.value(), it.key());
	}

	QListWidget* listWidget = new QListWidget;
	for (auto it = sortedScores.begin(); it != sortedScores.end(); ++it) {
		QListWidgetItem* item = new QListWidgetItem(it.value() + ": " + QString::number(-it.key()), listWidget);
		listWidget->addItem(item);
	}

	listWidget->show();
}


