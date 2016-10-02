//
//  dtwTest.cpp
//  DTW
//
//  Created by hty on 01/10/2016.
//  Copyright © 2016 hty. All rights reserved.
//

#include "dtwTest.h"

string wavTemPath = "/Users/hty/desktop/testingData/template";
string txtTemPath = "/Users/hty/desktop/testingData/template";
string wavInputPath = "/Users/hty/desktop/testingData/input";
string txtInputPath = "/Users/hty/desktop/testingData/input";

//string wavTemPath = "/Users/hty/desktop/testingData/test1.0/template";
//string txtTemPath = "/Users/hty/desktop/testingData/test1.0/template";
//string wavInputPath = "/Users/hty/desktop/testingData/test1.0/input";
//string txtInputPath = "/Users/hty/desktop/testingData/test1.0/input";

void getTem(vector<vector<vector<double>>>& temGroup){
    
    for (unsigned int i = 0; i < TYPE_NUM; i++) {
//    for (unsigned int i = 0; i < 1; i++) {
        for(unsigned int j = 0; j < TEM_NUM; j ++){
            cout << "-----------------------Template " << i << " Instance " << j <<"------------------------" << endl;
            string wavpath = wavTemPath +  to_string(i) + "/" + to_string(j)+ "/record.wav";
//            capture(wavpath);
            
            vector<vector<double>> temFeature;
            string txtpath = txtTemPath + to_string(i) + "/";
            featureExtraction(temFeature, wavpath, txtpath);
            temGroup.push_back(temFeature);
        }
    }
}


void getInput(vector<vector<double>>& input, string& wavPath, string& txtPath){
    capture(wavPath);
//    getchar();
    featureExtraction(input, wavPath, txtPath);
}

void getResult(){
    vector<vector<vector<double>>> temGroup;
    
    getTem(temGroup);
    
    int correctNum =0;
    
    for (unsigned int i = 0; i < TYPE_NUM; i++) {
        
        for (unsigned int j = 0; j < INPUT_NUM; j++) {
            cout << endl;
            cout <<"-----------------------Input " << i <<"   Instance " << j << "------------------------" << endl;
            vector<vector<double>> input;
            string wavPath = wavInputPath + to_string(i) + "/" + to_string(j) + "/record.wav";
            string txtPath = txtInputPath + to_string(i) + "/" + to_string(j) + "/";
            getInput(input, wavPath, txtPath);
            
            double minDtw = dtw(input, temGroup[0]);
            int bestIndex = 0;
            cout << "The input is " << i << ", the dtwValue with 0.0 is " << minDtw << endl;
            
            for (unsigned int k = 1; k < TEM_NUM * TYPE_NUM; k++) {
                double dtwValue = dtw(input, temGroup[k]);
                cout << "The input is " << i << ", the dtwValue with "<< k / TEM_NUM << "."<< k % TEM_NUM << " is " << dtwValue << endl;
                if (dtwValue < minDtw) {
                    bestIndex = k;
                    minDtw = dtwValue;
                }
            }
            cout << "The input is " << i << ", while the match template is " << bestIndex / TEM_NUM << "."<< bestIndex % TEM_NUM << ". Their dtw value is "<< minDtw <<  endl;
            
            if (i == bestIndex / TEM_NUM) {
                correctNum += 1;
                cout << "The matching is correct!! Now the correct number is " << correctNum << endl;
            }
            else{
                cout << "The matching is wrong......." << endl;
            }
        }
    }
    
    cout << "The total number of input is "<< TYPE_NUM * INPUT_NUM << endl;
    cout << "The correct matching input number is "<< correctNum << endl;
    cout << "The accuracy of the matching is " << (1.0 * correctNum / (TYPE_NUM * INPUT_NUM)) << endl;
}


//void getSegTem(){
//    vector<vector<vector<double>>> temGroup;
//    getTem(temGroup);
//    
//    vector<vector<double>> segTem;
//    segTem = dtw2hmm(temGroup);
//    cout << "yes!!"<<endl;
//}

