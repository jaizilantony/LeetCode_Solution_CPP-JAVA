class Solution {
    List<List<Integer>> ans = new ArrayList<>();

    void solve(int[] candidates, int target, List<Integer> temp, int start) {
        if (target == 0) {
            ans.add(new ArrayList<>(temp));
            return;
        }

        if (target < 0) return;

        for (int i = start; i < candidates.length; i++) {
            temp.add(candidates[i]);
            solve(candidates, target - candidates[i], temp, i); 
            temp.remove(temp.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        solve(candidates, target, new ArrayList<>(), 0);
        return ans;
    }
}

