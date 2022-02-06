
// MiJuego09.h: archivo de encabezado principal para la aplicación PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// Símbolos principales


// CMiJuego09App:
// Consulte la sección MiJuego09.cpp para obtener información sobre la implementación de esta clase
//

class CMiJuego09App : public CWinApp
{
public:
	CMiJuego09App();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación

	DECLARE_MESSAGE_MAP()
};

extern CMiJuego09App theApp;