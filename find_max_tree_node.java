public class FindMaxValueInTree {
    static int res;  

   static void find(TreeNode  root){
     
    if(root.value>res) res= root.value;
    if(root.left!=null) find(root.left);
    if(root.right!=null) find(root.right);
  }
    static int findMax(TreeNode  root) {
      res=Integer.MIN_VALUE;
      find(root);
        return res;
    }
}

/////////////////
public class FindMaxValueInTree {

    static int findMax(TreeNode n) {
      return n == null ?
                 Integer.MIN_VALUE :
                        Math.max(n.value, Math.max(findMax(n.left), findMax(n.right)));
    }
}
//////////////
public class FindMaxValueInTree {
    static int findMax(TreeNode  root) { 
         if(root==null)return Integer.MIN_VALUE; 
         int max = Math.max(findMax(root.left),findMax(root.right));
         return Math.max(root.value,max);
    }
}