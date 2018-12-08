# Makefile for rgbsys project version 2.1

# section 1: project data ------------------------------------------------------------
SRC = main.c rgbsys.c rgbmap.c widgets/textbox.c widgets/colorbox.c
INC = rgbsysdefs.h rgbsystypes.h rgbsys.h rgbmap.h widgets/textbox.h widgets/colorbox.h
VERSION	= 2.1
DEFINES	= -DLINUX
XINCDIR	= /usr/include
XLIBDIR	= /usr/lib/x86_64-linux-gnu
TARGET	= rgbsys
DESTDIR = /usr/local/bin
COPYFILE = cp -f
# section 2: compiler configuration --------------------------------------------------

CC		= gcc
CFLAGS	= -Wall -O $(DEFINES)
INCDIR	= -I. -I$(XINCDIR)
LIBS	= -L$(XLIBDIR) -lX11 -lXext

# section 3: makefile data -----------------------------------------------------------
DELFILE = rm -rf
MAKEDIR = mkdir
OBJSDIR = .objs
OBJS = $(addprefix $(OBJSDIR)/, $(notdir $(SRC:.c=.o) ) )
# section 4: main target -------------------------------------------------------------
$(TARGET): main.o rgbsys.o rgbmap.o textbox.o colorbox.o 
	@echo "> édition de liens pour  ..."
	$(CC) -o main.o rgbsys.o rgbmap.o textbox.o colorbox.o $(LIBS)

$(OBJSDIR)/$main.o: main.c rgbsys.h rgbsysdefs.h rgbsystypes.h rgbmap.h widgets/textbox.h widgets/colorbox.h
	@echo "> compilation de main.c..."
	$(CC) $(CFLAGS) $(INCDIR) -o $(TARGET) -c main.c

rgbsys.o: rgbsys.c rgbsys.h rgbsysdefs.h rgbsystypes.h rgbmap.h widgets/textbox.h widgets/colorbox.h
	@echo "> compilation de rgbsys.c..."
	$(CC) $(CFLAGS) $(INCDIR) -o rgbsys.o -c rgbsys.c

rgbmap.o: rgbmap.c rgbmap.h rgbsystypes.h
	@echo "> compilation de rgb.c..."
	$(CC) $(CFLAGS) $(INCDIR) -o rgbmap.o -c rgbmap.c

textbox.o: widgets/textbox.c widgets/textbox.h rgbsystypes.h
	@echo "> compilation de textbox.c..."
	$(CC) $(CFLAGS) $(INCDIR) -o textbox.o -c widgets/textbox.c

colorbox.o: widgets/colorbox.c widgets/colorbox.h rgbsystypes.h
	@echo "> compilation de colorbox.c..."
	$(CC) $(CFLAGS) $(INCDIR) -o colorbox.o -c widgets/colorbox.c

# section 5: other targets -----------------------------------------------------------
.PHONY: all install clean mkobjsdir
mkobjsdir:
	@if ! [ -e "$(OBJSDIR)" ]; then $(MAKEDIR) $(OBJSDIR) ; fi

all:
	@$(mkobjsdir) $(TARGET)
install: 
	@echo "> installation de rgbsys."
	@$(COPYFILE) $(TARGET) $(DESTDIR)

clean: 
	@echo "> suppression du programme"
	@$(DELFILE) *.o
	@$(DELFILE) $(TARGET)
	@$(DELFILE) $(DESTDIR)
	@$(DELFILE) $(OBJSDIR)
