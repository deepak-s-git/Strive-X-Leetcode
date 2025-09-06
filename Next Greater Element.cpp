// Problem: Next Greater Element I
// Given two arrays nums1 and nums2 (nums1 is a subset of nums2).
// For each element in nums1, find the next greater element in nums2.
// If it does not exist, return -1.
//
// Example:
// nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output = [-1,3,-1]
//
// Approach (Monotonic Stack + HashMap):
// 1. Traverse nums2 from right to left.
// 2. Maintain a stack of elements in decreasing order.
//    - While stack.top() <= current element, pop it.
//    - If stack is empty, no greater element → map[val] = -1.
//    - Else, map[val] = stack.top() (next greater element).
// 3. Push current element onto stack.
// 4. Finally, build ans[] by looking up each element of nums1 in the map.
//
// Time Complexity: O(n + m) 
//    (where n = nums1.size(), m = nums2.size())
// Space Complexity: O(m) for stack + map.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;   // stores next greater for each num in nums2
        stack<int> s;               // monotonic decreasing stack

        // Process nums2 from right to left
        for (int i = nums2.size()-1; i >= 0; i--) {
            // Pop all smaller or equal elements
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }

            // If stack empty → no greater element
            m[nums2[i]] = s.empty() ? -1 : s.top();

            // Push current element
            s.push(nums2[i]);
        }

        // Build answer for nums1
        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(m[x]);
        }
        return ans;
    }
};
