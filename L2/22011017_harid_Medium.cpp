/*
id:22011017
name:harid
group: g1
lab: L2 (Medium)-Find median in row wise sorted matrix
problem-https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int findMedian(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int low = mat[0][0];
    int high = mat[0][m - 1];

    
    for (int i = 1; i < n; ++i) {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m - 1]);
    }

    int desired = (n * m) / 2;

    while (low <= high) {
        int mid = (low + high) / 2;
        int place = 0;

        
        for (int i = 0; i < n; ++i) {
            place += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        }

        if (place <= desired)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main() {
    
    vector<vector<int>> mat1 = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << "Median is: " << findMedian(mat1) << endl;

    
    vector<vector<int>> mat2 = {
        {1, 3, 4},
        {2, 5, 6},
        {3, 7, 9}
    };
    cout << "Median is: " << findMedian(mat2) << endl;

    return 0;
}
