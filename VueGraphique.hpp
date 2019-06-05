#pragma once

#include <gtkmm.h>
#include <cairomm/context.h>

#include "Observateur.hpp"
#include "MyArea.hpp"
#include "Modele.hpp"


class Controleur;

class VueG : public Gtk::Window, public Commande, public Observateur<Commande>{

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
		Cairo::RefPtr<Cairo::Context> _myContext;

		//affiche aide text
		Gtk::TextView aideText;
		Glib::RefPtr<Gtk::TextBuffer> textBuffer1;
		std::string line;

	public :

		VueG();
		virtual ~VueG();
		void update(Commande) override;
		void setDraw(Commande CMD);
		void setContext();

		void addDrawCommandListener(Controleur*);
		Cairo::RefPtr<Cairo::Context> getContext() const;

		std::string getEntry() const;
		void setEntry(std::string msg);

};
