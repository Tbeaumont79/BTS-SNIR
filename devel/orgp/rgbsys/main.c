/* ----------------------------------------------------------------------------
 |
 |	Nom :			main.c
 |
 |	Type :			APPLICATION programme principal, boucle d'événements
 |	Sujet :			rgbsys - frontal Unix rgb.txt ( mode TrueColor )
 |
 |	Version :		2.1
 |	Création :		2001
 |	Mise à jour :	04/10/2014
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
 *	\mainpage	rgbsys version 2.0
 *
 *	Le système informatique de multifenêtrage X utilise une liste de définitions de
 *	couleurs enregistrée dans un fichier texte simple nommé \e rgb.txt.
 *
 *	Ce fichier  est un tableau dont chaque ligne est une fiche comprenant au moins
 *	quatre champs séparés par des espaces. 
 *	Les trois premiers  présentent  des valeurs entre  0 et 255  correspondant  aux
 *	proportions  RVB  de la couleur ;  le reste  jusqu'à la fin  est une  chaîne de
 *	caractères donnant le nom de la couleur.
 *	La liste présente des synonymes,  avec une version en deux mots  et une version
 *	en CamelCase, de façon à tolérer les habitudes des utilisateurs.  Elle comprend
 *	aussi des graphies alternatives telles que gray et grey  et code 100 niveaux de
 *	gris.
 *
 *	Rgbsys est un frontal proposant l'affichage de la palette des couleurs trouvées
 *	dans le fichier  et permettant la sélection d'une couleur afin  d'en visualiser
 *	les  composantes.  Rgbsys reproduit  aussi, pour  la  couleur sélectionnée,  le 
 *	graphe de synthèse additive correspondant.
 *
 *	La sélection peut se faire au moyen des touches flèches ou  directement avec la
 *	souris en cliquant sur une cellule de la palette.
 *
 *	L'issue du programme est obtenue en appuyant sur la touche d'échappement (Esc).
 *
 *	Rgbsys est écrit en C et basé sur la bibliothèque XLib.
 */
 
#include <rgbsys.h>

int main(int argc, char* argv[] ) 
{
	Display*	dpy ;
	int			screen ;
	Visual*		visual ;
	Window		root ; 
	Window		win ;
	int			width, height ;
	GC			gc ;
	lword		wpx, bpx ;
	boolean		quit = false ;
	int			currentRgb = 0 ;
	lword		mask[3] ;
	boolean		loadFailed ;
	
	dpy 	= XOpenDisplay(0 ) ;
	if ( !dpy ) {
		fprintf(stderr, "Error: Could not open display\n" ) ;
		return -2 ;
	}
	screen 	= DefaultScreen(dpy ) ;
	root 	= DefaultRootWindow(dpy ) ;
	bpx 	= BlackPixel(dpy, screen ) ;	
	wpx 	= WhitePixel(dpy, screen ) ;	
	visual 	= XDefaultVisual(dpy, screen ) ;
	
	if ( ( visual->class != DirectColor )&&( visual->class != TrueColor ) ) {
		fprintf(stderr, "Error: DIRECT mode required, sorry...\n" ) ;
		return -3 ;
	}

	mask[Red] = visual->red_mask ;
	mask[Green] = visual->green_mask ;
	mask[Blue] = visual->blue_mask ;
	
	loadFailed = loadRgbDataFromFile( argc > 1 ? argv[1] : DEFAULTDATAFILE, mask ) ;
	if ( loadFailed ) {
		fprintf(stderr, "Error: RGB data file not found\n" ) ;
		return -1 ;
	}

#ifdef VERBOSE
	printf("%d RGB colors loaded\n", numberOfRgb() ) ;
#endif

	width = DEFAULTWIDTH ;
	height = DEFAULTHEIGHT ;
	win = XCreateSimpleWindow(dpy, root, 0, 0, width, height, 1, bpx, wpx ) ;

	XSelectInput(dpy, win, KeyPressMask | ExposureMask | ButtonPressMask | StructureNotifyMask ) ;
	XStoreName(dpy, win, "rgbsys - X11 Colors Names - v2.1" ) ;
	gc = XCreateGC(dpy, win, 0, NULL ) ;
	XSetBackground(dpy, gc, wpx ) ;

	XMapWindow(dpy, win ) ;
	
	createChildren(dpy, screen, visual, win ) ;
	setChildrenGeometry(width, height ) ;
	
	while ( !quit ) {
		boolean updateNeeded = false ;
		XEvent  event ;
		XNextEvent(dpy, &event ) ;
		
		switch( event.type ) {
		
			case Expose :
				XSetForeground(dpy, gc, wpx ) ;
				XFillRectangle(dpy, win, gc, 0, 0, width, height ) ;	
				drawColorMap(dpy, win, gc, width, height ) ;
				updateNeeded = true ;
				break ;
	
			case ButtonPress :
				drawSelectedColor(dpy, win, gc, width, height, currentRgb, false ) ;
				getClickedColor(&currentRgb, width, height, event.xbutton.x, event.xbutton.y ) ;
				updateNeeded = true ;
				break ;
			
			case KeyPress :	
				drawSelectedColor(dpy, win, gc, width, height, currentRgb, false ) ;
				switch( event.xkey.keycode ) {
					case KEY_LEFT :
						if ( --currentRgb < 0 ) currentRgb = numberOfRgb() - 1 ;
						break ;
					case KEY_RIGHT :
						if ( ++currentRgb >= numberOfRgb() ) currentRgb = 0 ;
						break ; 
					case KEY_UP :
						if ( ( currentRgb - CELLPERLINE ) >= 0 ) currentRgb -= CELLPERLINE ;
						break ;
					case KEY_DOWN :
						if ( ( currentRgb + CELLPERLINE ) < numberOfRgb() )	currentRgb += CELLPERLINE ;
						break ; 
					case KEY_ESC :	
						quit = true ;
				}
				updateNeeded = true ;
				break ;
				
			case ConfigureNotify :
				if ( ( event.xconfigure.width != width )||( event.xconfigure.height != height ) ) {
				  	width = event.xconfigure.width ;
				  	height = event.xconfigure.height ;
					setChildrenGeometry(width, height ) ;
				}
				break ;
		}
		
		if ( updateNeeded ) {
			drawChildren(currentRgb ) ;
			drawSelectedColor(dpy, win, gc, width, height, currentRgb, true ) ;
			drawAdditiveSynthesis(dpy, win, gc, width, height, currentRgb ) ;
		}
	}
	
	deleteChildren() ;
	freeColorMap() ;
	
	XFreeGC(dpy, gc ) ;
	XDestroyWindow(dpy, win ) ;
	XCloseDisplay(dpy ) ;

	return 0 ;
}
