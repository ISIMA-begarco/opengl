#include "mouse.hpp"

static void MouseData::updatePosition(Sint32 x, Sint32 y) {  
  MouseData::pmousex = MouseData::mousex;
  MouseData::pmousey = MouseData::mousey;
  MouseData::mousex = x; // mémorisation coordonnées souris 
  MouseData::mousey = y; // mémorisation coordonnées souris 
}
