#pragma once

#include <gtkmm.h>
#include <cairomm/context.h>

#include "Observateur.hpp"
#include "MyArea.hpp"


class Controleur;
class Commande;

class VueGraphique : public Gtk::Window, public Observateur<Commande>{

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
		/* Attribut qui indique si on est dans l'état initial ou après, afin de ne crée le context cairo une seule fois */
		int m_state;

	public :

		VueGraphique();
		virtual ~VueGraphique();
		
		void update(Commande) override;
		void setDraw(Commande CMD,int state);
		void setContext(int state);

		void addDrawCommandListener(Controleur*);
		Cairo::RefPtr<Cairo::Context> getContext() const;

		std::string getEntry() const;
		void setEntry(std::string msg);
		void setState(int state);
		int getState() const;

};
