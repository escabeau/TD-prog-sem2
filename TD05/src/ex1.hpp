#ifndef EX1_HPP
#define EX1_HPP

#include <string>
#include <cstddef> 

size_t hachage_folding(const std::string& chaine, size_t max);
size_t hachage_folding_ordre(const std::string& chaine, size_t max);
size_t hachage_polynomial(const std::string& chaine, size_t p, size_t m);

#endif 
