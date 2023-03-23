all:	my_mastermind

my_mastermind:	my_mastermind.o
		gcc	-Wall	-Werror	-o	my_mastermind	my_mastermind.o
	

my_mastermind.o:	headerfile.h	my_mastermind.c
		gcc	-Wall	-Wextra	-Werror	-c	headerfile.h	my_mastermind.c

clean:
		rm	-f	*.o

fclean:	clean
		rm	-f	my_mastermind

re:	fclean	all