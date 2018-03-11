#include "Polinomio.h"

#include <string>
#include <stdexcept>
#include <algorithm>

#include "Monomio.h"

Monomio::Monomio(int auxCoefi, int auxExponecial) {
	coeficiente = auxCoefi;
	exponencial = auxExponecial;
}

Monomio::~Monomio() {}

bool Monomio::isEndLine() {
	return (coeficiente == 0) && (exponencial == 0);
}

int Monomio::calculateMonomio(int valor) {
	return (coeficiente * pow(valor, exponencial));
}