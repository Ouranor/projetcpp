#pragma once

#include "Observable.hpp"
# include <string>



class Modele : public Observable<double> {

  private:
  	std::string _command;
  	std::string _direction;
  	double _drawLenght;

  public:
  	void commandtoDraw();

};
