/*Brute Force Approach

Idea: Check every possible pair in the array.

Steps:

Loop through each element i.

For each i, loop through every element j > i.

Check if arr[i] + arr[j] == target.

If yes → return the pair.

If no pair found after all checks → return none.
------------------------------------------------------
💻 C++ Code (Brute Force Pair Sum)
cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 7, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                cout << "Pair found: " << arr[i] << " + " << arr[j] << " = " << target << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "No pair found!" << endl;
    }
    return 0;
}
📊 Complexity
Time Complexity: 
𝑂(n square) because we check all pairs.

Space Complexity: 
𝑂 (1)
 (no extra data structures).*/
 
#include <iostream>
#include <vector>
using namespace std;

vector <int> pairSum(vector<int> nums, int target) {
    vector<int> ans;
    int n = nums.size();

    for (int i=0;i<n;i++)
    {
        for (int j=i+1; j < n ; j++) {
            if (nums[i] + nums[j] == target) {
                ans.push_back(i);
                 ans.push_back(j);
                 return ans;
            }
        }
    }
    return ans;
}

int main()
{
    vector <int> nums = {2,31,27,6,4,10};
    int target = 29;

    vector <int> ans = pairSum (nums,target);
    cout << "(" << ans[0] << "," << ans[1] << ")" << endl;
    return 0;
}