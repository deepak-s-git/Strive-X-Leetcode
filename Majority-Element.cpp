// Problem: Find the element that appears more than ⌊n / 2⌋ times in the array.
// Approach: 
// 1. Sort the array so identical elements are grouped together.
// 2. Traverse the sorted array and count the frequency of each number.
// 3. If any number's frequency exceeds n/2, return it as the majority element.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int freq = 1, ans = nums[0];

        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1]) {
                freq++;  // increase count for the current number
            } else {
                freq = 1;   // reset count for new number
                ans = nums[i];
            }

            if(freq > n / 2) {
                return nums[i];  // found majority element
            }
        }

        return ans;  // fallback (guaranteed to be majority as per problem constraints)
    }
};


// Problem: Find the majority element (appears more than ⌊n / 2⌋ times).
// Better Approach: Boyer-Moore Voting Algorithm
// 1. We maintain a candidate and a frequency counter.
// 2. If the counter drops to zero, we pick the current number as a new candidate.
// 3. If the current number equals the candidate, we increase the counter. Else, decrease it.
// 4. Since the majority element is guaranteed to exist, the final candidate will be the answer.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(freq == 0) {
                ans = nums[i]; // pick new candidate
            }

            if(ans == nums[i]) {
                freq++;        // increase count if same as candidate
            } else {
                freq--;        // decrease count otherwise
            }
        }

        return ans; // final candidate is the majority element
    }
};
