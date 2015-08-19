#ifndef OPENAL_WRAPPER_H
#define OPENAL_WRAPPER_H

#ifdef _WIN32
#include <malloc.h>
#endif

#include <AL/al.h>
#include <AL/alc.h>

//#include "ogg/ogg.h"
//#include "vorbis/vorbisfile.h"


#include "MacCompatibility.h"

#if 0 /* this should only be enable if OPENAL doesn't provide AL_API on all platforms */
#if (!defined(WIN32) && !defined(_WIN32) && !defined(__WIN32__) && !defined(_WIN64) && !defined(_WIN32_WCE) && !defined(_XBOX)) || (defined(__GNUC__) && defined(WIN32))
#ifndef __cdecl
#define __cdecl
#endif
#ifndef __stdcall
#define __stdcall
#endif
#endif

#if defined(_WIN32_WCE)
#define AL_API _cdecl
#define F_CALLBACKAPI _cdecl
#else
#define AL_API __stdcall
#define F_CALLBACKAPI __stdcall
#endif

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#if defined(__LCC__) || defined(__MINGW32__) || defined(__CYGWIN32__)
#define DLL_API AL_API
#else
#define DLL_API
#endif /* __LCC__ ||  __MINGW32__ || __CYGWIN32__ */
#endif /* DLL_EXPORTS */
#endif /* if 0 */


typedef struct OPENAL_SAMPLE    OPENAL_SAMPLE;
typedef struct OPENAL_STREAM    OPENAL_STREAM;
typedef struct OPENAL_DSPUNIT   OPENAL_DSPUNIT;

enum OPENAL_OUTPUTTYPES
{
	OPENAL_OUTPUT_NOSOUND,    /* NoSound driver, all calls to this succeed but do nothing. */
	OPENAL_OUTPUT_OSS,        /* Linux/Unix OSS (Open Sound System) driver, i.e. the kernel sound drivers. */
	OPENAL_OUTPUT_ALSA,       /* Linux Alsa driver. */
};

#define OPENAL_LOOP_OFF      0x00000001  /* For non looping samples. */
#define OPENAL_LOOP_NORMAL   0x00000002  /* For forward looping samples. */
#define OPENAL_HW3D          0x00001000  /* Attempts to make samples use 3d hardware acceleration. (if the card supports it) */
#define OPENAL_2D            0x00002000  /* Tells software (not hardware) based sample not to be included in 3d processing. */
#define OPENAL_FREE             -1      /* value to play on any free channel, or to allocate a sample in a free sample slot. */
#define OPENAL_ALL              -3      /* for a channel index , this flag will affect ALL channels available!  Not supported by every function. */

#ifdef __cplusplus
extern "C" {
#endif

#undef AL_API
#define AL_API

AL_API void OPENAL_3D_Listener_SetAttributes(const float *pos, const float *vel, float fx, float fy, float fz, float tx, float ty, float tz);
AL_API signed char OPENAL_3D_SetAttributes(int channel, const float *pos, const float *vel);
AL_API void OPENAL_3D_SetDopplerFactor(float scale);
AL_API signed char OPENAL_Init(int mixrate, int maxsoftwarechannels, unsigned int flags);
AL_API void OPENAL_Close();
AL_API OPENAL_SAMPLE *OPENAL_GetCurrentSample(int channel);
AL_API signed char OPENAL_GetPaused(int channel);
AL_API unsigned int OPENAL_GetLoopMode(int channel);
AL_API signed char OPENAL_IsPlaying(int channel);
AL_API int OPENAL_PlaySoundEx(int channel, OPENAL_SAMPLE *sptr, OPENAL_DSPUNIT *dsp, signed char startpaused);
AL_API OPENAL_SAMPLE *OPENAL_Sample_Load(int index, const char *name_or_data, unsigned int mode, int offset, int length);
AL_API void OPENAL_Sample_Free(OPENAL_SAMPLE *sptr);
AL_API signed char OPENAL_Sample_SetMode(OPENAL_SAMPLE *sptr, unsigned int mode);
AL_API signed char OPENAL_Sample_SetMinMaxDistance(OPENAL_SAMPLE *sptr, float mindist, float maxdist);
AL_API signed char OPENAL_SetFrequency(int channel, int freq);
AL_API signed char OPENAL_SetVolume(int channel, int vol);
AL_API signed char OPENAL_SetPaused(int channel, signed char paused);
AL_API void OPENAL_SetSFXMasterVolume(int volume);
AL_API signed char OPENAL_StopSound(int channel);
AL_API OPENAL_STREAM *OPENAL_Stream_Open(const char *name_or_data, unsigned int mode, int offset, int length);
AL_API void OPENAL_Stream_Close(OPENAL_STREAM *stream);
AL_API OPENAL_SAMPLE *OPENAL_Stream_GetSample(OPENAL_STREAM *stream);
AL_API int OPENAL_Stream_PlayEx(int channel, OPENAL_STREAM *stream, OPENAL_DSPUNIT *dsp, signed char startpaused);
AL_API signed char OPENAL_Stream_Stop(OPENAL_STREAM *stream);
AL_API signed char OPENAL_Stream_SetMode(OPENAL_STREAM *stream, unsigned int mode);
AL_API void OPENAL_Update();
AL_API signed char OPENAL_SetOutput(int outputtype);

#ifdef __cplusplus
}
#endif

#if USE_OPENAL
#  define OPENAL_Sample_LoadEx(a, b, c, d, e) OPENAL_Sample_Load( a, ConvertFileName( b), c, d, e)
#  define OPENAL_Stream_OpenEx(a, b, c, d) OPENAL_Stream_Open(ConvertFileName(a), b, c, d)
#elif !PLATFORM_MACOSX
#  define OPENAL_Sample_LoadEx(a, b, c, d, e) OPENAL_Sample_Load( a, ConvertFileName( b), c, d, e)
#  define OPENAL_Stream_OpenEx(a, b, c, d) OPENAL_Stream_Open(ConvertFileName(a), b, c, d)
#endif

#endif
