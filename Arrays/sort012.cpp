#include <iostream>
#include <vector>
using namespace std;

void sort012 (vector<int> &nums){

    int low = 0;
    int mid = 0;
    int high = nums.size()-1;

    while(mid<=high){
        switch(nums[mid]){
            
            case 0:
                swap(nums[low++], nums[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid],nums[high--]);
                break;

        }
    }
}
int main(){

    vector<int> arr={2,0,2,0,2,1,1,1};

    sort012(arr);

    for(int i = 0; i< arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    

    return 0;
}