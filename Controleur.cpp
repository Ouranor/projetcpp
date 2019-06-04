#include "Controleur.hpp"
#include <iostream>


Controleur::Controleur(Modele *m,VueG *v) : _m(m),_v(v){
	_v->addDrawCommandListener(this);
	std::cout<<"controleur cree" << std::endl;
}

void Controleur::on_button_enter(){
	/*Appelle de commandToDraw dans la classe modele */
	_m->setDecodedCommand(_v->getEntry());
  _m->commandtoDraw();
  std::cout <<" controleur appelé" <<std::endl;
}
