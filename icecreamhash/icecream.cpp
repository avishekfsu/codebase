#include <bits/stdc++.h>
#include<unordered_map>

using namespace std;

void solve(vector <int> arr, int money) {
    // Complete this function
    unordered_map<int,int> myhash;
    int rr;
    //cin >> rr;
    //for (int i=0;i<arr.size();i++)
    //    cout<<arr[i]<<"\t";
    //cout<<endl;
    for (int j=0;j<arr.size();j++){
        if (myhash[arr[j]]==0){
            
            //cin >>rr;
            if (money-arr[j] > 0){
                myhash[money-arr[j]]=j+1;
            }
            //cout<<" reached here for value "<<arr[j]<<" made hash entry at "<<money-arr[j]<<endl;
        }
        else if (myhash[arr[j]]!=0){
           // cout<<" **reached here2 for value "<<arr[j]<<"hash entry = "<<myhash[j]<<endl;
            int rem = myhash[arr[j]];
            
                if (rem < j+1)
                    cout<< rem<<" "<<j+1<<endl;
                else
                    cout<< j+1<<" "<<rem<<endl;
                break;
                
            
        }
        
    }
    
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int money;
        cin >> money;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
            cin >> arr[arr_i];
        }
        solve(arr, money);
    }
    return 0;
}

