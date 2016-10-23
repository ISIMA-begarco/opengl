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
OBJ = main.o modele.o gui.o vue.o frames.o scene.o noeud.o vecteur3D.o abstractCamera.o lookAtCamera.o transfoCamera.o mouse.o computedScene.o maillage.o
BUILD = ./obj
APP = runDemo

CXXFLAGS =  -std=c++11 -Wall -pedantic -O2 \
    -pedantic-errors -Wextra -Wcast-align \
    -Wcast-qual  -Wchar-subscripts  -Wcomment \
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
   #-Waggregate-return -Winline -Wstrict-aliasing -Wstrict-aliasing=2 -Weffc++  -Wconversion


all: $(APP)

$(APP) : $(OBJ)
	cd $(BUILD); $(CXX) $^ -o ../$@ $(CXXFLAGS) $(LXX)

%.o : %.cpp
	$(CXX) -c $< -o $(BUILD)/$@ $(CXXFLAGS)

run :
	./$(APP)

clean:
	rm -rf $(APP) $(BUILD)/*
