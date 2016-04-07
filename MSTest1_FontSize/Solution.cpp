#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(vector<int>& Ai, int size, int width, int height, int pages){
    int charsInALine = width / size;
    int lineInAPage = height / size;
    int sumLines = 0;
    for (int i = 0; i < Ai.size(); i++) {
        if (Ai[i] % charsInALine == 0) {
            sumLines += (Ai[i]/charsInALine);
        }else{
            sumLines += (Ai[i]/charsInALine + 1);
        }
    }
    int pagesNeed = 0;
    if (sumLines % lineInAPage == 0) {
        pagesNeed = sumLines / lineInAPage;
    }else{
        pagesNeed = sumLines / lineInAPage + 1;
    }
    
    if (pagesNeed > pages) {
        return false;
    }else{
        return true;
    }
}

int main(){
    
    vector<int> res;
    int tasks;
    cin >> tasks;
    for (int i = 0; i < tasks; i++) {
        int N = 0, P = 0, W = 0, H = 0;
        cin >> N >> P >> W >> H;
        vector<int> Ai;
        int thisAi = 0;
        for (int i = 0; i < N; i++) {
            cin >> thisAi;
            Ai.push_back(thisAi);
        }
        int narrow = 0;
        if (W < H) {
            narrow = W;
        }else{
            narrow = H;
        }
        int charSize = 1;
        for (; charSize <= narrow; charSize++) {
            if (!isValid(Ai, charSize, W, H, P)) {
                res.push_back(charSize-1);
                break;
            }
            if (charSize == narrow) {
                res.push_back(charSize);
            }
        }
        
        
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}

