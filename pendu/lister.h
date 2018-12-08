#ifndef _LISTER_H
	#define _LISTER_H

/******************************/
/* fonction lisant un fichier */
/* affichant son contenu et   */
/* stockant son contenu dans  */
/* un tableau de nom buffer   */
/* Arg : entree : nom fichier */
/*	 sortie : -1 si erreur */
/*		  nb octets lus*/
/* autrement     */
	int lister(char *nom);
#endif
