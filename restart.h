#ifndef RESTART_H
#define RESTART_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.2f
#define BIRD_RESTITUTION 0.5f

class Restart : public GameItem
{
public:
    Restart(int x, int y, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
   // void setLinearVelocity(b2Vec2 velocity);
};

#endif // RESTART_H
