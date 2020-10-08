class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_map<int, vector<int>> umap;
        size_t total_sum = 0;
        for(size_t i=0; i<nums.size(); ++i) {
            for(size_t j=2; j*j<=nums[i]; ++j) { //optimisation
                if(nums[i] % j == 0) { //if divisible
                    if(umap[nums[i]].empty()) { //if we havent found any divisor yet
                        umap[nums[i]].push_back(j); //push the divisor
                        if(j != nums[i]/j) { //check if its 5*5 etc... then we do not push again
                        umap[nums[i]].push_back(nums[i]/j); //else : push the counterpart of the divisor
                        } 
                    } else { //if we have already found 1 or 2 divisors, and we have more divisors available..
                        umap[nums[i]].pop_back(); //current size is 2.. so make it 1 to not enter the if loop to count
                        break; //there are more than total 4 divisors, so break off and stop computing further
                    }  
                }
            }
            if(umap[nums[i]].size() == 2) { //2 new divisors i.e we've got total 4
                vector<int> curr = move(umap[nums[i]]);
                int sum = accumulate(curr.begin(), curr.end(), 0);
                total_sum += sum;
                total_sum += nums[i] + 1;
            }
        }
        return total_sum;
    }
};
/*
24
1,24,2,12,3,8,4,6
100
1,100,2,50,4,25,5,20,10,10 */