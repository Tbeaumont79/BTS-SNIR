/* ----------------------------------------------------------------------------
 |
 |	Nom :			rgbmap.h
 |
 |	Type :			INTERFACE
 |	Sujet :			rgbsys - gestion de la palette de couleurs RGB
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
 *	\file	rgbmap.h
 *	\brief	gestion d'une palette de couleurs RGB
 *	\details	l'interface rgb.h et son implémentation \e rgb.c 
 				proposent un ensemble de ressources de gestion d'une palette de
 				couleurs chargées à partir d'un fichier de type Unix rgb.txt.
 */
 
#ifndef RGBMAP_H
#define RGBMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <rgbsystypes.h>

#define MAXNUMOFRGB	1024	/*!< nombre max. d'entrées RGB */

int loadRgbDataFromFile(const char* path, lword* mask ) ;
int numberOfRgb() ;
byte rgbColor(PrimaryColor pc, int id ) ;
lword rgbMask(PrimaryColor pc, int id ) ;
lword rgbValue(int id ) ;
const char* rgbName(int id ) ;
void freeColorMap() ;

#endif
