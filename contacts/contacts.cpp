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
vector<string> subnames(string name)
{
    vector <string> subname(name.length());
    for (int i=0;i<name.length();i++)
        subname[i]=name.substr(0,i+1);
    return subname;
}

int main(){
    int n;
    vector <string> subname;
    vector <int> output;
    unordered_map<string,int> mymap;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if (op == "add"){
            
            subname = subnames(contact);
            
            for (int p=0;p<contact.length();p++)
                mymap[subname[p]]++;
            
        }
        else {
            
            cout<<mymap[contact]<<endl;
        }
        
    }
    return 0;
}



