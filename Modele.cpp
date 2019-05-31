#include "Modele.hpp"
#include "Observable.hpp"

void Modele::commandtoDraw(){
	this->_drawLenght = 0.0;

 notifyObservateurs(this->_drawLenght);

}
