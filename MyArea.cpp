#include <gtkmm/drawingarea.h>

#include "Modele.hpp"
#include "MyArea.hpp"
# include <iostream>


MyArea::MyArea(double fix,int width, int height) : m_fix (fix),m_width(width),m_height(height)
{

  set_size_request (this->m_width,this->m_height);

}

MyArea::~MyArea(){}

bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)

{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();
  std ::cout << width << std::endl;
  std ::cout << " height =" << height << std::endl;

  cr->set_line_width(1.0);


  // draw one line, every two pixels
  // without the 'fix', you won't notice any space between the lines,
  // since each one will occupy two pixels (width)


   cr->move_to(0, 0);
   cr->line_to(0, height);

  std::cout <<" essai ligne "<< std::endl;


   cr->move_to(0, 0);
   cr->line_to(height,0);

   cr->move_to(0, height);
   cr->line_to(width, height);

   cr->move_to(width,0);
   cr->line_to(width, height);



   cr->stroke();
   return true;
}
//double getHeidth() const
double MyArea::getHeight() const  {
  return this->m_height;

}

double MyArea::getWidth() const {
  return this->m_width;
}
