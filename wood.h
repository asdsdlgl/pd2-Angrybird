#ifndef WOOD_H
#define WOOD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.2f
#define BIRD_RESTITUTION 0.5f

class Wood : public GameItem
{
public:
    Wood(float x, float y, float w,float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    //void setLinearVelocity(b2Vec2 velocity);
};


#endif // WOOD_H
