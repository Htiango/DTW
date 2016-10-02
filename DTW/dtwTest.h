//
//  dtwTest.h
//  DTW
//
//  Created by hty on 01/10/2016.
//  Copyright © 2016 hty. All rights reserved.
//

#ifndef dtwTest_h
#define dtwTest_h

#include <iostream>
#include "portaudio.h"
#include "captureData.h"
#include "fft.h"
#include "featureExtraction.h"
#include "dtw.h"
#include <stdlib.h>
#include "seg_K_mean.h"

using namespace std;


#define TEM_NUM     (5)

#define TYPE_NUM    (10)
#define INPUT_NUM   (5)


void getResult();
void getSegTem();

#endif /* dtwTest_h */
