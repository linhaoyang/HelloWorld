The DP solution proceeds row by row, starting from the first row. 
Let the maximal rectangle area at row i and column j be computed by [right(i,j) - left(i,j)]*height(i,j).

class Solution {

public:
int maximalRectangle(vector<vector<char> > &matrix) {

    if(matrix.empty()) return 0;
    
    const int m = matrix.size();
    const int n = matrix[0].size();
    
    int left[n], right[n], height[n];
    fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);
    int maxA = 0;
    
    for(int i=0; i<m; i++) {
        int cur_left=0, cur_right=n; 
        for(int j=0; j<n; j++) { // compute height (can do this from either side)
            if(matrix[i][j]=='1') height[j]++; 
            else height[j]=0;
        }
        for(int j=0; j<n; j++) { // compute left (from left to right)
            if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);   //key!!!!!!!!!!!!!!
            else {left[j]=0; cur_left=j+1;}
        }
        // compute right (from right to left)
        for(int j=n-1; j>=0; j--) {
            if(matrix[i][j]=='1') right[j]=min(right[j],cur_right);   //key!!!!!!!!!!!!!
            else {right[j]=n; cur_right=j;}    
        }
        // compute the area of rectangle (can do this from either side)
        for(int j=0; j<n; j++)
            maxA = max(maxA,(right[j]-left[j])*height[j]);
    }
    
    return maxA;
}

==================================================================================================


This question is similar as [Largest Rectangle in Histogram]:

You can maintain a row length of Integer array H recorded its height of '1's, and scan and update row by row to find out the largest rectangle of each row.

For each row, if matrix[row][i] == '1'. H[i] +=1, or reset the H[i] to zero.
and accroding the algorithm of [Largest Rectangle in Histogram], to update the maximum area.
