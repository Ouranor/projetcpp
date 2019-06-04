#pragma once

#include "Modele.hpp"
#include "VueGraphique.hpp"


class Controleur {

  private:

    Modele *_m;
  	VueG *_v;

  public:
  	Controleur(Modele *m,VueG *v);
  	void on_button_enter();

};
