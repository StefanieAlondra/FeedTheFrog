#pragma once
#include "stdafx.h"
#include <string.h>
#include "SpriteAnimado.h"
#include <list>

#define NUMPIXELESPORTIC	5

#define ARRIBA		-1
#define ABAJO		1
#define IZQUIERDA	-1
#define DERECHA		1

#define LIMSUP	(dc.top)
#define LIMINF	(dc.bottom)
#define LIMIZQ	(dc.left)
#define LIMDER	(dc.right)
using namespace std;

struct ENTRADA
{
	CRect  Rect;
	int Tecla;
};

class Personaje
{
protected:
	int	m_iRen;
	int	m_iCol;
	CSpriteAnimado	m_Sprite;
						
	int	m_iVectorHor;
	int	m_iVectorVer;
	int	m_iPixelesPorTic;
	int	m_iEstado;
			
	int	m_bVisible;			
	unsigned long m_Tic;	

public:
	static	const int	VISIBLE = 0;
	static	const int	INVISIBLE = 1;

	Personaje(void);
	int		Renglon		(void);
	void	Renglon		(int);
	int		Columna		(void);
	void	Columna		(int);
	void	Asigna		(int, int);
	int		Estado		(void);
	void	Estado		(int Estado);
	int		EsVisible	(void);
	void	Visible		(int);
	int		HayColision	(Personaje & objeto);
	CSpriteAnimado&	Sprite		(void);
	virtual void	Pinta		(CDC&);
	virtual void	Mueve		(ENTRADA &)=0;
};


