/* rgbtohsv.c */

#include "argv.h"

int main (int argc, char* argv[] )
{
	unsigned long rgba = 0 ;
	unsigned char	rgb[3] , vmin , vmax ;
	int i ;
	char h ;
	char s ;
	char v ;

	if ( NumberOfArg < 3 ) return BadNumberOfArg ;
	for ( i = 0 ; i < 3 ; ++i ) {
		rgb[i] = IntegerArg(i+1) ;
		printf("%d ", rgb[i] ) ;
	}
	putchar('\n') ;
	rgba = (rgb[0]<<16)|(rgb[1]<<8)|(rgb[2]) ;
	printf("#%06lx\n", rgba ) ;

	vmin = 255 ;	
	for ( i = 0 ; i < 3 ; ++i ) {
		if ( rgb[i] < vmin ) vmin = rgb[i] ;
	}
	vmax = 0 ;
	for ( i = 0 ; i < 3 ; ++i ) {
		if ( rgb[i] > vmax ) vmax = rgb[i] ;
	}
	
	
	if( vmax == 0)
		s = 0 ;
	else 	s = ( ( 1 - (vmin / (float)vmax ) ) * 100 ) ;
	v = vmax / (float)255 * 100 ;

	if (vmax == vmin) h = 0 ;
	else if (vmax == rgb[0]) h = (60*(rgb[1] - rgb[2]) / (vmax - vmin) + 360) % 360 ;
	else if (vmax == rgb[1]) h = 60*(rgb[2] - rgb[0]) / (vmax - vmin) + 120 ;
	else h = 60*(rgb[0] - rgb[1]) / ( vmax - vmin ) + 240 ;
	
	printf("H %d°, S %d%%, V %d%%\n", h, s , v ) ;


	return 0 ;
}
