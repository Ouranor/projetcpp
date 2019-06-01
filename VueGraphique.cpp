#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <gtkmm.h>
#include <cairomm/context.h>

#include "Controleur.hpp"
#include "VueGraphique.hpp"
#include "MyArea.hpp"

#include <string>

#include <gtkmm/button.h>


VueG::VueG() :
		boxTop(Gtk::ORIENTATION_HORIZONTAL),
		box_gauche(Gtk::ORIENTATION_VERTICAL),box_gauche_haut(Gtk::ORIENTATION_VERTICAL),
		box_droit(Gtk::ORIENTATION_VERTICAL),box_droit_bas(Gtk::ORIENTATION_VERTICAL),

		bEnter("Enter"), img_title("tortue.png"),myDrawArea(0.0,400,500)
{




	std::cout<<"Vuegraphique "<<std::endl;
	//box_gauche_haut
	box_gauche_haut.set_size_request(200,100);

	//pour afficher les text d'aide dans box_gauche_bas

	textBuffer1=Gtk::TextBuffer::create();
	ifstream in("aidefile.txt");
	if(in.is_open()){
		while(!in.eof()){
		getline(in,line);
		cout<<line<<endl;
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
	//myDrawArea.show();

	}
/* mise à jours vennant de l'observable */
void VueG::update(double d){



	this->setDraw();

	setDraw();

}
/* Le modele notifie l'observable puis celui-ci fais un update à la vue graphique , la fonction setDraw est alors appele */
/* Ici setDraw est uniquement exemple d'utilisation de tracé d'une ligne rouge dans la zone de dessins */ 
void VueG:: setDraw(){
	Cairo::RefPtr<Cairo::Context> myContext=this->get_window()->create_cairo_context();
	//myDrawArea
	//this->myDrawArea.on_draw(myContext);
	std::cout<<"draw"<<std ::endl;
     //myDrawArea
	//set_draw_func(sigc::mem_fun(*this,&MyArea::on_draw));
	//Cairo::RefPtr<Cairo::Context> myContext=this->myDrawArea.get_surface()->create_cairo_context();
	//on_draw(myContext);
	const int height=this->myDrawArea.getHeight();
	const int width=this->myDrawArea.getWidth();
	myContext->set_source_rgb(0.8, 0.0, 0.0);
	myContext->set_line_width(2.0);
	myContext->move_to(width,height);
   	myContext->line_to(width, height+width);
   	myContext->stroke();


}


VueG::~VueG(){}

//Override default signal handler:
//bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

void VueG::addDrawCommandListener(Controleur *c){
	//bEnter.signal_clicked().connect(sigc::mem_fun(*c, &Controleur::on_button_enter));

	bEnter.signal_clicked().connect(sigc::mem_fun(*c, &Controleur::on_button_enter));






}
