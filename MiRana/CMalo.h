#pragma once
#include "CPersonaje.h"
#include "windows.h"

class Malo : public Personaje{
public:
	Malo(void);
	~Malo(void);

	void Mueve(ENTRADA & dc);
	void Crear(UINT idImagenRes);
};

