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


class VueG : public Gtk::Window
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
	VueG() :
		box1(Gtk::ORIENTATION_HORIZONTAL),
		box2(Gtk::ORIENTATION_VERTICAL),
		begin("ok")
		
	{
	set_size_request(1000, 1000);
	set_title("Convertisseur");
	// l’entrée
	entry.set_max_length(50);
	entry.set_text("Enter");
	entry.select_region(0, entry.get_text_length());
	
	textBuffer1=Gtk::TextBuffer::create();
	
	ifstream in("aidefile.txt");
	if(in.is_open()){
		while(!in.eof()){
		getline(in,line);
		cout<<line<<endl;
		textBuffer1->insert_at_cursor(line);
		textBuffer1->insert_at_cursor("\n");		
		}
		in.close();
	}
	aideText.set_buffer(textBuffer1);
	
	aideText.move_child(aideText,50,50);
	box1.pack_start(aideText);
	box1.pack_start(entry);
	box1.pack_start(begin);
	
	box2.add(box1);
	drawArea.set_size_request(200,200);
	box2.pack_start(drawArea,Gtk::PACK_SHRINK);
	
	
	add(box2);
	show_all_children();
   }


};



