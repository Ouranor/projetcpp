#pragma once


#include "Modele.hpp"

#include <gtkmm/drawingarea.h>

class MyArea : public Gtk::DrawingArea
{


private:
	double m_fix;
  double m_width;
	double m_height;

public:
  MyArea(double fix, int width, int height);
  double getHeight() const;
  double getWidth() const;
  virtual ~MyArea();


//protected:
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;


};
