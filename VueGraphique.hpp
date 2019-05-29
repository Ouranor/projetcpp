#pragma once

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
using namespace std;

#include "Observateur.hpp"
#include "drawArea.hpp"


class VueG : public Gtk::Window, public Observateur<double> 
{
	
private:
	Gtk::Box box1;
	Gtk::Box box2;
	Gtk::Entry entry;
	Gtk::Button begin;
	
	MyArea drawArea;
	Gtk::TextView aideText;
	Glib::RefPtr<Gtk::TextBuffer> textBuffer1;
	string line;
	
	
public:
	VueG();
	virtual ~VueG();

};



