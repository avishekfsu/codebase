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
unordered_map<int,int> myctr;
    
int findways(int n)
{
    
    if (myctr[n]!=0) 
        return myctr[n];
    myctr[n]=findways(n-1) + findways(n-2) +findways(n-3) ;
    return myctr[n];
        
}
    

int main(){
    myctr[1]=1;
    myctr[2]=2;
    myctr[3]=4;
    int s;
    int sum;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        sum=0;
        sum=findways(n);
        cout<<sum<<endl;
    }
    return 0;
}
