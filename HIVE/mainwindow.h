#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
QT_BEGIN_NAMESPACE
class QMenuBar;
class QStatusBar;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSinglePlayerButtonClicked();
    void onDoublePlayerButtonClicked();

private:
    QPushButton *singlePlayerButton;
    QPushButton *doublePlayerButton;
    QLabel *backgroundLabel;
};

#endif // MAINWINDOW_H
