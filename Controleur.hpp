#pragma once


#include "Modele.hpp"
#include "VueGraphique.hpp"

class Controleur {

  private:

    Modele *_m;
  	VueGraphique *_v;

  public:
  	Controleur(Modele *m,VueGraphique *v);
  	void on_button_enter();

};
