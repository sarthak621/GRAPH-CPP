class Solution {
public:


    void dfs(int row, int col,vector<vector<int>>& image,vector<vector<int>>& ans,int color,int initColor){
        ans[row][col]=color;

        int n=image.size();
        int m=image[0].size();
        
        int dRow[]={-1,0,1,0};
        int dCol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
              int nRow=row+dRow[i];
              int nCol=col+dCol[i];

              if(nRow>=0 && nRow<n && nCol>=0 && nCol<m
                 && image[nRow][nCol]==initColor && ans[nRow][nCol]!=color){
                    dfs(nRow,nCol,image,ans,color,initColor);
                 }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //copy the image
        vector<vector<int>>ans=image;
        int initColor=image[sr][sc];

        dfs(sr,sc,image,ans,color,initColor);

        return ans;
    }
};