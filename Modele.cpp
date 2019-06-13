#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <cstring>

#include "Modele.hpp"

Modele::Modele(){
  setModelState(init);
}

Modele::~Modele(){}

void Modele::commandtoDraw(){
 	notifyObservateurs(getDecodedCommand());
}

Commande Modele::commandDecoding(std::string entry){

  Commande Cmd;
  setModelState(find_inst);
  std::string::iterator it = entry.begin();
  std::string::iterator it_temp=it;
  while(getModelState() != init){

    if(getModelState() == find_inst){
      std::cout << "STATE INST"<<std::endl;
      if(FindInstCommand("MF",entry))Cmd.setCmd(Commande::MF);
      
      else if(FindInstCommand("MB",entry)) Cmd.setCmd(Commande::MB);
      else if(FindInstCommand("MR",entry)) Cmd.setCmd(Commande::MR);
      else if(FindInstCommand("ML",entry)) Cmd.setCmd(Commande::ML);
      else if(FindInstCommand("ROT",entry))Cmd.setCmd(Commande::ROT);
      else if(FindInstCommand("CARRE",entry)){
        Cmd.setCmd(Commande::CARRE);
        setModelState(find_inst);
        if(FindInstCommand("FRONT_LEFT",entry)) Cmd.setDir(Commande::FRONT_LEFT);
        else if(FindInstCommand("FRONT_RIGHT",entry)) Cmd.setDir(Commande::FRONT_RIGHT);
        else if(FindInstCommand("BACK_LEFT",entry)) Cmd.setDir(Commande::BACK_LEFT);
        else if(FindInstCommand("BACK_RIGHT",entry)) Cmd.setDir(Commande::BACK_RIGHT);
      }
      else setModelState(wrong_cmd);
    }

    if(getModelState() == find_arg1){
      std::cout << "STATE FIND ARG1 " <<std::endl;
      switch(Cmd.getCmd())
      {
        case(Commande::ROT):
         Cmd.setAngle(FindFirstArgument(it_temp));
        // Cmd.setLongueurAbscisse(FindFirstArgument(it));
        // std::cout<<Cmd.getLongueurAbscisse()<< std::endl;
         break;
        default: Cmd.setLenght(FindFirstArgument(it));
      }
    }
    if(getModelState()==find_arg2){
      std::cout << "STATE FIND ARG2" << std::endl;
      int longueur=FindSecondArgument(it);
      Cmd.setLongueurAbsciss(longueur);
      Cmd.setLongueurOrdinate(longueur);

    }

    if(getModelState() == find_endCmd){
      std::cout << "STATE END CMD " <<std::endl;
      FindEndCommand(entry);
    }

    if(stateIsWrongCmd()){
      Cmd.setValid(false);
      std::cout <<"WROONNG CMD  ";
      break;
      //setModelState(init);
    }

  }
  return Cmd;
}

void Modele::FindEndCommand(std::string entry){
  std::size_t last_pos_to_erase = entry.find(";");
  if(last_pos_to_erase != std::string::npos){
    entry.erase(0, last_pos_to_erase+1);
      setModelState(init);
  }
  else setModelState(wrong_cmd);

  std::cout << "New Entry: " << entry <<std::endl;

}

int Modele::FindFirstArgument(std::string::iterator it){
  std::string inst;
  std::string arg1;
  while(isalpha(*it)){
   inst+=*it;
   it++;
  }
  while(isspace(*it)) it++;
  while(isdigit(*it)){
    arg1 += *it;
    it++;
  }

  std::cout << "ARG1:  " << arg1 << "  ";
  char buffer[arg1.size() + 1];
  strcpy(buffer, arg1.c_str());
  if(this->FindInstCommand("ROT",inst))
  {
    std::cout<<"debut find arg2"<<std::endl;
    setModelState(find_arg2);
  }
  else {
  setModelState(find_endCmd);
  }
  return atoi(buffer);
}

int Modele::FindSecondArgument(std::string::iterator it){
  std::string arg2;
  while(isalpha(*it))it++;
  while(isspace(*it))it++;
  while(isdigit(*it))it++;
  while(isspace(*it))it++;
  while(isdigit(*it)){
    arg2 += *it;
    it++;
  }
  std::cout << "ARG2:  " << arg2 << "  ";
  char buffer[arg2.size() + 1];
  strcpy(buffer, arg2.c_str());
  setModelState(find_endCmd);
  return atoi(buffer);
}



bool Modele::FindInstCommand(std::string inst, std::string entry){
  std::size_t find;
  find = entry.find(inst);

  if(find != std::string::npos){
    setModelState(find_arg1);
    std::cout << "COMMAND FIND  ";
    return true;
  }
  else{
    std::cout << "COMMAND NOOOOOT FIND  ";
    return false;
  }
}

bool Modele::stateIsWrongCmd(){
  if(getModelState() == wrong_cmd) return true;
  else return false;
}

//====================Getters/Setters==============================
/* prends en argument la commande écrite par l'operateur */
void Modele::setDecodedCommand(std::string entry){
	this->_decodedCmd = commandDecoding(entry);
}
Commande Modele::getDecodedCommand(){
	return this->_decodedCmd;
}
Modele::state Modele::getModelState() const{
  return this->_state;
}
void Modele::setModelState(state myState){
  this->_state = myState;
}

/* but : comprendre classe commande et comment y acceder , faire un operateur <<*/

