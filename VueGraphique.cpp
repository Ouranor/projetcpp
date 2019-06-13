#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
# include <math.h>
#include "Controleur.hpp"
#include "VueGraphique.hpp"
# include <list>
int state=1;
//int sqrt[4][2];
double sind(double angle)
{
    double angleradians = angle * M_PI / 180.0f;
    return sin(angleradians);
}

double cosd(double angle)
{
    double angleradians = angle * M_PI / 180.0f;
    return cos(angleradians);
}
 //* M_PI / 180.0f;
VueGraphique::VueGraphique() :
		boxTop(Gtk::ORIENTATION_HORIZONTAL),
		box_gauche(Gtk::ORIENTATION_VERTICAL),box_gauche_haut(Gtk::ORIENTATION_VERTICAL),
		box_droit(Gtk::ORIENTATION_VERTICAL),box_droit_bas(Gtk::ORIENTATION_VERTICAL),
		img_title("tortue.png"),bEnter("Enter"),myDrawArea(0.0,500,500)
{

	std::cout<<"Vuegraphique "<<std::endl;
	box_gauche_haut.set_size_request(200,100);

	//pour afficher les text d'aide dans box_gauche_bas

	textBuffer1=Gtk::TextBuffer::create();
	std::ifstream in("aidefile.txt");
	if(in.is_open()){
		while(!in.eof()){
			getline(in,line);
			//std::cout<<line<<std::endl;
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
	//setContext();
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
	
	this->m_state=0;

	}

VueGraphique::~VueGraphique(){}


/* mise à jours vennant de l'observable - Structure de donnée de type Commande*/
void VueGraphique::update(Commande CMD){
	
	setDraw(CMD,this->getState());
	this->setState(1);

}



//=====================================================================
/* Le modele notifie l'observable puis celui-ci fais un update à la vue graphique ,
	la fonction setDraw est alors appelée
	Ici setDraw est uniquement exemple d'utilisation de tracé d'une ligne rouge
	dans la zone de dessins
	*/

void VueGraphique::setDraw(Commande CMD,int state){

	setContext(state);

	std::cout<<"draw"<<std ::endl;
	std::cout<<"CMD LEN  "<< CMD.getLenght() <<std::endl;
	std::cout<<"CMD INST  "<< CMD.getCmd() <<std::endl;

	//Type Commande contient toutes les infos pour tracer dans la VueGraphique
	//Switch pour différencier toutes les commandes possibles (MF, MB...)
	//Type commande contient infos sur type d'instruction, argument1(longueur,angle...)

	//TODO: tracer correct pour chaque instru
	switch(CMD.getCmd())
	{
		case(Commande::MF):{
			 std::cout << " nous traçon un MF de longueur : " << CMD.getLenght() << std::endl;

			 myDrawArea.setCoordinates(myDrawArea.getLastAbsciss()+CMD.getLenght(),myDrawArea.getLastOrdinate());

   			 break ;
		}


		case(Commande::MB):{
			
		    myDrawArea.setCoordinates(myDrawArea.getLastAbsciss()- CMD.getLenght(),myDrawArea.getLastOrdinate());
		    break;


		}
		case(Commande::MR):{
			
			 myDrawArea.setCoordinates(myDrawArea.getLastAbsciss(),myDrawArea.getLastOrdinate()+CMD.getLenght());
			 break;

		}
		case(Commande::ML):{
			 std::cout << " nous traçon un ML de longueur : " << CMD.getLenght() << std::endl;
			 std::cout << " nous traçon un ML de longueur : " <<CMD.getCmd() << std::endl;
			myDrawArea.setCoordinates(myDrawArea.getLastAbsciss(),myDrawArea.getLastOrdinate()-CMD.getLenght());

		}
		case(Commande::ROT):{
			std::cout<< "test dessins rotation" << std:: endl;
			std::cout<<"'angle correspond a :" <<cosd(CMD.getAngle())<< std::endl;
			std::cout << " longeur en absciss de la rotation :" << CMD.getLongueurAbsciss()<< std::endl;
			std::cout << " longeur en ordonnee de la rotation :" << CMD.getLongueurOrdinate()<< std::endl;


			myDrawArea.setCoordinates((CMD.getLongueurAbsciss())*cosd(CMD.getAngle())+myDrawArea.getLastAbsciss(),(-CMD.getLongueurOrdinate())*sind(CMD.getAngle())+myDrawArea.getLastOrdinate());
		}

		case (Commande::CARRE):{
			
			switch(CMD.getDir()){
				case(Commande::FRONT_LEFT):{
					
					this->_myContext->save();
					/*Front line */
					myDrawArea.setCoordinates(myDrawArea.getLastAbsciss()+CMD.getLenght(),myDrawArea.getLastOrdinate());
					this->_myContext->line_to(myDrawArea.getAbsciss(),myDrawArea.getOrdinate());
					myDrawArea.setLastCoordinates(myDrawArea.getAbsciss(),myDrawArea.getOrdinate());
					/*Left line */
					myDrawArea.setCoordinates(myDrawArea.getLastAbsciss(),myDrawArea.getLastOrdinate()-CMD.getLenght()); 
					this->_myContext->line_to(myDrawArea.getAbsciss(),myDrawArea.getOrdinate());
					myDrawArea.setLastCoordinates(myDrawArea.getAbsciss(),myDrawArea.getOrdinate());
					/*Back line */
					myDrawArea.setCoordinates(myDrawArea.getLastAbsciss()- CMD.getLenght(),myDrawArea.getLastOrdinate());
					this->_myContext->line_to(myDrawArea.getAbsciss(),myDrawArea.getOrdinate());
					myDrawArea.setLastCoordinates(myDrawArea.getAbsciss(),myDrawArea.getOrdinate());
					/*Right line*/




				}
				case(Commande::FRONT_RIGHT):{

					this->_myContext->save();
					/*Front line */

					myDrawArea.setCoordinates(myDrawArea.getLastAbsciss()+CMD.getLenght(),myDrawArea.getLastOrdinate());
					this->_myContext->line_to(myDrawArea.getAbsciss(),myDrawArea.getOrdinate());
					myDrawArea.setLastCoordinates(myDrawArea.getAbsciss(),myDrawArea.getOrdinate());
					/*trait vers la droite */
					myDrawArea.setCoordinates(myDrawArea.getLastAbsciss(),myDrawArea.getLastOrdinate()+CMD.getLenght());
					this->_myContext->line_to(myDrawArea.getAbsciss(),myDrawArea.getOrdinate());
					myDrawArea.setLastCoordinates(myDrawArea.getAbsciss(),myDrawArea.getOrdinate());
					/*Back line */
					myDrawArea.setCoordinates(myDrawArea.getLastAbsciss()- CMD.getLenght(),myDrawArea.getLastOrdinate());
					this->_myContext->line_to(myDrawArea.getAbsciss(),myDrawArea.getOrdinate());
					myDrawArea.setLastCoordinates(myDrawArea.getAbsciss(),myDrawArea.getOrdinate());
					/*Left Line */
					myDrawArea.setCoordinates(myDrawArea.getLastAbsciss(),myDrawArea.getLastOrdinate()-CMD.getLenght());
					this->_myContext->line_to(myDrawArea.getAbsciss(),myDrawArea.getOrdinate());
					myDrawArea.setLastCoordinates(myDrawArea.getAbsciss(),myDrawArea.getOrdinate());
					this->_myContext->stroke_preserve();
					this->_myContext->restore();







				}
				case (Commande::BACK_LEFT):{
					int width=myDrawArea.getWidth();
					int height=myDrawArea.getHeight();
					const int lesser = std::min(width, height);
					/*
					this->_myContext->save();
  					this->_myContext->arc(width / 3.0, height / 4.0, lesser / 4.0, -(M_PI / 5.0), M_PI);
  					this->_myContext->close_path();   // line back to start point
 				    this->_myContext->set_source_rgb(0.0, 0.8, 0.0);
  					this->_myContext->fill_preserve();
  					this->_myContext->restore();  // back to opaque black
 				    this->_myContext->stroke();   // outline it
 				    */
 				    const int xc = width / 2;
  					const int yc = height / 2;
 				    this->_myContext->save();
  					this->_myContext->arc(xc, yc, lesser / 2.0, 0.0, 2.0 * M_PI); // full circle
  					this->_myContext->set_source_rgba(0.0, 0.0, 0.8, 0.6);    // partially translucent
 				    this->_myContext->fill_preserve();
  					this->_myContext->restore();  // back to opaque black
  					this->_myContext->stroke();

				}
				case (Commande::BACK_RIGHT):{

				}
			}
			
		}
		default:{//Wrong CMD command not found
			setEntry("Wrong Command Format! Please see Help menu.");
		};
	}
	if(CMD.getCmd()!=Commande::CARRE){
		this->_myContext->save();
		this->_myContext->line_to(myDrawArea.getAbsciss(),myDrawArea.getOrdinate());
		myDrawArea.setLastCoordinates(myDrawArea.getAbsciss(),myDrawArea.getOrdinate());
		this->_myContext->stroke_preserve();
		this->_myContext->restore();
	}

}


//=====================================================================


//========================Getters/Setters==============================

std::string VueGraphique::getEntry() const {
	Glib::ustring cmdEntry = entry.get_text();
	std::cout << "getEntry:" << cmdEntry << std::endl;
	static_cast<std::string>(cmdEntry);
	return cmdEntry;
}

void VueGraphique::setEntry(std::string msg){
	static_cast<Glib::ustring>(msg);
	std::cout <<"setEntry";
	entry.set_text(msg);
}

//Set des paramètres initiaux du contexte - Appelé dans setDraw()
void VueGraphique::setContext(int state){
	if(!state){
	this->_myContext = this->myDrawArea.get_window()->create_cairo_context();
//	this->_myContext->move_to(myDrawArea.getWinWidth()/2,myDrawArea.getWinHeight()/2);
	myDrawArea.setLastAbsciss(myDrawArea.getWinWidth()/2+myDrawArea.getWidth()/2);
	myDrawArea.setLastOrdinate(myDrawArea.getWinHeight()/2+myDrawArea.getHeight()/2);
	this->_myContext->move_to(myDrawArea.getLastAbsciss(),myDrawArea.getLastOrdinate());
	this->_myContext->set_source_rgb(0.8, 0.0, 0.0);

	this->_myContext->set_line_width(4.0);
	std::cout << "setContext" << std::endl;
}
}

Cairo::RefPtr<Cairo::Context> VueGraphique::getContext() const{
	return this->_myContext;
	std::cout << "getContext" << std::endl;
}

void VueGraphique::setState(int state){
	this->m_state=state;
}
int VueGraphique::getState() const{
	return this->m_state;
}
//=====================================================================


//===============================Listeners==============================

//Override default signal handler:
void VueGraphique::addDrawCommandListener(Controleur *c){
	bEnter.signal_clicked().connect(sigc::mem_fun(*c, &Controleur::on_button_enter));
}
/*
void setSqrt(Commande::dir d){
	switch(d){
		case(FRONT_RIGHT):{
			_sqrt.push_back()


		}
	}
}
*/