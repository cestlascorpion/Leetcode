/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if(s == null)
            return false;
        else{
            if(isSametree(s,t))
                return true;
            else
                return isSubtree(s.left,t) || isSubtree(s.right,t);
        }
    }
    public boolean isSametree(TreeNode s,TreeNode t)
    {
        if(s==null && t==null)
            return true;
        else{
            if(s==null || t==null)
                return false;
            if(s.val!=t.val)
                return false;
            else
                return isSametree(s.left,t.left) && isSametree(s.right,t.right);
        }
    }
}