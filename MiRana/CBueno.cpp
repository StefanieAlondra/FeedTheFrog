#include "StdAfx.h"
#include "CBueno.h"
#include "resource.h"
#include <windows.h>
#include<stdio.h>
#include<stdlib.h>
#include "math.h"


Bueno::Bueno(void){
	m_Sprite.InsertaImagen(IDB_RANA);
	m_Sprite.InsertaImagen(IDB_RANAGOLPE);
	m_Sprite.InsertaImagen(IDB_RANAHAPPY);
	m_Sprite.ColorTransparencia(RGB(255,0,0));
	m_Sprite.TicsPorFotograma(2);
	m_Sprite.Carga(IDB_RANA);

	m_iRen = 600;
	m_iCol = 500;
	m_iEstado = Bueno::INICIO;
	m_Puntos = 0;	
	m_iPixelesPorTic=50;
}

Bueno::~Bueno(void){
}


void Bueno::Mueve(ENTRADA & dc){
	int incremento;
	
	switch(dc.Tecla )
	{
	case VK_LEFT:
		if (m_iCol >= dc.Rect.left+1)
			this->m_iCol-=m_iPixelesPorTic;
		m_Sprite.SeleccionaSiguienteImagen();
		m_Sprite.m_iNumSpriteActual++;
		m_Sprite.SeleccionaSiguienteImagen();
		break;
	case VK_RIGHT:
		if (m_iCol <= dc.Rect.right-150)
			this->m_iCol+=m_iPixelesPorTic;
		m_Sprite.SeleccionaSiguienteImagen();
		m_Sprite.m_iNumSpriteActual++;
		m_Sprite.SeleccionaSiguienteImagen();
		break;
	case VK_UP:
		if (m_iRen >= dc.Rect.top+400)
			this->m_iRen-=m_iPixelesPorTic;
		m_Sprite.SeleccionaSiguienteImagen();
		m_Sprite.m_iNumSpriteActual++;
		m_Sprite.SeleccionaSiguienteImagen();
		break;
	case VK_DOWN:
		if (m_iRen <= dc.Rect.bottom-110)
			this->m_iRen+=m_iPixelesPorTic;
		m_Sprite.SeleccionaSiguienteImagen();
		m_Sprite.m_iNumSpriteActual++;
		m_Sprite.SeleccionaSiguienteImagen();
		break;
	case VK_SPACE:
		Estado(Bueno::DISPARANDO);
		break;
	}
	
}


int Bueno::Puntos(void){
	return m_Puntos;
}

void Bueno::CreaPunto(void){
	m_Puntos+=10;
}


int	Bueno::HayColision(Personaje & objeto){
	int bHayColision=false;
	if ( (Columna()+m_Sprite.MapaBits().GetWidth()/2) > objeto.Columna() &&
		(objeto.Columna()+
		objeto.Sprite().MapaBits().GetWidth()/2)>Columna()){
		if ((Renglon()+Sprite().MapaBits().GetHeight()) > objeto.Renglon() &&
			(objeto.Renglon()+objeto.Sprite().MapaBits().GetHeight())>Renglon()+3*Sprite().MapaBits().GetHeight()/4){
				if(true)
					m_Sprite.SeleccionaImagen(1);
				bHayColision=true;
		}
	}
	return bHayColision;
}
