#include <iostream>
#include <vector>

using namespace std;

vector<int> firstlastoccurance(vector<int>& nums, int target) {
    int first = -1, last = -1;
    
    // Search for the first occurrence
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            first = mid;
            high = mid - 1; // Continue searching on the left side
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    // Search for the last occurrence
    low = 0;
    high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            last = mid;
            low = mid + 1; // Continue searching on the right side
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return {first, last};
}

int main() {
    int t;
    cin>>t;
    while(t--){

    int n;
    cin>>n;

    vector<int> nums(n) ;
    for(int i=0; i<n; i++){
        cin >> nums[i] ;
        
    }
    int target;
    cin>>target;

    vector<int> result = firstlastoccurance(nums, target);

    cout << "First occurrence: " << result[0] << endl;
    cout << "Last occurrence: " << result[1] << endl;

}
    return 0;
}