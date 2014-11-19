######################################
#Makefile for MDB
######################################
CC=g++
CC_FLAG=-g -Wall

LIB=-lpthread



all:mdb 
.PHONY: all

OBJS=main.o util/trace.o

mdb: $(OBJS)
	$(CC) $(CC_FLAG) $(LIB) -o $@ $(OBJS)

main.o: main.cpp mdbheader.h util/trace.h
	$(CC) -c  $(CC_FLAG) $< -o $@


util/trace.o:	util/trace.cpp util/trace.h
	$(CC)  -c $(CC_FLAG) $< -o $@

clean:
	rm *.o
	rm util/*.o
