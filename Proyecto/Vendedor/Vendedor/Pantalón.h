#pragma once
#include "Prenda.h"

class Pantalon : public Prenda {
public:
	Pantalon(double cantidadStock, double precioUnitario, string calidad, double unidades, int RN, vector<string> tipo) {
		this->cantidadStock = cantidadStock;
		this->precioUnitario = precioUnitario;
		this->calidad = calidad;
		this->unidades = unidades;
		this->RN = RN;
		this->tipo = tipo;
	}

	double calcularDescuentoTipo() {
		if (RN == 4) {
			descuento = -(unidades * precioUnitario * 0.12);
		}
		return descuento;
	}
};