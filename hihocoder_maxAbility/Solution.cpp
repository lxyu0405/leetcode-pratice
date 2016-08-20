#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <vector>
#include <set>
#include <assert.h>
#include <iomanip>
#include <cstdlib>
using namespace std;


int main(){
    int n,k;
    cin >> n >>k;
    vector<int> A(k,0);
    vector<int> B(k,0);
    vector<double> tmp(k,0);
    
    vector<int> currentvalue(k,0);
    
    for (int i = 0 ; i< k; i++)
        cin >> A[i];
    for (int i = 0 ; i< k; i++)
        cin >> B[i];
    //init——————————
    double max = 1.0;
    for (int i = 0; i < k; i++){
        currentvalue[i] = A[i];
        tmp[i] = pow(A[i], 1.0/B[i]);
        max *= tmp[i];
    }
    
    for (int i = 0; i < n; i++){
        int index = 0;
        for (int j = 0; j < k ; j++){
            double temp = pow((currentvalue[j] + 1), 1.0/B[j]);
            for (int jj = 0; jj < k; jj++){
                if (jj != j){
                    temp *= tmp[jj];
                }
            }
            if (temp > max){
                max = temp;
                index = j;
            }
        }
        currentvalue[index] ++;
        tmp[index] = pow(currentvalue[index], 1.0/B[index]);
    }
    //cout<< max << endl;
    printf("%.4f\n",max);
    return 0;
}

