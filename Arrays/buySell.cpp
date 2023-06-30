#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// int maxProfit(vector<int> prices){

//     int n = prices.size();
//     int maxProfit;
//     int mini = INT_MAX;
//     int maxi = INT_MIN;
//     int index = -1;

//     for(int i = 0 ; i < n; i++){
//         if(prices[i]<mini){
//             mini = prices[i];
//             index = i;
//         }
//     }

//     if(index==n-1){
//         maxProfit = 0;
//     }
//     else{
//         for(int i = index+1; i< n ; i++){
//             if(prices[i]>maxi){
//                 maxi = prices[i];
//             }
//         }

//         maxProfit = maxi - mini;
//     }

//     return maxProfit;

// }

// int maxProfit(vector<int>prices){
//     int n = prices.size();
//     int i = 0;
//     int maxProfit = 0;
//     while(i<n){
//         for(int j = i+1 ; j<n ; j++){
//             if(j>i && maxProfit < (prices[j]-prices[i])){
//                 maxProfit = prices[j]-prices[i];
//             }
//         }
//         i++;
//     }
//     return maxProfit;
// }

int maxProfit(vector<int> prices){

    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i = 0; i<prices.size(); i++){

        int potentialProfit = prices[i]-minPrice;
        maxProfit = max(potentialProfit, maxProfit);
        minPrice = min(prices[i],minPrice);
    }

    return maxProfit;
}

int main(){
    vector<int> money = {10,3,6,4,1};
    cout<<"MAX is: "<<maxProfit(money);
    cout<<endl;

    return 0;
}