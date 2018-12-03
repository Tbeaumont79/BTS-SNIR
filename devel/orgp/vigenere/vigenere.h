/* ---------------------------------------------------------------------------
 *  Nom         :   vigenere.h
 *  Type        :   INTERFACE
 *  Sujet       :   chiffrage polyalphabétique de Vigenère 
 *
 *  Auteur      :   Beaumont Thibault
 *  Version     :   0.1
 *  Création    :   26/11/2018
 *  Dern. màj   :   26/11/2018
 *
 *  
 * ---------------------------------------------------------------------------
*/

#ifndef VIGENERE_H

#define VIGENERE_H
#define MINKEYSIZE 5
#define MAXKEYSIZE 1000
#define DEFAULTKEYSIZE 10
#define VERSION "0.1"
#define AUTHOR "Beaumont Thibault"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {ENCODING, DECODING} VigenereMode;
VigenereMode mode;


const char *vigenereKey(int length);
char *vigenereProcess(VigenereMode mode, char *argv);
#endif
