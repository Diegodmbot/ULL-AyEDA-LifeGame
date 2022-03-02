/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Algoritmo y Estructuras de Datos Avanzados
 * @file: P01DiegoDiazMoron/main
 * @author: Diego Diaz Moron
 * @mail: alu0101337975@ull.edu.es
 * @date: 22/02/22
 * @version: 0.1
 * @brief: El Juego de la Vida.
 */

#include <unistd.h>  // sleep

#include <cstring>  // strcmp

#include "../include/Cell.hpp"
#include "../include/Grid.hpp"

/**
 * @brief Función que explica el funcionamiento del programa.
 *
 */
void Help(void);

int main(int argc, char *argv[]) {
  if (argc == 2 && strcmp(argv[1], "--help") == 0) {
    Help();
    return 0;
  }
  if (argc != 2) {
    std::cout << "Modo de empleo:\n"
                 "- make: compila el programa\n"
                 "- make run: compila y ejecuta el programa\n"
                 "- make help: muestra la ayuda del programa\n"
                 "Pruebe './lifegame --help' para mas informacion."
              << std::endl;
  } else {
    Grid world(argv[1]);
    while (true) {
      world.Write();
      world.NextGeneration();
      sleep(1);
    }
    return 0;
  }
}

void Help(void) {
  std::cout
      << "El programa se basa en el popular Juego de la Vida. "
         "Para más información se recomienda ver:\n "
         "https://es.wikipedia.org/wiki/Juego_de_la_vida\n"
         "inputdata.txt es el fichero de texto que recoge: el numero de "
         "turnos, el tamaño del mapa, el numero de celulas y sus coordenadas.\n"
         "Modo de empleo:\n"
         "- make: compila el programa\n"
         "- make run: compila y ejecuta el programa\n"
         "- make help: muestra la ayuda del programa\n"
         "Pruebe './lifegame --help' para mas informacion."
      << std::endl;
}