#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pos{
    int x;
    int y;
    Pos(int a, int b){
        x = a;
        y = b;
    }
};

void shortestDFS(vector<vector<bool>> &visited, const vector<vector<int>> &matrix, Pos thisPos, const Pos &des, vector<Pos> &route, vector<Pos>&shortestRoute, int energy, const int &limit, int &shortest){
    if (energy > limit) {
        return;
    }
    if (thisPos.x == des.x && thisPos.y == des.y && (shortest == -1 || energy <= shortest)) {
        shortest = energy;
        shortestRoute.clear();
        for (int i = 0; i < route.size(); i++) {
            Pos newPos(route[i].x, route[i].y);
            shortestRoute.push_back(newPos);
        }
        return;
    }
    
    int row = thisPos.x;
    int col = thisPos.y;
    //up
    if (row > 0 && matrix[row-1][col] == 1 && (!visited[row-1][col])) {
        Pos nextPos(row-1, col);
        visited[row-1][col] = true;
        
        route.push_back(nextPos);
        shortestDFS(visited, matrix, nextPos, des, route, shortestRoute, energy + 3, limit, shortest);
        route.pop_back();
        
        visited[row-1][col] = false;
    }
    //down
    if (row < matrix.size()-1 && matrix[row+1][col] == 1 && (!visited[row+1][col])) {
        Pos nextPos(row+1, col);
        visited[row+1][col] = true;
        
        route.push_back(nextPos);
        shortestDFS(visited, matrix, nextPos, des, route, shortestRoute, energy, limit, shortest);
        route.pop_back();
        
        visited[row+1][col] = false;
    }
    //left
    if (col > 0 && matrix[row][col-1] == 1 && (!visited[row][col-1])) {
        Pos nextPos(row, col-1);
        visited[row][col-1] = true;
        
        route.push_back(nextPos);
        shortestDFS(visited, matrix, nextPos, des, route, shortestRoute, energy + 1, limit, shortest);
        route.pop_back();
        
        visited[row][col-1] = false;
    }
    //right
    if (col < matrix.size()-1 && matrix[row][col+1] == 1 && (!visited[row][col+1])) {
        Pos nextPos(row, col+1);
        visited[row][col+1] = true;
        
        route.push_back(nextPos);
        shortestDFS(visited, matrix, nextPos, des, route, shortestRoute, energy + 1, limit, shortest);
        route.pop_back();
        
        visited[row][col+1] = false;
    }
}

void printRoute(const vector<Pos> &route){
    cout << "[" << route[0].x << "," << route[0].y << "]";
    for (int i = 1; i < route.size(); i++) {
        cout << ",[" << route[i].x << "," << route[i].y << "]";
    }
    cout << endl;
}

int main(){
    int n, m, p;
    cin >> n >> m >> p;
    
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;
    
    int shortest = -1;
    
    Pos startPos(0, 0);
    Pos desPos(0, m-1);
    vector<Pos> shortestRoute;
    
    vector<Pos> tempRoute;
    tempRoute.push_back(startPos);
    
    
    shortestDFS(visited, matrix, startPos, desPos, tempRoute, shortestRoute, 0, p, shortest);
    if (shortest == -1 || shortest > p) {
        cout << "Can not escape!" << endl;
    }else{
        printRoute(shortestRoute);
    }
    return 0;
}
