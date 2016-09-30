#include "dtw.h"

/**
 *  compute the Euclidean distance of two 39-dimension vector
 *
 *  @param matrix1                  the first vector
 *  @param matrix2    the second vector
 *
 *  @return the double distance
 */
double dis(vector<double>& matrix1, vector<double>& matrix2){
    double distance = 0;
    unsigned int num1 = (unsigned int)matrix1.size();
    unsigned int num2 = (unsigned int)matrix2.size();
    
    if (num1 == num2) {
        for (unsigned int i = 0; i < num1; i++) {
            distance += pow((matrix1[i] - matrix2[i]), 2);
        }
        distance = sqrt(distance);
    }
    else{
        cout << "------------------ERROR------------------"<< endl;
        cout << "THE DIMENSION OF EACH VECTOR IS NOT SAME!"<< endl;
    }
    
    return distance;
}


/**
 *  use dtw to compute the cost
 *
 *  @param inputAduio input audio feature, seperate into different frames and each frame with a 39-D features
 *  @param temAduio   pre-input template audio feature, the same as input
 *
 *  @return the minimun cost from the best path.
 */
double dtw(vector<vector<double>>& inputAduio, vector<vector<double>>& temAduio){
    
    unsigned int inputFrameNum = (unsigned int)inputAduio.size();
    unsigned int temFrameNum = (unsigned int)temAduio.size();
    
    vector<double> col(temFrameNum), prevCol(temFrameNum), colMax(temFrameNum);
    
    for (unsigned i = 0; i < temFrameNum; i++) {
        colMax[i] = UINT_MAX / 2;
    }
    
    prevCol = colMax;
    
    prevCol[0] = dis(inputAduio[0], temAduio[0]);
    prevCol[1] = dis(inputAduio[0], temAduio[1]);
    
    for (unsigned int i = 1; i < inputFrameNum; i++) {
        
        unsigned int temp = min({2 * (i + 1), temFrameNum});
        col = colMax;
        
        for (unsigned int j = 0; j < temp; j++) {
            
            if (j == 0) {
                col[j] = prevCol[j] + dis(inputAduio[i], temAduio[j]);
            }
            
            else if (j == 1){
                col[j] = min({prevCol[j - 1], prevCol[j]}) + dis(inputAduio[i], temAduio[j]);
            }
            else
                col[j] = min({prevCol[j - 2], prevCol[j - 1], prevCol[j]}) +  dis(inputAduio[i], temAduio[j]);
        }
        
        col.swap(prevCol);
    }
    
    return prevCol[temFrameNum - 1];
}


/**
 *  do the time-synchronomous DTW
 *
 *  @param inputAduio : input audio feature, seperate into different frames and each frame with a 39-D features
 *  @param tempsAudio : several template audio features, seperate into different templates, then into different frames with 39-D features.
 *
 *  @return a vector with a size of 2, vector(0) stores the index of the best fit template(need to be transformed into unsigned int when using), vector(1) store the minimum cost from the best template's best path
 */
vector<double> dtwSynchronous(vector<vector<double>>& inputAduio, vector<vector<vector<double>>>& temsAudio){
    
    vector<double> result(2);
    
    unsigned int inputFrameNum = (unsigned int)inputAduio.size();
    unsigned int temNum = (unsigned int)temsAudio.size();
    
    unsigned int temFrameNum;
    
    vector<vector<double>> col, prevCol;
    
    // get the largest template frames and initialize the columns
    for (unsigned int i = 0; i < temNum; i++) {
        temFrameNum = (unsigned int) temsAudio[i].size();
        vector<double> vecMax(temFrameNum);
        for (unsigned int j = 0; j < temFrameNum; j++) {
            vecMax[j] = UINT_MAX / 2;
        }
        prevCol.push_back(vecMax);
        col.push_back(vecMax);
    }
    
    for (unsigned int i = 0; i < temNum; i++) {
        prevCol[i][0] = dis(inputAduio[0], temsAudio[i][0]);
        prevCol[i][1] = dis(inputAduio[0], temsAudio[i][1]);
    }
    
    for (unsigned int i = 1; i < inputFrameNum; i++) {
        for (unsigned int j = 0; j < temNum; j++) {
            temFrameNum = (unsigned int) temsAudio[j].size();
            unsigned int tem = min({2 * (i + 1), temFrameNum});
            for (unsigned int k = 0; k < tem; k++) {
                if (k == 0) {
                    col[j][k] = prevCol[j][k] + dis(inputAduio[i], temsAudio[j][k]);
                }
                
                else if (k == 1){
                    col[j][k] = min({prevCol[j][k - 1], prevCol[j][k]}) + dis(inputAduio[i], temsAudio[j][k]);
                }
                else
                    col[j][k] = min({prevCol[j][k - 2], prevCol[j][k - 1], prevCol[j][k]}) +  dis(inputAduio[i], temsAudio[j][k]);
            }
            col[j].swap(prevCol[j]);
        }
    }
    
    double bestIndex = 0;
    double bestValue = UINT_MAX / 2;
    
    for (unsigned int i = 0; i < temNum; i++) {
        temFrameNum =(unsigned int) temsAudio[i].size();
        if (prevCol[i][temFrameNum - 1] < bestValue ) {
            bestIndex = i;
            bestValue = prevCol[i][temFrameNum - 1] ;
        }
    }
    
    result[0] = bestIndex;
    result[1] = bestValue;
    
    return result;
}







