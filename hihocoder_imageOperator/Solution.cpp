#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool RGauss(const vector<vector<double> > & A, vector<double> & x){
    x.clear();
    //由于输入函数已经保证了系数矩阵是对的，就不检查A了
    int n = A.size();
    int m = A[0].size();
    x.resize(n);
    //复制系数矩阵，防止修改原矩阵
    vector<vector<double> > Atemp(n);
    for (int i = 0; i < n; i++)
    {
        vector<double> temp(m);
        for (int j = 0; j < m; j++)
        {
            temp[j] = A[i][j];
        }
        Atemp[i] = temp;
        temp.clear();
    }
    for (int k = 0; k < n; k++)
    {
        //选主元
        double max = -1;
        int l = -1;
        for (int i = k; i < n; i++)
        {
            if (abs(Atemp[i][k]) > max)
            {
                max = abs(Atemp[i][k]);
                l = i;
            }
        }
        if (l != k)
        {
            //交换系数矩阵的l行和k行
            for (int i = 0; i < m; i++)
            {
                double temp = Atemp[l][i];
                Atemp[l][i] = Atemp[k][i];
                Atemp[k][i] = temp;
            }
        }
        //消元
        for (int i = k+1; i < n; i++)
        {
            double l = Atemp[i][k]/Atemp[k][k];
            for (int j = k; j < m; j++)
            {
                Atemp[i][j] = Atemp[i][j] - l*Atemp[k][j];
            }
        }
    }
    //回代
    x[n-1] = Atemp[n-1][m-1]/Atemp[n-1][m-2];
    for (int k = n-2; k >= 0; k--)
    {
        double s = 0.0;
        for (int j = k+1; j < n; j++)
        {
            s += Atemp[k][j]*x[j];
        }
        x[k] = (Atemp[k][m-1] - s)/Atemp[k][k];
    }
    return true;
}

void displayX(vector<double> &x, int D){
    for (int i = 0; i < x.size(); i++) {
        if (abs(x[i]) < 1e-12) {
            cout << 0;
        }else{
            printf("%.0f", x[i]);
        }
        
        if ((i + 1) % D == 0) {
            cout << endl;
        }else{
            cout << " ";
        }
    }
}

int main(){
    int H, W, D;
    cin >> H >> W >> D;
    vector<vector<double>> image(H, vector<double>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> image[i][j];
        }
    }
    
    vector<vector<double>> B(H-D+1, vector<double>(W-D+1, 0));
    for (int i = 0; i < H-D+1; i++) {
        for (int j = 0; j < W-D+1; j++) {
            cin >> B[i][j];
        }
    }
    
    
    int res_size = D * D;
    
    vector<vector<double>> A;
    vector<double> x (res_size, 0);
    
    int cnt = 0;
    for (int i = 0; i < H-D+1; i++) {
        for (int j = 0; j < W-D+1; j++) {
            vector<double> thisLineA;
            for (int dy = 0; dy < D; dy++) {
                for (int dx = 0; dx < D; dx++) {
                    thisLineA.push_back(image[i+dy][j+dx]);
                }
            }
            thisLineA.push_back(B[i][j]);
            A.push_back(thisLineA);
            cnt++;
            if (cnt == res_size) {
                RGauss(A, x);
                displayX(x, D);
                return 0;
            }
        }
    }
    
    return 0;
}
