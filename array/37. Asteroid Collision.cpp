class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i =asteroids.size()-1;
        int j =asteroids.size()-2;
        while(j>=0){
            if((asteroids[i]<0 && asteroids[j]>0)){
                if(abs(asteroids[i])>abs(asteroids[j])){
                    asteroids.erase(asteroids.begin()+j);
                    
                }
                else if(abs(asteroids[i])<abs(asteroids[j])){
                    asteroids.erase(asteroids.begin()+i);
                    
                }
                else{
                    asteroids.erase(asteroids.begin()+i);
                    asteroids.erase(asteroids.begin()+j);
                    
                }
            }
            else{
                i--;
                j--;
            }
        }
        return asteroids;
    }
};