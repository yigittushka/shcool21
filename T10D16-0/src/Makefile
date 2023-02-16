CC = gcc
WWW = -Wall -Wextra -Werror
B = ../build/

STT = s21_string_test.o
ST = s21_string.o

STLEN = s21_strlen_test_strlen.o

STCMP = s21_string_test_strcmp.o

STCPY = s21_string_test_strcpy.o

STCAT = s21_string_test_strcat.o


strlen_tests : $(ST) $(STLEN)
	$(CC) $(WWW) $(STT) $(ST) -o $(B)Quest_1

strcmp_tests : $(ST) $(STCMP)
	$(CC) $(WWW) $(STT) $(ST) -o $(B)Quest_2

strcpy_tests : $(ST) $(STCPY)
	$(CC) $(WWW) $(STT) $(ST) -o $(B)Quest_3

strcat_tests : $(ST) $(STCAT)
	$(CC) $(WWW) $(STT) $(ST) -o $(B)Quest_4

$(ST) : s21_string.c 
	$(CC) $(WWW) s21_string.c -c 

$(STLEN) : s21_string_test.c
	$(CC) $(WWW) -DLEN s21_string_test.c -c

$(STCMP) : s21_string_test.c
	$(CC) $(WWW) -DCMP s21_string_test.c -c

$(STCPY) : s21_string_test.c
	$(CC) $(WWW) -DCPY s21_string_test.c -c

$(STCAT) : s21_string_test.c
	$(CC) $(WWW) -DCAT s21_string_test.c -c

clean :
	rm -rf *.o $(B)Quest_1 $(B)Quest_2 $(B)Quest_3 $(B)Quest_4 

# rebuild_strlen : clean strlen_tests

# rebuild_strcmp : clean strcmp_tests 

# rebuild_strcpy : clean strcpy_tests

# rebuild_strcat : clean strcat_tests