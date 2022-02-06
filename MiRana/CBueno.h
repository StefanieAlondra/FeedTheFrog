#pragma once
#include "CPersonaje.h"

class Bueno:public Personaje
{
	int	m_Puntos;

public:
	static const int INICIO=0;
	static const int ACTIVO=1;
	static const int DISPARANDO=2;
	static const int EXPLOTANDO=3;
	static const int MUERTO=4;
	Bueno(void);
	~Bueno(void);

	void	Mueve			(ENTRADA & dc);
	int		Puntos			(void);
	void	CreaPunto		(void);
	int		HayColision		(Personaje & objeto);
};