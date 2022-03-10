Example 1:

Input: array = [2,3,6,7], target = 7       Output: [[2,2,3],[7]]
Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times. 7 is a candidate, and 7 = 7. These are the only two combinations.
  
// Intuition: For questions like printing combinations or subsequences, the first thing that should strike your mind is recursion.
Whenever the problem is related to picking up elements from an array to form a combination, start thinking about the “pick and non-pick” approach.
  
  
CODE: 
class Solution {
  public:
    void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) // Recusrion call
    {
      if (ind == arr.size()) // base case cehcks all the indexes  from n to (n-1).
      {
        if (target == 0) 
        {
          ans.push_back(ds);
        }
        return;
      }
      // pick up the element 
      if (arr[ind] <= target)  // we can only add if arr[i] is less than target
      {
        ds.push_back(arr[ind]); //then adding that into our DS.
        findCombination(ind, target - arr[ind], arr, ans, ds);  
        ds.pop_back();
      }

      findCombination(ind + 1, target, arr, ans, ds);  // for the non pick

    }
  public:
    vector < vector < int >> combinationSum(vector < int > & candidates, int target)  // vector of vectors with the given array and the target
    {
      vector < vector < int >> ans; // vector of vectors which going to store all the combinations
      vector < int > ds;            // declaring a DS used during recursion
      findCombination(0, target, candidates, ans, ds); // calling the recusrion -> first being 0 then target then array then the other two DS
      return ans;
    }
};
