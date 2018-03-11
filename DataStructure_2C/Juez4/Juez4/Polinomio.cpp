#include "Polinomio.h"

#include <string>
#include <stdexcept>
#include <algorithm>

#include "Polinomio.h"

Polinomio::~Polinomio() {}

void Polinomio::addMonomio(Monomio mon) {
	vcMonomios.push_back(mon);
}

int Polinomio::calculatePolinomio(int valor) {
	int totalPolinomio = 0;
	for (int i = 0; i < vcMonomios.size(); i++){
		totalPolinomio += vcMonomios[i].calculateMonomio(valor);
	}
	return totalPolinomio;
}