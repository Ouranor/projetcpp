#include <iostream>
#include <iomanip>
#include "VueGraphique.hpp"
#include "Controleur.hpp"


VueG::VueG() :
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
	
	//aideText.move_child(aideText,50,50);
	box1.pack_start(aideText);
	box1.pack_start(entry);
	box1.pack_start(begin);
	
	box2.add(box1);
	box2.add(drawArea);
	
	
	add(box2);
	show_all_children();
	
 }

VueG::~VueG()
{

}


