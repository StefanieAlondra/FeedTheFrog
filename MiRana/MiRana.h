
// MiJuego09.h: archivo de encabezado principal para la aplicaci�n PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// S�mbolos principales


// CMiJuego09App:
// Consulte la secci�n MiJuego09.cpp para obtener informaci�n sobre la implementaci�n de esta clase
//

class CMiJuego09App : public CWinApp
{
public:
	CMiJuego09App();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementaci�n

	DECLARE_MESSAGE_MAP()
};

extern CMiJuego09App theApp;