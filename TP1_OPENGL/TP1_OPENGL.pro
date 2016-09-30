TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += -lSDL2 -lGL -lGLU  -lSDL2_ttf -lglut

SOURCES += main.cpp \
    eventsHandling.cpp \
    cameraParams/camera.cpp

HEADERS += \
    vue.hpp \
    frames.hpp \
    gui.hpp \
    modele.hpp \
    mouse.hpp \
    cameraParams/camera.hpp \
    cameraParams/transform.hpp \
    sourceShading/light.hpp \
    textureImage/bitmap.hpp

OTHER_FILES += \
    makefile \
    fichiers3DS/Audi_tt.3ds \
    fichiers3DS/budda.3ds \
    fichiers3DS/camel.3ds \
    fichiers3DS/greek_sculpture.3ds \
    fichiers3DS/ionic_temple.3ds \
    fichiers3DS/main.3ds \
    fichiers3DS/mosque.3ds \
    fichiers3DS/stanfordBunny.3ds \
    fichiers3DS/stanfordDragon.3ds \
    fichiers3DS/Audi_tt.thanks \
    fichiers3DS/budda.thanks \
    fichiers3DS/camel.thanks \
    fichiers3DS/greek_sculpture.thanks \
    fichiers3DS/ionic_temple.thanks \
    fichiers3DS/main.thanks \
    fichiers3DS/mosque.thanks

