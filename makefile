# makefile for simpleshell

myftp: myftp.o token.o
	gcc myftp.o token.o -o myftp

myftpd: myftpd.o token.o
	gcc myftpd.o token.o -o myftpd

myftp.o: myftp.c token.h
	gcc -c myftp.c

myftpd.o: myftpd.c token.h
	gcc -c myftpd.c

token.o: token.c token.h
	gcc -c token.c

clean:
	rm *.o

git-add:
	git add makefile *.c *.h
