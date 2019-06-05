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

	int getHeight() const;
	int getWidth() const;
	void setWidth(int myWidth);
	void setHeight(int myHeight);

	void setWinWidth(int w) const;
	void setWinHeight(int h) const;
	int getWinWidth();
	int getWinHeight();

  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;


};
