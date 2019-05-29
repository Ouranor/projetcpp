#include <gtkmm/application.h>
#include "Modele.hpp"
#include "Controleur.hpp"
#include "VueGraphique.hpp"


int main(int argc, char *argv[]){

	auto app= Gtk::Application::create(argc,argv);
	
	return app->run(* new VueG());
		
}
