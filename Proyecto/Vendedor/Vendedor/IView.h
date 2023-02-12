#pragma once
#include "Vendedor.h"

using namespace std;

class IView {
public:
	virtual void mostrarTexto(Cotizacion cotizacion) = 0; 
	virtual void mostrarTexto(vector<Cotizacion> cotizaciones) = 0;
};