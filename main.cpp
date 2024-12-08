#include <QApplication>
#include "MainWindow.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w; // 创建主窗口实例
    w.show(); // 显示主窗口
    return a.exec(); // 启动事件循环
}
