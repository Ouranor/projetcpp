#include <gtkmm/application.h>
#include "Modele.hpp"
#include "Controleur.hpp"
#include "VueGraphique.hpp"
#include "MyArea.hpp"

int main(int argc, char *argv[]){

	auto app = Gtk::Application::create(argc,argv);

	Modele *m = new Modele();
	VueG *vg = new VueG();
	Controleur *c = new Controleur(m,vg);
	m->addObservateur(vg);

	return app->run(*vg);

}
