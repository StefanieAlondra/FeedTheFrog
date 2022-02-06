#include "StdAfx.h"
#include "CJuego.h"
#include "SpriteAnimado.h"
#include "resource.h"


CJuego::CJuego(void){
	srand((unsigned)time(NULL));

	m_fondo.InsertaImagen(ID_FONDO);
	m_fondo.ColorTransparencia(RGB(255,255,0));
	m_fondo.TicsPorFotograma(10000);
	m_fondo.SeleccionaImagen(0);
	m_fondo.Carga(ID_FONDO);

	//for (int i=0; i< NUM_MALOS; i++)
	//{
	//	m_Malos[i].Sprite().InsertaImagen(IDB_MARIPOSA);
	//	m_Malos[i].Sprite().ColorTransparencia(RGB(255,0,0));
	//	m_Malos[i].Sprite().SeleccionaImagen(0);
	//	m_Malos[i].Sprite().Carga(IDB_MARIPOSA);
	//}
	m_Malos[0].Crear(IDB_MALO);
	m_Malos[1].Crear(IDB_MALO2);
	m_Malos[2].Crear(IDB_MARIPOSA);
	m_Malos[3].Crear(IDB_MALO2);
	m_Malos[4].Crear(IDB_MALO);


	int j=0;
	m_elemento[j++] = &m_Bueno;

	for (int i=0; i < NUM_MALOS; i++){
		m_elemento[j++] = &m_Malos[i];
	}

	m_iNumElementosTotal = NUM_MALOS+1;
	
	m_iEstadoJuego = CJuego::JUEGO_INICIANDO;
}

CJuego::~CJuego(void){
}

void CJuego::Pinta(CDC &NuevaImagenDC,CDialogEx *m_MiVentana){
	CRect rect;

	m_MiVentana->GetClientRect(&rect);
	
	ASSERT(NuevaImagenDC!= NULL);

	m_fondo.Pinta(NuevaImagenDC,0,0);

	//NuevaImagenDC.SetBkMode(TRANSPARENT);
	/*NuevaImagenDC.SetTextColor(RGB(255, 255, 0));*/
	
	for (int i=0;i< m_iNumElementosTotal; i++)
			m_elemento[i]->Pinta(NuevaImagenDC);
}
	
void CJuego::Pinta(){
	Beep(440,500);
}

void CJuego::Mueve(ENTRADA &rect){
	int i;
	for (i = 0;i < m_iNumElementosTotal; i++)
		m_elemento[i]->Mueve(rect);
	m_iEstadoJuego = CJuego::JUEGO_JUGANDO;
}

int CJuego::DetectaColision(ENTRADA &entrada){
	int i,j;
	int bHayColision = 0;
	for (i = 0; i < NUM_MALOS; i++){
		if (m_Bueno.HayColision(m_Malos[i])){
			Beep(440,500);
			//PlaySound(_T("Explosion.wav"),NULL,SND_FILENAME|SND_ASYNC);
			m_Malos[i].Columna(rand()%entrada.Rect.right);
			m_Malos[i].Renglon(rand()%entrada.Rect.bottom);
			bHayColision = 1;
			m_Bueno.CreaPunto();

		}
	}	
	return bHayColision;
}

int	CJuego::FinJuego(void){
	int i;
	int HayVisibles = 1;
	m_iEstadoJuego = CJuego::JUEGO_FINALIZANDO;
	return HayVisibles;
}

int CJuego::Jugar(ENTRADA &entrada){
	int bContinuarJugando=true;
	if (m_iEstadoJuego == CJuego::JUEGO_INICIANDO ||m_iEstadoJuego == CJuego::JUEGO_JUGANDO){
		Mueve(entrada);
		DetectaColision(entrada);
		if (m_Bueno.Estado() == Bueno::MUERTO)
			this->m_iEstadoJuego = CJuego::JUEGO_FINALIZANDO;
	}
	else{
		if (!FinJuego())
			bContinuarJugando=false;
	}
	return bContinuarJugando;
}