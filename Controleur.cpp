
# include "Modele.hpp"
#include "Controleur.hpp"
#include "VueGraphique.hpp"

Controleur::Controleur(Modele *m,VueG*v):_m(m),_v(v){
	_v->addDrawCommandListener(this);
	std::cout<<"controleur cree" << std::endl;
}

void Controleur::on_button_enter(){
	/*Appelle de commandToDraw dans la classe modele */
_m->commandtoDraw();
std::cout <<" controleur appelé" <<std::endl;
}

