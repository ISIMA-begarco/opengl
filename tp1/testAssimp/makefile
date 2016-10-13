################################################################################
#     Copyright (C) 2016 by Rémy Malgouyres                                    # 
#     http://malgouyres.org                                                    # 
#                                                                              # 
# The program is distributed under the terms of the GNU General Public License # 
#                                                                              # 
################################################################################ 

CXXFLAGS = 

all: runDemo

runDemo:
	gcc $(CXXFLAGS) Sample_SimpleOpenGL.c -o runDemo -lSDL2 -lGL -lGLU  -lSDL2_ttf -lglut -lassimp
clean:
	rm -f runDemo
