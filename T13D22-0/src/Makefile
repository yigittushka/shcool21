CC = gcc 
WWW = -Wall -Wextra -Werror


cipher: cipher.o
	$(CC) $(WWW) cipher.o -o ../build/cipher

cipher.o: cipher.c 
	$(CC) $(WWW) cipher.c -c

clean:
	rm -rf *.o ../build/cipher