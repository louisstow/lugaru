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

#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#include "gamegl.h"
#include "Frustum.h"
#include "Lights.h"
#include "TGALoader.h"
#include "Quaternions.h"
#include "Quaternions.h"

#define max_terrain_size			256		
#define curr_terrain_size			size
#define subdivision 				64
#define max_patch_elements			(max_terrain_size/subdivision)*(max_terrain_size/subdivision)*54

#define allfirst 0
#define mixed 1
#define allsecond 2

#define max_decals 1000

#define shadowdecal 0
#define footprintdecal 1
#define blooddecal 2
#define blooddecalfast 3
#define shadowdecalpermanent 4
#define breakdecal 5
#define blooddecalslow 6
#define bodyprintdecal 7

#define snowyenvironment 0
#define grassyenvironment 1
#define desertenvironment 2
//
// Model Structures
//

class Terrain{
public:
	GLuint bloodtexture;
	GLuint bloodtexture2;
	GLuint shadowtexture;
	GLuint footprinttexture;
	GLuint bodyprinttexture;
	GLuint breaktexture;
	GLuint terraintexture;
	short	size;

	int patchobjectnum[subdivision][subdivision];
	int patchobjects[subdivision][subdivision][300];

	float scale;
	int type;
	float heightmap[max_terrain_size+1][max_terrain_size+1];
	XYZ normals[max_terrain_size][max_terrain_size];
	XYZ facenormals[max_terrain_size][max_terrain_size];
	XYZ triangles[(max_terrain_size-1)*(max_terrain_size-1)*2][3];
	float colors[max_terrain_size][max_terrain_size][4];
	float opacityother[max_terrain_size][max_terrain_size];
	float texoffsetx[max_terrain_size][max_terrain_size];
	float texoffsety[max_terrain_size][max_terrain_size];
	int numtris[subdivision][subdivision];
	int textureness[subdivision][subdivision];

	GLfloat vArray[(max_patch_elements)*subdivision*subdivision];

	bool visible[subdivision][subdivision];
	float avgypatch[subdivision][subdivision];
	float maxypatch[subdivision][subdivision];
	float minypatch[subdivision][subdivision];
	float heightypatch[subdivision][subdivision];

	int patch_elements;

	float decaltexcoords[max_decals][3][2];
	XYZ decalvertex[max_decals][3];
	int decaltype[max_decals];
	float decalopacity[max_decals];
	float decalrotation[max_decals];
	float decalalivetime[max_decals];
	float decalbrightness[max_decals];
	XYZ decalposition[max_decals];
	int numdecals;

	void AddObject(XYZ where, float radius,int id);
	void DeleteDecal(int which);
	void MakeDecal(int type, XYZ where, float size, float opacity, float rotation);
	void MakeDecalLock(int type, XYZ where, int whichx, int whichy, float size, float opacity, float rotation);
	int lineTerrain(XYZ p1,XYZ p2, XYZ *p);
	float getHeight(float pointx, float pointz);
	float getHeightExtrude(float pointx, float pointz,float point2x, float point2z);
	float getOpacity(float pointx, float pointz);
	XYZ getLighting(float pointx, float pointz);
	XYZ getNormal(float pointx, float pointz);
	void UpdateVertexArray(int whichx, int whichy);
	void UpdateTransparency(int whichx, int whichy);
	void UpdateTransparencyother(int whichx, int whichy);
	void UpdateTransparencyotherother(int whichx, int whichy);
	bool load(const char *fileName);
	void CalculateNormals();
	void drawdecals();
	void draw(int layer);
	void drawpatch(int whichx, int whichy, float opacity);
	void drawpatchother(int whichx, int whichy, float opacity);
	void drawpatchotherother(int whichx, int whichy, float opacity);
	void DoLighting();
	void DoShadows();

	Terrain();
	~Terrain();
};

#endif
