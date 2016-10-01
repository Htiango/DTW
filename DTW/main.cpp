//
//  main.cpp
//  SpeechRecognition
//
//  Created by hty on 9/2/16.
//  Copyright © 2016 hty. All rights reserved.
//

#include <iostream>
#include "portaudio.h"
#include "captureData.h"
#include "fft.h"
#include "featureExtraction.h"
#include "dtw.h"
#include "dtwTest.h"

using namespace std;


int main(int argc, const char * argv[]) {
    
    
    getResult();

    
//    cout << "-------------------------TEMPLATE--------------------------" << endl;
////    getchar();
//    
//    string wavFilePath1 = "/Users/hty/desktop/testingData/template/record.wav";
////    capture(wavFilePath1);           // capture data and write it to a wav file
//    
//    
//    cout << "Press any key to get the tem feature." << endl;
//    getchar();
//    
//    vector<vector<double>> temFeature;
//    string txtFilePath1 = "/Users/hty/desktop/testingData/template/";
//    featureExtraction(temFeature, wavFilePath1, txtFilePath1);   // write txt file to the disk in order to watch
//    
//    
//    
//    cout << "-------------------------INPUT1--------------------------" << endl;
//    cout << "Press any key to record the input" << endl;
////    getchar();
//    
//    string wavFilePath2 = "/Users/hty/desktop/testingData/input1/record.wav";
////    capture(wavFilePath2);           // capture data and write it to a wav file
//    
//    
////    cout << "Press any key to get the input feature." << endl;
////    getchar();
//    
//    vector<vector<double>> inputFeature;
//    string txtFilePath2 = "/Users/hty/desktop/testingData/input1/";
//    featureExtraction(inputFeature, wavFilePath2, txtFilePath2);   // write txt file to the disk in order to watch
//    
//
//    
//    cout << "Press any key to record the input" << endl;
//    getchar();
//    
//    
//
//    //------------------------------------INPUT 2--------------------------
//    cout << "-------------------------INPUT2--------------------------" << endl;
//    string wavFilePath3 = "/Users/hty/desktop/testingData/input2/record.wav";
////    capture(wavFilePath3);           // capture data and write it to a wav file
//    
//    
////    cout << "Press any key to get the input feature." << endl;
////    getchar();
//    
//    vector<vector<double>> inputFeature2;
//    string txtFilePath3 = "/Users/hty/desktop/testingData/input2/";
//    featureExtraction(inputFeature2, wavFilePath3, txtFilePath3);   // write txt file to the disk in order to watch
//    
//    
//    
//    
//    
//    
//    cout << endl;
//    double cost = dtw(inputFeature, temFeature);
//    cout << "The first cost value = " << cost << endl;
//    
//    cout << endl;
//    double cost2 = dtw(inputFeature2, temFeature);
//    cout << "The second cost value = " << cost2 << endl;
//    cout << " " << endl;
}


