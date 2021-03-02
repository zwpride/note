class NumMatrix {
public:
    vector<vector<int>> a;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m > 0){
            int n = matrix[0].size();
            a.resize(m, vector<int>(n + 1));
            for(int i = 0 ; i < m ; i++){
                a[i][0] = 0;
                for(int j = 0 ; j < n ; j++){
                    a[i][j+1] = matrix[i][j] + a[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1 ; i <= row2 ; i++){
            sum += (a[i][col2+1] - a[i][col1]);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
