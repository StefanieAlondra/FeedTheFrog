#pragma once

/* Version con Arreglo con crecimiento amortizado*/
class CSpriteAnimado
{

private:
	CImage	Sprite;				//La imagen a mostrar
	int		m_iNumSprites;			//Indica el numero de Sprites máximo en el elemento
			//Indica cual es el Sprite en curso
	int		m_iTicsPorFotograma;	//indica cuantos tics de reloj por fotograma se dejan pasar antes de la siguiente animacion
	COLORREF m_ColorTransparente;
	HINSTANCE	m_hInstancia;		//la instancia en la que estamos ejecutando
	int		m_Tic;

	//LDobleEnlazada <int> m_ListaIdImagenes;
	int *m_ListaIdImagenes;
	int m_iNumImagenes;
	

public:
	CSpriteAnimado(void);
	~CSpriteAnimado(void);
	int		m_iNumSpriteActual;
	void	EliminaListaImagenes(void);
	void	InsertaImagen		(UINT idImagenRes);
	void	SeleccionaImagen	(int i);		//Selecciona la imagen a mostrar
	void	SeleccionaImagenAleatoria	(void);		//Selecciona una imagen al azar
	int	SeleccionaSiguienteImagen(void); //asume que hay un ciclo
	void	PixelesporTic		(int iPxT);		//Numero de Pixeles por Tic. Este factor permite aumentar la velocidad
	void    TicsPorFotograma    (int iTxF);     //COntrola la velocidad de cambio del fotograma
	int     TicsPorFotograma    (void);
	void	Carga				(LPCTSTR szArchivo);		//Carga un recurso por nombre de archivo
	void	Carga				(UINT	NombreRecurso); //Carga un recurso binario
	CImage & MapaBits			(void);
	void	ColorTransparencia	(COLORREF cColor); //Establece el color de la transparencia del Sprite
	COLORREF ColorTransparencia(void);
	void	DestruyeBitMap(void);
	void	Pinta(CDC &dc, int columna, int renglon);
	int		NumImagenes		(void);

};

