/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Computabilidad y Algoritmia
** Curso: 2º
** Practica 6: Autómatas Finitos
** Autor: Marco Pérez Padilla
** Correo: alu0101469348@ull.edu.es
** Fecha: 18/10/2024

** Archivo p06_finite_automaton.cc: programa cliente.
**      Contiene la funcion main del proyecto que usa las clases programa, comentario, variable, bucle, principal
**      para analizar un codigo en c++ pasado por linea de comandos. Contiene así mismo las funciones de ayuda y validación.
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      18/10/2024 - Creacion (primera version) del codigo
**      19/10/2024 - Finalización del código fuente
**/

#include <iostream>

#include "check_functions.h"
#include "NFA.h"

int main (int argc, char* argv[]) {
  ValidateCommand(argc, argv);
  NFA nfa(argv[1]);
  nfa.SimulateAutomaton(argv[2]);
  return 0;
}