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

** Archivo NFA.cc: Implementación de la clase NFA
**      Contiene los métodos de la clase NFA
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      18/10/2024 - Creacion (primera version) del codigo
**      19/10/2024 - Adición de métodos de adición de estados, y obtener estados
**/

#include <sstream>

#include "NFA.h"
#include "state.h"
#include "check_functions.h"

const State& NFA::getState (long unsigned id) const {
  if (0 <= id < states_.size()) {
    return states_[id];
  } else {
    std::cerr << "Error: Cannot access " << id << " state. It must be in range [0-" << states_.size() - 1 << "]" << std::endl;
    exit (EXIT_FAILURE);
  }
}


NFA::NFA (const std::string& file_fa){
  ReadAutomaton(file_fa);
}


void NFA::ReadAutomaton (const std::string& file_fa) {
  std::ifstream input_fa(file_fa);
  if (!input_fa.is_open()) {
    std::cerr << "Error: File couldn't be opened " << file_fa << ". Try \"p04_code_anylizer --help\" for further information " << std::endl;
    return;
  }

  std::string line;

  long unsigned int states {0};
  long unsigned int start {0};
  long unsigned int id {0};
  long unsigned int num_transitions {0};
  bool non_accept;
  Alphabet alphabet;

  //Reading the alphabet  
  if (std::getline(input_fa, line)) {
    for (char chr : line) {
      if (chr != ' ') {
        alphabet.AddSymbol(Symbol(chr));
      }
    }
  }

  //Checking the alphabet
  if (alphabet.Empty()) {
    std::cerr << "Incorrect input format in line 1: Alphabet cannot be empty." << std::endl;
    return;
  }

  //Reading number of total states
  if (std::getline(input_fa, line)) {
    if (ValidateNumber(line)) {
      states = std::stoi(line);
      if (states <= 0) {
        std::cerr << "Error: Number of states cannot be negative nor 0.\n"
                  << "Try 'p06_automata_simulator --help' for further information\n";
        return;
      }
    } else {
      std::cerr << "Error: Incorrect format in total state numbers line.\n"
                << "Try 'p06_automata_simulator --help' for further information\n";
      return; 
    }
  }

  //Reading Start State
  if (std::getline(input_fa, line)) {
    if (ValidateNumber(line)) {
      start = std::stoi(line);
      if (start < 0) {
        std::cerr << "Error: Start state cannot be negative.\n"
                  << "Try 'p06_automata_simulator --help' for further information\n";
        return;
      }
    } else if (start >= states) {
        std::cerr << "Error: Start state must be between range: [0-" << states - 1 << "] "<< std::endl;
        return;
      } else {
      std::cerr << "Error: Incorrect format in Start state line.\n"
                << "Try 'p06_automata_simulator --help' for further information\n";
      return; 
    }
  }

  long unsigned int iteration_counter {3};

  //Reading each state
  for (long unsigned int i {0}; i < states; ++i) {
    if (std::getline(input_fa, line)) {
      std::istringstream single_line (line);
      single_line >> id >> non_accept >> num_transitions;

      if (id >= states) {
        std::cerr << "Error in line " << iteration_counter + 1 <<  ": Current state must be between range: [0-" << states - 1 << "] "<< std::endl;
        return;
      }

      State state(id, non_accept, num_transitions);

      for (long unsigned int j {0}; j < state.getNumberTransitions(); ++j) {
        char symbol;
        long unsigned dest_state;
        if (single_line >> symbol >> dest_state) {
          Symbol trans_symbol (symbol);

          if (!alphabet.Find(symbol)) {
            std::cerr << "Fatal error in line "<< iteration_counter + 1 << ": Transition symbol does not belong to described alphabet." << std::endl;
            return;
          }

          if (dest_state >= states) {
            std::cerr << "Error in line " << iteration_counter + 1 <<  ": Destiny state must be between range: [0-" << states - 1 << "] "<< std::endl;
            return;
          }

          state.AddTransition(trans_symbol, dest_state);
        } else {
          std::cerr << "Error in line " << iteration_counter + 1 << ": Incorrect format in transitions.\n"
                    << "Try 'p06_automata_simulator --help' for further information\n";
          return;
        }
      }
      ++iteration_counter;
      AddState(state);
    }
  }
}