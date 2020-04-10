# Environment
CXXFLAGS=`fltk-config --cxxflags` --std=c++11 -g
LDFLAGS=`fltk-config --ldflags`
CXX=`fltk-config --cxx`

#The Apps
TARGETS=gameoflife
all: $(TARGETS)
gameoflife: main.o gameoflife_ui.o grid_widget.o gol_grid.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

#The Ingredients
grid_widget.o: grid_widget.cpp grid_widget.h
gameoflife_ui.o: gameoflife_ui.cxx gameoflife_ui.h
	$(CXX) $(CXXFLAGS) -c gameoflife_ui.cxx -o gameoflife_ui.o
main.o: main.cpp gameoflife_ui.h
gol_grid.o: gol_grid.cpp gol_grid.h

#FLUID ingredient builds
%.h %.cxx: %.fl
	fluid -c $^

# utility
clean:
	rm -f *.o $(TARGETS)
