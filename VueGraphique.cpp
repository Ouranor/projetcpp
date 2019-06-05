#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

#include "VueGraphique.hpp"
#include "Controleur.hpp"

VueG::VueG() :
		boxTop(Gtk::ORIENTATION_HORIZONTAL),
		box_gauche(Gtk::ORIENTATION_VERTICAL),box_gauche_haut(Gtk::ORIENTATION_VERTICAL),
		box_droit(Gtk::ORIENTATION_VERTICAL),box_droit_bas(Gtk::ORIENTATION_VERTICAL),
		img_title("tortue.png"),bEnter("Enter"),myDrawArea(0.0,500,500)
{

	std::cout<<"Vuegraphique "<<std::endl;
	//box_gauche_haut
	box_gauche_haut.set_size_request(200,100);

	//pour afficher les text d'aide dans box_gauche_bas

	textBuffer1=Gtk::TextBuffer::create();
	std::ifstream in("aidefile.txt");
	if(in.is_open()){
		while(!in.eof()){
			getline(in,line);
			std::cout<<line<<std::endl;
			textBuffer1->insert_at_cursor("\t");
			textBuffer1->insert_at_cursor(line);
			textBuffer1->insert_at_cursor("\n");
		}
		in.close();
	}
	aideText.set_buffer(textBuffer1);
	aideText.set_border_width(20);
	//box_gauche
	//box_gauche.pack_start(box_gauche_haut,Gtk::PACK_SHRINK);
	box_gauche.pack_start(img_title,Gtk::PACK_SHRINK);
	box_gauche.pack_start(aideText,Gtk::PACK_SHRINK);
	box_gauche.set_size_request(200,800);
	box_gauche.set_border_width(20);

	//box_droit_bas
	box_droit_bas.pack_start(myDrawArea,Gtk::PACK_SHRINK);
	box_droit_bas.set_size_request(400,400);
	box_droit_bas.set_border_width(30);

	// l’entrée
	entry.set_max_length(50);
	entry.set_text("Enter");
	entry.select_region(0, entry.get_text_length());

	//box_droit
	box_droit.pack_start(entry,Gtk::PACK_SHRINK);
	box_droit.pack_start(bEnter);
	box_droit.pack_start(box_droit_bas,Gtk::PACK_SHRINK);
	box_droit.set_size_request(500,800);
	box_droit.set_border_width(30);

	//boxTop
	boxTop.pack_start(box_gauche,Gtk::PACK_SHRINK);
	boxTop.pack_start(box_droit,Gtk::PACK_SHRINK);
	boxTop.set_size_request(1000,1000);
	boxTop.set_border_width(30);
	add(boxTop);

	show_all_children();

	}
/* mise à jours vennant de l'observable */
void VueG::update(Commande CMD){

	setDraw(CMD);

}

void VueG::setContext(){
	this->_myContext = this->myDrawArea.get_window()->create_cairo_context();
	std::cout << "setContext" << std::endl;
	this->_myContext->move_to(myDrawArea.getWinWidth()/2,myDrawArea.getWinHeight()/2);
}

Cairo::RefPtr<Cairo::Context> VueG::getContext() const{
	return this->_myContext;
	std::cout << "getContext" << std::endl;
}

std::string VueG::getEntry() const {
	Glib::ustring cmdEntry = entry.get_text();
	std::cout << "getEntry:" << cmdEntry << std::endl;
	static_cast<std::string>(cmdEntry);
	return cmdEntry;
}

void VueG::setEntry(std::string msg){
	static_cast<Glib::ustring>(msg);
	std::cout <<"setentryyyyyyyyyy";
	entry.set_text(msg);
}


/* Le modele notifie l'observable puis celui-ci fais un update à la vue graphique , la fonction setDraw est alors appele */
/* Ici setDraw est uniquement exemple d'utilisation de tracé d'une ligne rouge dans la zone de dessins */
void VueG::setDraw(Commande CMD){

	setContext();

	this->_myContext->set_source_rgb(0.8, 0.0, 0.0);
	this->_myContext->set_line_width(4.0);
	std::cout<<"draw"<<std ::endl;
	std::cout<<"CMD LEN  "<< CMD._lenght <<std::endl;
	std::cout<<"CMD INST  "<< CMD._cmd <<std::endl;

	//Type Commande contient toutes les infos pour tracer dans la VueGraphique
	//Switch pour différencier toutes les commandes possibles (MF, MB...)
	//Type commande contient infos sur type d'instruction, argument1(longueur,angle...)

	//TODO: tracer correct pour chaque instru
	switch(CMD._cmd)
	{
		case(MF):{
			this->_myContext->line_to(myDrawArea.getWidth(),myDrawArea.getHeight());
			myDrawArea.setWidth(myDrawArea.getWidth() + CMD._lenght);
			this->_myContext->move_to(myDrawArea.getWidth(),myDrawArea.getHeight());
			this->_myContext->stroke_preserve(); break;
		}
		case(MB):{
			this->_myContext->line_to(myDrawArea.getWidth(),myDrawArea.getHeight());
			myDrawArea.setWidth(myDrawArea.getWidth() - CMD._lenght);
			this->_myContext->move_to(myDrawArea.getWidth(),myDrawArea.getHeight());
			this->_myContext->stroke_preserve(); break;
		}
		case(MR):{
			this->_myContext->line_to(myDrawArea.getWidth(),myDrawArea.getHeight());
			myDrawArea.setHeight(myDrawArea.getHeight() - CMD._lenght);
			this->_myContext->move_to(myDrawArea.getWidth(),myDrawArea.getHeight());
			this->_myContext->stroke_preserve(); break;
		}
		case(ML):{
			this->_myContext->line_to(myDrawArea.getWidth(),myDrawArea.getHeight());
			myDrawArea.setHeight(myDrawArea.getHeight() + CMD._lenght);
			this->_myContext->move_to(myDrawArea.getWidth(),myDrawArea.getHeight());
			this->_myContext->stroke_preserve(); break;
		}
		default:{//Wrong CMD command not found
			setEntry("Wrong Command Format! Please see Help menu.");
		};
	}


}


//Override default signal handler:
void VueG::addDrawCommandListener(Controleur *c){
	bEnter.signal_clicked().connect(sigc::mem_fun(*c, &Controleur::on_button_enter));
}

VueG::~VueG(){}
