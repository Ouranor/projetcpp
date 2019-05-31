#include <iostream>
#include <iomanip> 
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/textview.h>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <gtkmm/widget.h>

#include "Controleur.hpp"
#include "VueGraphique.hpp"
#include "drawArea.hpp"


VueG::VueG():
		boxTop(Gtk::ORIENTATION_HORIZONTAL),
		box_gauche(Gtk::ORIENTATION_VERTICAL),box_gauche_haut(Gtk::ORIENTATION_VERTICAL),
		box_droit(Gtk::ORIENTATION_VERTICAL),box_droit_bas(Gtk::ORIENTATION_VERTICAL),
	bEnter("enter"), img_title("tortue.png")
	{
	
		
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
	show_all_children ();

	}

void VueG::update(double d){}

VueG::~VueG(){}


