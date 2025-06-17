/*
id:22011017
name:harid
group: g1
lab: L2 (Hard)-A Boolean Matrix Question
problem-https://www.geeksforgeeks.org/dsa/a-boolean-matrix-question/
*/
#include <iostream>
#include <vector>
using namespace std;

void modifyMatrix(vector<vector<int>>& mat) {
    int R = mat.size();
    int C = mat[0].size();

    
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (mat[i][j] == 1) {
                
                for (int k = 0; k < C; ++k) {
                    if (mat[i][k] == 0)
                        mat[i][k] = -1;
                }
                
                for (int k = 0; k < R; ++k) {
                    if (mat[k][j] == 0)
                        mat[k][j] = -1;
                }
            }
        }
    }

    
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (mat[i][j] == -1)
                mat[i][j] = 1;
        }
    }
}

void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };

    modifyMatrix(mat);
    printMatrix(mat);

    return 0;
}
