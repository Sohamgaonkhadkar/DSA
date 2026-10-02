#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        string prev=s[0];
        long long ans1=1;
        for(int i = 2;i<n ; i+=2){
            if((prev!=?) && (prev==s[i])){
                return 0;
            }
            else if ((prev==?) && (prev==s[i])){
                ans1*=2;
            }
            else{
                prev=s[i];
            }

        }
        long long ans2=1;
        prev=s[1];
        for(int i = 3;i<n ; i+=2){
            if((prev!=?) && (prev==s[i])){
                return 0;
            }
            else if ((prev==?) && (prev==s[i])){
                ans2*=2;
            }
            else{
                prev=s[i];
            }

        }



        long long ans = ans1 * ans2 % MOD;


        // ============================
        // Print answer
        // ============================

        cout << ans % MOD << "\n";
    }