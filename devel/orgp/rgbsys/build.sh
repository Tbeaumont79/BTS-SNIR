#!/bin/bash

XINCDIR="/usr/include"
XLIBDIR="/usr/lib/x86_64-linux-gnu"
LIBS="-lX11 -lXext"

CFLAGS="-Wall -O"
DEFINES="-DLINUX -DVERBOSE"

SRC="main.c rgbsys.c rgbmap.c widgets/textbox.c widgets/colorbox.c"
gcc $CFLAGS $DEFINES -I. -I$XINCDIR -o rgbsys $SRC -L$XLIBDIR $LIBS
