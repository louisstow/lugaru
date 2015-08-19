SRCDIR := ./Source
SRCS := \
	Frustum.cpp \
	GameDraw.cpp \
	GameInitDispose.cpp \
	GameTick.cpp \
	Globals.cpp \
	Lights.cpp \
	Models.cpp \
	Objects.cpp \
	pack.c \
	pack_private.c \
	Person.cpp \
	private.c \
	Quaternions.cpp \
	Random.c \
	Skeleton.cpp \
	Skybox.cpp \
	Sprites.cpp \
	Terrain.cpp \
	Text.cpp \
	TGALoader.cpp \
	unpack.c \
	unpack_private.c \
	Weapons.cpp \
	WinInput.cpp \
	OpenGL_Windows.cpp \
	openal_wrapper.cpp \
	MacCompatibility.cpp \

SRCS := $(foreach f,$(SRCS),$(SRCDIR)/$(f))

LIBPNGDIR := ./Dependencies/libpng
PNGSRCS := \
	png.c \
	pngerror.c \
	pngget.c \
	pngmem.c \
	pngpread.c \
	pngread.c \
	pngrio.c \
	pngrtran.c \
	pngrutil.c \
	pngset.c \
	pngtrans.c \
	pngwio.c \
	pngwrite.c \
	pngwtran.c \
	pngwutil.c \

PNGSRCS := $(foreach f,$(PNGSRCS),$(LIBPNGDIR)/$(f))

JPEGLIBDIR := ./Dependencies/libjpeg
JPEGSRCS := \
	jdapistd.c \
	jdmaster.c \
	jdapimin.c \
	jcapimin.c \
	jdmerge.c \
	jdatasrc.c \
	jdatadst.c \
	jdcoefct.c \
	jdcolor.c \
	jddctmgr.c \
	jdhuff.c \
	jdinput.c \
	jdmainct.c \
	jdmarker.c \
	jdpostct.c \
	jdsample.c \
	jdtrans.c \
	jerror.c \
	jidctflt.c \
	jidctfst.c \
	jidctint.c \
	jmemmgr.c \
	jutils.c \
	jmemnobs.c \
	jquant1.c \
	jquant2.c \
	jcomapi.c \
	jcmarker.c \
	jcapistd.c \
	jcparam.c \
	jcinit.c \
	jcdctmgr.c \
	jccoefct.c \
	jcmainct.c \
	jfdctflt.c \
	jfdctint.c \
	jfdctfst.c \
	jchuff.c \
	jcsample.c \
	jcmaster.c \
	jccolor.c \
	jcprepct.c \
	jcarith.c \
	jdarith.c \
	jaricom.c \

JPEGSRCS := $(foreach f,$(JPEGSRCS),$(JPEGLIBDIR)/$(f))

ZLIBDIR := ./Dependencies/zlib
ZLIBSRCS = \
	adler32.c \
	compress.c \
	crc32.c \
	deflate.c \
	infback.c \
	inffast.c \
	inflate.c \
	inftrees.c \
	trees.c \
	uncompr.c \
	zutil.c \

ZLIBSRCS := $(foreach f,$(ZLIBSRCS),$(ZLIBDIR)/$(f))

GLUDIR := ./Dependencies/GLU
GLUSRCS = \
	dict.c \
	geom.c \
	memalloc.c \
	mesh.c \
	mipmap.c \
	normal.c \
	priorityq.c \
	render.c \
	sweep.c \
	tess.c \
	tessmono.c \
	util.c \

GLUSRCS := $(foreach f,$(GLUSRCS),$(GLUDIR)/$(f))

obj = ./obj

COMMONFLAGS = -O3 -s ASSERTIONS=1 -s DEMANGLE_SUPPORT=1

$(obj)/jpeg.bc: $(JPEGSRCS)
	em++ $(COMMONFLAGS) $(JPEGSRCS) -I$(JPEGLIBDIR) -o $(obj)/jpeg.bc

$(obj)/png.bc: $(PNGSRCS) ./Dependencies/zlib/libz.a
	em++ $(COMMONFLAGS) ./Dependencies/zlib/libz.a $(PNGSRCS) -I$(LIBPNGDIR) -I$(ZLIBDIR) -o $(obj)/png.bc

$(obj)/glues.bc: ./Dependencies/glues/source/glues_mipmap.c
	em++ $(COMMONFLAGS) ./Dependencies/glues/source/glues_mipmap.c -I./Dependencies/glues/source -o $(obj)/glues.bc

all: $(obj)/jpeg.bc $(obj)/png.bc $(obj)/glues.bc
	em++ $(COMMONFLAGS) -s LEGACY_GL_EMULATION=1 -s TOTAL_MEMORY=95829120 -s GL_ASSERTIONS=1 -s GL_UNSAFE_OPTS=0 -s GL_FFP_ONLY=1 $(obj)/jpeg.bc $(obj)/png.bc $(obj)/glues.bc ./Dependencies/zlib/libz.a $(SRCS) -I$(SRCDIR) -I$(ZLIBDIR) -I$(JPEGLIBDIR) -I$(LIBPNGDIR) -I./Dependencies/glues/source --preload-file Data --pre-js pre.js -o build/lugaru.html

clean:
	rm $(obj)/*.bc

.PHONY: clean all

# https://raw.githubusercontent.com/KhronosGroup/WebGLDeveloperTools/master/src/debug/webgl-debug.js
# GameDraw.cpp +2719
# js 141940
