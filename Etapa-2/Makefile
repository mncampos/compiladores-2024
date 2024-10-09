# MATEUS NUNES CAMPOS - 00268613
# GUILHERME DE SOUSA CIRUMBOLO - 00330049
# Makefile para etapa 2 do trabalho de compiladores

CC = gcc
SCANNER = scanner.l
OBJ = parser.tab.o lex.yy.o main.o
REPORT_FILE = parser.output

etapa2: $(OBJ)
	$(CC) -o etapa2 $(OBJ)

parser.tab.o: parser.tab.c parser.tab.h
	$(CC) -c parser.tab.c

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y --report-file=$(REPORT_FILE) 

lex.yy.o: lex.yy.c parser.tab.h
	$(CC) -c lex.yy.c

lex.yy.c: $(SCANNER)
	flex $(SCANNER)

main.o: main.c
	$(CC) -c main.c

clean:
	rm -f $(OBJ) $(REPORT_FILE) lex.yy.c parser.tab.c parser.tab.h etapa2

run: etapa2
	./etapa2


