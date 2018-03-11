#include "Complejo.h"

#include <string>
#include <stdexcept>
#include <algorithm>

Complejo::Complejo(float auxReal, float auxImag, int auxIter) {
	numeroReal = auxReal;
	numeroImag = auxImag;
	numeroIter = auxIter;
}

Complejo::~Complejo() {}

Complejo Complejo::operator+(Complejo const& that) const {
	Complejo comp;
	comp.numeroReal = that.numeroReal + numeroReal;
	comp.numeroImag = that.numeroImag + numeroImag;
	comp.numeroIter = that.numeroIter;
	return comp;
}

Complejo Complejo::operator*(Complejo const& that) const {
	Complejo comp;
	comp.numeroReal = (that.numeroReal * numeroReal) - (that.numeroImag * numeroImag);
	comp.numeroImag = (that.numeroReal * numeroImag) + (that.numeroImag * numeroReal);
	comp.numeroIter = that.numeroIter;
	return comp;
}

/*Complejo Complejo::operator^(int const& that) const {
	Complejo comp;
	comp.numeroReal = pow(numeroReal, that);
	comp.numeroImag = pow(numeroReal, that);
	comp.numeroIter = numeroIter;
	return comp;
}*/

int Complejo::operator%(Complejo const& that) const {
	return sqrt((numeroReal * numeroReal) + (numeroImag * numeroImag));
}

int Complejo::get_numeroIter() {
	return numeroIter;
}

