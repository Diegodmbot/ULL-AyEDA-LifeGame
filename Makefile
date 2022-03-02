# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Algoritmo y Estructuras de Datos Avanzados
# @file: P01DiegoDiazMoron/Makefile
# @author: Diego Diaz Moron
# @mail: alu0101337975@ull.edu.es
# @date: 22/02/22
# @version: 0.1
# @brief: El Juego de la Vida.

CXX		  := g++
CXX_FLAGS := -Wall -Wextra -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include

LIBRARIES	:=
EXECUTABLE	:= lifegame
FILE := inputdata.txt
HELP := --help

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE) $(FILE)


clean:
	-rm $(BIN)/$(EXECUTABLE)

help:
	clear
	./$(BIN)/$(EXECUTABLE) $(HELP)
