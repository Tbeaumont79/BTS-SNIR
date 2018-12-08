/* ----------------------------------------------------------------------------
 |
 |	Nom :			rgbsystypes.h
 |
 |	Type :			DEFINITIONS
 |	Sujet :			rgbsys - frontal Unix rgb.txt ( mode TrueColor )
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
 *	\file	rgbsystypes.h
 *	\brief	types utilisateur
 */
 
#ifndef RGBSYSTYPES_H
#define RGBSYSTYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } 	boolean ;	/*! \enum boolean type booléen */
typedef unsigned char			byte ;		/*!< type entier non signé sur 8 bits */
typedef unsigned short			word ;		/*!< type entier non signé sur 16 bits */
typedef unsigned long			lword ;		/*!< type entier non signé sur 32 bits */

typedef enum { Red, Green, Blue }	PrimaryColor ;	/*! \enum PrimaryColor couleurs primaires */

#endif
