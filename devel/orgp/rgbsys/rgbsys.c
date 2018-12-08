/* ----------------------------------------------------------------------------
 |
 |	Nom :			rgbsys.c
 |
 |	Type :			DEPENDANCE
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

#include <rgbsys.h>

int dBox[2] ;	// mode, copyright widgets
int rBox[5] ;	// "red" widgets
int gBox[5] ;	// "green" widgets
int bBox[5] ;	// "blue" widgets
int cBox[5] ;	// "rgb" widgets

char*	vclass[] = {	"StaticGray",	"GrayScale",
						"StaticColor",	"PseudoColor",
						"TrueColor",	"DirectColor" } ;

/*!
 *	\fn		void createChildren(Display* dpy, int screen, Visual* visual, Window parent )
 *	\brief	création des "widgets" TextBox et ColorBox de l'IHM
 *	\param	dpy		serveur d'affichage utilisé
 *	\param	screen	écran du serveur d'affichage
 *	\param	visual	caractéristiques matérielles de l'affichage
 *	\param	parent	fenêtre mère des widgets
 */
 
void createChildren(Display* dpy, int screen, Visual* visual, Window parent )
{
	char buf[80] ;
	rBox[4] = createColorBox(dpy, parent ) ;
	gBox[4] = createColorBox(dpy, parent ) ;
	bBox[4] = createColorBox(dpy, parent ) ;
	cBox[4] = createColorBox(dpy, parent ) ;
	
	setTextBoxDefaultFont("helvetica", 16 ) ;

	setTextBoxDefaultColors( 0xBABABA, 0xFFFFFF ) ;
	
	sprintf(buf,"Mode : %s - Depth : %d bits", vclass[visual->class], DisplayPlanes(dpy, screen ) ) ;
	dBox[0] = createTextBox(dpy, parent, buf ) ;
	dBox[1] = createTextBox(dpy, parent, "(c) 2001-2014  by  A. Menu" ) ;
	setTextBoxFont(dBox[1], "helvetica", 12 ) ;
	
	rBox[0] = createTextBox(dpy, parent, "R mask :" ) ;
	gBox[0] = createTextBox(dpy, parent, "G mask :" ) ;
	bBox[0] = createTextBox(dpy, parent, "B mask :" ) ;

	rBox[1] = createTextBox(dpy, parent, "$00000" ) ;
	gBox[1] = createTextBox(dpy, parent, "$00000" ) ;
	bBox[1] = createTextBox(dpy, parent, "$00000" ) ;

	rBox[2] = createTextBox(dpy, parent, "R value :" ) ;
	gBox[2] = createTextBox(dpy, parent, "G value :" ) ;
	bBox[2] = createTextBox(dpy, parent, "B value :" ) ;

	cBox[1] = createTextBox(dpy, parent, "Id/Name :" ) ;

	setTextBoxDefaultColors( 0x000000, 0xFFFFFF ) ;

	rBox[3] = createTextBox(dpy, parent, "000" ) ;
	gBox[3] = createTextBox(dpy, parent, "000" ) ;
	bBox[3] = createTextBox(dpy, parent, "000" ) ;
	cBox[0] = createTextBox(dpy, parent, "[nnn]" ) ;
	cBox[2] = createTextBox(dpy, parent, "name list" ) ;
	cBox[3] = createTextBox(dpy, parent, "#000000" ) ;
}

/*!
 *	\fn		void setChildrenGeometry(int w, int h )
 *	\brief	calcule la géométrie (position et dimensions) des widgets en 
 *			fonction des dimensions de la fenêtre d'application
 *	\param	w	largeur de la fenêtre
 *	\param	h	hauteur de la fenêtre
 */
 
void setChildrenGeometry(int w, int h )
{
	int x0 = TAB0 / 100.0 * w ;
	int x1 = TAB1 / 100.0 * w ;
	int x2 = TAB2 / 100.0 * w ;
	int x3 = TAB3 / 100.0 * w ;
	int x4 = TAB4 / 100.0 * w ;
	int x5 = TAB5 / 100.0 * w ;
	int x6 = TAB6 / 100.0 * w ;
	int x7 = TAB7 / 100.0 * w ;

	int y0 = 0 ;
	int y1 = HTEXTLINE / 100.0 * h ;
	int y2 = ( 2 * HTEXTLINE ) / 100.0 * h ;
	int y3 = ( 3 * HTEXTLINE ) / 100.0 * h ;
	int y4 = ( 4 * HTEXTLINE ) / 100.0 * h ;
	
	int m = MARGIN ;
	
	int x1b = x1 + getTextBoxTextWidth(cBox[0] ) + m ;

	setTextBoxGeometry(dBox[0], x0 + m, y0 + m/2, x4 - x0 - 2*m, y1 - m ) ;
	setTextBoxGeometry(dBox[1], x4 + m, y0 + m/2, x7 - x4 - 2*m, y1 - m ) ;
	setTextBoxAlignment(dBox[1], ALIGN_RIGHT | ALIGN_VCENTER ) ;

	setTextBoxGeometry(rBox[0], x0 + m, y1 + m/2, x1 - x0 - 2*m, y1 - m ) ;
	setTextBoxGeometry(gBox[0], x0 + m, y2 + m/2, x1 - x0 - 2*m, y1 - m ) ;
	setTextBoxGeometry(bBox[0], x0 + m, y3 + m/2, x1 - x0 - 2*m, y1 - m ) ;
	
	setTextBoxGeometry(rBox[1], x1 + m, y1 + m/2, x2 - x1 - 2*m, y1 - m ) ;
	setTextBoxGeometry(gBox[1], x1 + m, y2 + m/2, x2 - x1 - 2*m, y1 - m ) ;
	setTextBoxGeometry(bBox[1], x1 + m, y3 + m/2, x2 - x1 - 2*m, y1 - m ) ;

	setTextBoxGeometry(rBox[2], x2 + m, y1 + m/2, x3 - x2 - 2*m, y1 - m ) ;
	setTextBoxGeometry(gBox[2], x2 + m, y2 + m/2, x3 - x2 - 2*m, y1 - m ) ;
	setTextBoxGeometry(bBox[2], x2 + m, y3 + m/2, x3 - x2 - 2*m, y1 - m ) ;

	setTextBoxGeometry(rBox[3], x3 + m, y1 + m/2, x4 - x3 - 2*m, y1 - m ) ;
	setTextBoxGeometry(gBox[3], x3 + m, y2 + m/2, x4 - x3 - 2*m, y1 - m ) ;
	setTextBoxGeometry(bBox[3], x3 + m, y3 + m/2, x4 - x3 - 2*m, y1 - m ) ;

	setTextBoxAlignment(rBox[3], ALIGN_RIGHT | ALIGN_VCENTER ) ;
	setTextBoxAlignment(gBox[3], ALIGN_RIGHT | ALIGN_VCENTER ) ;
	setTextBoxAlignment(bBox[3], ALIGN_RIGHT | ALIGN_VCENTER ) ;
	
	setColorBoxGeometry(rBox[4], x4 + m, y1 + m/2, x5 - x4 - 2*m, y2 - y1 - m ) ;
	setColorBoxGeometry(gBox[4], x4 + m, y2 + m/2, x5 - x4 - 2*m, y3 - y2 - m ) ;
	setColorBoxGeometry(bBox[4], x4 + m, y3 + m/2, x5 - x4 - 2*m, y4 - y3 - m ) ;

	setTextBoxGeometry(cBox[0], x1 + m, y4 + m/2, x2 - x1 - 2*m, y1 - m ) ;
	setTextBoxGeometry(cBox[1], x0 + m, y4 + m/2, x1 - x0 - 2*m, y1 - m ) ;
	setTextBoxGeometry(cBox[2], x1b + m, y4 + m/2, x6 - x1b - 2*m, y1 - m ) ;
	setTextBoxGeometry(cBox[3], x6 + m, y4 + m/2, x7 - x6 - 2*m, y1 - m ) ;

	setTextBoxAlignment(cBox[3], ALIGN_CENTERED ) ;
	
	setColorBoxGeometry(cBox[4], x6 + m, y1 + m/2, x7 - x6 - 2*m, y4 - y1 - m ) ;
}

/*!
 *	\fn		void drawChildren(int id )
 *	\brief	dessin des widgets
 *	\param	id	numéro de l'entrée RGB sélectionnée
 */
 
void drawChildren(int id )
{
	char buf[10] ;
	
	setColorBoxBackground(rBox[4], rgbValue(id) & rgbMask(Red, id ) ) ;
	setColorBoxBackground(gBox[4], rgbValue(id) & rgbMask(Green, id ) ) ;
	setColorBoxBackground(bBox[4], rgbValue(id) & rgbMask(Blue, id ) ) ;
	setColorBoxBackground(cBox[4], rgbValue(id) ) ;

	sprintf(buf,"$%06lX", rgbMask(Red, id ) ) ; 	setTextBoxText(rBox[1], buf ) ;
	sprintf(buf,"$%06lX", rgbMask(Green, id ) ) ; 	setTextBoxText(gBox[1], buf ) ;
	sprintf(buf,"$%06lX", rgbMask(Blue, id ) ) ; 	setTextBoxText(bBox[1], buf ) ;

	sprintf(buf,"%d", rgbColor(Red,id ) ) ; 	setTextBoxText(rBox[3], buf ) ;
	sprintf(buf,"%d", rgbColor(Green, id ) ) ;	setTextBoxText(gBox[3], buf ) ;
	sprintf(buf,"%d", rgbColor(Blue, id ) ) ; 	setTextBoxText(bBox[3], buf ) ;
	sprintf(buf,"[%03d]", id ) ; 	setTextBoxText(cBox[0], buf ) ;
	setTextBoxText(cBox[2], rgbName(id) ) ;
	sprintf(buf,"#%06lX", rgbValue(id) ) ; 	setTextBoxText(cBox[3], buf ) ;
	
	drawTextBox( dBox[0] ) ;
	drawTextBox( dBox[1] ) ;

	drawColorBox( rBox[4] ) ;
	drawColorBox( gBox[4] ) ;
	drawColorBox( bBox[4] ) ;
	drawColorBox( cBox[4] ) ;

	int i ;
	for ( i = 0 ; i < 4 ; ++i )	{
		drawTextBox( rBox[i] ) ;
		drawTextBox( gBox[i] ) ;
		drawTextBox( bBox[i] ) ;
		drawTextBox( cBox[i] ) ;
	}
}

/*!
 *	\fn		void deleteChildren()
 *	\brief	destruction de tous les widgets
 */
 
void deleteChildren()
{
	deleteAllColorBox() ;
	deleteAllTextBox() ;
}

/*!
 *	\fn		void drawColorMap(Display* dpy, Window win, GC gc, int w, int h )
 *	\brief	dessin de la palette RGB
 *	\param	dpy	serveur d'affichage
 *	\param	win	fenêtre conteneur
 *	\param	gc	contexte graphique à utiliser
 *	\param	w	largeur de la fenêtre conteneur
 *	\param 	h	hauteur de la fenêtre conteneur
 */
 
void drawColorMap(Display* dpy, Window win, GC gc, int w, int h )
{
	int x0 = 0 ;
	int y0 = ( HTEXTLINE * 5 ) / 100.0 * h ;
	int wcell = w / CELLPERLINE ;
	int hcell = ( h - y0 ) / ( numberOfRgb() / CELLPERLINE + 1 ) ;

	int i ;
	
	for ( i = 0 ; i < numberOfRgb() ; ++i ) {
		int x = x0 + ( i % CELLPERLINE ) * wcell ;
		int y = y0 + ( i / CELLPERLINE ) * hcell ;
		XSetForeground(dpy, gc, rgbValue(i) ) ;
		XFillRectangle(dpy, win, gc, x, y, wcell, hcell ) ;	
	}
	XSetForeground(dpy, gc, 0 ) ;
	XDrawLine(dpy, win, gc, x0, y0 - 1, w, y0 - 1 ) ;
}

/*!
 *	\fn		void drawSelectedColor(Display* dpy, Window win, GC gc, int w, int h, int id, boolean selected )
 *	\brief	met en valeur ou restitue un élément de la palette RGB. LA mise en valeur est matérialisée
 *			par superposition d'un rectangle plein de couleur complémentaire à celle de l'élément.
 *	\param	dpy	serveur d'affichage
 *	\param	win	fenêtre conteneur
 *	\param	gc	contexte graphique à utiliser
 *	\param	w	largeur de la fenêtre conteneur
 *	\param 	h	hauteur de la fenêtre conteneur
 *	\param	id	indice de l'entrée de la palette concernée
 *	\param	selected	indique si l'élément \a id doit être mis en valeur ou non
 */
 
void drawSelectedColor(Display* dpy, Window win, GC gc, int w, int h, int id, boolean selected )
{
	int x0 = 0 ;
	int y0 = ( HTEXTLINE * 5 ) / 100.0 * h ;
	int wcell = w / CELLPERLINE ;
	int hcell = ( h - y0 ) / ( numberOfRgb() / CELLPERLINE + 1 ) ;
	
	if ( id >= numberOfRgb() )	return ;
	
	int x = x0 + ( id % CELLPERLINE ) * wcell ;
	int y = y0 + ( id / CELLPERLINE ) * hcell ;
	
	XSetForeground(dpy, gc, rgbValue(id) ) ;
	XFillRectangle(dpy, win, gc, x, y, wcell, hcell ) ;	
	
	if ( selected ) {
		x += wcell / 4 ;
		y += hcell / 4 ;
		wcell /= 2 ;
		hcell /= 2 ; 
		XSetForeground(dpy, gc, ~rgbValue(id) ) ;
		XFillRectangle(dpy, win, gc, x, y, wcell, hcell ) ;	
	}
	
	XSetForeground(dpy, gc, 0 ) ;
}

/*!
 *	\fn		void drawAdditiveSynthesis(Display* dpy, Window win, GC gc, int w, int h, int id )
 *	\brief	dessine la synthèse additive d'une composition RGB
 *	\param	dpy	serveur d'affichage
 *	\param	win	fenêtre conteneur
 *	\param	gc	contexte graphique à utiliser
 *	\param	w	largeur de la fenêtre conteneur
 *	\param 	h	hauteur de la fenêtre conteneur
 *	\param	id	indice de l'entrée de la palette concernée
 */
 
void drawAdditiveSynthesis(Display* dpy, Window win, GC gc, int w, int h, int id )
{
	int x0 = TAB5 / 100.0 * w + MARGIN ;
	int x1 = TAB6 / 100.0 * w - MARGIN ;
	int y0 = HTEXTLINE / 100.0 * h + MARGIN / 2 ;
	int y1 = ( 4 * HTEXTLINE ) / 100.0 * h - MARGIN / 2 ;
	
	int min = ( ( x1 - x0 ) > ( y1 - y0 ) ? y1 - y0 : x1 - x0 ) - 2 * MARGIN ;
	int r = min / 3 ;
	
	int xr = x0 + ( ( x1 - x0 ) - min ) / 2 ;
	int yr = y0 + ( ( y1 - y0 ) - 2.866 * r ) / 2 ;
	int xg = xr + 0.866 * r ;
	int yg = yr + r / 2 ;
	int xb = xr ;
	int yb = yr + r ;

	XSetForeground(dpy, gc, 0 ) ;
	XFillRectangle(dpy, win, gc, x0, y0, x1 - x0, y1 - y0 ) ;

	XSetFunction(dpy, gc, GXxor ) ;
	XSetForeground(dpy, gc, rgbValue(id) & rgbMask(Red, id ) ) ;
	XFillArc(dpy, win, gc, xr, yr, 2 * r, 2 * r, 0 ,360 * 64 ) ;
	XSetForeground(dpy, gc, rgbValue(id) & rgbMask(Green, id ) ) ;
	XFillArc(dpy, win, gc, xg, yg, 2 * r, 2 * r, 0 ,360 * 64 ) ;
	XSetForeground(dpy, gc, rgbValue(id) & rgbMask(Blue, id ) ) ;
	XFillArc(dpy, win, gc, xb, yb, 2 * r, 2 * r, 0 ,360 * 64 ) ;
	XSetFunction(dpy, gc, GXcopy ) ;
}

/*!
 *	\fn		int  getClickedColor(int* id, int w, int h, int xclick, int yclick )
 *	\brief	teste l'appartenance d'un point (x,y) à un élément de la palette RGB.
 *	\param	id	réceptable de l'indice palette trouvé, non modifié en cas d'échec
 *	\param	w	largeur de la fenêtre conteneur
 *	\param 	h	hauteur de la fenêtre conteneur
 *	\param	xclick	coordonnée horizontale du point à tester
 *	\param	yclick	coordonnée verticale du point à tester
 *	\return	0 en cas de suucès, ou une valeur négative si les coordonnées sont hors de la palette
 */
 
int  getClickedColor(int* id, int w, int h, int xclick, int yclick )
{
	int x0 = 0 ;
	int y0 = ( HTEXTLINE * 5 ) / 100.0 * h ;
	int wcell = w / CELLPERLINE ;
	int hcell = ( h - y0 ) / ( numberOfRgb() / CELLPERLINE + 1 ) ;
	
	int i = 0 ;
	
	while ( i < numberOfRgb() ) {
		int x1 = x0 + ( i % CELLPERLINE ) * wcell ;
		int y1 = y0 + ( i / CELLPERLINE ) * hcell ;
		int x2 = x1 + wcell - 1 ;
		int y2 = y1 + hcell - 1 ;
		if ( ( xclick >= x1 )&&( xclick <= x2 )&&( yclick >= y1 )&&( yclick <= y2 ) ) {
			*id = i ;
			return 0 ;
		}
		i++ ;
	}
	
	return -1 ;
}
