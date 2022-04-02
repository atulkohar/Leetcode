class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        
        
       return builtTreeNew(postorder, 0,postorder.length-1, inorder, 0, inorder.length-1);
        
        
    }
    public static TreeNode builtTreeNew(int [] postorder, int psi, int pei, int [] inorder, int isi, int iei)
    {
        if(psi>pei)
        {
            return null;
        }
       int val =postorder[pei];
        int idx = isi;
        
        
         while(inorder[idx]!=val)
         {
             idx++;
         }
         // now finding the total remaining elements
        int trel = idx - isi;
        TreeNode node = new TreeNode(val); 
        
        //dry run to get the logic for the equation
        node.right= builtTreeNew(postorder, psi+trel,pei-1, inorder, idx+1, iei);
        
       node.left= builtTreeNew(postorder, psi,psi+trel-1, inorder, isi, idx-1);
       
        
        return node;
        
        
    }
}