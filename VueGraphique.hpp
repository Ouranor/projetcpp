#pragma once

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/entry.h>

#include "Observateur.hpp"


class VueG : public Gtk::Window, public Observateur<double> {

  private:

  public:
    VueG();
    virtual ~VueG();

};
