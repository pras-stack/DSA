Example 1:bInput: candidates = [10,1,2,7,6,1,5], target = 8  Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]]
Explanation: These are the unique combinations whose sum is equal to target.
  
// Before starting the recursive call make sure to sort the elements because the ans should contain the combinations in sorted order and should not be repeated.
  
  
  CODE : void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  if (target == 0)
  {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++) 
  {
    if (i > ind && arr[i] == arr[i - 1]) 
      continue;
    if (arr[i] > target) 
      break;
    ds.push_back(arr[i]);
    findCombination(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}
vector < vector < int >> combinationSum2(vector < int > & candidates, int target) 
{
  sort(candidates.begin(), candidates.end());
  vector < vector < int >> ans;
  vector < int > ds;
  findCombination(0, target, candidates, ans, ds);
  return ans;
}
