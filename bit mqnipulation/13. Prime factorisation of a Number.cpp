class Solution {
public:

    vector<int> primeFactors(int n){

        vector<int> temp;

        for(int i = 2; i * i <= n; i++){

            while(n % i == 0){

                temp.push_back(i);

                n /= i;
            }
        }

        // Remaining prime factor
        if(n > 1)
            temp.push_back(n);

        return temp;
    }

    vector<vector<int>> primeFactorization(vector<int>& queries) {

        vector<vector<int>> ans;

        for(int num : queries){

            ans.push_back(primeFactors(num));
        }

        return ans;
    }
};

//-2
class Solution {
public:

    vector<int> primeFactors(int n){

        vector<int> ans;

        // Handle factor 2 using bit manipulation
        while((n & 1) == 0){

            ans.push_back(2);

            n >>= 1;
        }

        // Check odd factors
        for(int i = 3; i * i <= n; i += 2){

            while(n % i == 0){

                ans.push_back(i);

                n /= i;
            }
        }

        // Remaining prime
        if(n > 1)
            ans.push_back(n);

        return ans;
    }
};
