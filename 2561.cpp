class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        
        long long ans = 0; 

        vector<int> store; // vector to store the elements for swap
        unordered_map<int,int> mpp;
        int mini = INT_MAX; // minimum element 
        for(auto& x : basket1)
        {
            mpp[x]++;
            mini = min(mini,x);
        }
        for(auto& x : basket2)
        {
            mpp[x]--;
            mini = min(mini,x);
        }

        for(auto& it : mpp){ // now map has differ frequency of all elements  many 
            
            if(it.second < 0) it.second *= -1; // if -ve convert to +ve (here -ve means elements ae more inside basket 2 )

            if((it.second & 1) != 0) return -1; // (now if its odd then we can not divide in 2 equally so its impossible return -1 from here)

            for(int i = 1;i<=it.second/2;i++){
                store.push_back(it.first); // frequency / 2 times push in common vector
            }
        }


        sort(store.begin(),store.end()); // simple sort 
        for(int i = 0;i<store.size()/2;i++){
            ans += min(store[i],2*mini); // note here if element is minimum then we directly swap or else we have the way to indirectly swap with the minimum element 
            /*
            lets say we have to swap 5 and 9 ...
            on direct min(5,9) = cost is 5;
            but lets say mini = 1;
            now we swap frist 5,1 and then 1,9 
            now cost is min(5,1) + min(1,9) i.e 2 which is < 5
            // so note here more omtimally we swap 
            */
            
        }

        return ans;

        
    }
};