#include <iostream>

#include "MyArea.hpp"


MyArea::MyArea(double fix,int width, int height) : m_fix (fix),m_width(width),m_height(height)
{

  set_size_request (this->m_width,this->m_height);
  Gtk::Allocation allocation = get_allocation();
  this->setWinWidth(allocation.get_width());
  this->setWinHeight(allocation.get_height());

}

MyArea::~MyArea(){}

bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)

{
  cr->set_line_width(1.0);

   cr->move_to(0, 0);
   cr->line_to(0, getHeight());

   cr->move_to(0, 0);
   cr->line_to(getHeight(),0);

   cr->move_to(0, getHeight());
   cr->line_to(getWidth(), getHeight());

   cr->move_to(getWidth(), 0);
   cr->line_to(getWidth(), getHeight());

   cr->stroke();
   return true;
}

//==============Getters====================
int MyArea::getHeight() const  {
  return this->m_height;
}
int MyArea::getWidth() const {
  return this->m_width;
}

int MyArea::getWinWidth() const{
  return this->m_WinWidth;
}
int MyArea::getWinHeight() const{
  return this->m_WinHeight;
}

//===============Setters====================
void MyArea::setWinWidth(int WinW){
  this->m_WinWidth = WinW;
}
void MyArea::setWinHeight(int WinH){
  this->m_WinHeight = WinH;
}

void MyArea::setWidth(int myWidth){
  this->m_width = myWidth;
}
void MyArea::setHeight(int myHeight){
  this->m_height = myHeight;
}
