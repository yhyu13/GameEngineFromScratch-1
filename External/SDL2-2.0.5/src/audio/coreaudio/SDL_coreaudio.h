/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2016 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "../../SDL_internal.h"

#ifndef _SDL_coreaudio_h
#define _SDL_coreaudio_h

#include "../SDL_sysaudio.h"

#if !defined(__IPHONEOS__)
#define MACOSX_COREAUDIO 1
#endif

#if MACOSX_COREAUDIO
#include <CoreAudio/CoreAudio.h>
#include <CoreServices/CoreServices.h>
#else
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIApplication.h>
#endif

#include <AudioToolbox/AudioToolbox.h>
#include <AudioUnit/AudioUnit.h>

/* Hidden "this" pointer for the audio functions */
#define _THIS   SDL_AudioDevice *this

struct SDL_PrivateAudioData
{
    SDL_Thread *thread;
    AudioQueueRef audioQueue;
    AudioQueueBufferRef audioBuffer[2];
    void *buffer;
    UInt32 bufferOffset;
    UInt32 bufferSize;
    AudioStreamBasicDescription strdesc;
    SDL_sem *ready_semaphore;
    char *thread_error;
    SDL_atomic_t shutdown;
#if MACOSX_COREAUDIO
    AudioDeviceID deviceID;
#else
    SDL_bool interrupted;
    CFTypeRef interruption_listener;
#endif
};

#endif /* _SDL_coreaudio_h */
/* vi: set ts=4 sw=4 expandtab: */