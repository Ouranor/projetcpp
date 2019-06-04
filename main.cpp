#include "Controleur.hpp"
#include "Modele.hpp"
#include "VueGraphique.hpp"

#include <iostream>
#include <gtkmm/application.h>


int main(int argc, char *argv[]){

	auto app = Gtk::Application::create(argc,argv);

	std::cout << "test main0";

	Modele *m = new Modele();
	std::cout << "test main1";
	VueG *vg = new VueG();
	std::cout << "test main2";
	Controleur *c = new Controleur(m,vg);
	std::cout << "test main3";
	m->addObservateur(vg);

	return app->run(*vg);

}
