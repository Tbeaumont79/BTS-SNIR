# Makefile dedicated to C/C++ XamGraph applications
# -------------------------------------------------------------------
# XamGraph version sdl2-0.27 - (c)2007-2017 Alain Menu
# -------------------------------------------------------------------

# PARAMETRAGE :
# -------------
# COMPILER	type de compilateur = gcc | g++
# TARGET	nom de l'exécutable à générer
# VERSION	version courante de l'application
# XAMRELDIR	chemin relatif vers le répertoire 'xamgraph'
# SRC		liste des fichiers source
# INC		liste des fichiers entête
# DEFINES	définition de constantes (-D...)
# AUX		liste d'entrées supplémentaires à inclure à l'archive
# DESTDIR	répertoire de destination pour cible 'install'

COMPILER	= gcc
TARGET		= othello
VERSION		= 0.41
XAMRELDIR	= ../../src
SRC			= main.c othello.c ia.c eval.c
INC			= othdef.h othello.h ia.h eval.h
DEFINES     = -DXAM_DEBUG
AUX			=
DESTDIR		= $(HOME)/bin

#WITH_XAMPNM = 1

# -------------------------------------------------------------------

AUX	   	   := $(AUX) Makefile xamdefaultfont.ttf xamdefaultfont.c

INCDIR		= -I. -I$(XAMRELDIR)

HOST=$(shell uname)

ifeq ($(HOST),Darwin)
	DEFINES += -DXAMGRAPH_SDL2
	INCDIR += -I/Library/Frameworks/SDL2.framework/Headers
	INCDIR += -I/Library/Frameworks/SDL2_image.framework/Headers
	INCDIR += -I/Library/Frameworks/SDL2_ttf.framework/Headers
	LIBS    = -F/Library/Frameworks/
	LIBS   += -framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework Cocoa
endif

ifeq ($(HOST),Linux)
	INCDIR += -I/usr/include/SDL
	DEFINES += -D_GNU_SOURCE=1 -D_REENTRANT
	LIBS	= -lm -lSDLmain -lSDL -lSDL_image -lSDL_ttf
endif

CC         := $(COMPILER)

ifeq ($(CC),gcc)
	EXT	   := .c
	SRC	   := $(SRC) $(XAMRELDIR)/xamgraph.c $(XAMRELDIR)/xamgraphfont.c $(XAMRELDIR)/xamgraphdraw.c
	INC	   := $(INC) $(XAMRELDIR)/xamgraph.h $(XAMRELDIR)/xamgraphdef.h $(XAMRELDIR)/xamgraphlib.h
else
	DEFINES += -DXAMGRAPHCLASS
	EXT	   := .cpp
	SRC	   := $(SRC) $(XAMRELDIR)/xamgraph.cpp $(XAMRELDIR)/xamgraphfont.cpp $(XAMRELDIR)/xamgraphdraw.cpp
	INC	   := $(INC) $(XAMRELDIR)/xamgraph.h $(XAMRELDIR)/xamgraphdef.h $(XAMRELDIR)/xamgraphclass.h
	AUX	   := $(AUX) $(XAMRELDIR)/xamgraph.c
endif

ifdef WITH_XAMPNM
	XAMPNMDIR = $(XAMRELDIR)/../tools/xampnm
	INCDIR	+= -I$(XAMPNMDIR)
	SRC += $(XAMPNMDIR)/xampnm.cpp
	INc += $(XAMPNMDIR)/xampnm.h
endif

CFLAGS		= -Wall -O2 $(DEFINES)
CFLAGSDEBUG	= -g $(DEFINES)

COPYFILE	= cp -f
DELFILE		= rm -rf
MAKEDIR		= mkdir
ZIP			= tar cvzf
ARCHIVE		= $(TARGET)_src_$(VERSION).tar.gz
DEPSDIR		= .deps

OBJSDIR		= .objs
OBJS		= $(addprefix $(OBJSDIR)/, $(notdir $(SRC:$(EXT)=.o) ) )

FNLIST		= $(notdir $(SRC))
DEPS		= $(addprefix $(DEPSDIR)/, $(FNLIST:$(EXT)=.d) )

.PHONY: all debug sdllink dirdeps dirobjs clean install dist locv

# -------------------------------------------------------------------

all: sdllink dirdeps dirobjs $(TARGET)

debug: CFLAGS = $(CFLAGSDEBUG)

debug: all

# -------------------------------------------------------------------
# Mac OS SDL2 headers symbolic link

sdllink:
ifeq ($(HOST),Darwin)
	@if ! [ -e "$(XAMRELDIR)/SDL2" ] ; then \
		echo "> ajout lien symbolique vers headers SDL..." ; \
		ln -s /Library/Frameworks/SDL2.framework/Headers $(XAMRELDIR)/SDL2 ; \
	fi
endif

# -------------------------------------------------------------------
# XamPNM / compiler compatibility

ifdef WITH_XAMPNM
ifeq ($(CC),gcc)
	@echo "WITH_XAMPNM incompatible with 'gcc' compiler!"
endif
endif

# -------------------------------------------------------------------

dirdeps:
	@if ! [ -e "$(DEPSDIR)" ] ; then $(MAKEDIR) $(DEPSDIR) ; fi

dirobjs:
	@if ! [ -e "$(OBJSDIR)" ] ; then $(MAKEDIR) $(OBJSDIR) ; fi

# -------------------------------------------------------------------

$(TARGET): $(OBJS)
	@echo "> édition de liens..."
	$(CC) -o $(TARGET) $^ $(LIBS)

$(OBJSDIR)/%.o: %$(EXT)
	@echo "> compilation de $<..."
	@$(CC) -MM -MF $(DEPSDIR)/$(notdir $(subst .o,.d,$@)) -MP -MT $@ $(CFLAGS) $(INCDIR) $<
	$(CC) $(CFLAGS) -o $(OBJSDIR)/$(notdir $(subst $(EXT),.o,$@)) -c $< $(INCDIR)

$(OBJSDIR)/%.o: $(XAMRELDIR)/%$(EXT)
	@echo "> compilation de $<..."
	@$(CC) -MM -MF $(DEPSDIR)/$(notdir $(subst .o,.d,$@)) -MP -MT $@ $(CFLAGS) $(INCDIR) $<
	$(CC) $(CFLAGS) -o $(OBJSDIR)/$(notdir $(subst $(EXT),.o,$@)) -c $< $(INCDIR)

ifdef WITH_XAMPNM
$(OBJSDIR)/%.o: $(XAMPNMDIR)/%$(EXT)
	@echo "> compilation de $<..."
	@$(CC) -MM -MF $(DEPSDIR)/$(notdir $(subst .o,.d,$@)) -MP -MT $@ $(CFLAGS) $(INCDIR) $<
	$(CC) $(CFLAGS) -o $(OBJSDIR)/$(notdir $(subst $(EXT),.o,$@)) -c $< $(INCDIR)
endif

-include $(DEPS)

# -------------------------------------------------------------------

clean:
	@$(DELFILE) $(DEPSDIR)
	@$(DELFILE) $(OBJSDIR)
	@$(DELFILE) $(TARGET)
	@$(DELFILE) $(DESTDIR)/$(TARGET)

install:
	@echo "> copie de $(TARGET) vers $(DESTDIR)..."
	@$(COPYFILE) $(TARGET) $(DESTDIR)

dist:
	@echo "> création de l'archive $(ARCHIVE)..."
	@$(ZIP) $(ARCHIVE) $(SRC) $(INC) $(AUX)

locv:
	@echo "cc   = $(CC)"
	@echo "ext  = $(EXT)"
	@echo "inc  = $(INC)"
	@echo "src  = $(SRC)"
	@echo "objs = $(OBJS)"
