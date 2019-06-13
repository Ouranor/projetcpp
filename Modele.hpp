#pragma once

#include "Commande.hpp"
#include "Observable.hpp"
#include <string>


class Modele : public Observable<Commande> {

  protected:

    typedef enum ModelState{init,find_inst,find_arg1,find_arg2,find_arg3,find_endCmd,wrong_cmd} state;
    state _state;
    Commande _decodedCmd;

  public:

    Modele();
    virtual ~Modele();
  	void commandtoDraw();

    Commande getDecodedCommand();
    void setDecodedCommand(std::string entry);
    Commande commandDecoding(std::string c);

    state getModelState() const;
    void setModelState(state myState);
    bool stateIsWrongCmd();

    int FindFirstArgument(std::string::iterator it);
    int FindSecondArgument(std::string::iterator it);
    int FindThirdArgument(std::string::iterator it);
//std::string FindCircleArgument(std::string::iterator);
    bool FindInstCommand(std::string inst, std::string entry);
    void FindEndCommand(std::string entry);
};
