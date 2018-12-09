/* ----------------------------------------------------------------------------
 |
 |	Nom :			textbox.h
 |
 |	Type :			INTERFACE
 |	Sujet :			XLib "widget" de type texte
 |
 |	Version :		2.1
 |	Création :		2001
 |	Mise à jour :	03/10/2014
 + ----------------------------------------------------------------------------
 |  Copyright 2001-2014 A. Menu   <alain.menu@ac-creteil.fr>
 | 
 |  This file is part of "rgbsys project"
 | 
 |  This program is free software ;  you can  redistribute it and/or  modify it
 |  under the terms of the  GNU General Public License as published by the Free
 |  Software Foundation ; either version 2 of the License, or  (at your option)
 |  any later version.
 |
 |  This program is distributed in the hope that it will be useful, but WITHOUT
 |  ANY WARRANTY ; without even the  implied  warranty  of  MERCHANTABILITY  or
 |  FITNESS FOR  A PARTICULAR PURPOSE. See the  GNU General Public License  for
 |  more details < http://www.gnu.org/licenses/gpl.txt >.
 + ------------------------------------------------------------------------- */

/*!
 *	\file	textbox.h
 *	\brief	XLib "widget" de type zone de texte
 *	\details	l'interface textbox.h et son implémentation \e textbox.c 
 				proposent un ensemble de ressources de gestion de labels 
 				sous forme de fenêtres (Window) XLib.
 */
 
#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../rgbsystypes.h"

#define	MAXNUMOFTEXTBOX	  20	/*!< nombre max. de widgets TextBox */
#define MAXTEXTLENGTH	  80	/*!< taille max. du texte d'un TextBox */

#define ALIGN_LEFT		0x01	/*!< contrainte d'alignement à gauche */
#define	ALIGN_RIGHT		0x02	/*!< contrainte d'alignement à droite */
#define	ALIGN_HCENTER	0x04	/*!< contrainte d'alignement centrage horizontal */
#define	ALIGN_TOP		0x10	/*!< contrainte d'alignement en haut */
#define ALIGN_BOTTOM	0x20	/*!< contrainte d'alignement centrage vertical */
#define	ALIGN_VCENTER	0x40	/*!< contrainte d'alignement en bas */
#define	ALIGN_CENTERED	( ALIGN_HCENTER | ALIGN_VCENTER )	/*!< contrainte d'alignement centré */

int  createTextBox(Display* dpy, Window parent, const char* text ) ;
void setTextBoxDefaultFont(const char* family, int size ) ;
void setTextBoxDefaultColors(lword foreground, lword background ) ;
void setTextBoxGeometry(int id, int x, int y, int w, int h ) ;
void setTextBoxColors(int id, lword foreground, lword background ) ;
void setTextBoxBorder(int id, int width ) ;
void setTextBoxText(int id, const char* text ) ;
void setTextBoxFont(int id, const char* family, int size ) ;
void setTextBoxAlignment(int id, byte alignment ) ;
int  getTextBoxTextWidth(int id ) ;
void drawTextBox(int id ) ;
void deleteAllTextBox() ;

#endif
