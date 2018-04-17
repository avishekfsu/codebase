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


int main(){
    int p;
    cin >> p;
    int flag;
    for(int a0 = 0; a0 < p; a0++){
        int n;
        cin >> n;
        if (n==1)
            cout <<"Not prime\n";
        else if (n==2)
            cout <<"Prime\n";
        else if (n%2==0)
            cout<<"Not prime\n";
        else
        {
            flag=1;
            for (int i=3;i<sqrt(n)+1;i++)
            {
                if (n%i==0){
                    flag=0;
                    break;
                }
            }
            if (flag)
                cout<<"Prime\n";
            else
                cout<<"Not prime\n";
                    
        }
    }
                
    return 0;
}
