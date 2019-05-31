#pragma once

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

#include "drawArea.hpp"
#include "Controleur.hpp"

using namespace std;


class VueG:public Gtk::Window , public Observateur<double>{
	private:

		Gtk::Box boxTop ;
		Gtk::Box box_gauche;
		Gtk::Box box_gauche_haut;
		Gtk::Box box_droit ;
		Gtk::Box box_droit_bas ;
	
		Gtk::Image img_title ;
  		Gtk::Button bEnter;
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


};
