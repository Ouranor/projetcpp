#pragma once


#include "Modele.hpp"

#include <gtkmm/drawingarea.h>

class MyArea : public Gtk::DrawingArea
{

private:
  double m_fix;

public:
  MyArea();
  virtual ~MyArea();


//protected:
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;


};
