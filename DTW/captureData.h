#ifndef _DATACAPTURE_H_
#define _DATACAPTURE_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "portaudio.h"
#include "readwave.h"
#include <math.h>

using namespace std;

/* #define SAMPLE_RATE  (17932) // Test failure to open with this value. */
#define SAMPLE_RATE  (44100)
#define FRAMES_PER_BUFFER (882)


/*
 define the number of times
 */
#define NUM_SECONDS     (30)
#define NUM_CHANNELS    (1)
/* #define DITHER_FLAG     (paDitherOff) */
#define DITHER_FLAG     (0) /**/
/** Set to 1 if you want to capture the recording to a file. */
#define WRITE_TO_FILE   (1)

#define PA_SAMPLE_TYPE  paInt16
typedef short SAMPLE;
#define SAMPLE_SILENCE  (0)
#define PRINTF_S_FORMAT "%d"

#define FORGET_FACTOR   (1)
#define ADJUSTMENT      (0.05)
#define THRESHOLD       (20)
#define SILENCETHRESHOLD    (15)        // make it to 300ms

void capture();

#endif