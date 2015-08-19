/*
Copyright (C) 2003, 2010 - Wolfire Games

This file is part of Lugaru.

Lugaru is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#ifndef USE_GLES
	#define USE_GLES 1
#endif

#ifndef _LUGARU_GL_H_
#define _LUGARU_GL_H_


#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <string>

//#define GL_GLEXT_PROTOTYPES 1
#if defined(USE_GLES)
// #include "GL/Regal.h"
#include "GLES/gl.h"
#include "GLES/glext.h"
typedef double GLdouble;
#include "GL/glu.h"

#define GL_MODELVIEW_MATRIX			0x0BA6
#define GL_PROJECTION_MATRIX              0x0BA7
#define GL_TEXTURE0_ARB                   0x84C0
//#include "GL/gl.h"
//#include "GL/glext.h"
//#include "GL/glu.h"


#define GL_CLAMP        GL_CLAMP_TO_EDGE
//#define glOrtho         glOrthof
#define glClearDepth    glClearDepthf

#define BUFFER_OFFSET(i) ((char*)NULL + (i))
#else
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glext.h"
#include "MacCompatibility.h"
#endif

#if !PLATFORM_MACOSX
struct RGBColor
{
	unsigned short red;
	unsigned short green;
	unsigned short blue;
};
typedef struct RGBColor RGBColor;
typedef RGBColor * RGBColorPtr;
#endif

using namespace std;

/* !!! FIXME: until we replace logger better. --ryan. */
#define LOGFUNC
void LOG(const std::string &fmt, ...);

#endif


