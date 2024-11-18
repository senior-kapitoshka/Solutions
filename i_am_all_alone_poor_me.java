public class Dinglemouse {
    public static boolean DFS(int i,int j, char[][] hs){
      if(hs[i][j]=='#' || i<0 || i>hs.length || j<0 || j>hs[0].length) return true;
      if(hs[i][j]=='o') return false;
      hs[i][j]='#';
      return DFS(i+1,j,hs) && DFS(i-1,j,hs)&& DFS(i,j+1,hs) && DFS(i,j-1,hs);
    }
  
    public static boolean allAlone(char[][] hs) {
      boolean res=false;
      for(int i=0;i<hs.length;++i){
        for(int j=0;j<hs[0].length;++j){
          if(hs[i][j]=='X'){
            res=DFS(i,j,hs);
          }
        }
      }
      return res;
    }
  
  }

  /////////////////
  public class Dinglemouse {

    public static boolean allAlone(char[][] c) { 
      for (int i=0;i<c.length;i++){ 
        for (int j=0;j<c[i].length;j++){
            if(c[i][j]=='X'){ 
               A(c,i,j);break;
            }
          }
        }
        return c[0][0]!='!';
      } 
     public static void A (char c [][], int i, int j){
          if(c[i][j]=='#'||c[0][0]=='!')return;
          if(c[i][j]=='o')c[0][0]='!';
          c[i][j]='#';
          A(c,i,j+1);
          A(c,i+1,j);
          A(c,i,j-1);
          A(c,i-1,j);
      }
  }