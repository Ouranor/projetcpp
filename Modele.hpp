#pragma once

#include "Observable.hpp"
#include <string>

class Commande{
  public:
    typedef enum direction{RIGHT,LEFT,TOP,BOT} dir;
    typedef enum command{MF,MB,MR,ML,ROT} cmd;
    cmd _cmd;
    dir _dir;
    int _lenght;
    int _angle;
};

class Modele : public Commande, public Observable<Commande> {

  protected:

    typedef enum ModelState{init,find_inst,find_arg1,find_endCmd} state;
    state _state;
    Commande _decodedCmd;

  public:

    Modele();
    virtual ~Modele();
  	void commandtoDraw();

    Commande getDecodedCommand();
    void setDecodedCommand(std::string entry);
    Commande commandDecoding(std::string c);

    int FindFirstArgument(std::string::iterator it);
    bool FindInstCommand(std::string inst, std::string entry);
    void FindEndCommand(std::string entry);
};
