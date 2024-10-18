/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Computabilidad y Algoritmia
** Curso: 2º
** Practica 6: Autómatas Regulares
** Autor: Marco Pérez Padilla
** Correo: alu0101469348@ull.edu.es
** Fecha: 18/10/2024

** Archivo state.cc: Implementación de la clase State
**      Contiene los métodos de la clase State
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      18/10/2024 - Creacion (primera version) del codigo
**/

#include "state.h"

void State::AddTransition (Symbol trans_symbol, long unsigned int trans__state_id) {
  ++number_transitions_;
  transitions_.insert(std::pair<Symbol, long unsigned int> (trans_symbol, trans__state_id));
}