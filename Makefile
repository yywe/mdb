######################################
#Makefile for MDB
######################################
CC=g++
CC_FLAG=-g -Wall -o0

LIB=-lpthread



all:mdb 
.PHONY: all

OBJS= main.o sqlparser/parser.o util/trace.o  sqlparser/lexer.o  executor/exec.o sqlparser/parsefunc.o

mdb: $(OBJS)
	$(CC) $(CC_FLAG) $(LIB) -o $@ $(OBJS)

main.o: main.cpp mdbtype.h mdbproto.h util/trace.h
	$(CC)	-c  $(CC_FLAG) $< -o $@


util/trace.o:	util/trace.cpp util/trace.h
	$(CC)  -c $(CC_FLAG) $< -o $@

sqlparser/lexer.o:	sqlparser/lexer.cpp sqlparser/lexer.h sqlparser/parser.h mdbtype.h
	$(CC)  -c $(CC_FLAG) $< -o $@

sqlparser/parser.o:	sqlparser/parser.cpp sqlparser/lexer.h sqlparser/parser.h mdbtype.h
	$(CC)  -c $(CC_FLAG) $< -o $@


sqlparser/parser.cpp: sqlparser/parser.y
	gcc sqlparser/mdb_lemon.c -o sqlparser/mdb_lemon
	sqlparser/mdb_lemon sqlparser/parser.y

sqlparser/parsefunc.o: sqlparser/parsefunc.cpp mdbproto.h
	$(CC)  -c $(CC_FLAG) $< -o $@

executor/exec.o: executor/exec.cpp executor/exec.h sqlparser/lexer.h
	$(CC) -c $(CC_FLAG) $< -o $@

clean:
	rm *.o
	rm mdb
	rm util/*.o
	rm executor/*.o
	rm sqlparser/*.o

