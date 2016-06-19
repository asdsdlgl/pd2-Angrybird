#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QPixmap(":background.jpg"));
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));

    // Create bird (You can edit here)

    Bird *birdie = new Bird(5.5f,7.2f,0.8f,&timer, QPixmap(":bird.png").scaled(60,60),world,scene);
    Birdlist.push_back(birdie);

    Bird *birdie2 = new Bird(1.0f,7.2f,0.8f,&timer, QPixmap(":bird2.png").scaled(60,60),world,scene);
    Birdlist.push_back(birdie2);

    Bird *birdie3 = new Bird(1.0f,5.7f,0.8f,&timer, QPixmap(":bird3.png").scaled(60,60),world,scene);
    Birdlist.push_back(birdie3);

    Bird *birdie4 = new Bird(1.0f,4.0f,0.8f,&timer, QPixmap(":bird4.png").scaled(60,60),world,scene);
    Birdlist.push_back(birdie4);

    Pig * pig1 = new Pig(17.0,10.0, 0.9f,&timer, QPixmap(":pig.png").scaled(60,60),world,scene);
    Piglist.push_back(pig1);

    Pig * pig2 = new Pig(25.0,5.0, 0.9f,&timer, QPixmap(":pig2.png").scaled(60,60),world,scene);
    Piglist.push_back(pig2);

    Wood *woodlet = new Wood(17.0f,5.0f,1.0f,4.0f,&timer, QPixmap(":wood2.png").scaled(30,120),world,scene);
    Woodlist.push_back(woodlet);

    Wood *woodlet2 = new Wood(23.0f,5.0f,1.0f,4.0f,&timer, QPixmap(":thinwood2.png").scaled(30,120),world,scene);
    Woodlist.push_back(woodlet2);

    Wood *woodlet3 = new Wood(27.0f,5.0f,1.0f,4.0f,&timer, QPixmap(":thinwood3.png").scaled(30,120),world,scene);
    Woodlist.push_back(woodlet3);

    Wood *woodlet4 = new Wood(25.0f,10.0f,4.0f,1.0f,&timer, QPixmap(":wood3.png").scaled(120,30),world,scene);
    Woodlist.push_back(woodlet4);

    Shoot *shootlet = new Shoot(150,330 , QPixmap(":shooter.png").scaled(60,120),world,scene);
    Shootlist.push_back(shootlet);

    Restart *restartlet = new Restart(780,10,QPixmap(":restart.png").scaled(60,60),world,scene);
    Restartlist.push_back(restartlet);

    Exit *exitlet = new Exit(850,10,QPixmap(":exit.png").scaled(60,60),world,scene);
    Exitlist.push_back(exitlet);

    // Setting the Velocity
    birdie->setLinearVelocity(b2Vec2(0,10));
    //itemList.push_back(birdie);



    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);

    Birdlist[0]->g_body->SetType(b2_staticBody);
    Birdlist[1]->g_body->SetType(b2_staticBody);
    Birdlist[2]->g_body->SetType(b2_staticBody);
    Birdlist[3]->g_body->SetType(b2_staticBody);
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        /* TODO : add your code here */
        //std::cout << "Press !" << std::endl ;

        setnum=1;
        QMouseEvent *PressEvent = static_cast<QMouseEvent *>(event);

        if(855<PressEvent->x() && 900>PressEvent->x() && 0<PressEvent->y() && 80>PressEvent->y()){
            emit quitGame();
        }

        if(780<PressEvent->x() && 840>PressEvent->x() && 0<PressEvent->y() && 80>PressEvent->y()){

            timer.stop();
            for(int i=0;i<4;i++){
                    delete Woodlist[i];
            }
            for(int i=0;i<2;i++){
                    delete Piglist[i];
            }
            for(int i=0;i<4;i++){
                    delete Birdlist[i];
            }

            Woodlist.clear();
            Piglist.clear();
            Birdlist.clear();



            Bird *birdie = new Bird(5.5f,7.2f,0.8f,&timer, QPixmap(":bird.png").scaled(60,60),world,scene);
            Birdlist.push_back(birdie);

            Bird *birdie2 = new Bird(1.0f,7.2f,0.8f,&timer, QPixmap(":bird2.png").scaled(60,60),world,scene);
            Birdlist.push_back(birdie2);

            Bird *birdie3 = new Bird(1.0f,5.7f,0.8f,&timer, QPixmap(":bird3.png").scaled(60,60),world,scene);
            Birdlist.push_back(birdie3);

            Bird *birdie4 = new Bird(1.0f,4.0f,0.8f,&timer, QPixmap(":bird4.png").scaled(60,60),world,scene);
            Birdlist.push_back(birdie4);

            Pig * pig1 = new Pig(17.0,10.0, 0.9f,&timer, QPixmap(":pig.png").scaled(60,60),world,scene);
            Piglist.push_back(pig1);

            Pig * pig2 = new Pig(25.0,5.0, 0.9f,&timer, QPixmap(":pig2.png").scaled(60,60),world,scene);
            Piglist.push_back(pig2);

            Wood *woodlet = new Wood(17.0f,5.0f,1.0f,4.0f,&timer, QPixmap(":wood2.png").scaled(30,120),world,scene);
            Woodlist.push_back(woodlet);

            Wood *woodlet2 = new Wood(23.0f,5.0f,1.0f,4.0f,&timer, QPixmap(":thinwood2.png").scaled(30,120),world,scene);
            Woodlist.push_back(woodlet2);

            Wood *woodlet3 = new Wood(27.0f,5.0f,1.0f,4.0f,&timer, QPixmap(":thinwood3.png").scaled(30,120),world,scene);
            Woodlist.push_back(woodlet3);

            Wood *woodlet4 = new Wood(25.0f,10.0f,4.0f,1.0f,&timer, QPixmap(":wood3.png").scaled(120,30),world,scene);
            Woodlist.push_back(woodlet4);

            timer.start(100/6);

            Birdlist[0]->g_body->SetType(b2_staticBody);
            Birdlist[1]->g_body->SetType(b2_staticBody);
            Birdlist[2]->g_body->SetType(b2_staticBody);
            Birdlist[3]->g_body->SetType(b2_staticBody);

            countbird = 0;
            setnum = 0;
            set=0;
            temp=0;
        }

        if(50<PressEvent->x() && 250>PressEvent->x() && 250<PressEvent->y() && 400>PressEvent->y()){
            std::cout << "Signal receive !" << std::endl ;
            //tempX = PressEvent->x();
            //tempY = PressEvent->y();
        }


    }

    if(event->type() == QEvent::MouseMove)
    {
       /* QMouseEvent *mousemove = static_cast<QMouseEvent *>(event);
        float x=3.0-((tempX-mousemove->x())/50.0);
        float y=6.0+((tempY-mousemove->y())/50.0);
        Birdlist[countbird]->g_body->SetTransform(b2Vec2(x,y),0);*/
    }

    if(event->type() == QEvent::MouseButtonRelease)
    {
        /* TODO : add your code here */
        //std::cout << "Release !" << std::endl ;

        //Birdlist[0]->g_body->SetType(b2_dynamicBody);
      //  Birdlist[0]->setLinearVelocity(b2Vec2(-2.5,5));
                   //Birdlist[0]->g_body->GetPosition().x;

        QMouseEvent *mousePressEvent = static_cast<QMouseEvent *>(event);

        if(250>mousePressEvent->x() && mousePressEvent->x()>50 && mousePressEvent->y()>250 && mousePressEvent->y()<400 && countbird==0 && Birdlist[3]->g_body->GetLinearVelocity().x<10 && setnum==1){

          /*  tempX2 = mousePressEvent->x();
            tempY2 = mousePressEvent->y();

            int tempX3 = tempX-tempX2;
            int tempY3 = tempY2-tempY;*/
//            Birdlist[countbird]->setLinearVelocity(b2Vec2(tempX3/7.5,tempY3/7.5));

            Birdlist[countbird]->g_body->SetType(b2_dynamicBody);
            Birdlist[countbird]->setLinearVelocity(b2Vec2(10+countbird*2,1+countbird*2));
            countbird++;
            Birdlist[countbird]->g_body->SetTransform(b2Vec2(5.5,7.2),0);
           // Birdlist[countbird]->setLinearVelocity(b2Vec2(tempX3/7.5,tempY3/7.5));
            set=1;
            temp=0;
        }

        if( 250>mousePressEvent->x() && mousePressEvent->x()>50 && mousePressEvent->y()>250 && mousePressEvent->y()<400 && setnum==1&& temp==0 && set==0 && Birdlist[countbird-1]->g_body->GetLinearVelocity().x<10){

           /* int tempX3 = tempX-tempX2;
            int tempY3 = tempY2-tempY;*/
           // Birdlist[countbird]->setLinearVelocity(b2Vec2(tempX3/7.5,tempY3/7.5));

            setnum=0;
            Birdlist[countbird]->g_body->SetType(b2_dynamicBody);
            //Birdlist[countbird]->setLinearVelocity(b2Vec2(tempX3,tempY3));

            Birdlist[countbird]->setLinearVelocity(b2Vec2(10+countbird*2,1+countbird*2));

            //if(Birdlist[countbird]->g_body->GetLinearVelocity().x>5)
            //    Birdlist[countbird]->g_body->SetTransform(b2Vec2(5.5,7.2),0);

            if(countbird<3){
                countbird++;
                Birdlist[countbird]->g_body->SetTransform(b2Vec2(5.5,7.2),0);
            }
            else{
                countbird=0;
                temp = 1;
            }
        }
        //if(Birdlist[countbird-1]->g_body->GetPosition().x>10.0)Birdlist[countbird]->g_body->SetTransform(b2Vec2(5.5,7.2),0);

        set=0;
    }


    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();

}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
    exit(1);
}
