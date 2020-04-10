// game of life main
#include <FL/Fl.H>
#include <string>
#include "gol_grid.h"
#include "gameoflife_ui.h"
#include "grid_widget.h"
#include "gol_grid.h"

using namespace std;

struct Gol_Grid_Controller {
    Grid_Widget *grid;   //displayed gol grid
    Gol_Grid *gol;  //backend model
};

void update_gol_grid(Gol_Grid_Controller *dfc);

void go_button_callback(Fl_Button *button, Gol_Grid_Controller *dfc);

void clear_button_callback(Fl_Button *button, Gol_Grid_Controller *dfc);

void random_button_callback(Fl_Button *button, Gol_Grid_Controller *dfc);

void save_button_callback(Fl_Button *button, Gol_Grid_Controller *dfc);

void load_button_callback(Fl_Button *button, Gol_Grid_Controller *dfc);

void grid_callback(Grid_Widget *widget, Fl_Color *cell)
{
    *cell = FL_GREEN;
    widget->redraw();
}

int main()
{
    Gameoflife_UI *ui = new Gameoflife_UI;

    Gol_Grid_Controller dfc;
    dfc.grid = ui->gol_grid();
    dfc.gol = new Gol_Grid();

    //set up the button callback
    ui->go_button()->callback((Fl_Callback*) go_button_callback, &dfc);

    //set up clear button
    ui->clear_button()->callback((Fl_Callback*) clear_button_callback, &dfc);

    //set up random button
    ui->random_button()->callback((Fl_Callback*) random_button_callback, &dfc);

    //set up save button
    ui->save_button()->callback((Fl_Callback*) save_button_callback, &dfc);

    //set up load button
    ui->load_button()->callback((Fl_Callback*) load_button_callback, &dfc);

    dfc.grid->callback((Fl_Callback*) grid_callback);

    ui->show();

    //run the event loop
    return Fl::run();



}

void reset_grid(Grid_Widget *grid, Fl_Color color)
{
    const Fl_Color off = FL_BLACK;
    

    
    
    
    

    //draw the top and the bottom
    for(int x=0, y=0; x<=grid->cols(), y<=grid->rows(); x++, y++)
    {
        grid->cell(x,y) = off;
    }

    
}

void update_gol_grid(Gol_Grid_Controller *dfc)
{
    const Fl_Color off = FL_BLACK;

    
    //update the gol to the next frame
    dfc->gol->next();

    //repeat our timeout
    Fl::repeat_timeout(0.75, (Fl_Timeout_Handler) update_gol_grid, dfc);
}

void go_button_callback(Fl_Button *button, Gol_Grid_Controller *dfc)
{
    //get the label as a c++ string
    string label = button->label();    

    //ok, we're going to go
    if(label == "Go") {
        //change the button to "stop"
        button->label("Stop");

        //start the timer ticking
        Fl::add_timeout(0.75,(Fl_Timeout_Handler) update_gol_grid, dfc);
    } else {
        //change the button to "go"
        button->label("Go");

        //stop the timer from ticking
        Fl::remove_timeout((Fl_Timeout_Handler) update_gol_grid, dfc);
    }
}

//respond to random button click
void random_button_callback(Fl_Button *button, Gol_Grid_Controller *dfc)
{

}

//repond to clear button click
void clear_button_callback(Fl_Button *button, Gol_Grid_Controller *dfc)
{
    
   reset_grid(dfc->grid, 0);
}

//respond to save button click
void save_button_callback(Fl_Button *button, Gol_Grid_Controller *dfc)
{

}

//repond to load button click
void load_button_callback(Fl_Button *button, Gol_Grid_Controller *dfc)
{

}