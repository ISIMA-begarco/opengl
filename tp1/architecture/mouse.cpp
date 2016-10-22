#include "mouse.hpp"

// Initialisation des données de classe
int MouseData::mousex = 0;
int MouseData::mousey = 0;
int MouseData::pmousex = 0;
int MouseData::pmousey = 0;
bool MouseData::leftButtonPressed = false;
bool MouseData::middleButtonPressed = false;
bool MouseData::rightButtonPressed = false;
float MouseData::vitesse = 0.2f;

void MouseData::updatePosition(int x, int y) {  
  MouseData::pmousex = MouseData::mousex;
  MouseData::pmousey = MouseData::mousey;
  MouseData::mousex = x; // mémorisation coordonnées souris 
  MouseData::mousey = y; // mémorisation coordonnées souris 
}
