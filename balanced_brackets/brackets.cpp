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

bool is_balanced(string expression) {
    stack<char> mystack;
    int len = expression.length();
    for (int i=0;i<len;i++)
    {
        char ch = expression[i];
        if (ch=='[' ||ch=='{'||ch=='(')
            mystack.push(ch);
        else
        {
            if (mystack.empty())
                return false;
            char chout = mystack.top();
            //cout<<" here ip is"<<ch<< "and stack top is "<<chout<<endl;
            mystack.pop();
            if ((ch==')' && chout=='(')||(ch==']' && chout=='[')||(ch=='}' && chout=='{')){
                //cout<<"reached here for "<<ch<<chout<<endl;
                continue;
            }
            else
                return false;
                    
            
        }
        
    }
    return (mystack.empty());
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}


