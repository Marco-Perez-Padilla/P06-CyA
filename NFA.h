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

** Archivo NFA.h: Declaración de la clase NFA
**      Contiene las declaraciones de la clase NFA
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      18/10/2024 - Creacion (primera version) del codigo
**      19/10/2024 - Adición de métodos de adición de estados, y obtener estados
**/

#ifndef NFA_H
#define NFA_H

#include <iostream>
#include <fstream>
#include <vector>

#include "alphabet.h"
#include "state.h"

class NFA {
 private:
  Alphabet alphabet_;
  State start_;
  std::vector<State> states_;
  
 public:
  NFA (const std::string& input_fa);

  const Alphabet& GetAlphabet () const {return alphabet_;}
  const State& getStart () const {return start_;}
  const State& getState (long unsigned id) const;

  void AddState (const State& state) {states_.push_back(state);}
  void ReadAutomaton (const std::string& input_fa);
};

#endif