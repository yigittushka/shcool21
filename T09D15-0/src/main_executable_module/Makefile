CC = gcc
WWW = -Wall -Wextra -Werror
BUILD = ../../build/
L = ../data_libs/
MODELE = ../data_module/
YET = ../yet_another_decision_module/
MEMMP = ../main_executable_module/

IO = data_io.o 
STAT = data_stat.o
SORT= data_sort.o 
DME = data_module_entry.o
DP= data_process.o
MEM =main_executable_module.o
D= decision.o
YADME = yet_another_decision_module_entry.o
MACRO =main_executable_module_macro.o


build : main

main : $(D) $(IO) $(STAT) $(MEM) $(DP) $(SORT)
	$(CC) $(WWW) $(D) $(IO) $(STAT) $(MEM) $(DP) $(SORT) -o $(BUILD)Quest_3 

build_with_macro : $(D) $(STAT) $(MACRO) $(DP) $(SORT)
	$(CC) $(WWW) $(MEM) $(STAT) $(D) $(SORT) $(DP) -o $(BUILD)Quest_4 

build_with_static : $(D) $(IO) data_stat.a $(MEM) $(DP) $(SORT)
	$(CC) $(WWW) $(D) $(IO) $(MEM) $(DP) $(SORT) -o $(BUILD)Quest_5 data_stat.a

build_with_dynamic : $(DP) $(D) $(IO) data_process.so $(MEM) $(STAT)  $(SORT) 
	$(CC) $(WWW) $(DP) $(D) $(IO) $(MEM) $(STAT)  $(SORT) -o $(BUILD)Quest_6 -L$(L) -Wl,-rpath,

data_process.so : $(MODELE)data_process.c $(L)data_stat.c
	$(CC) $(WWW) -c -fPIC $(MODELE)data_process.c 
	$(CC) $(WWW) -c -fPIC $(L)data_stat.c
	$(CC) -shared -o data_process.so $(DP) $(STAT)
	

data_stat.a : $(STAT)
	ar r data_stat.a $(STAT)

$(MACRO) : main_executable_module_macro.o
	$(CC) $(WWW) -c -DMACROS main_executable_module.c 

$(MEM) : main_executable_module.c 
	$(CC) $(WWW) -c  main_executable_module.c

$(D) : $(YET)decision.c $(YET)decision.h
	$(CC) $(WWW) -c $(YET)decision.c 

$(DP) : $(MODELE)data_process.c $(MODELE)data_process.h
	$(CC) $(WWW) -c $(MODELE)data_process.c

$(SORT) : $(L)data_sort.c $(L)data_sort.h
	$(CC) $(WWW) -c $(L)data_sort.c 
	
$(IO) : $(L)data_io.c $(L)data_io.h
	$(CC) $(WWW) -c $(L)data_io.c 

$(STAT) : $(L)data_stat.c $(L)data_stat.h
	$(CC) $(WWW) -c $(L)data_stat.c 

clean : 
	rm -rf *.o *.a *.so $(BUILD)Quest_3 $(BUILD)Quest_4 $(BUILD)Quest_5 $(BUILD)Quest_6 $(L)*.a $(L)*.so

rebuild :
	clean build
