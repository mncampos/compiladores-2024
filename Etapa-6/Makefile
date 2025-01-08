# MATEUS NUNES CAMPOS - 00268613
# GUILHERME DE SOUSA CIRUMBOLO - 00330049
# Makefile para etapa 6 do trabalho de compiladores

CC = gcc
CFLAGS = -g -Wall -Iinclude
LIBS = -lfl

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
FLEX_DIR = flex
BISON_DIR = bison

# Fontes
SCANNER = $(FLEX_DIR)/scanner.l
PARSER = $(BISON_DIR)/parser.y
OBJ = $(SRC_DIR)/type_lex.o $(SRC_DIR)/tree.o $(BISON_DIR)/parser.tab.o $(FLEX_DIR)/lex.yy.o $(SRC_DIR)/main.o $(SRC_DIR)/stack.o $(SRC_DIR)/symbol_table.o $(SRC_DIR)/iloc.o $(SRC_DIR)/linked_list.o $(SRC_DIR)/assembly.o

# Alvo principal
all: etapa6

# Regra para gerar lex.yy.c
$(FLEX_DIR)/lex.yy.c: $(SCANNER)
	flex -o $@ $(SCANNER)

# Regra para gerar parser.tab.c e parser.tab.h
$(BISON_DIR)/parser.tab.c $(BISON_DIR)/parser.tab.h: $(PARSER)
	bison -d -o $(BISON_DIR)/parser.tab.c $(PARSER) -Wcounterexamples

# Regras para compilar cada arquivo objeto
$(SRC_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FLEX_DIR)/lex.yy.o: $(FLEX_DIR)/lex.yy.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BISON_DIR)/parser.tab.o: $(BISON_DIR)/parser.tab.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/type_lex.o: $(SRC_DIR)/type_lex.c $(INCLUDE_DIR)/type_lex.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/tree.o: $(SRC_DIR)/tree.c $(INCLUDE_DIR)/tree.h $(INCLUDE_DIR)/type_lex.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/stack.o: $(SRC_DIR)/stack.c $(INCLUDE_DIR)/stack.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/symbol_table.o: $(SRC_DIR)/symbol_table.c $(INCLUDE_DIR)/symbol_table.h $(INCLUDE_DIR)/stack.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/iloc.o: $(SRC_DIR)/iloc.c $(INCLUDE_DIR)/iloc.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/linked_list.o: $(SRC_DIR)/linked_list.c $(INCLUDE_DIR)/linked_list.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/assembly.o: $(SRC_DIR)/assembly.c $(INCLUDE_DIR)/assembly.h
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para construir o executável
etapa6: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

# Regra de limpeza
clean:
	rm -f $(OBJ) $(FLEX_DIR)/lex.yy.c $(FLEX_DIR)/lex.yy.o \
	$(BISON_DIR)/parser.tab.c $(BISON_DIR)/parser.tab.h \
	$(BISON_DIR)/parser.tab.o etapa6
