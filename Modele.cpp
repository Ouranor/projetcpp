#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <cstring>

#include "Modele.hpp"

Modele::Modele(){
  this->_state = init;
}

Modele::~Modele(){}

void Modele::commandtoDraw(){
 	notifyObservateurs(getDecodedCommand());
}

Commande Modele::commandDecoding(std::string entry){

  Commande Cmd;
  this->_state = find_inst;
  std::string::iterator it = entry.begin();

  while(this->_state != init){

    if(this->_state == find_inst){
      std::cout << "STATE INST"<<std::endl;
      if(FindInstCommand("MF",entry)) Cmd._cmd = MF;
      else if(FindInstCommand("MB",entry)) Cmd._cmd = MB;
      else if(FindInstCommand("MR",entry)) Cmd._cmd = MR;
      else if(FindInstCommand("ML",entry)) Cmd._cmd = ML;
      else if(FindInstCommand("ROT",entry)) Cmd._cmd = ROT;
      else this->_state = init;
    }

    if(this->_state == find_arg1){
      std::cout << "STATE FIND ARG1 " <<std::endl;
      switch(Cmd._cmd)
      {
        case(ROT): Cmd._angle = FindFirstArgument(it); break;
        default: Cmd._lenght = FindFirstArgument(it);
      }
    }

    if(this->_state == find_endCmd){
      std::cout << "STATE END CMD " <<std::endl;
      FindEndCommand(it, entry);
    }

  }
  return Cmd;
}

void Modele::FindEndCommand(std::string::iterator it, std::string entry){
  while(*it != ';'){
    it++;
  }
  if(*it == ';'){
    entry.erase(entry.cbegin(), entry.cend());
  }
  this->_state = init;
  std::cout << "New Entry: " << entry <<std::endl;

}

int Modele::FindFirstArgument(std::string::iterator it){

  std::string arg1;

  while(isalpha(*it)) it++;
  while(isspace(*it)) it++;
  while(isdigit(*it)){
    arg1 += *it;
    it++;
  }
  std::cout << "ARG1:  " << arg1 << "  ";
  char buffer[arg1.size() + 1];
  strcpy(buffer, arg1.c_str());
  this->_state = find_endCmd;
  return atoi(buffer);
}

bool Modele::FindInstCommand(std::string inst, std::string entry){
  std::size_t find;
  find = entry.find(inst);

  if(find != std::string::npos){
    this->_state = find_arg1;
    std::cout << "COMMAND FIND  ";
    return true;
  }
  else{
    std::cout << "COMMAND NOOOOOT FIND  ";
    return false;
  }
}


void Modele::setDecodedCommand(std::string entry){
	this->_decodedCmd = commandDecoding(entry);
}
Commande Modele::getDecodedCommand(){
	return this->_decodedCmd;
}
