#include <iostream>

#include "MyArea.hpp"


MyArea::MyArea(double fix,int width, int height) : m_fix (fix),m_width(width),m_height(height)
{

  set_size_request (this->m_width,this->m_height);
  Gtk::Allocation allocation = get_allocation();
  setWinWidth(allocation.get_width());
  setWinHeight(allocation.get_height());

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
int MyArea::getAbsciss() const{
  return this->m_absciss;
}
int MyArea::getOrdinate() const {
  return this->m_ordinate;
}

int MyArea::getLastAbsciss() const{
  return this->m_lastAbsciss;
}
 int MyArea::getLastOrdinate() const{
  return this->m_lastOrdinate;
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
void MyArea::setOrdinate(int y){
  this->m_ordinate=y;
}
void MyArea::setAbsciss(int x){
  this->m_absciss=x;
}
void MyArea::setCoordinates(int x,int y){
  this->setAbsciss(x);
  this->setOrdinate(y);
}
void MyArea::setLastOrdinate(int y){
  this->m_lastOrdinate=y;
}
void MyArea::setLastAbsciss(int x){
  this->m_lastAbsciss=x;
}

void MyArea::setLastCoordinates(int x,int y){
  this->setLastOrdinate(y);
  this->setLastAbsciss(x);
}