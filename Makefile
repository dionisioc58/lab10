INC_DIR = ./include
SRC_DIR = ./src
DOC_DIR = ./doc
OBJ_DIR = ./build
LIB_DIR = ./lib

CC      = g++
CFLAGS  = -Wall -pedantic -std=c++11 -ansi -I. -I$(INC_DIR) -g
ARCHIVE = ar

linux: clean dionisio.a dionisio.so prog_estatico prog_dinamico doxy

windows: clean dionisio.lib dionisio.dll prog_estatico.exe prog_dinamico.exe doxy

#LINUX
dionisio.a: $(SRC_DIR)/dionisio.cpp $(INC_DIR)/erros.h $(INC_DIR)/pilha.h $(INC_DIR)/fila.h $(INC_DIR)/lista.h $(INC_DIR)/buscas.h $(INC_DIR)/ordenacoes.h $(INC_DIR)/dionisio.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/dionisio.cpp -o $(OBJ_DIR)/dionisio.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/dionisio.o
	@echo "+++ [Biblioteca estatica criada em $(LIB_DIR)/$@] +++"

dionisio.so: $(SRC_DIR)/dionisio.cpp $(INC_DIR)/erros.h $(INC_DIR)/pilha.h $(INC_DIR)/fila.h $(INC_DIR)/lista.h $(INC_DIR)/buscas.h $(INC_DIR)/ordenacoes.h $(INC_DIR)/dionisio.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/dionisio.cpp -o $(OBJ_DIR)/dionisio.o
	$(CC) -shared -fPIC -o $(LIB_DIR)/$@ $(OBJ_DIR)/dionisio.o
	@echo "+++ [Biblioteca dinamica criada em $(LIB_DIR)/$@] +++"

prog_estatico:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/dionisio.a -o $(OBJ_DIR)/$@

prog_dinamico:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/dionisio.so -o $(OBJ_DIR)/$@


#WINDOWS
dionisio.lib: $(SRC_DIR)/dionisio.cpp $(INC_DIR)/erros.h $(INC_DIR)/pilha.h $(INC_DIR)/fila.h $(INC_DIR)/lista.h $(INC_DIR)/buscas.h $(INC_DIR)/ordenacoes.h $(INC_DIR)/dionisio.h
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/dionisio.o
	@echo "+++ [Biblioteca estatica criada em $(LIB_DIR)/$@] +++"

dionisio.dll: $(SRC_DIR)/dionisio.cpp $(INC_DIR)/erros.h $(INC_DIR)/pilha.h $(INC_DIR)/fila.h $(INC_DIR)/lista.h $(INC_DIR)/buscas.h $(INC_DIR)/ordenacoes.h $(INC_DIR)/dionisio.h
	$(CC) -shared -o $(LIB_DIR)/$@ $(OBJ_DIR)/dionisio.o
	@echo "+++ [Biblioteca dinamica criada em $(LIB_DIR)/$@] +++"

prog_estatico.exe:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/dionisio.lib -o $(OBJ_DIR)/$@

prog_dinamico.exe:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/dionisio.dll -o $(OBJ_DIR)/$@

doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

clean:
	@echo "Removendo arquivos objeto e executaveis/binarios..."
	@rm -rf $(OBJ_DIR)/*
	@rm -rf $(DOC_DIR)/*