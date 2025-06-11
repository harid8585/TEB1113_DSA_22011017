/*
id:22011017
name:harid
group: g1
lab: L2 (Easy)-Program to multiply two matrices
problem-https://www.geeksforgeeks.org/c-program-multiply-two-matrices/
*/

#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> multiply_matrices(const vector<vector<int>>& m1, const vector<vector<int>>& m2) {
    int m = m1.size();
    int n = m1[0].size();
    int p = m2[0].size();

    vector<vector<int>> result(m, vector<int>(p, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return result;
}


void print_matrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    
    vector<vector<int>> m1_square = {{1, 1}, {2, 2}};
    vector<vector<int>> m2_square = {{1, 1}, {2, 2}};
    vector<vector<int>> res_square = multiply_matrices(m1_square, m2_square);

    cout << "Square Matrix Multiplication Result:\n";
    print_matrix(res_square);

    
    vector<vector<int>> m1_rect = {{1, 1}, {2, 2}, {3, 3}};
    vector<vector<int>> m2_rect = {{1, 1, 1}, {2, 2, 2}};
    vector<vector<int>> res_rect = multiply_matrices(m1_rect, m2_rect);

    cout << "\nRectangular Matrix Multiplication Result:\n";
    print_matrix(res_rect);

    return 0;
}
