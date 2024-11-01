# MATEUS NUNES CAMPOS - 00268613
# GUILHERME DE SOUSA CIRUMBOLO - 00330049
# Makefile para etapa 3 do trabalho de compiladores

CC = gcc
CFLAGS = -g -Wall
LIBS = -lfl

# Fontes
SCANNER = scanner.l
PARSER = parser.y
OBJ = type_lex.o tree.o parser.tab.o lex.yy.o main.o

# Alvo principal
all: etapa3

# Regra para gerar lex.yy.c
lex.yy.c: $(SCANNER)
	flex $(SCANNER)

# Regra para gerar parser.tab.c
parser.tab.c: $(PARSER) tree.h
	bison -d $(PARSER) -Wcounterexamples

# Regras para compilar cada arquivo objeto
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c lex.yy.c

parser.tab.o: parser.tab.c
	$(CC) $(CFLAGS) -c parser.tab.c

type_lex.o: type_lex.c type_lex.h
	gcc -c type_lex.c

tree.o: tree.c tree.h type_lex.h
	gcc -c tree.c

# Regra para construir o executável
etapa3: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

# Regra de limpeza
clean:
	rm -f $(OBJ) lex.yy.c parser.tab.c parser.tab.h parser.output etapa3
