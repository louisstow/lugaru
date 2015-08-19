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

#include "Skybox.h"
#include "Game.h"
#include "ESshit.h"

extern float viewdistance;
extern int detail;
extern bool trilinear;
extern float blurness;
extern int environment;
extern TGAImageRec texture;
extern bool skyboxtexture;
extern float skyboxr;
extern float skyboxg;
extern float skyboxb;
extern int tutoriallevel;

bool	SkyBox::load( const char *ffront,const char *fleft,const char *fback,const char *fright,const char *fup,const char *fdown,const char *fcloud,const char *freflect)
{
/*	static GLuint		type;
	unsigned char fileNamep[256];
*/
	LOGFUNC;
	fprintf(stderr, "SKYBOX %s\n", ffront);
	fprintf(stderr, "SKYBOX %s\n", fup);

	//front
	Game::LoadTexture(ffront, &front, true, false);
	//left
	Game::LoadTexture(fleft, &left, true, false);
	//back
	Game::LoadTexture(fback, &back, true, false);
	//right
	Game::LoadTexture(fright, &right, true, false);
	//up
	Game::LoadTexture(fup, &up, true, false);
	//down
	Game::LoadTexture(fdown, &down, true, false);
	//cloud
	Game::LoadTexture(fcloud, &cloud, true, false);
	//reflect
	Game::LoadTexture(freflect, &reflect, true, false);
/*
	//front
	CopyCStringToPascal(ffront,fileNamep);
	upload_image( fileNamep ,0); 
	if(1==1){
		if ( texture.bpp == 24 )
			type = GL_RGB;
		else
			type = GL_RGBA;

		glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

		if(!front)glGenTextures( 1, &front );
		glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

		glBindTexture( GL_TEXTURE_2D, front);
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		//glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		if(trilinear)glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
		if(!trilinear)glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );

		gluBuild2DMipmaps( GL_TEXTURE_2D, type, texture.sizeX, texture.sizeY, type, GL_UNSIGNED_BYTE, texture.data );

	}

	//left
	CopyCStringToPascal(fleft,fileNamep);
	upload_image( fileNamep ,0); 
	if(1==1){
		if ( texture.bpp == 24 )
			type = GL_RGB;
		else
			type = GL_RGBA;

		glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

		if(!left)glGenTextures( 1, &left );
		glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

		glBindTexture( GL_TEXTURE_2D, left);
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		//glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		if(trilinear)glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
		if(!trilinear)glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );

		gluBuild2DMipmaps( GL_TEXTURE_2D, type, texture.sizeX, texture.sizeY, type, GL_UNSIGNED_BYTE, texture.data );

	}

	//back
	CopyCStringToPascal(fback,fileNamep);
	upload_image( fileNamep ,0); 
	if(1==1){
		if ( texture.bpp == 24 )
			type = GL_RGB;
		else
			type = GL_RGBA;

		glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

		if(!back)glGenTextures( 1, &back );
		glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

		glBindTexture( GL_TEXTURE_2D, back);
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		//glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		if(trilinear)glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
		if(!trilinear)glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );

		gluBuild2DMipmaps( GL_TEXTURE_2D, type, texture.sizeX, texture.sizeY, type, GL_UNSIGNED_BYTE, texture.data );

	}

	//right
	CopyCStringToPascal(fright,fileNamep);
	upload_image( fileNamep ,0); 
	if(1==1){
		if ( texture.bpp == 24 )
			type = GL_RGB;
		else
			type = GL_RGBA;

		glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

		if(!right)glGenTextures( 1, &right );
		glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

		glBindTexture( GL_TEXTURE_2D, right);
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		//glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		if(trilinear)glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
		if(!trilinear)glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );

		gluBuild2DMipmaps( GL_TEXTURE_2D, type, texture.sizeX, texture.sizeY, type, GL_UNSIGNED_BYTE, texture.data );

	}

	//up
	CopyCStringToPascal(fup,fileNamep);
	upload_image( fileNamep ,0); 
	if(1==1){
		if ( texture.bpp == 24 )
			type = GL_RGB;
		else
			type = GL_RGBA;

		glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

		if(!up)glGenTextures( 1, &up );
		glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

		glBindTexture( GL_TEXTURE_2D, up);
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		//glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		if(trilinear)glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
		if(!trilinear)glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );

		gluBuild2DMipmaps( GL_TEXTURE_2D, type, texture.sizeX, texture.sizeY, type, GL_UNSIGNED_BYTE, texture.data );

	}

	//down
	CopyCStringToPascal(fdown,fileNamep);
	upload_image( fileNamep ,0); 
	if(1==1){
		if ( texture.bpp == 24 )
			type = GL_RGB;
		else
			type = GL_RGBA;

		glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

		if(!down)glGenTextures( 1, &down );
		glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

		glBindTexture( GL_TEXTURE_2D, down);
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		//glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		if(trilinear)glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
		if(!trilinear)glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );

		gluBuild2DMipmaps( GL_TEXTURE_2D, type, texture.sizeX, texture.sizeY, type, GL_UNSIGNED_BYTE, texture.data );

	}

	//cloud
	CopyCStringToPascal(fcloud,fileNamep);
	upload_image( fileNamep ,0); 
	if(1==1){
		if ( texture.bpp == 24 )
			type = GL_RGB;
		else
			type = GL_RGBA;

		glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

		if(!cloud)glGenTextures( 1, &cloud );
		glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

		glBindTexture( GL_TEXTURE_2D, cloud);
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		//glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		if(trilinear)glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
		if(!trilinear)glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );

		gluBuild2DMipmaps( GL_TEXTURE_2D, type, texture.sizeX, texture.sizeY, type, GL_UNSIGNED_BYTE, texture.data );

	}

	//up
	CopyCStringToPascal(freflect,fileNamep);
	upload_image( fileNamep ,0); 
	if(1==1){
		if ( texture.bpp == 24 )
			type = GL_RGB;
		else
			type = GL_RGBA;

		glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

		if(!reflect)glGenTextures( 1, &reflect );
		glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

		glBindTexture( GL_TEXTURE_2D, reflect);
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		//glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		if(trilinear)glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
		if(!trilinear)glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );

		gluBuild2DMipmaps( GL_TEXTURE_2D, type, texture.sizeX, texture.sizeY, type, GL_UNSIGNED_BYTE, texture.data );

	}
*/
	return true;
}

void	SkyBox::draw()
{
	static float size=viewdistance/4;
	glPushMatrix();
	static GLfloat M[16];

#if defined(USE_GLES)
    static float old_size;
    int offset;
    int vtx_size, tex_size;

    static int vtxA_Offset, vtxB_Offset, vtxC_Offset, vtxD_Offset, vtxE_Offset, vtxF_Offset;
    static int texA_Offset, texB_Offset, texC_Offset;

    GLfloat vtxA[] = {
        -size, -size,   size,
         size, -size,   size,
         size,  size,   size,
        -size,  size,   size
    };

    GLfloat vtxB[] = {
        -size, -size,  -size,
        -size,  size,  -size,
         size,  size,  -size,
         size, -size,  -size
    };

    GLfloat vtxC[] = {
        -size,  size,  -size,
        -size,  size,   size,
         size,  size,   size,
         size,  size,  -size
    };

    GLfloat vtxD[] = {
        -size, -size,  -size,
         size, -size,  -size,
         size, -size,   size,
        -size, -size,   size
    };

    GLfloat vtxE[] = {
         size, -size,  -size,
         size,  size,  -size,
         size,  size,   size,
         size, -size,   size
    };

    GLfloat vtxF[] = {
         -size, -size, -size,
         -size, -size,  size,
         -size,  size,  size,
         -size,  size, -size
    };

    GLfloat texA[] = {
        0,      0,
        1,      0,
        1,      1,
        0,      1
    };

    GLfloat texB[] = {
        1,      0,
        1,      1,
        0,      1,
        0,      0
    };

    GLfloat texC[] = {
        0,      1,
        0,      0,
        1,      0,
        1,      1
    };


    vtx_size = sizeof(GLfloat)*12;
    tex_size = sizeof(GLfloat)*8;

    if(!BufferName) {
        glGenBuffers(1, &BufferName);

        glBindBuffer(GL_ARRAY_BUFFER, BufferName);
        glBufferData(GL_ARRAY_BUFFER, (vtx_size*6)+(tex_size*3), NULL, GL_STATIC_DRAW);
    }
    else
    {
        glBindBuffer(GL_ARRAY_BUFFER, BufferName);
    }


    if (old_size!=size)
    {
        vtxA_Offset = offset = 0;
        glBufferSubData(GL_ARRAY_BUFFER, offset, vtx_size, vtxA);
        vtxB_Offset = (offset += vtx_size);
        glBufferSubData(GL_ARRAY_BUFFER, offset, vtx_size, vtxB);
        vtxC_Offset = (offset += vtx_size);
        glBufferSubData(GL_ARRAY_BUFFER, offset, vtx_size, vtxC);
        vtxD_Offset = (offset += vtx_size);
        glBufferSubData(GL_ARRAY_BUFFER, offset, vtx_size, vtxD);
        vtxE_Offset = (offset += vtx_size);
        glBufferSubData(GL_ARRAY_BUFFER, offset, vtx_size, vtxE);
        vtxF_Offset = (offset += vtx_size);
        glBufferSubData(GL_ARRAY_BUFFER, offset, vtx_size, vtxF);
        texA_Offset = (offset += vtx_size);
        glBufferSubData(GL_ARRAY_BUFFER, offset, tex_size, texA);
        texB_Offset = (offset += tex_size);
        glBufferSubData(GL_ARRAY_BUFFER, offset, tex_size, texB);
        texC_Offset = (offset += tex_size);
        glBufferSubData(GL_ARRAY_BUFFER, offset, tex_size, texC);
    }
#endif

	glGetFloatv(GL_MODELVIEW_MATRIX,M);

	M[12]=0;
	M[13]=0;
	M[14]=0;
	glLoadMatrixf(M);
	//if(environment==2)glTranslatef(0,blurness*viewdistance/1000,0);
	if(environment==2)glScalef(1+blurness/1000,1,1+blurness/1000);
	if(environment!=2) {
#if defined(USE_GLES)
        glColor4f(.85*skyboxr,.85*skyboxg,.95*skyboxb,1.0);
#else
        glColor3f(.85*skyboxr,.85*skyboxg,.95*skyboxb);
#endif
	}
	else {
#if defined(USE_GLES)
        glColor4f(1*skyboxr,.95*skyboxg,.95*skyboxb,1.0);
#else
        glColor3f(1*skyboxr,.95*skyboxg,.95*skyboxb);
#endif
	}

	if(!skyboxtexture){
		glDisable(GL_TEXTURE_2D); 
#if defined(USE_GLES)
		glColor4f(skyboxr*.8,skyboxg*.8,skyboxb*.8,1.0);
#else
		glColor3f(skyboxr*.8,skyboxg*.8,skyboxb*.8);
#endif
	}
	glDepthMask(0);
	glDisable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glDisable(GL_LIGHTING);
	glActiveTexture(GL_TEXTURE0);
	//glActiveTexture(GL_TEXTURE0_ARB);
	if(skyboxtexture)glEnable(GL_TEXTURE_2D);
	glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	glBindTexture(GL_TEXTURE_2D, front); 
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
#if defined(USE_GLES)
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glNormal3f( 0.0f, 0.0f, -1);
    glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(vtxA_Offset));
    glTexCoordPointer(2, GL_FLOAT, 0, BUFFER_OFFSET(texA_Offset));
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
#else
	glBegin(GL_QUADS);
	glNormal3f( 0.0f, 0.0f, -1);
	glTexCoord2f(0, 0); glVertex3f(-size, -size,  size);
	glTexCoord2f(1, 0); glVertex3f( size, -size,  size);
	glTexCoord2f(1, 1); glVertex3f( size,  size,  size);
	glTexCoord2f(0, 1); glVertex3f(-size,  size,  size);
	glEnd();
#endif
	glBindTexture(GL_TEXTURE_2D, back);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
#if defined(USE_GLES)
	glNormal3f( 0.0f, 0.0f, 1);
    glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(vtxB_Offset));
    glTexCoordPointer(2, GL_FLOAT, 0, BUFFER_OFFSET(texB_Offset));
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
#else
	glBegin(GL_QUADS);
	glNormal3f( 0.0f, 0.0f, 1);
	glTexCoord2f(1, 0); glVertex3f(-size, -size, -size);
	glTexCoord2f(1, 1); glVertex3f(-size,  size, -size);
	glTexCoord2f(0, 1); glVertex3f( size,  size, -size);
	glTexCoord2f(0, 0); glVertex3f( size, -size, -size);
	glEnd();
#endif
	glBindTexture(GL_TEXTURE_2D, up);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
#if defined(USE_GLES)
	glNormal3f( 0.0f, -1.0f, 0);
    glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(vtxC_Offset));
    glTexCoordPointer(2, GL_FLOAT, 0, BUFFER_OFFSET(texC_Offset));
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
#else
	glBegin(GL_QUADS);
	glNormal3f( 0.0f, -1.0f, 0);
	glTexCoord2f(0, 1); glVertex3f(-size,  size, -size);
	glTexCoord2f(0, 0); glVertex3f(-size,  size,  size);
	glTexCoord2f(1, 0); glVertex3f( size,  size,  size);
	glTexCoord2f(1, 1); glVertex3f( size,  size, -size);
	glEnd();
#endif
	//if(detail!=0){
	glBindTexture(GL_TEXTURE_2D, down);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
#if defined(USE_GLES)
	glNormal3f( 0.0f, 1.0f, 0);
    glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(vtxD_Offset));
    glTexCoordPointer(2, GL_FLOAT, 0, BUFFER_OFFSET(texA_Offset));
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
#else
	glBegin(GL_QUADS);
	glNormal3f( 0.0f, 1.0f, 0);
	glTexCoord2f(0, 0); glVertex3f(-size, -size, -size);
	glTexCoord2f(1, 0); glVertex3f( size, -size, -size);
	glTexCoord2f(1, 1); glVertex3f( size, -size,  size);
	glTexCoord2f(0, 1); glVertex3f(-size, -size,  size);
	glEnd();
#endif
	//}
	glBindTexture(GL_TEXTURE_2D, right);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
#if defined(USE_GLES)
	glNormal3f( -1.0f, 0.0f, 0);
    glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(vtxE_Offset));
    glTexCoordPointer(2, GL_FLOAT, 0, BUFFER_OFFSET(texB_Offset));
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
#else
	glBegin(GL_QUADS);
	glNormal3f( -1.0f, 0.0f, 0);
	glTexCoord2f(1, 0); glVertex3f( size, -size, -size);
	glTexCoord2f(1, 1); glVertex3f( size,  size, -size);
	glTexCoord2f(0, 1); glVertex3f( size,  size,  size);
	glTexCoord2f(0, 0); glVertex3f( size, -size,  size);
	glEnd();
#endif
	glBindTexture(GL_TEXTURE_2D, left);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
#if defined(USE_GLES)
	glNormal3f( 1.0f, 0.0f, 0);
    glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(vtxF_Offset));
    glTexCoordPointer(2, GL_FLOAT, 0, BUFFER_OFFSET(texA_Offset));
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
#else
	glBegin(GL_QUADS);
	glNormal3f( 1.0f, 0.0f, 0);
	glTexCoord2f(0, 0); glVertex3f(-size, -size, -size);
	glTexCoord2f(1, 0); glVertex3f(-size, -size,  size);
	glTexCoord2f(1, 1); glVertex3f(-size,  size,  size);
	glTexCoord2f(0, 1); glVertex3f(-size,  size, -size);
	glEnd();
#endif
	/*
	glEnable(GL_BLEND);
	glColor4f(1,1,1,1);
	glBindTexture(GL_TEXTURE_2D, cloud);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
	glBegin(GL_QUADS);
	glNormal3f( 0.0f, -1.0f, 0);
	glTexCoord2f(0, 				(1+cloudmove)*30);	glVertex3f(-size,  	size/200, -size);
	glTexCoord2f(0, 				0); 				glVertex3f(-size,  	size/200,  size);
	glTexCoord2f((1+cloudmove)*30, 	0); 				glVertex3f( size, 	size/200,  size);
	glTexCoord2f((1+cloudmove)*30, 	(1+cloudmove)*30); 	glVertex3f( size,  	size/200, -size);
	glEnd();
	glDisable(GL_BLEND);*/
	glEnable(GL_CULL_FACE);
	glDepthMask(1);
	glPopMatrix();

#if defined(USE_GLES)
    glBindBuffer(GL_ARRAY_BUFFER,0);

    old_size = size;
#endif
}

SkyBox::SkyBox()
{
	front = 0,left = 0,back = 0,right = 0,up = 0,down = 0,cloud = 0,reflect = 0;
	cloudmove = 0;
#if defined(USE_GLES)
	BufferName = 0;
#endif
}
SkyBox::~SkyBox()
{
	if (front) glDeleteTextures( 1, &front );
	if (left) glDeleteTextures( 1, &left );
	if (back) glDeleteTextures( 1, &back );
	if (right) glDeleteTextures( 1, &right );
	if (up) glDeleteTextures( 1, &up );
	if (down) glDeleteTextures( 1, &down );
	if (cloud) glDeleteTextures( 1, &cloud );
	if (reflect) glDeleteTextures( 1, &reflect );
#if defined(USE_GLES)
    glDeleteBuffers(1, &BufferName);
#endif
};

