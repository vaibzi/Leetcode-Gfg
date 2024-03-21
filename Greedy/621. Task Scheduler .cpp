//Medium
//TC - O(1) . SC - O(1)

// You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. 
//   Each cycle or interval allows the completion of one task. 
//   Tasks can be completed in any order, but there's a constraint:
//   identical tasks must be separated by at least n intervals due to cooling time.

// ​Return the minimum number of intervals required to complete all tasks.
// Example 1:
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8

// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

// After completing task A, you must wait two cycles before doing A again.
//   The same applies to task B. 
//   In the 3rd interval, neither A nor B can be done, so you idle. 
//   By the 4th cycle, you can do A again as 2 intervals have passed.


//Approach:

// Count the frequency of each task using an array freq.
// Sort the freq array in descending order.
// Calculate the number of intervals needed based on the task with the maximum frequency.
// Return the total number of intervals required.

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for(char task : tasks){
            freq[task - 'A']++;
        }
        sort(begin(freq) , end(freq));
        int chunk = freq[25] - 1;
        int interval = chunk * n;

        for(int i=24; i>=0; i--){
            interval -= min(chunk,freq[i]);
        }

        return interval < 0 ? tasks.size() : tasks.size() + interval;
    }
};


