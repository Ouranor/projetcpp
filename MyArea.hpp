#pragma once

#include <gtkmm/drawingarea.h>

class MyArea : public Gtk::DrawingArea
{


private:
	double m_fix;
  int m_width;
	int m_height;

	int m_WinWidth;
	int m_WinHeight;

public:
  MyArea(double fix, int width, int height);
  virtual ~MyArea();

	void setWidth(int myWidth);
	void setHeight(int myHeight);
	void setWinWidth(int w);
	void setWinHeight(int h);

	int getHeight() const;
	int getWidth() const;
	int getWinWidth() const;
	int getWinHeight() const;


  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;


};
