
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


//drawArea.cpp
MyArea::MyArea()
: m_fix (0)
{
  set_size_request (400, 500);
}

MyArea::~MyArea()
{
}

bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  
  cr->set_line_width(1.0);

  // draw one line, every two pixels
  // without the 'fix', you won't notice any space between the lines,
  // since each one will occupy two pixels (width)
   cr->move_to(0, 0);
   cr->line_to(0, height);
   
  
   cr->move_to(0, 0);
   cr->line_to(width,0);
   
   cr->move_to(0, height);
   cr->line_to(width, height);
   
   cr->move_to(width,0);
   cr->line_to(width, height);
   
   
 cr->stroke();
  return true;
}

#endif // GTKMM_EXAMPLE_MYAREA_H
