
PROGS     	= pendu 
MYLIB		= lister.o
CFLAGS 		=  -Wall
OBJS	   = pendu1.o 

SRC	   = pendu1.c 

SRCLIB	   = lister.c 

INSTDIR = $(prefix)/usr/bin


#prog final
all: $(PROGS)
$(PROGS): $(OBJS)
	gcc  -o $@ $(CFLAGS) $(SRC) -L. -llister -lc 
	stty -icanon
#passage en mode non canonique

#prog final sans librairie Q4
allfinal: $(PROGS)
$(PROGS): $(OBJS)
	gcc -o $@ $(CFLAGS) $(SRC) -lc 
	stty -icanon
#passage en mode non canonique

#for librairie  		 
alllib1: 
	gcc -fPIC -c $(SRCLIB)  
	#creation d'une librairie statique
	ar cr liblister.a $(MYLIB) 

clean:
	rm -f $(PROGS) *.o
