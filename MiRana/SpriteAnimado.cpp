#include "StdAfx.h"
#include "SpriteAnimado.h"


CSpriteAnimado::CSpriteAnimado(void)
{
	CImage	Sprite;				//La imagen a mostrar
	m_iNumSprites=0;
	m_iNumSpriteActual=0;
	m_iTicsPorFotograma=1;
	m_Tic=0;
	m_iNumImagenes=1;
	m_ListaIdImagenes = new int[1];
}


CSpriteAnimado::~CSpriteAnimado(void){
}
void CSpriteAnimado::TicsPorFotograma(int iTxF){
	m_iTicsPorFotograma = iTxF;
}
int	CSpriteAnimado::TicsPorFotograma(void){
	return m_iTicsPorFotograma ;
}
void CSpriteAnimado::InsertaImagen(UINT idImagenRes){
	int *piArr;
	int *piAux;

	m_iNumSprites++;
	
	if (m_iNumSprites >= m_iNumImagenes / 2 + 1  )
	{		
		m_iNumImagenes++;
		piArr = new int[m_iNumImagenes*2];
		for (int i=0; i<m_iNumImagenes/2; i++)
		{
			piArr[i] = m_ListaIdImagenes[i];
		}
		piAux = m_ListaIdImagenes;
		m_ListaIdImagenes = piArr;
		delete piAux;
		m_iNumImagenes = m_iNumImagenes*2;
	}
	m_ListaIdImagenes[m_iNumSprites-1]=idImagenRes;

}
void CSpriteAnimado::SeleccionaImagen(int i){
	m_iNumSpriteActual=i;
	//m_ListaIdImagenes[i];
}
int	CSpriteAnimado::SeleccionaSiguienteImagen(void){
	
	m_Tic++;
	if (m_Tic % TicsPorFotograma() == 0)
	{
		
		m_iNumSpriteActual++;
		if (m_iNumSpriteActual >= m_iNumSprites)
			m_iNumSpriteActual=0;
		SeleccionaImagen(m_iNumSpriteActual);
		m_Tic=0;
	}
	return m_Tic == 0;
}
void CSpriteAnimado::SeleccionaImagenAleatoria	(void)
{
	SeleccionaImagen(rand()%NumImagenes());
}
void CSpriteAnimado::Carga(LPCTSTR szArchivo)
{
	Sprite.Load(szArchivo);
}
/*

	Carga un recurso binario

*/
void	CSpriteAnimado::Carga	(UINT	NombreRecurso)
{
	if (!MapaBits().IsNull())
	{
		//Pintar usando transparencias en la Columna y renglon actual 
		DestruyeBitMap();
	
	}
	m_hInstancia=AfxGetInstanceHandle();
	Sprite.LoadFromResource(m_hInstancia,NombreRecurso);	
}
CImage & CSpriteAnimado::MapaBits(void)
{
	return Sprite;
}
void CSpriteAnimado::ColorTransparencia(COLORREF cColor)
{
	m_ColorTransparente=cColor;
	Sprite.SetTransparentColor(cColor);
}
COLORREF	CSpriteAnimado::ColorTransparencia(void)
{
	return m_ColorTransparente;
}
void CSpriteAnimado::DestruyeBitMap(void)
{
	Sprite.Destroy();
}

void CSpriteAnimado::Pinta(CDC &dc, int columna, int renglon)
{
	// Pinta no realiza el pintado, lo hace el gesto de contexto
	//por medio del mapa de bits
	//Si el Mapa de bits ya esta cargado en memoria ( si no es nulo)
	
	if (!MapaBits().IsNull())
	{
		//Pintar usando transparencias en la Columna y renglon actual 
		DestruyeBitMap();
		Carga(m_ListaIdImagenes[m_iNumSpriteActual]);
		Sprite.TransparentBlt(dc.m_hDC,columna,renglon,MapaBits().GetWidth(),MapaBits().GetHeight(),this->ColorTransparencia() );	
	}	
}

int		CSpriteAnimado::NumImagenes		(void)
{
	return m_iNumImagenes;
}
void	CSpriteAnimado::EliminaListaImagenes(void)
{	
	m_iNumSprites=0;
	
	delete m_ListaIdImagenes;
	m_iNumImagenes=1;
	m_ListaIdImagenes = new int[1];
}