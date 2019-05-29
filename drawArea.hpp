
#ifndef GTKMM_EXAMPLE_MYAREA_H
#define GTKMM_EXAMPLE_MYAREA_H

#include <gtkmm/drawingarea.h>

class MyArea : public Gtk::DrawingArea
{
	
private:
  double m_fix;
  
public:
  MyArea();
  virtual ~MyArea();

  
protected:
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;


};

//***************************************
//drawArea.cpp
MyArea::MyArea()
: m_fix (50)
{
  set_size_request (200, 500);
}

MyArea::~MyArea()
{
}

bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  int xc, yc;
  xc = width / 4;
  yc = height / 4;
  cr->set_line_width(1.0);

  // draw one line, every two pixels
  // without the 'fix', you won't notice any space between the lines,
  // since each one will occupy two pixels (width)
  
  
  
   cr->move_to(xc, yc);
   cr->line_to(xc, height);
   
  
   cr->move_to(xc, yc);
   cr->line_to(width-90,yc);
   
   cr->move_to(xc, height);
   cr->line_to(width-90, height);
   
   cr->move_to(width-90,yc);
   cr->line_to(width-90, height);

   cr->stroke();

  return true;
}

#endif // GTKMM_EXAMPLE_MYAREA_H
