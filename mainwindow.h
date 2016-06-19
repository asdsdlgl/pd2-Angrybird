#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <QPoint>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <pig.h>
#include <wood.h>
#include <shoot.h>
#include <restart.h>
#include <exit.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);

signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QList<Bird *> Birdlist;
    QList<Pig *> Piglist;
    QList<Wood *> Woodlist;
    QList<Shoot *> Shootlist;
    QList<Restart *> Restartlist;
    QList<Exit *> Exitlist;
    QTimer timer;
    int countbird = 0,setnum = 0,set=0 ,temp=0;
   // int tempX=0,tempY=0,tempX2=0,tempY2=0;
};

#endif // MAINWINDOW_H
