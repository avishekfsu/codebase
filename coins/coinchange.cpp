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
unordered_map<int,long long> mymap;
long long make_change(vector<int> coins, int money,int n) {
//similar to knapsack one set with coin include d one without
    long long i,j;
    long rows=coins.size();//coins.size();
    long cols=money+1;
    vector< vector<long long> > myarr (rows, vector <long long> (cols, 0 ));
    // cout<<"------------------------"<<endl;
    //          for(int m=0;m<rows;m++){
    //             for(int n=0;n<cols;n++){
    //                 cout<<myarr[m][n]<<"\t";
    //             }
    //             cout<<endl;
    //         }
    // cout<<"------------------------"<<endl;    
    
     for (i=0;i<rows;i++)
        myarr[i][0]=1;
    for (i=1;i<cols;i++){
        if (i%coins[0]==0)
            myarr[0][i]=1;
    }
        
    for (i=1;i<rows;i++)
    {
        for (j=0;j<cols;j++)
        {
            if (j-coins[i] < 0 ) //cant be included
            {
                myarr[i][j]=myarr[i-1][j];
            }
            else
            {
                myarr[i][j] = myarr[i-1][j] + myarr[i][j-coins[i]];
            }
            // cout<<"------------------------"<<endl;
            //  for(int m=0;m<rows;m++){
            //     for(int n=0;n<cols;n++){
            //         cout<<myarr[m][n]<<"\t";
            //     }
            //     cout<<endl;
            // }
            // cout<<"------------------------"<<endl;
        
        }
    }
    
   
    return(myarr[rows-1][cols-1]);

}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    for(int coins_i = 0;coins_i < m;coins_i++){
       cin >> coins[coins_i];
    }
    cout << make_change(coins, n,coins.size()) << endl;
    return 0;
}
