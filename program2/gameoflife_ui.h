// generated by Fast Light User Interface Designer (fluid) version 1.0305

#ifndef gameoflife_ui_h
#define gameoflife_ui_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Group.H>
#include "grid_widget.h"
#include <FL/Fl_Button.H>

class Gameoflife_UI {
public:
  Gameoflife_UI();
private:
  Fl_Double_Window *_window;
  Grid_Widget *_gol_grid;
  Fl_Button *_go_button;
  Fl_Button *_clear_button;
  Fl_Button *_random_button;
  Fl_Button *_save_button;
  Fl_Button *_load_button;
public:
  void show();
  Fl_Button* go_button();
  Fl_Button* clear_button();
  Fl_Button* random_button();
  Fl_Button* save_button();
  Fl_Button* load_button();
  Grid_Widget * gol_grid();
};
#endif
