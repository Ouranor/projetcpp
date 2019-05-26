#pragma once
#include "Observateur.hpp"
#include <list>


template<typename T>
class Observable {
  private:
    std::list<Observateur<T> *> list_observateurs;
  public:
    void notifyObservateurs(T info) {
      for (auto obs : this->list_observateurs) obs->update(info);
    }
    void addObservateur(Observateur<T> * obs) {
      this->list_observateurs.push_back(obs);
    }
};
