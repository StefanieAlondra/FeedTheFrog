#pragma once

#include "SpriteAnimado.h"
#include "resource.h"
#include "CBueno.h"
#include "CPersonaje.h"
#include "CMalo.h"

#define NUM_MALOS 5
#define NUM_PERSONAJES 6 

class CJuego{
	static const int JUEGO_INICIANDO=0;
	static const int JUEGO_JUGANDO=1;
	static const int JUEGO_FINALIZANDO=2;
	static const int JUEGO_FINALIZADO=3;
public:
	CJuego(void);
	~CJuego(void);
	int variable;
	
protected:
	int m_iEstadoJuego;
	CSpriteAnimado m_fondo;
	int m_iNumElementosTotal;
	Malo m_Malos[NUM_MALOS];
	Bueno m_Bueno;
	Personaje* m_elemento[NUM_PERSONAJES];

public:
	void Pinta();
	void Pinta(CDC &NuevaImagenDC,CDialogEx *m_MiVentana);
	void Mueve(ENTRADA &datos);
	int DetectaColision(ENTRADA &entrada);
	Bueno & getBueno(void)
	{
		return m_Bueno;
	}
	int Jugar(ENTRADA &datos);
	int	 FinJuego(void);	
};
