#include "collision.h"
#include <cmath>

bool checkCollision(PlayerObject* object1, Object* object2)
{
    int x1 = object1->GetX();
    int y1 = object1->GetY();
    int radiusX1 = object1->GetRadiusX()+3;
    int radiusY1 = object1->GetRadiusY()+3;

    int x2 = object2->GetX();
    int y2 = object2->GetY();
    int radiusX2 = object2->GetRadiusX()+3;
    int radiusY2 = object2->GetRadiusY()+3;

    int dx = x2 - x1;
    int dy = y2 - y1;
    int distanceX = abs(dx) - (radiusX1 + radiusX2);
    int distanceY = abs(dy) - (radiusY1 + radiusY2);

    return distanceX <= 0 && distanceY <= 0;
}