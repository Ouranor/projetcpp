#pragma once

template<typename T>
class Observateur {
  public:
    virtual void update(T info) = 0;
};
