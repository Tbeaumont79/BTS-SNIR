/* asciiart.c */
#include <stdio.h>
int main() {
    printf("\x1b[H\x1b[2J\n\x1b[8G\x1b[43;33m\\|||/\n") ;
    printf("\x1b[8G\x1b[43;31m(\x1b[43;34mo o\x1b[43;31m)\n\x1b[0m") ;
    printf("+~~\x1b[43;31mooO\x1b[0m~~\x1b[43;31m(_)\x1b[0m~~~~~~~~+\n") ;
    printf("\x1b[43m|[0m\x1b[43m[18C|[0m\n[43m|[0m\x1b[4m") ;
    printf("\x1b[43mA S C I I  A R T[0m") ;
    printf("\x1b[43m |\n|[0m\x1b[43m;18C|\n[0m") ;
    printf("\x1b[43m +~~~~~~~~~~~~~[0m\x1b[43;31mOoo\x1b[43m~~+\n[0m") ;
    printf("\x1b[7G\x1b[43;32m|__|__|\n") ;
    printf("\x1b[8G\x1b[43;31m|| ||\n") ;
    printf("\x1b[7G\x1b[43;35mooO Ooo\n\x1b[0m\x1b[2B") ;
    return (0) ; 
}
