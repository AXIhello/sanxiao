#include "GameWidget.h"
#include <QMouseEvent>
#include <QDebug>
#include <QTimer>
GameWidget::GameWidget(QWidget* parent)
	: QWidget(parent)
{
	setFixedSize(600, 650);
	map_ = new Map(this);
}

GameWidget::~GameWidget()
{

}

void GameWidget::setName(const QString& name)
{
	_userName = name;
}

void GameWidget::reset()
{
	map_->initMap();

	//update();
}

void GameWidget::mousePressEvent(QMouseEvent* event)
{
	int j = event->pos().rx() / Block_Width, i = (event->pos().ry() - 50) / Block_Width;
	if (map_->indexIsValid(i, j))
	{
		if (clickIndex_.flag_ == true)
		{
			int prei = clickIndex_.i;
			int prej = clickIndex_.j;
			if (map_->isValid(prei, prej, i, j))
			{
				auto animation = map_->swapWithAnimation(prei, prej, i, j, true);
				animation->start();
				connect(animation, &QAbstractAnimation::finished, this, [=]() {
					QTimer::singleShot(300, this, [=]() {
						emit sig_score(map_->runClear());
						});
					});
			}
			else
			{
				map_->swapParalleAnimation(prei, prej, i, j, true)->start();
			}
			clickIndex_ = ClickIndex();
		}
		else
		{
			clickIndex_.flag_ = true;
			clickIndex_.i = i;
			clickIndex_.j = j;
		}
	}
}
