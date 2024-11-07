	CC	=	 gcc
	CFLAGS	=	-Wall	-g
	LDFLAGS	=	-Wl,-Map=main.map

	all:	main

	main:	main.o	misc.o
		$(CC)	main.o	misc.o	$(LDFLAGS)	-o	main

	main.o:	main.c
		$(CC) $(CFLAGS)	-c	main.c

	misc.o: misc.c
		$(CC)	$(CFLAGS)	-c	misc.c

	clean:
		rm	-f	*.o	main	main.map 
