#pragma once
#include <iostream>
#include <string>

using namespace std;

class Prenda {
protected:
	double precioUnitario;
	double cantidadStock;
	string calidad;
	int RN;
	double unidades;
	vector<string> tipo;
	double descuento;

public:
	double getPrecioUnitario() { return precioUnitario; }
	double getCantidadStock() { return cantidadStock; }
	string getCalidad() { return calidad; }
	int getRN() { return RN; }
	double getUnidades() { return unidades; }
	vector<string> getType() { return tipo; }

	void setRN(int RN) { this->RN = RN; }

	virtual double calcularDescuentoTipo() { return descuento; };
};
