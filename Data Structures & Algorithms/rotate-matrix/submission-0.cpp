class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // int row= matrix.size()-1;
        // int column= matrix[0].size()-1;
        int n= matrix.size();
         
         //we can transpose first then we can reverse the row....
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};