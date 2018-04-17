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

int number_needed(string a, string b) {
    vector<int> frequency(26);
    for (int i=0;i<a.length();i++)
        frequency[a[i]-'a']++;
    for (int j=0;j<b.length();j++)
        frequency[b[j]-'a']--;
    int sum=0;
    for (int k= 0;k<26;k++)
        sum=sum+abs(frequency[k]);
    return (sum);
   
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
