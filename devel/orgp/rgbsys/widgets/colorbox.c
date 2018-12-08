/* ----------------------------------------------------------------------------
 |
 |	Nom :			colorbox.c
 |
 |	Type :			UTILITAIRE
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

#include "colorbox.h"

/*!
 *	\private
 */
 
typedef struct {
	Display*	  dpy ;
	Window		  parent ;
	Window		  win ;
	int	          x, y ;	// position
	unsigned int  w, h ;	// dimensions
	unsigned int  wbo ;		// border width
	unsigned long cbo ;		// border color
	unsigned long cbg ;		// background color
} ColorBox ;

ColorBox*	colorBox[ MAXNUMOFCOLORBOX ] ;
static int  colorBoxNum = 0 ;

/*!
 *	\fn		int  createColorBox(Display* dpy, Window parent )
 *	\brief	création d'un widget de type zone colorée
 *	\param	dpy	serveur d'affichage
 *	\param	parent	fenêtre mère
 *	\return	identifiant \e int du nouveau widget, ou -1 en cas d'échec
 */
 
int  createColorBox(Display* dpy, Window parent )
{
	if ( colorBoxNum >= MAXNUMOFCOLORBOX ) {
#ifdef VERBOSE
		fprintf(stderr, "unable to create new ColorBox widget" ) ;
#endif
		return -1 ;
	}

	ColorBox* p = (ColorBox*)malloc( sizeof( ColorBox ) ) ;
	colorBox[ colorBoxNum ] = p ;
	
	p->dpy = dpy ;
	p->parent = parent ;
	p->wbo = 1 ;
	p->x = 1 ;
	p->y = 1 ;
	p->w = 10 ;
	p->h = 10 ;
	p->cbo = BlackPixel(dpy, DefaultScreen(dpy ) ) ;
	p->cbg = WhitePixel(dpy, DefaultScreen(dpy ) ) ;

	p->win = XCreateSimpleWindow(p->dpy, p->parent, p->x, p->y, p->w, p->h, p->wbo, p->cbo, p->cbg ) ;
	XMapWindow(p->dpy, p->win ) ;

	return colorBoxNum++ ;
}

/*!
 *	\fn		void setColorBoxGeometry(int id, int x, int y, int w, int h )
 *	\brief	fixe la géométrie (position et dimensions) du widget d'identifiant \a id
 *			relativement à son parent spécifié lors de la création
 *	\param	id	identifiant du widget concerné
 *	\param	x position horizontale
 *	\param	y position verticale
 *	\param	w largeur
 *	\param	h hauteur
 */
 
void setColorBoxGeometry(int id, int x, int y, int w, int h )
{
	if ( id >= colorBoxNum )	return ;
	
	ColorBox* p = colorBox[id] ;
	p->x = x ;
	p->y = y ;
	p->w = w ;
	p->h = h ;
}

/*!
 *	\fn		void setColorBoxBackground(int id, unsigned long background )
 *	\brief	fixe la couleur de fond du widget (blanc par défaut)
 *	\param	id	identifiant du widget concerné
 *	\param	background couleur du fond
 */
 
void setColorBoxBackground(int id, lword background )
{
	if ( id >= colorBoxNum )	return ;
	colorBox[id]->cbg = background ;
}

/*!
 *	\fn		void setColorBoxBorder(int id, int width, lword color )
 *	\brief	spécifie la couleur (noire par défaut) et l'épaisseur de trait du cadre
 			(1 par défaut)
 *	\param	id	identifiant du widget concerné
 *	\param	width	épaisseur de trait
 *	\param	color	couleur du trait
 */
 
void setColorBoxBorder(int id, int width, lword color )
{
	if ( id >= colorBoxNum )	return ;
	colorBox[id]->wbo = width ;
	colorBox[id]->cbo = color ;
}

/*!
 *	\fn		void drawColorBox(int id )
 *	\brief	dessine le widget
 *	\param	id	identifiant du widget concerné
 */
 
void drawColorBox(int id )
{
	if ( id >= colorBoxNum )	return ;
	
	ColorBox* p = colorBox[id] ;
	XMoveWindow(p->dpy, p->win, p->x, p->y ) ;
	XResizeWindow(p->dpy, p->win, p->w, p->h ) ;
	XSetWindowBackground(p->dpy, p->win, p->cbg ) ;
	XSetWindowBorder(p->dpy, p->win, p->cbo ) ;
	XSetWindowBorderWidth(p->dpy, p->win, p->wbo ) ;
	XClearWindow(p->dpy, p->win ) ;
}

/*!
 *	\fn		void deleteAllColorBox()
 *	\brief	détruit tous les widgets précédement créés par createColorBox()
 */
 
void deleteAllColorBox()
{
	int i ;
	for ( i = 0 ; i < colorBoxNum ; ++i )	free( colorBox[i] ) ;
}
