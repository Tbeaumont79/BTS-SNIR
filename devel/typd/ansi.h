#include <stdio.h>
enum { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE } ;
#define FGCOLOR(V) printf("\x1b[%dm", 30 + (V) )
#define BGCOLOR(V) printf("\x1b[%dm", 40 + (V) )
#define RESET printf("\x1b[0m" )
#define CUU(N) printf("\x1b[%dA",
#define CUD(N)
#define CUF(N)
#define CUB(N)
#define CHA(X)
#define CUP(X,Y)
#define CLRSCR CUP(1,1) ; printf("\x1b[2J")
printf("\x1b[%dB",
printf("\x1b[%dC",
printf("\x1b[%dD",
printf("\x1b[%dG",
printf("\x1b[%d;%dH", Y, X )
// Foreground Color
// Background Color
// Reset attributes
// Cursor Up
// Cursor Down
// Cursor Forward
// Cursor Back
// Cursor Horizontal Absolute
// Cursor Position
// Clear Screen
