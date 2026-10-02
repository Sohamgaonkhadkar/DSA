vector<int> findArrayIntersection(vector<int> &A, vector<int> &B, int n, int m)
{
    vector<int> ans;
    int vis[m] = {0};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            if(A[i] == B[j] && vis[j] == 0) {
                ans.push_back(A[i]);
                vis[j] = 1;
                break;
            }

            if(B[j] > A[i]) break;   // ✅ moved inside
        }
    }
    return ans;
}
//2
int i = 0, j = 0;
vector<int> ans;

while(i < n && j < m) {
    if(A[i] < B[j]) i++;
    else if(B[j] < A[i]) j++;
    else {
        ans.push_back(A[i]);
        i++;
        j++;
    }
}
