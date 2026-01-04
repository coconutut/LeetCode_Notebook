#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    //水平镜像
    void horizion_mirror(vector<vector<int>>& matrix){
        int dim = matrix.size();
        if(dim == 0) return;
        for(int r = 0; r < dim / 2; r++){
            for(int c = 0; c < dim; c++){
                int temp = matrix[r][c];
                matrix[r][c] = matrix[dim-r-1][c];
                matrix[dim-r-1][c] = temp;
            }
        }
    }
    //垂直镜像
    void vertical_mirror(vector<vector<int>>& matrix){
        int dim = matrix.size();
        if(dim == 0) return;
        for(int c = 0; c < dim / 2; c++){
            for(int r = 0; r < dim; r++){
                int temp = matrix[r][c];
                matrix[r][c] = matrix[r][dim-c-1];
                matrix[r][dim-c-1] = temp;
            }
        }
    }
    //转置
    void transpose(vector<vector<int>>& matrix){
        int dim = matrix.size();
        if(dim == 0) return;
        for(int r = 0; r < dim; r++){
            for(int c = 0; c < r; c++){
                int temp = matrix[r][c];
                matrix[r][c] = matrix[c][r];
                matrix[c][r] = temp;
            }
        }
    }
    //顺时针旋转90度
    void rotate_90_r(vector<vector<int>>& matrix){
        horizion_mirror(matrix);
        transpose(matrix);
    }
    //逆时针旋转90度
    void rotate_90_l(vector<vector<int>>& matrix){
        vertical_mirror(matrix);
        transpose(matrix);
    }
    //旋转180度
    void rotate_180(vector<vector<int>>& matrix){
        vertical_mirror(matrix);
        horizion_mirror(matrix);
    }

};

class print_vector{
public:
    void operator()(vector<int>& v){
        for(const int& p : v){
            cout << p << " ";
        }
        cout << endl;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    Solution s;
    s.rotate_180(matrix);
    for_each(matrix.begin(), matrix.end(), print_vector());
    return 0;
}