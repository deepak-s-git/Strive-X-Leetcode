// Problem: Gas Station
// Approach:
// 1. First, check feasibility:
//      - If total gas < total cost, it's impossible to complete the circuit → return -1.
// 2. Otherwise, there exists a valid start point (guaranteed by the problem).
// 3. Greedy choice:
//      - Iterate through each station and track `currGas` (net gas at that point).
//      - If `currGas` drops below 0, it means we cannot reach the next station.
//        → So, set the next station as the new starting point and reset `currGas` to 0.
// 4. At the end, the valid `start` index is our answer.
//
// Time Complexity: O(n)  (one pass to compute totals, one pass for greedy check)
// Space Complexity: O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas = 0, totCost = 0;

        // Step 1: check feasibility
        for (int val : gas) totGas += val;
        for (int val : cost) totCost += val;
        if (totGas < totCost) return -1;

        // Step 2: greedy traversal
        int start = 0, currGas = 0;
        for (int i = 0; i < gas.size(); i++) {
            currGas += gas[i] - cost[i];

            // Can't reach next station, move start forward
            if (currGas < 0) {
                start = i + 1;
                currGas = 0;
            }
        }
        return start;
    }
};
