/* ----------------------------------------------------------------------------
 |
 |	Nom :			rgbsys.h
 |
 |	Type :			INTERFACE
 |	Sujet :			rgbsys - gestion des "widgets" de l'IHM
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
 *	\file	rgbsys.h
 *	\brief	rgbsys - gestion des "widgets" de l'IHM
 *	\details	l'interface rgbsys.h et son implémentation \e rgbsys.c 
 				se chargent de la création du placement et de la mise à jour
 				des différents élements qui composent l'interface utilisateur
 				de l'application 'rgbsys'.
 */
 
#include <rgbsysdefs.h>
#include <rgbsystypes.h>
#include <rgbmap.h>
#include <widgets/textbox.h>
#include <widgets/colorbox.h>

void createChildren(Display* dpy, int screen, Visual* visual, Window parent ) ;
void setChildrenGeometry(int w, int h ) ;
void drawChildren(int id ) ;
void deleteChildren() ;

void drawColorMap(Display* dpy, Window win, GC gc, int w, int h ) ;
void drawSelectedColor(Display* dpy, Window win, GC gc, int w, int h, int id, boolean selected ) ;
int  getClickedColor(int* id, int w, int h, int xclick, int yclick ) ;

void drawAdditiveSynthesis(Display* dpy, Window win, GC gc, int w, int h, int id ) ;
