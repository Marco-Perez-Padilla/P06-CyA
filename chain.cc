/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Computabilidad y Algoritmia
** Curso: 2º
** Practica 6: Autómatas Finitos
** Autor: Marco Pérez Padilla
** Correo: alu0101469348@ull.edu.es
** Fecha: 20/09/2024

** Archivo chain.cc: Implemenatción de la clase cadena.
**      Contiene las implementaciones de la clase cadena.
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      20/09/2024 - Creacion (primera version) del codigo
**      23/09/2024 - Adición del método empty
**      24/09/2024 - Manejo de casos en donde el alfabeto no se corresponde a la cadena
**      24/09/2024 - Adición de los métodos prefijos y sufijos 
**      18/10/2024 - Deleción de los métodos prefijos y sufijos para eliminar dependencia de la clase Lenguaje
**/

#include <algorithm>
#include <iostream>
#include <fstream>

#include "chain.h"

/**
 * @brief Method to get the size of a chain (Longitud)
 * @return int size
 */
const int Chain::ChainSize() const {
  if (chain_[0].getSymbol() == '&') return 0;
  else return chain_.size();
}

/**
 * @brief Method Inverse of a chain object
 * @return chain object. Inverse of invoker chain
 */
const Chain Chain::Inverse () const {
  std::vector<Symbol> reversed_chain = chain_;
  std::reverse(reversed_chain.begin(), reversed_chain.end());
  return reversed_chain;
}

/**
 * @brief Addition of new symbols to the chain
 * @param symbol
 * @return Previous chain with the wanted addition
 */
void Chain::AddBack (const Symbol& new_symbol) {
  chain_.push_back(new_symbol);
}

/**
 * @brief Empty method to see if a chain is empty
 * @return bool-type
 */
bool Chain::Empty() const {
    return chain_.empty();
}

/**
 * @brief Overload of < operator
 * @param chain
 * @return bool-type
 */
bool Chain::operator<(const Chain& chain) const {
  return chain_ < chain.getChain(); 
}

/**
 * @brief Overload of == operator
 * @param chain
 * @return bool-type
 */
bool Chain::operator==(const Chain& chain) const {
  return chain_ == chain.getChain();
}

/**
 * @brief Overload of << operator for Chain class
 * @param std::ostream  
 * @param chain
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const Chain& chains) {
  const std::vector<Symbol>& symbols = chains.getChain();
  for (size_t i = 0; i < symbols.size(); ++i) {
    os << symbols[i];
  }
  return os;
}
