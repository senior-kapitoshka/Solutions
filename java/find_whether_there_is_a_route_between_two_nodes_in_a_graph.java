import java.util.*;

public class CheckPath {
  private static boolean BFS(Node a,Node b){
    Queue<Node> q=new LinkedList<Node>();
    q.offer(a);
    Set<Node>vis=new HashSet<Node>();
    vis.add(a);
    while(!q.isEmpty()){
      Node x=q.poll();
      for(var n:x.edges){
        if(n.value==b.value) return true;
        if(!vis.contains(n)){
          q.offer(n);
          vis.add(n);
        }
      }
    }
    return false;
  }
  
  public static boolean getRoute(Node a, Node b) {
    return BFS(a,b);
  }
}
///////////////////
import java.util.Stack;
import java.util.Set;
import java.util.HashSet;

public class CheckPath {
  public static boolean getRoute(Node a, Node b) {
    // return whether there is a route from a to b
    
    Stack<Node> stack = new Stack<>();
    Set<Node> visited = new HashSet<>();
    stack.add(a);
    
    while (!stack.isEmpty()) {
      Node curr = stack.pop();
      
      visited.add(curr);
      for (Node neighbour : curr.edges) {
        if (neighbour.equals(b)) {
          return true;
        }
        if (!visited.contains(neighbour)) {
          stack.add(neighbour);
        }
      }
    }
    
    return false;
  }
  
}
//////////////
