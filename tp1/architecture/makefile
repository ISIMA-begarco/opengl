################################################################################
#     Copyright (C) 2016 by Rémy Malgouyres                                    # 
#     http://malgouyres.org                                                    # 
#                                                                              # 
# The program is distributed under the terms of the GNU General Public License # 
#                                                                              # 
################################################################################ 

# definition des cibles particulieres
.PHONY: clean

# definition des variables
CXX = g++
LXX = -lSDL2 -lGL -lGLU  -lSDL2_ttf -lglut -lassimp
DXX = -pg
OBJ = main.o camera.o modele.o gui.o vue.o frames.o scene.o noeud.o vecteur3D.o abstractCamera.o mouse.o computedScene.o
APP = runDemo

CXXFLAGS =  -std=c++11 -Wall -pedantic -O2 \
    -pedantic-errors -Wextra -Wcast-align \
    -Wcast-qual  -Wchar-subscripts  -Wcomment -Wconversion \
    -Wdisabled-optimization \
    -Werror -Wformat -Wformat=2 \
    -Wformat-nonliteral -Wformat-security  \
    -Wformat-y2k \
    -Wimport  -Winit-self \
    -Winvalid-pch   \
    -Wunsafe-loop-optimizations -Wmissing-braces \
    -Wmissing-field-initializers -Wmissing-format-attribute   \
    -Wmissing-include-dirs -Wmissing-noreturn \
    -Wparentheses  -Wpointer-arith \
    -Wredundant-decls -Wreturn-type \
    -Wsequence-point  -Wshadow -Wsign-compare  -Wstack-protector \
    -Wswitch  -Wswitch-default \
    -Wswitch-enum -Wtrigraphs  -Wuninitialized \
    -Wunknown-pragmas  -Wunreachable-code -Wunused \
    -Wunused-function  -Wunused-label  -Wunused-parameter \
    -Wunused-value  -Wunused-variable  -Wvariadic-macros \
    -Wvolatile-register-var  -Wwrite-strings -Wfloat-equal \
   #-Waggregate-return -Winline -Wstrict-aliasing -Wstrict-aliasing=2 -Weffc++
                

all: runDemo

$(APP) : $(OBJ)
	$(CXX) $^ -o ./$@ $(CXXFLAGS) $(LXX)

main.o : main.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

abstractCamera.o : abstractCamera.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

gui.o : gui.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

vue.o : vue.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

camera.o : camera.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

scene.o : scene.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

computedScene.o : computedScene.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

noeud.o : noeud.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

vecteur3D.o : vecteur3D.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

mouse.o : mouse.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

frames.o : frames.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

modele.o : modele.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f $(APP); rm -rf *.bak; rm -rf *.o
