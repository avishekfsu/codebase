#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
struct Node
{
    int row;
    int col;
    vector<Node *> adjList;
};
int isValidCell(vector< vector<int> > grid,int r,int c,int rowsize,int colsize)
{
    
    
    if (r>=0 && r<rowsize && c>=0 && c<colsize && grid[r][c]==1)
        return true;
    return false;
    
}
void doDFS(vector< vector<int> > grid,int n,int m,vector< vector<int> > &visited,Node *start,int *sum,int *rupdate,int *cupdate)
{
    int i;
    int thisrow=start->row;
    int thiscol=start->col;
    if (grid[thisrow][thiscol]==0 || visited[thisrow][thiscol]==1)
        return;
    int id = thisrow*m +thiscol;
    //cout <<" came to "<<id<<endl;
    visited[thisrow][thiscol]=1; //mark as visited;
    *sum=*sum+1;
    for (i=0;i<8;i++)
    {
        if (isValidCell(grid,thisrow+rupdate[i],thiscol+cupdate[i],n,m)){ //found valid neighbor
            Node *temp = new Node();
            temp->row=thisrow+rupdate[i];
            temp->col=thiscol+cupdate[i];
            start->adjList.push_back(temp);
        }
    }
    
    if (start->adjList.size()>0)
    {
        for (i=0;i<start->adjList.size();i++)
        {
            Node *adjNode = start->adjList[i];
            
            
            doDFS(grid,n,m,visited,adjNode,sum,rupdate,cupdate);
        }
    }
    
    
}

int get_biggest_region(vector< vector<int> > grid,int n,int m) {
    int rupdate[8]={-1,-1,-1,0,0,1,1,1};
    int cupdate[8]={-1,0,1,-1,1,-1,0,1};
    int MAX_SUM=-1;
    for (int ii=0;ii<n;ii++)
    {
        for (int jj=0;jj<m;jj++)
        {
            vector< vector<int> > visited(n,vector<int>(m));
            Node *start =new Node();
            start->row=ii;
            start->col=jj;
            int thissum=0;
            doDFS(grid,n,m,visited,start,&thissum,rupdate,cupdate);
            if (thissum > MAX_SUM)
                MAX_SUM = thissum;
            //cout<<thissum<<endl;
        }
    }
    return MAX_SUM;
    
}



int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
        for(int grid_j = 0;grid_j < m;grid_j++){
            cin >> grid[grid_i][grid_j];
        }
    }
    cout << get_biggest_region(grid,n,m) << endl;
    return 0;
}




