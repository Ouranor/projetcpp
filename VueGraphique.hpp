#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <gtkmm.h>
#include <cairomm/context.h>
#include <gtkmm/label.h>

#include "MyArea.hpp"
#include "Controleur.hpp"


using namespace std;
class Controleur;

class VueG:public Gtk::Window , public Observateur<double>{

	private:
        
        //all boxs
		Gtk::Box boxTop ;
		Gtk::Box box_gauche;
		Gtk::Box box_gauche_haut;
		Gtk::Box box_droit ;
		Gtk::Box box_droit_haut ;
		Gtk::Box box_droit_bas ;
	
				
		Gtk::Image img_title ;
	//all button	
  	Gtk::Button bEnter;
  	Gtk::Button bBack;
  	Gtk::Button bClaire;
  
  	
		Gtk::Entry entry;
		MyArea myDrawArea;

		//affiche aide text
		Gtk::TextView aideText;
		Glib::RefPtr<Gtk::TextBuffer> textBuffer1;
		string line;
	public :

		VueG();
		virtual ~VueG();
		void update(double d) override;
		void setDraw();
		void addDrawCommandListener(Controleur *c);


};
