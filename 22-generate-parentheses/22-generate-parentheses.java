class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        process(res, "", 0, 0, n);
        return res;
    }

    public void process(List<String> res, String cur, int open, int close, int n){
        if(cur.length() == 2 * n){
            res.add(cur);
            return;
        }

        if(open < n){
            process(res, cur + "(", open + 1, close, n);
        }

        if(close < open){
            process(res, cur + ")", open, close + 1, n);
        }
        return;

    }
}