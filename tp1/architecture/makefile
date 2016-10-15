################################################################################
#     Copyright (C) 2016 by Rémy Malgouyres                                    # 
#     http://malgouyres.org                                                    # 
#                                                                              # 
# The program is distributed under the terms of the GNU General Public License # 
#                                                                              # 
################################################################################ 

CXXFLAGS =  -std=c++11 -Wall -pedantic \
    -pedantic-errors -Wextra -Wcast-align \
    -Wcast-qual  -Wchar-subscripts  -Wcomment -Wconversion \
    -Wdisabled-optimization \
    -Werror -Wformat -Wformat=2 \
    -Wformat-nonliteral -Wformat-security  \
    -Wformat-y2k \
    -Wimport  -Winit-self  -Winline \
    -Winvalid-pch   \
    -Wunsafe-loop-optimizations -Wmissing-braces \
    -Wmissing-field-initializers -Wmissing-format-attribute   \
    -Wmissing-include-dirs -Wmissing-noreturn \
    -Wparentheses  -Wpointer-arith \
    -Wredundant-decls -Wreturn-type \
    -Wsequence-point  -Wshadow -Wsign-compare  -Wstack-protector \
    -Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch  -Wswitch-default \
    -Wswitch-enum -Wtrigraphs  -Wuninitialized \
    -Wunknown-pragmas  -Wunreachable-code -Wunused \
    -Wunused-function  -Wunused-label  -Wunused-parameter \
    -Wunused-value  -Wunused-variable  -Wvariadic-macros \
    -Wvolatile-register-var  -Wwrite-strings -Wfloat-equal \
                #-Waggregate-return \
                -Weffc++

all: runDemo

runDemo: main.cpp frames.hpp ../cameraParams/transform.hpp gui.hpp  modele.hpp camera.cpp vue.hpp mouse.hpp eventsHandling.cpp scene.cpp noeud.cpp vecteur3D.cpp
	g++ $(CXXFLAGS) camera.cpp scene.cpp noeud.cpp vecteur3D.cpp main.cpp -o runDemo -lSDL2 -lGL -lGLU  -lSDL2_ttf -lglut -lassimp
clean:
	rm -f runDemo
