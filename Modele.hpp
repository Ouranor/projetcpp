#pragma once

#include "Observable.hpp"
# include <string>



class Modele : public Observable<double> {
  
  private:
  	std::string command;
  	std::string direction;
  	double drawLenght;

  public:
  	void commandtoDraw();

};
