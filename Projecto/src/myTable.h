#ifndef MYTABLE_H
#define MYTABLE_H

#include "CGFobject.h"
#include "myUnitCube.h"
#include "myTable.h"
#include "CGFappearance.h"


class myTable: public CGFobject {
 public:
  void draw(CGFappearance *legs , CGFappearance *tampo);
  void drawLegs(CGFappearance *legs);
  void drawTampo(CGFappearance *tampo);
};

#endif