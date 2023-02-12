#pragma once
#include "Vendedor.h"
#include "Tienda.h"
#include "IView.h"
#include "Camisa.h"
#include "Pantalón.h"
#include "Prenda.h"

class Presenter {
private:
	Vendedor* vendedor;
	Tienda* tienda;
	IView* iview;
	short codigoVendedor;
public:
	Presenter(IView* iview) {
		this->iview = iview;
		codigoVendedor = 1;
		vendedor = new Vendedor("Julio", "Barrios", codigoVendedor++);
		tienda = new Tienda("Ripley", "Cercado de Lima");
	}

	void insertarPrenda(double precioUnitario, string calidad, int unidades, int RN, vector<string> tipo) {
		if (tipo[0] == "Camisa") {
			Camisa* prenda1 = new Camisa(tienda->totalCamisas(), precioUnitario, calidad, unidades, RN, tipo);
			tienda->contabilizar(prenda1);
			vendedor->realizarCotizacion(prenda1);
		}
		else {
			Pantalon* prenda = new Pantalon(tienda->totalPantalon(), precioUnitario, calidad, unidades, RN, tipo);
			tienda->contabilizar(prenda);
			vendedor->realizarCotizacion(prenda);
		}
		
		system("cls");
		iview->mostrarTexto(vendedor->getCotizaciones()[vendedor->getCotizaciones().size() - 1]);
	}

	void mostrarCotizaciones() {
		iview->mostrarTexto(vendedor->getCotizaciones());
	}

	Tienda* getTienda() { return tienda; }
	Vendedor* getVendedor() { return vendedor; }
};