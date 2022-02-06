#include "StdAfx.h"
#include "CMalo.h"
#include "resource.h"


Malo::Malo(void){
	/*m_Sprite.InsertaImagen(IDB_MALO);
	m_Sprite.InsertaImagen(IDB_MALO2);
	m_Sprite.ColorTransparencia(RGB(255,0,0));
	m_Sprite.TicsPorFotograma(2);
	m_Sprite.Carga(IDB_MALO);
	m_Sprite.Carga(IDB_MALO2);*/
	m_iRen=rand()%900;
	m_iCol=rand()%900;
//	Estado(CSatelite::ACTIVA);
	m_iVectorVer=1;
	m_iVectorHor=1;
	m_iPixelesPorTic=3;
}


Malo::~Malo(void)
{
}


void Malo::Mueve(ENTRADA & dc){

	m_iPixelesPorTic=rand()%(dc.Rect.right/40)+1;
	m_Sprite.SeleccionaSiguienteImagen();
	//m_iPixelesPorTic=1;
	Renglon(m_iRen+m_iVectorVer*m_iPixelesPorTic);
	Columna(m_iCol+m_iVectorHor*m_iPixelesPorTic);

	if (m_iVectorHor >0){
		//Este es el unico que toma en cuenta el mapa de bits!!
		if (m_iCol >= dc.Rect.right-1)
			m_iVectorHor=-1;
	}
	else{
		if (m_iCol <= dc.Rect.left+1)
			m_iVectorHor=1;
	}

	if(m_iVectorVer  < 0)	{
		if (m_iRen <= dc.Rect.top+1)
			m_iVectorVer=1;
	}
	else
		if (m_iRen >= dc.Rect.bottom-300)
			m_iVectorVer=-1;

	/*m_NumTicsDesdeDisparo++;
	if (m_NumTicsDesdeDisparo > TicsPorDisparo() && Estado() != CSatelite::INVISIBLE)
	{
		m_NumTicsDesdeDisparo = 0;
		Estado(CSatelite::DISPARANDO);
	}*/
}

void Malo::Crear(UINT idImagen){
	m_Sprite.InsertaImagen(idImagen);
	m_Sprite.ColorTransparencia(RGB(255,0,0));
	m_Sprite.TicsPorFotograma(2);
	m_Sprite.SeleccionaImagen(0);
	m_Sprite.Carga(idImagen);
}