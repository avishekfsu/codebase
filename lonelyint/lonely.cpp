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

int lonely_integer(vector < int > a) {
    int sum;
    for (int i=0;i<101;i++){
        if (a[i] > 0)
            sum+=a[i];
    }
    return sum;
}

int main(){
    int n,temp;
    cin >> n;
    vector<int> a(101,-1);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> temp; 
       if (a[temp] < 0)
        a[temp]=temp;
       else
        a[temp]=0;
    }
    
    cout << lonely_integer(a) << endl;
    return 0;
}
