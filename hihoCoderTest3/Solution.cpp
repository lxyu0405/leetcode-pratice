#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;


int eachQuesMin(int thres, int timesLeft, int S, int T){
    for (int minTimes = 0; minTimes <= timesLeft; minTimes++) {
        int chancesLeft = timesLeft - minTimes;
        int thresLeft = thres - S * minTimes;
        if (chancesLeft * T >= thresLeft) {
            return minTimes;
        }
    }
    return -1;
}


int main(int argc, const char * argv[]) {
    int Q = 0;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int N, M, S, T;
        cin >> N >> M >> S >> T;
        vector<int> line(M+1,0);
        vector<vector<int>> fRes(N,line);
        vector<int> thres(N,0);

        for (int j = 0; j < N; j++) {
            cin >> thres[j];
        }
        
        for (int j = 0; j <= M; j++) {
            fRes[0][j] = eachQuesMin(thres[0], j, S, T);
        }
        
        for (int j = 1; j < N; j++) {
            vector<int> quesMin(M+1,0);
            for (int times = 0; times <= M; times++) {
                quesMin[times] = eachQuesMin(thres[j], times, S, T);
            }
            
            for (int times = 0; times <= M; times++) {
                int thisFMin = -1;
                
                for (int times2 = 1; times2 < times; times2++) {
                    int tempThis = quesMin[times-times2];
                    int tempbefore = fRes[j-1][times2];
                    if (tempThis != -1 && tempbefore != -1) {
                        int thisNum = tempThis + tempbefore;
                        if (thisFMin == -1) {
                            thisFMin = thisNum;
                        }
                        if (thisFMin > thisNum) {
                            thisFMin = thisNum;
                        }
                    }
                }
                fRes[j][times] = thisFMin;
            }
        }
        
        if (fRes[N-1][M] == -1) {
            cout << "No" << endl;
        }else{
            cout << fRes[N-1][M] << endl;
        }
    }
    return 0;
}
