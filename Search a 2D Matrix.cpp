// Problem: Search a 2D Matrix
// Link: https://leetcode.com/problems/search-a-2d-matrix/
//
// You are given an m x n matrix where each row is sorted in ascending order,
// and the first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in the matrix, otherwise false.
//
// Approach:
// 1. Use binary search on rows to find the candidate row where target could lie.
//    - Compare target with the first and last element of the mid row.
// 2. Once the correct row is found, perform a binary search on that row.
// 3. Return true if found, false otherwise.
//
// Time Complexity: O(log m + log n) = O(log(m*n))
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Binary search inside a single row
    bool searchInRow(vector<vector<int>>& mat, int target, int row) {
        int n = mat[0].size();
        int st = 0, end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (mat[row][mid] == target) {
                return true;
            } else if (mat[row][mid] < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();

        int startRow = 0, endRow = m - 1;
        while (startRow <= endRow) {
            int midRow = startRow + (endRow - startRow) / 2;

            // Check if target lies within this row's range
            if (target >= mat[midRow][0] && target <= mat[midRow][n - 1]) {
                return searchInRow(mat, target, midRow);
            } 
            else if (target > mat[midRow][n - 1]) {
                startRow = midRow + 1;  // search in rows below
            } 
            else {
                endRow = midRow - 1;    // search in rows below
            }
        }
        return false;
    }
};