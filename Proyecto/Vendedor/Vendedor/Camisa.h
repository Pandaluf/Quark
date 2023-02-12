#pragma once
#include "Prenda.h"

class Camisa: public Prenda {
public:

	Camisa(double cantidadStock, double precioUnitario, string calidad, double unidades, int RN, vector<string> tipo) {
		this->cantidadStock = cantidadStock;
		this->precioUnitario = precioUnitario;
		this->calidad = calidad;
		this->unidades = unidades;
		this->RN = RN;
		this->tipo = tipo;
	}

	double calcularDescuentoTipo() {

		if (RN == 1) {
			descuento = -(unidades * precioUnitario * 0.10);
		}
		else {
			if (RN == 2) {
				descuento = (unidades * precioUnitario * 0.03);
			}
		}

		return descuento;
	}
};