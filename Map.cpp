#include "Map.h"
#include <QPropertyAnimation>
#include <QEventLoop>
#include <qlayout.h>
#include <QParallelAnimationGroup>
#include <qdebug.h>


Map::Map(QWidget* widget)
	:maps_(QVector<QVector<Block*>>(Map_Height / Block_Width, QVector<Block*>(Map_Width / Block_Width))),
	widget_(widget)
{
	initMap();
}

//图片以qlabel显示
void Map::swap(int x1, int y1, int x2, int y2, bool changepos)
{
	//把a和b的数据交换并把位置交换
	if (isNeighbor(x1, y1, x2, y2))
	{
		
		if (changepos)//从ui角度改变位置 应对代码层面的交换
		{
			auto pos1 = maps_[x1][y1]->label_->pos();
			auto pos2 = maps_[x2][y2]->label_->pos();
			maps_[x1][y1]->label_->move(pos2);
			maps_[x2][y2]->label_->move(pos1);
			//将图片的坐标进行交换
			qSwap(maps_[x1][y1], maps_[x2][y2]);
			//将图片的数据进行交换
		}
		else
		{	//只交换数据 应对用户层面的交换
			qSwap(maps_[x1][y1], maps_[x2][y2]);
		}
	}
}

//管理并行和串行动画
QAbstractAnimation* Map::swapWithAnimation(int x1, int y1, int x2, int y2, bool isDouble)
{
	QAbstractAnimation* animation;
	if (isDouble)
	{
		animation = swapParalleAnimation(x1, y1, x2, y2, false);
	}
	else
	{
		animation = swapSingaleAnimation(x1, y1, x2, y2, false);
	}
	connect(animation, &QAbstractAnimation::finished, this, [=]() {swap(x1, y1, x2, y2, false); });
	return animation;
}

//并行动画
QParallelAnimationGroup* Map::swapParalleAnimation(int x1, int y1, int x2, int y2, bool back)
{

	QParallelAnimationGroup* animationGroup = new QParallelAnimationGroup(widget_);
	auto ani1 = swapSingaleAnimation(x1, y1, x2, y2, back);
	auto ani2 = swapSingaleAnimation(x2, y2, x1, y1, back);
	animationGroup->addAnimation(ani1);//给每次操作加入动画
	animationGroup->addAnimation(ani2);
	return animationGroup;

}

//串行动画
QPropertyAnimation* Map::swapSingaleAnimation(int x1, int y1, int x2, int y2, bool back)
{
	//创建动画
	QPropertyAnimation* animation = new
		QPropertyAnimation(maps_[x1][y1]->label_, "geometry");

	animation->setDuration(50);
	if (back)//不能交换 就挪动之后再回来
	{
		animation->setStartValue(QRect(y1 * Block_Width, x1 * Block_Width + 50, Block_Width, Block_Width));
		animation->setKeyValueAt(0.5, QRect(y2 * Block_Width, x2 * Block_Width + 50, Block_Width, Block_Width));
		animation->setEndValue(QRect(y1 * Block_Width, x1 * Block_Width + 50, Block_Width, Block_Width));

	}
	else //直接挪动过去
	{
		animation->setStartValue(QRect(y1 * Block_Width, x1 * Block_Width + 50, Block_Width, Block_Width));
		animation->setEndValue(QRect(y2 * Block_Width, x2 * Block_Width + 50, Block_Width, Block_Width));
	}
	return animation;
}

//判断a和b能不能消除
bool Map::isValid(int x1, int y1, int x2, int y2)
{

	// 如果并不需要检测是否能够消除交换
	if (!isNeighbor(x1, y1, x2, y2))//只能交换邻居结点
	{
		return false;
	}
	bool ret = false;
	qSwap(maps_[x1][y1], maps_[x2][y2]);
	auto datas = canClear();
	if (datas.size() != 0) {
		ret = true;
	}
	qSwap(maps_[x1][y1], maps_[x2][y2]);
	return ret;
}

//判断是否相邻
bool Map::isNeighbor(int x1, int y1, int x2, int y2)//把坐标传入
{
	// 确保坐标在范围内
	int rows = maps_.size();
	int cols = maps_[0].size();
	if (x1 < 0 || x1 >= rows || y1 < 0 || y1 >= cols || x2 < 0 || x2 >= rows || y2 < 0 || y2 >= cols) {
		return false;
	}

	// 两个块必须相邻才可以交换
	if (abs(x1 - x2) + abs(y1 - y2) != 1) {
		return false;
	}
	return true;
}

//返回Map上所有能消除的结点 在操作之后调用
QVector<QPair<int, int>> Map::canClear()
{
	int rows = maps_.size();
	int cols = maps_[0].size();
	QVector<QPair<int, int>> clear;

	// 检查每一行
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols - 2; ++j) { // 至少需要3个块才能消除
			if (maps_[i][j]->type_ != Blank && maps_[i][j]->type_ == maps_[i][j + 1]->type_
				&& maps_[i][j]->type_ == maps_[i][j + 2]->type_) { // 水平方向连续三个相同
				clear.push_back({ i, j });//把可以消去的方块记录
				clear.push_back({ i, j + 1 });
				clear.push_back({ i, j + 2 });
			}
		}
	}

	// 检查每一列
	for (int j = 0; j < cols; ++j) {
		for (int i = 0; i < rows - 2; ++i) {
			if (maps_[i][j]->type_ != Blank && maps_[i][j]->type_ == maps_[i + 1][j]->type_ &&
				maps_[i][j]->type_ == maps_[i + 2][j]->type_) { // 垂直方向连续三个相同
				clear.push_back({ i, j });
				clear.push_back({ i + 1, j });
				clear.push_back({ i + 2, j });
			}
		}
	}

	// 返回可以消除的块的位置
	return clear;
}

//检查坐标是否越界 判断鼠标点击的位置是否有效
bool Map::indexIsValid(int x, int y)
{
	int rows = maps_.size();
	int cols = maps_[0].size();
	if (x < 0 || x >= rows || y < 0 || y >= cols) {
		return false;
	}
	return true;
}

//填充一格的数据 在消除后 最上面一行填充
bool Map::refillData(bool useswap)
{
	int rows = maps_.size(), cols = maps_[0].size();
	bool ret = false;
	for (int i = rows - 1; i > 0; i--)//方块掉下来的操作
	{
		for (int j = 0; j < cols; j++)
		{
			if (maps_[i][j]->type_ == Blank)//发现一个方块为blank时，需要继续填充
			{
				if (useswap)
					swap(i - 1, j, i, j, true); //代码将图片消除()将changepos改为true
				ret = true;
			}
		}
	}

	for (int i = 0; i < cols; i++)//填充第一行
	{
		if (maps_[0][i]->type_ == Blank)//随机放一个方块
		{
			delete maps_[0][i];
			maps_[0][i] = new Block(true, widget_);
			maps_[0][i]->label_->move(i * Block_Width, 50);
			maps_[0][i]->label_->show();
		}
	}
	return ret;
}

//这一行空了则从从下往上进行交换
QAbstractAnimation* Map::refillAnimation()
{
	int rows = maps_.size(), cols = maps_[0].size();
	QSequentialAnimationGroup* sa = new QSequentialAnimationGroup(widget_);
	//从最后一行往上检查是否为空，然后进行交换
	for (int i = rows - 1; i > 0; i--)
	{
		QParallelAnimationGroup* animationGroup = new QParallelAnimationGroup(widget_);
		for (int j = 0; j < cols; j++)
		{
			if (maps_[i][j]->type_ == Blank)
			{
				animationGroup->addAnimation(swapWithAnimation(i - 1, j, i, j, true));
			}
		}
		if (animationGroup->children().size() != 0)
		{
			sa->addAnimation(animationGroup);
		}
	}
	return sa;
}

//8x8
void Map::initMap()
{
	for (int i = 0; i < maps_.size(); i++)
	{
		for (int j = 0; j < maps_[0].size(); j++)
		{
			if (maps_[i][j])
			{
				delete maps_[i][j];
			}
			maps_[i][j] = new Block(true, widget_);
			maps_[i][j]->label_->move(j * Block_Width, i * Block_Width + 50);
		}
	}
	auto vecs = canClear();
	while (vecs.size() != 0)
	{
		for (auto vec : vecs)
		{
			maps_[vec.first][vec.second]->clear();
		}

		bool needmore = refillData(true);
		while (needmore)
		{
			needmore = refillData(true);
		}
		vecs = canClear();
	}
}

//交换成功后 进行清空 进行连续消除的操作 直到不能消除为止
int Map::runClear()
{
	//检查可以消除的点
	auto vecs = canClear();
	//进行计分
	int score = 0;
	while (vecs.size() != 0)
	{
		score += vecs.size();
		for (auto vec : vecs)
		{
			maps_[vec.first][vec.second]->clear();//消除一个调用clear函数
		}
		bool needmore = false;
		do
		{
			needmore = false;
			auto animation = refillAnimation();//返回动画 和bool值 代表有没有数据需要填充
			QEventLoop loop;//动画执行结束后进行下一步操作 用loop阻塞主线程
			animation->start();
			//检查，如果有
			if (animation->children().size() != 0)
			{
				connect(animation, &QSequentialAnimationGroup::finished, [&]() {
					needmore = refillData(false);//返回是否需要填充更多图片和数据
					loop.quit();
					});
				loop.exec();
				widget_->update();
			}
			else
			{
				needmore = refillData(true);
			}

		} while (needmore);
		vecs = canClear();
	}
	return score;
}

