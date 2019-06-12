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
	int m_absciss;
	int m_ordinate;
	int m_lastOrdinate;
	int m_lastAbsciss;

public:
  MyArea(double fix, int width, int height);
  virtual ~MyArea();

	void setWidth(int myWidth);
	void setHeight(int myHeight);
	void setWinWidth(int w);
	void setWinHeight(int h);
	/*Set les actuelles coordonnées que l'ont va utilisés pour tracer*/
	void setAbsciss(int x);
	void setOrdinate(int y);
	void setCoordinates(int x,int y);
	/*Set les anciennes cordonnées pour faire un trait relatif au dernier trait */
	void setLastAbsciss(int x);
	void setLastOrdinate(int y);
	void setLastCoordinates(int x,int y);
	


	int getHeight() const;
	int getWidth() const;
	int getWinWidth() const;
	int getWinHeight() const;
	int getOrdinate() const;
	int getAbsciss() const;
	int getLastAbsciss() const;
	int getLastOrdinate() const;


  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;


};
