
// MiJuego09Dlg.cpp: archivo de implementación
//

#include "stdafx.h"
#include "MiRana.h"
#include "MiRanaDlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include <mmsystem.h>
#include <WinUser.h>
//#include "SpriteAnimado.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cuadro de diálogo de CMiJuego09Dlg




CMiJuego09Dlg::CMiJuego09Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMiJuego09Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CMiJuego09Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMiJuego09Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_KEYDOWN()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON1, &CMiJuego09Dlg::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
//	ON_WM_MOUSEMOVE()
ON_COMMAND(ID_INICIAR, &CMiJuego09Dlg::OnIniciar)
END_MESSAGE_MAP()


// Controladores de mensaje de CMiJuego09Dlg

BOOL CMiJuego09Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Establecer el icono para este cuadro de diálogo. El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	//ShowWindow(SW_NORMAL);
	int DlgWidth,DlgHeight;

		DlgWidth = GetSystemMetrics(SM_CXSCREEN);
	DlgHeight = GetSystemMetrics(SM_CYSCREEN);
	//maximizar la ventana
	//SetWindowPos(&wndTopMost, 0, 0, DlgWidth, DlgHeight, SWP_SHOWWINDOW);
	//para depurar, solo la mitad de la ventana
	SetWindowPos(&wndTopMost, DlgWidth/2, 0,DlgWidth/2 , DlgHeight, SWP_SHOWWINDOW);
	GetClientRect(&entradas.Rect);
	 int x, y;
	 x = juego.getBueno().Sprite().MapaBits().GetWidth()/2;
	 y = juego.getBueno().Sprite().MapaBits().GetHeight()/2;
	 juego.getBueno().Asigna(entradas.Rect.right/2-x,entradas.Rect.bottom/4*3-y);

	// TODO: agregar aquí inicialización adicional


	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CMiJuego09Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono. Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CMiJuego09Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
	
		CDialogEx::OnPaint();			
		CClientDC dc(this); //El gestor al área cliente
		CDC NuevaImagenDC; //El gestor a la nueva imagen
		CBitmap *bmpPantallaAnterior=NULL;//Un mapa de bits que contiene la pantalla activa
		CBitmap bmpNuevoCuadroAnimacion; //Un mapa de bits vacío
		CRect rectTamannoVentana; //Para almacenar el tamaño de la ventana
		//Un GC compatible con el monitor de trabajo
		NuevaImagenDC.CreateCompatibleDC(&dc);
		//Obtener el tamaño de la ventana
		GetClientRect(&rectTamannoVentana);
		bmpNuevoCuadroAnimacion.CreateCompatibleBitmap(
		&dc,rectTamannoVentana.right ,
		rectTamannoVentana.bottom );
		bmpPantallaAnterior = (CBitmap *) NuevaImagenDC.SelectObject(&bmpNuevoCuadroAnimacion);
		//>>>>>>>>>>>>>>>>>>>> Pintar los elementos de animación.
		
		juego.Pinta(NuevaImagenDC, this);

		//>>>>>> Se envia a la pantalla fisica
		dc.BitBlt(0,0,rectTamannoVentana.right , rectTamannoVentana.bottom ,&NuevaImagenDC,0,0,SRCCOPY);
		NuevaImagenDC.SelectObject(bmpPantallaAnterior);
		NuevaImagenDC.DeleteDC();
		
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CMiJuego09Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMiJuego09Dlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{	
	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CMiJuego09Dlg::PreTranslateMessage(MSG* pMsg)
{
	//Inidicar que tecla fue
	if (pMsg->message == WM_KEYDOWN){
		entradas.Tecla = pMsg->wParam;	
		Invalidate();
	}
	//  Detener la tecla 
	if (pMsg->message == WM_KEYUP)
		entradas.Tecla = 0;

	return CDialogEx::PreTranslateMessage(pMsg);
}


BOOL CMiJuego09Dlg::OnEraseBkgnd(CDC* pDC)
{
	// Se elimino el tratamiento por omision

	//CDialogEx::OnEraseBkgnd(pDC);
	return true;
}


void CMiJuego09Dlg::OnBnClickedButton1()
{
	//Inicia el juego
    SetTimer(1,100,NULL);
}


void CMiJuego09Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// Siempre se debe envia el tamaño de la venta de inicio
	GetClientRect(&entradas.Rect);
	juego.Jugar(entradas);
	Invalidate();
 	CDialogEx::OnTimer(nIDEvent);
}


void CMiJuego09Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{	
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMiJuego09Dlg::OnIniciar()
{
	// TODO: Agregue aquí su código de controlador de comandos
		//Inicia el juego
    SetTimer(1,100,NULL);
}
