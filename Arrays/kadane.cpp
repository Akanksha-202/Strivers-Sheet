#include <iostream>
#include <vector>
using namespace std;

int kadane (vector<int>&nums){
    int sum = 0;
    int maxi = nums[0];
    for(int i = 0 ; i < nums.size() ; i++){
        sum+=nums[i];
        maxi = max(maxi,sum);
        if(sum<0){
            sum = 0;
        }
    }
    return maxi;
}

int main(){
    vector<int>nums = {2,4,1,5,-2,1};
    cout<<kadane(nums);
    return 0;
}