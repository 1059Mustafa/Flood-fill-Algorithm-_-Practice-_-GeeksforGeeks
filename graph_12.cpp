class Solution {
public:

    void find(int x, int y, int newC , int old , vector<vector<int>>& g, int R, int C)
    {
        if(x<0||x>=R||y<0||y>=C)
        {
            return;
        }
        if(g[x][y]!=old)
        {
            return;
        }
        if(g[x][y]==newC)
        {
            return;
        }
        g[x][y]=newC;
        find(x-1,y,newC,old,g,R,C);
        find(x+1,y,newC,old,g,R,C);
        find(x,y-1,newC,old,g,R,C);
        find(x,y+1,newC,old,g,R,C);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int oldColor=image[sr][sc];
        vector<vector<int>> img=image;
        find(sr,sc,newColor,oldColor,img,image.size(),image[0].size());
        return img;
    }
};
