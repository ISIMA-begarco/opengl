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
ARCH = main.o camera.o computedScene.o eventsHandling.o frames.o gui.o modele.o mouse.o  scene.o noeud.o vecteur3D.o vue.o
OBJ = $(ARCH)
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

$(APP): $(OBJ)
	$(CXX) $^ -o ./$@ $(CXXFLAGS) $(LXX)

$(OBJ): $(OBJ:.o=.cpp)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f $(APP); rm -rf *.bak; rm -rf *.o
