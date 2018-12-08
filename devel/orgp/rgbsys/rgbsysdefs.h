/* ----------------------------------------------------------------------------
 |
 |	Nom :			rgbsysdefs.h
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
 *	\file	rgbsysdefs.h
 *	\private
 */
 
/*
				TAB0	TAB1		  TAB2	  TAB3	  TAB4  TAB5   TAB6	 TAB7
				  |		 |				|		|	    |	  |	    |	  |
				+-----------------------------------------------------------+
				| mode : TrueColor - depth : 24     						|
		-------	|										+-----+	    +-----+	|
   HTEXTLINE	| R mask : $FF0000		R value : 255	|	  |	    |	  |	|
		-------	|										+-----+	    |	  |	|
				| G mask : $00FF00		G value :   0	|	  |	    |	  |	|
				|										+-----+	    |	  |	|
				| B mask : $0000FF		B value :	0	|	  |	    |	  |	|
				|										+-----+	    +-----+	|
				| Name   : [ 193 ] "red"							#FF0000	|
				+-----------------------------------------------------------+
				|															|
				|<--------------------- CELLPERLINE ----------------------->|
				.															.
				+-----------------------------------------------------------+
*/

#ifndef RGBSYSDEFS_H
#define RGBSYSDEFS_H

#define DEFAULTDATAFILE	"rgb.txt"

#define	DEFAULTWIDTH	730		// dimensions par défaut de la fenêtre
#define	DEFAULTHEIGHT	650

#define	HTEXTLINE		  7		// proportions en %
#define	TAB0			  0
#define	TAB1			 15
#define	TAB2			 30
#define	TAB3			 45
#define	TAB4			 55
#define	TAB5			 65
#define	TAB6			 85
#define	TAB7			 99

#define	MARGIN			 10		// marge en pixels

#define	CELLPERLINE		 26		// nombre de cellules par ligne

#if defined(DARWIN)
	#define	KEY_ESC		0x3D	// codes géographiques clavier
	#define KEY_LEFT	0x83
	#define KEY_RIGHT	0x84
	#define	KEY_UP		0x86
	#define KEY_DOWN	0x85
#elif defined(LINUX)
	#define	KEY_ESC		0x09
	#define KEY_LEFT	0x71
	#define KEY_RIGHT	0x72
	#define	KEY_UP		0x6F
	#define KEY_DOWN	0x74
#else
	#error "Unsupported OS (LINUX or DARWIN define expected)"
#endif

#endif
