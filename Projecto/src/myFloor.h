#ifndef MYFLOOR_H
#define MYFLOOR_H

#include "CGFobject.h"
#include "myUnitCube.h"
#include "myTable.h"


class myFloor: public CGFobject {
 public:
  void draw();
  void update(unsigned long millis);
};

#endif