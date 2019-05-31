#include "Modele.hpp"
# include "Observable.hpp"

void Modele::commandtoDraw(){
	this->drawLenght=0.0;

 notifyObservateurs(this->drawLenght);

}