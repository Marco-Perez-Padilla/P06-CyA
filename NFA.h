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
**      Enlaces de interes:
**          https://www.geeksforgeeks.org/multimap-equal_range-in-c-stl/ 

** Historial de revisiones:
**      18/10/2024 - Creacion (primera version) del codigo
**      19/10/2024 - Adición de métodos de adición de estados, y operador []
**      19/10/2024 - Adición de método simulador de Autómatas
**/

#ifndef NFA_H
#define NFA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "alphabet.h"
#include "state.h"

class NFA {
 private:
  Alphabet alphabet_;
  State start_;
  std::multimap<long unsigned int, State> states_;
  
 public:
  //Constructor. Requires a correct input file
  NFA (const std::string& input_fa);

  //Getters
  const Alphabet& GetAlphabet () const {return alphabet_;}
  const State& getStart () const {return start_;}
  const std::multimap<long unsigned int, State>& getStates () const {return states_;}

  //Methods
  void AddState (const State& state) {states_.insert({state.getId(), state});} //Adds states to the NFA.
  void ProcessAutomaton (const std::string& file_fa); //Reads the input file.
  void SimulateAutomaton (const std::string& file_txt);

  //Operators
  std::vector<State> operator[](const long unsigned int id) const;
};

#endif