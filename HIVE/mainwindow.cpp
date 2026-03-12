#include "mainwindow.h"
#include <QAction>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QMessageBox>
#include "gamewindow.h"
#include "anothergamewindow.h"
#include <QDialog>
#include "singlegamewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口大小
    this->resize(300, 200);

    // 创建背景标签
    QLabel *backgroundLabel = new QLabel(this);
    QPixmap pixmap("D:/images/background.png");
    backgroundLabel->setPixmap(pixmap);
    backgroundLabel->setScaledContents(true);

    // 创建按钮
    QPushButton *singlePlayerButton = new QPushButton("单机游戏", backgroundLabel);
    QPushButton *doublePlayerButton = new QPushButton("双人游戏", backgroundLabel);

    // 设置按钮的位置
    singlePlayerButton->setGeometry(QRect(100, 500, singlePlayerButton->sizeHint().width(), singlePlayerButton->sizeHint().height()));
    doublePlayerButton->setGeometry(QRect(750, 500, doublePlayerButton->sizeHint().width(), doublePlayerButton->sizeHint().height()));
    int originalWidth = singlePlayerButton->sizeHint().width();
    int originalHeight = singlePlayerButton->sizeHint().height();

    // 定义放大的比例
    float scale = 5.0;

    // 应用新的尺寸
    singlePlayerButton->setGeometry(QRect(100, 500, originalWidth * scale, originalHeight * scale));
    doublePlayerButton->setGeometry(QRect(750, 500, originalWidth * scale, originalHeight * scale));

    // 获取当前字体
    QFont font = singlePlayerButton->font();
    QFont doubleFont = doublePlayerButton->font();

    // 设置新的字体大小
    int fontSize = font.pointSize() * scale;
    font.setPointSize(fontSize);
    doubleFont.setPointSize(fontSize);

    // 应用新的字体
    singlePlayerButton->setFont(font);
    doublePlayerButton->setFont(doubleFont);

    // 设置中央部件为背景标签
    setCentralWidget(backgroundLabel);

    // 连接信号和槽
    connect(singlePlayerButton, &QPushButton::clicked, this, &MainWindow::onSinglePlayerButtonClicked);
    connect(doublePlayerButton, &QPushButton::clicked, this, &MainWindow::onDoublePlayerButtonClicked);

}

MainWindow::~MainWindow()
{
}


void MainWindow::onSinglePlayerButtonClicked()
{
    // 单机游戏按钮点击事件
    qDebug() << "单机游戏按钮被点击";
    SingleGameWindow *singleGameWindow = new SingleGameWindow(this);
    singleGameWindow->setModal(true);
    singleGameWindow->exec();
    if(GameBoard::_bRedTurn == 0)
    {
        singleGameWindow->startAI();
    }
}

void MainWindow::onDoublePlayerButtonClicked()
{
    // 双人游戏按钮点击事件
    qDebug() << "双人游戏按钮被点击";

    // 创建一个消息框询问用户是否加入拓展项
    QMessageBox msgBox;
    msgBox.setWindowTitle("加入拓展项");
    msgBox.setText("您想要加入拓展项吗？");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);

    int ret = msgBox.exec();


    if (ret == QMessageBox::No) {

        GameWindow *gameWindow = new GameWindow();
        gameWindow->show();
    } else if (ret == QMessageBox::Yes) {

        AnotherGameWindow *anotherGameWindow = new AnotherGameWindow();
        anotherGameWindow->show();
    }
}
