class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int i = 0; 
        int j = 0;

        int sum = 0;

        //computing primary diagonal
        while(i < n && j < n){
            sum = sum + mat[i][j];
            ++i;
            ++j;
        }

        //computing secondary diagonal
        i = 0;
        j = n - 1;
        
        while(i < n && j >= 0){
            sum = sum + mat[i][j];
            ++i;
            --j;
        }

        //if the matrix size if odd 
        //remove the repeating element
        if(n % 2 == 1){
            sum = sum - mat[n/2][n/2];
        }

        return sum;
    }
};