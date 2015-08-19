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

/**> HEADER FILES <**/
#include "Game.h"
#include "Text.h"
#include "ESshit.h"

extern TGAImageRec texture;

void Text::LoadFontTexture(const char *fileName)
{
	GLuint		type;

	LOGFUNC;

	LOG(std::string("Loading font texture...") + fileName);

	Game::LoadTexture(fileName, &FontTexture, false, false);
/*
	//Load Image
	//LoadTGA( fileName ); 
	unsigned char fileNamep[256];
	CopyCStringToPascal(fileName,fileNamep);
	//Load Image
	upload_image( fileNamep ,1); 

	//Is it valid?
	if(1==1){
		//Alpha channel?
		if ( texture.bpp == 24 )
			type = GL_RGB;
		else
			type = GL_RGBA;

		glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

		if(!FontTexture)glGenTextures( 1, &FontTexture );
		glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

		glBindTexture( GL_TEXTURE_2D, FontTexture);
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

		gluBuild2DMipmaps( GL_TEXTURE_2D, type, texture.sizeX, texture.sizeY, type, GL_UNSIGNED_BYTE, texture.data );
	}
*/
	if (base)
	{
#if !defined(USE_GLES)
		glDeleteLists(base, 512);
#endif
		base = 0;
	}
}

#if defined(USE_GLES)
void Text::BuildFont()
{
    // Dummy Function
}

void Text::glPrintChar( int base, int len, char* str )
{
	float	cx;											// Holds Our X Character Coord
	float	cy;											// Holds Our Y Character Coord
    int     loop;
    int     i;

    glBindTexture(GL_TEXTURE_2D, FontTexture);			// Select Our Font Texture
    for (i=0; i<len; i++)
    {
        loop = base + str[i];
        if (loop < 256)
        {
            cx=float(loop%16)/16.0f;						// X Position Of Current Character
            cy=float(loop/16)/16.0f;						// Y Position Of Current Character
        }
        else
        {
            cx=float((loop-256)%16)/16.0f;						// X Position Of Current Character
            cy=float((loop-256)/16)/16.0f;						// Y Position Of Current Character
        }

        GLfloat tex[] = {
            cx,         1-cy-0.0625f+.001,
            cx+0.0625f, 1-cy-0.0625f+.001,
            cx+0.0625f, 1-cy-.001,
            cx,         1-cy-+.001
        };
        GLfloat vtx[] = {
            0,  0,
            16, 0,
            16, 16,
            0,  16
        };

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        glVertexPointer(2, GL_FLOAT, 0, vtx);
        glTexCoordPointer(2, GL_FLOAT, 0, tex);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);

        if (loop < 256)
            glTranslatef(10,0,0);						// Move To The Right Of The Character
        else
            glTranslatef(8,0,0);						// Move To The Right Of The Character
    }
}

#else
void Text::BuildFont()								// Build Our Font Display List
{
	float	cx;											// Holds Our X Character Coord
	float	cy;											// Holds Our Y Character Coord
	int loop;

	LOGFUNC;

	if (base)
	{
		LOG("Font already created...");
		return;
	}

//	base=glGenLists(256);								// Creating 256 Display Lists
	base=glGenLists(512);								// Creating 256 Display Lists

	glBindTexture(GL_TEXTURE_2D, FontTexture);			// Select Our Font Texture
	for (loop=0; loop<512; loop++)						// Loop Through All 256 Lists
	{
		if (loop < 256)
		{
			cx=float(loop%16)/16.0f;						// X Position Of Current Character
			cy=float(loop/16)/16.0f;						// Y Position Of Current Character
		}
		else
		{
			cx=float((loop-256)%16)/16.0f;						// X Position Of Current Character
			cy=float((loop-256)/16)/16.0f;						// Y Position Of Current Character
		}

		glNewList(base+loop,GL_COMPILE);				// Start Building A List
		glBegin(GL_QUADS);							// Use A Quad For Each Character
		glTexCoord2f(cx,1-cy-0.0625f+.001);			// Texture Coord (Bottom Left)
		glVertex2i(0,0);						// Vertex Coord (Bottom Left)
		glTexCoord2f(cx+0.0625f,1-cy-0.0625f+.001);	// Texture Coord (Bottom Right)
		glVertex2i(16,0);						// Vertex Coord (Bottom Right)
		glTexCoord2f(cx+0.0625f,1-cy-.001);			// Texture Coord (Top Right)
		glVertex2i(16,16);						// Vertex Coord (Top Right)
		glTexCoord2f(cx,1-cy-+.001);					// Texture Coord (Top Left)
		glVertex2i(0,16);						// Vertex Coord (Top Left)
		glEnd();									// Done Building Our Quad (Character)
		if (loop < 256)
			glTranslated(10,0,0);						// Move To The Right Of The Character
		else
			glTranslated(8,0,0);						// Move To The Right Of The Character
		glEndList();									// Done Building The Display List
	}													// Loop Until All 256 Are Built
}
#endif

void Text::glPrint(float x, float y, char *string, int set, float size, float width, float height)	// Where The Printing Happens
{
	glPrint(x, y, string, set, size, width, height, 0, strlen(string));
}

void Text::_glPrint(float x, float y, char *string, int set, float size, float width, float height,int start,int end, int offset)	// Where The Printing Happens
{
	if (set>1)
	{
		set=1;
	}
	glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	glBindTexture(GL_TEXTURE_2D, FontTexture);			// Select Our Font Texture
	glDisable(GL_DEPTH_TEST);							// Disables Depth Testing
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPushMatrix();										// Store The Projection Matrix
		glLoadIdentity();									// Reset The Projection Matrix
		glOrtho(0,width,0,height,-100,100);						// Set Up An Ortho Screen
		glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
		glPushMatrix();										// Store The Modelview Matrix
			glLoadIdentity();
#if defined(USE_GLES)
			glTranslatef(x,y,0);								// Position The Text (0,0 - Bottom Left)
#else
			glTranslated(x,y,0);								// Position The Text (0,0 - Bottom Left)
#endif
			glScalef(size,size,1);									// Reset The Modelview Matrix
#if defined(USE_GLES)
            glPrintChar(base-32+(128*set) + offset, end-start, &string[start] );
#else
			glListBase(base-32+(128*set) + offset);						// Choose The Font Set (0 or 1)
			glCallLists(end-start,GL_BYTE,&string[start]);			// Write The Text To The Screen
#endif
			glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
		glPopMatrix();										// Restore The Old Projection Matrix
		glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glPopMatrix();										// Restore The Old Projection Matrix
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
}

void Text::glPrint(float x, float y, char *string, int set, float size, float width, float height,int start,int end)	// Where The Printing Happens
{
	_glPrint(x, y, string, set, size, width, height, start, end, 0);
}

void Text::glPrintOutline(float x, float y, char *string, int set, float size, float width, float height)	// Where The Printing Happens
{
	glPrintOutline(x, y, string, set, size, width, height, 0, strlen(string));
}

void Text::glPrintOutline(float x, float y, char *string, int set, float size, float width, float height,int start,int end)	// Where The Printing Happens
{
	_glPrint(x, y, string, set, size, width, height, start, end, 256);
}
void Text::glPrintOutlined(float x, float y, char *string, int set, float size, float width, float height)	// Where The Printing Happens
{
	glPrintOutlined(1, 1, 1, x, y, string, set, size, width, height);
}

void Text::glPrintOutlined(float r, float g, float b, float x, float y, char *string, int set, float size, float width, float height)	// Where The Printing Happens
{
	glColor4f(0,0,0,1);
	glPrintOutline( x-2*size,  y-2*size, string,  set,  size*2.5/2,  width,  height);
	glColor4f(r,g,b,1);
	glPrint( x,  y, string,  set,  size,  width,  height);
}

Text::Text()
{
	base = 0;
	FontTexture = 0;
}
Text::~Text()
{
	if (base)
	{
#if !defined(USE_GLES)
		glDeleteLists(base, 512);
#endif
		base = 0;
	}
	if (FontTexture) glDeleteTextures( 1, &FontTexture );
}

