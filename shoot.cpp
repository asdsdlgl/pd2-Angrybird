#include "shoot.h"

Shoot::Shoot(int x, int y, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setPos(x,y);
    scene->addItem(&g_pixmap);
}

