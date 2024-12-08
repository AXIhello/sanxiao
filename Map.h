#pragma once
#include "Define.h"
#include <QLabel>
#include <QVector>
#include <QLabel>
#include <QRandomGenerator>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>

//每个方块的数据 由qlabel和tab组成
//
class Block
{
public:
	BlockType type_{ Blank };
	QLabel* label_{ nullptr };//ui
	//随机生成初始布局
	Block(bool useRandom, QWidget* parent = nullptr) {
		initBlock(useRandom, parent);//随机生成图片
	};

	//构造函数调用
	void initBlock(bool useRandom, QWidget* parent = nullptr) {
		label_ = new QLabel(parent);
		if (useRandom)
		{
			int randomNum = QRandomGenerator::global()->bounded(BlockType::A, BlockType::F + 1); // 生成x到y的随机数字（包括y）
			type_ = (BlockType)randomNum;
		}
		QPixmap pix;
		pix.load(QString(":imgs/%1.png").arg(type_));//加载图片 qrc资源定义
		label_->setScaledContents(true);
		label_->setPixmap(pix);
		label_->resize(Block_Width, Block_Width);
	}
	//设定图片为不同的宝石
	void setType(BlockType type)
	{
		QPixmap pix;
		pix.load(QString(":imgs/%1.png").arg(type));
		label_->setScaledContents(true);
		label_->setPixmap(pix);
		label_->resize(Block_Width, Block_Width);
		type_ = Blank;
	}

	//消除之后把图片设为空
	void clear()
	{
		setType(Blank);
	}

	~Block()
	{
		if (label_)
		{
			//label_->deleteLater();
			delete label_;
		}
		label_ = nullptr;
	}
};

//处理
class Map :public QObject//继承QObject 动画发出信号 map接收信号
{

	Q_OBJECT
private:

	QVector<QVector<Block*>> maps_;//
	QWidget* widget_;//对应GPW


public:

	Map(QWidget* widget);


	void swap(int x1, int y1, int x2, int y2, bool changepo);


	QAbstractAnimation* swapWithAnimation(int x1, int y1, int x2, int y2, bool isDouble);


	QParallelAnimationGroup* swapParalleAnimation(int x1, int y1, int x2, int y2, bool back = false);


	QPropertyAnimation* swapSingaleAnimation(int x1, int y1, int x2, int y2, bool back = false);


	bool isValid(int x1, int y1, int x2, int y2);


	bool isNeighbor(int x1, int y1, int x2, int y2);


	QVector<QPair<int, int>> canClear();



	bool indexIsValid(int x, int y);



	QAbstractAnimation* refillAnimation();

	bool refillData(bool changepos = true);

	void initMap();

	int runClear();
};

