#include "StdAfx.h"
#include "CPersonaje.h"


Personaje::Personaje(void){
	m_bVisible=true;	
	m_Sprite.SeleccionaImagen(0);
	m_Sprite.TicsPorFotograma(1);
}

int Personaje::Renglon(void){
	return this->m_iRen ;
}
void Personaje::Renglon(int Ren){
	m_iRen=Ren;
}
int Personaje::Columna(void){
	return this->m_iCol ;
}
void Personaje::Columna(int Col){
	m_iCol=Col;
}
void Personaje::Asigna(int Col, int Ren){
	Columna(Col);
	Renglon(Ren);
}

int	Personaje::Estado(void){
	return m_iEstado;
}

void Personaje::Estado(int Estado){
	m_iEstado= Estado;
}

CSpriteAnimado & Personaje::Sprite(void){
	return m_Sprite;
}

void Personaje::Pinta(CDC &dc){
	m_Sprite.Pinta(dc,Columna(),Renglon());
}

int	Personaje::HayColision(Personaje & objeto){
	int bHayColision=false;
	if ( (Columna()+Sprite().MapaBits().GetWidth()) > objeto.Columna() &&
		(objeto.Columna()+objeto.Sprite().MapaBits().GetWidth())>Columna()) {
		if ((Renglon()+Sprite().MapaBits().GetHeight()) > objeto.Renglon() &&
			(objeto.Renglon()+objeto.Sprite().MapaBits().GetHeight())>Renglon()){
			bHayColision=true;
		}
	}
	return bHayColision;
}

int	Personaje::EsVisible(void){
	return m_bVisible;
}

void Personaje::Visible(int visible){
	m_bVisible=visible;
}
