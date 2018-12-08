/* ----------------------------------------------------------------------------
 |
 |	Nom :			textbox.c
 |
 |	Type :			UTILITAIRE
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

#include "textbox.h"

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
	unsigned long cbo ;		// text and border color
	unsigned long cbg ;		// background color
	
	GC			  gc ;
	char		  text[ MAXTEXTLENGTH ] ;
	XFontStruct*  font ;
	byte		  alignment ;
	
} TextBox ;

TextBox*	textBox[ MAXNUMOFTEXTBOX ] ;
static int  textBoxNum = 0 ;

char		defaultFontFamily[80] = "fixed" ;
int			defaultFontSize = 18 ;
lword		defaultForegroundColor = -1 ;
lword		defaultBackgroundColor ;

/*!
 *	\fn		XFontStruct* loadFont(Display* dpy, const char* family, int size )
 *	\private
 */
 
XFontStruct* loadFont(Display* dpy, const char* family, int size )
{
	XFontStruct* 	font ;
	char			buf[128] ;
	
	sprintf(buf, "-*-%s-*-r-*-*-%d-*-*-*-*-*-*-*", family, size ) ;
	font = XLoadQueryFont(dpy, buf ) ;	
	if ( !font ) {
#ifdef VERBOSE
    	fprintf(stderr, "unable to load font %s, using fixed\n", buf ) ;
#endif
    	font = XLoadQueryFont(dpy, "fixed" ) ;
	}
	return font ;
}

/*!
 *	\fn		int  createTextBox(Display* dpy, Window parent, const char* text )
 *	\brief	création d'un widget de type zone de texte
 *	\param	dpy	serveur d'affichage
 *	\param	parent	fenêtre mère
 *	\param	text	texte du widget
 *	\return	identifiant \e int du nouveau widget, ou -1 en cas d'échec
 */
 
int  createTextBox(Display* dpy, Window parent, const char* text )
{
	if ( textBoxNum >= MAXNUMOFTEXTBOX ) {
#ifdef VERBOSE
		fprintf(stderr, "unable to create new TextBox widget" ) ;
#endif
		return -1 ;
	}

	TextBox* p = (TextBox*)malloc( sizeof( TextBox ) ) ;
	textBox[ textBoxNum ] = p ;
	
	p->dpy = dpy ;
	p->parent = parent ;
	p->wbo = 0 ;
	p->x = 1 ;
	p->y = 1 ;
	p->w = 10 ;
	p->h = 10 ;
	if ( defaultForegroundColor == -1 ) {
		p->cbo = BlackPixel(dpy, DefaultScreen(dpy ) ) ;
		p->cbg = WhitePixel(dpy, DefaultScreen(dpy ) ) ;
	}
	else {
		p->cbo = defaultForegroundColor ;
		p->cbg = defaultBackgroundColor ;
	}
	
	if ( text != NULL )	strncpy(p->text, text, MAXTEXTLENGTH - 1 ) ;
	else				strcpy(p->text, "?" ) ;
	p->alignment = ALIGN_LEFT | ALIGN_VCENTER ;

	p->win = XCreateSimpleWindow(p->dpy, p->parent, p->x, p->y, p->w, p->h, p->wbo, p->cbo, p->cbg ) ;
	XMapWindow(p->dpy, p->win ) ;

	p->gc = XCreateGC(p->dpy, p->win, 0, NULL ) ;
	XSetForeground(p->dpy, p->gc, p->cbo ) ; 
	XSetBackground(p->dpy, p->gc, p->cbg ) ; 
	
	p->font = loadFont(p->dpy, defaultFontFamily, defaultFontSize ) ;
    XSetFont(p->dpy, p->gc, p->font->fid ) ;
	
	return textBoxNum++ ;
}

/*!
 *	\fn		void setTextBoxDefaultFont(const char* family, int size )
 *	\brief	fixe une fonte par défaut pour les futurs TextBox
 *	\param	family	famille de polices
 *	\param	size	taille de police
 */
 
void setTextBoxDefaultFont(const char* family, int size )
{
	strncpy(defaultFontFamily, family, 80 ) ;
	defaultFontSize = size ;
}

/*!
 *	\fn		void setTextBoxDefaultColors(unsigned long foreground, unsigned long background )
 *	\brief	fixe les couleurs par défaut pour les futurs TextBox
 *	\param	foreground	couleur du texte et du cadre
 *	\param	background	couleur du fond
 */
 
void setTextBoxDefaultColors(lword foreground, lword background )
{
	defaultForegroundColor = foreground ;
	defaultBackgroundColor = background ;
}

/*!
 *	\fn		void setTextBoxGeometry(int id, int x, int y, int w, int h )
 *	\brief	fixe la géométrie (position et dimensions) du widget d'identifiant \a id
 *			relativement à son parent spécifié lors de la création
 *	\param	id	identifiant du widget concerné
 *	\param	x position horizontale
 *	\param	y position verticale
 *	\param	w largeur
 *	\param	h hauteur
 */
 
void setTextBoxGeometry(int id, int x, int y, int w, int h )
{
	if ( id >= textBoxNum )	return ;
	
	TextBox* p = textBox[id] ;
	p->x = x ;
	p->y = y ;
	p->w = w ;
	p->h = h ;
}

/*!
 *	\fn		void setTextBoxColors(int id, lword foreground, lword background )
 *	\brief	fixe les couleurs du widget d'identifiant \a id
 *	\param	id	identifiant du widget concerné
 *	\param	foreground	couleur du texte et du cadre
 *	\param	background	couleur du fond
 */
 
void setTextBoxColors(int id, lword foreground, lword background )
{
	if ( id >= textBoxNum )	return ;
	TextBox* p = textBox[id] ;
	p->cbo = foreground ;
	p->cbg = background ;
	XSetForeground(p->dpy, p->gc, p->cbo ) ; 
	XSetBackground(p->dpy, p->gc, p->cbg ) ; 
}

/*!
 *	\fn		void setTextBoxBorder(int id, int width )
 *	\brief	spécifie l'épaisseur de la bordure (0 par défaut)
 *	\param	id	identifiant du widget concerné
 *	\param	width	épaisseur du trait
 */
 
void setTextBoxBorder(int id, int width )
{
	if ( id >= textBoxNum )	return ;
	textBox[id]->wbo = width ;
}

/*!
 *	\fn		void setTextBoxText(int id, const char* text )
 *	\brief	fixe le contenu texte du widget d'identifiant \a id
 *	\param	id	identifiant du widget concerné
 *	\param	text	texte du widget
 */
 
void setTextBoxText(int id, const char* text )
{
	if ( id >= textBoxNum )	return ;
	strncpy(textBox[id]->text, text, MAXTEXTLENGTH - 1 ) ;
}

/*!
 *	\fn		void setTextBoxFont(int id, const char* family, int size )
 *	\brief	spécifie la fonte d'affichage du widget d'identifiant \a id
 *	\param	id	identifiant du widget concerné
 *	\param	family	famille de polices
 *	\param	size	taille de police
 */
 
void setTextBoxFont(int id, const char* family, int size )
{
	if ( id >= textBoxNum )	return ;
	TextBox* p = textBox[id] ;

	p->font = loadFont(p->dpy, family, size ) ;
    XSetFont(p->dpy, p->gc, p->font->fid ) ;
}

/*!
 *	\fn		void setTextBoxAlignment(int id, byte alignment )
 *	\brief	détermine les contraintes d'alignement du widget sur sa surface
 			(ALIGN_LEFT | ALIGN_VCENTER par défaut)
 *	\details	l'alignement horizontal est à choisir parmi ALIGN_LEFT, ALIGN_HCENTER et ALIGN_RIGHT,
 *				l'alignement vertical parmi ALIGN_TOP, ALIGN_VENTER et ALIGN_BOTTOM.
 *	\param	id	identifiant du widget concerné
 *	\param	alignment contraintes d'alignement
 */
 
void setTextBoxAlignment(int id, byte alignment )
{
	if ( id >= textBoxNum )	return ;
	textBox[id]->alignment = alignment ;
}

/*!
 *	\fn		void drawTextBox(int id )
 *	\brief	dessine le widget
 *	\param	id	identifiant du widget concerné
 */
 
void drawTextBox(int id )
{
	if ( id >= textBoxNum )	return ;
	
	TextBox* p = textBox[id] ;
	XMoveWindow(p->dpy, p->win, p->x, p->y ) ;
	XResizeWindow(p->dpy, p->win, p->w, p->h ) ;
	XSetWindowBackground(p->dpy, p->win, p->cbg ) ;
	XSetWindowBorder(p->dpy, p->win, p->cbo ) ;
	XSetWindowBorderWidth(p->dpy, p->win, p->wbo ) ;
	XClearWindow(p->dpy, p->win ) ;

	int x, y ;
	int direction, ascent, descent ;
	XCharStruct overall ;
	
	XTextExtents(p->font, p->text, strlen(p->text), &direction, &ascent, &descent, &overall ) ;
	
	if ( p->alignment & ALIGN_LEFT )		x = 0 ;
	else if ( p->alignment & ALIGN_RIGHT )	x = p->w - overall.width ;
	else 									x = ( p->w - overall.width ) / 2 ;
	
	if ( p->alignment & ALIGN_TOP )			y = ascent - descent ;
	else if ( p->alignment & ALIGN_BOTTOM )	y = p->h - ( ascent - descent ) ;
	else									y = p->h / 2 + ( ascent - descent ) / 2 ;
	
	XDrawString(p->dpy, p->win, p->gc, x, y, p->text, strlen(p->text) ) ;
}

/*!
 *	\fn		int  getTextBoxTextWidth(int id )
 *	\brief	calcule la largeur du texte courant
 *	\param	id	identifiant du widget concerné
 *	\return	largeur en pixels
 */
 
int  getTextBoxTextWidth(int id )
{
	if ( id >= textBoxNum )	return 0 ;
	TextBox* p = textBox[id] ;
	int direction, ascent, descent ;
	XCharStruct overall ;
	
	XTextExtents(p->font, p->text, strlen(p->text), &direction, &ascent, &descent, &overall ) ;
	
	return overall.width ;
}

/*!
 *	\fn		void deleteAllTextBox()
 *	\brief	détruit tous les widgets précédement créés par createColorBox()
 */
 
void deleteAllTextBox()
{
	int i ;
	for ( i = 0 ; i < textBoxNum ; ++i )	free( textBox[i] ) ;
}
