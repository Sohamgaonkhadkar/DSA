#include<bits/stdc++.h>
using namespace std;  
bool isSorted(int n, vector<int> a){
    for (int i=1;i<n;i++){
        if (a[i]>= a[i-1]){

        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    int n=5;
    vector<int> a={1,2,3,4,5};
    bool m=isSorted(n,a);
    cout << boolalpha << m << endl;
    cout << "Is the array sorted? " << boolalpha << m << endl;


    return 0;
}
