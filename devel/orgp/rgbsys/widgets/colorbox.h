/* ----------------------------------------------------------------------------
 |
 |	Nom :			colorbox.h
 |
 |	Type :			INTERFACE
 |	Sujet :			XLib "widget" de type zone colorée
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
 *	\file	colorbox.h
 *	\brief	XLib "widget" de type zone colorée
 *	\details	l'interface colorbox.h et son implémentation \e colorbox.c 
 				proposent un ensemble de ressources de gestion de surfaces 
 				colorées sous forme de fenêtres (Window) XLib.
 */
 
#ifndef COLORBOX_H
#define COLORBOX_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <rgbsystypes.h>

#define	MAXNUMOFCOLORBOX	10	/*!< nombre max. de widgets ColorBox */

int  createColorBox(Display* dpy, Window parent ) ;
void setColorBoxGeometry(int id, int x, int y, int w, int h ) ;
void setColorBoxBackground(int id, lword background ) ;
void setColorBoxBorder(int id, int width, lword color ) ;
void drawColorBox(int id ) ;
void deleteAllColorBox() ;

#endif
