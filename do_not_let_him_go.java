import java.awt.Point;
import java.util.stream.*;
import java.util.*;
import static java.lang.System.*;
class Solver {
  private static void DFS(int i,int j,Character mx[][],Point p){
    if(mx[i][j]=='#') return;
    if(i==0 || j==0 || i==mx.length-1 || j ==mx[0].length-1){
      p.setLocation(j,i);
      return;
    }
    mx[i][j]='#';
    int x[]={0,-1,0,1};
    int y[]={-1,0,1,0};
    for(int z=0;z<4;++z){
      if(Character.isWhitespace(mx[i+x[z]][j+y[z]])){
        p.setLocation(j,i);
        return;
      }
      DFS(i+x[z],j+y[z],mx,p);
    }
  }
  
  private static Point solve(Character mx[][]){
    Point p=new Point(0, 0);
    for(int i=0;i<mx.length;++i){
      for(int j=0;j<mx[0].length;++j){
        if(mx[i][j]=='.'){
          DFS(i,j,mx,p);
        };
      }
    }
    return p;
  }
  
    Point locateEntrace(String[] o) {
      Integer n=Arrays.stream(o)
                    .map(s->s.length())
                    .max(Integer::compare).get();
      Character mx[][]=new Character [o.length][n];
      int cnt[]=new int[1];
      Arrays.stream(o)
        .forEach(s->{
          for(int i=0;i<n;++i){
            if(i<s.length())mx[cnt[0]][i]=s.charAt(i);
            else mx[cnt[0]][i]=' ';     
          }
          ++cnt[0];
        });
        return solve(mx);
    }
  
}

/////////////////
/// import java.awt.Point;


class Solver {
    Point locateEntrace(String[] office) {
      for (int y = 0; y<office.length; y++){
        for (int x = 0; x<office[y].length(); x++){
          
          if (office[y].charAt(x) == '.'){
                try {
                  if (office[y-1].charAt(x) == ' '){return new Point (x,y);}
                  if (office[y+1].charAt(x) == ' '){return new Point (x,y);}
                  if (office[y].charAt(x-1) == ' '){return new Point (x,y);}
                  if (office[y].charAt(x+1) == ' '){return new Point (x,y);}

} catch (IndexOutOfBoundsException e) {
    return new Point (x, y);

        
        }
      
       
    }
  
}
}
 return null;  }
}

///////////////
/// import java.awt.Point;


class Solver {
  
    Point locateEntrace(String[] office) {
        int n = office.length;
        int m = 0,i=0;
        
        //find the entrance
        for(i=0;i<n;i++){
            m=office[i].length();
            for(int j=0;j<m;j++){
                if(office[i].charAt(j)=='.'){
                    String prevunits=office[i].substring(0,j);
                    String nextunits=office[i].substring(j+1,m);
                    if((i==0 || i==n-1) || (j==0 || j==m-1)){
                        return new Point(j,i);
                    }
                    int len_prevrow = office[i-1].length(),len_nextrow = office[i+1].length();
                    if(((j>=len_prevrow) || (j>=len_nextrow)) || ((j<len_prevrow && office[i-1].charAt(j)==' ') || (j<len_nextrow && office[i+1].charAt(j)==' ')) ){
                        return new Point(j,i);
                    }
                    if(!(prevunits.contains("#") || prevunits.contains(".")) || !(nextunits.contains("#") || nextunits.contains(".")))
                        return new Point(j,i);
                }
            }
        }
        return null;
    }
}

////////////
/// import java.awt.*;
import java.util.Collection;
import java.util.Set;
import java.util.function.Function;

import static java.util.stream.IntStream.range;

class Solver {

    Point locateEntrace(String[] office) {
        final var wall = range(0, office.length)
                .mapToObj(y -> range(0, office[y].length())
                        .filter(x -> '#' == office[y].charAt(x))
                        .mapToObj(x -> new Point(x, y))
                        .toList())
                .flatMap(Collection::stream).toList();

        return wall.stream()
                .map(neighbors)
                .filter(np -> np.n.stream().filter(wall::contains).count() == 1)
                .map(Neighbors::p)
                .reduce((a, b) -> new Point((a.x + b.x) / 2, (a.y + b.y) / 2))
                .orElseThrow();
    }

    private final Function<Point, Neighbors> neighbors = p -> new Neighbors(p, Set.of(
            new Point(p.x - 1, p.y),
            new Point(p.x + 1, p.y),
            new Point(p.x, p.y - 1),
            new Point(p.x, p.y + 1)));

    private record Neighbors(Point p, Set<Point> n) {}
}

//////////////
/// import java.awt.Point;


class Solver {
  
    static Point locateEntrace(String[] office) {
         String string;
         //проверка первой и последней строки на наличие входа сверху или снизу
         for (int i = 0; i < office.length; i += office.length - 1) {
             if (office[i].contains(".")) {
                 return new Point(office[i].indexOf("."), i);
             }
         }
         //проверка строк, кроме первой и последней, на наличие входа справа или слева
         for (int i = 1; i < office.length - 1; i++) {
             string = office[i].trim();
             if (string.startsWith(".")) {
                 return new Point(office[i].indexOf("."), i);
             }
             if (string.endsWith(".")) {
                 return new Point(office[i].lastIndexOf("."), i);
             }
         }
         //проверка ситуаций, когда длина строк разная - дорисовываем пробелами до одинаковой длины и ищем сочетание по вертикали пробел и точка или точка и пробел
 
         //ищем самую длинную строку
         int max = 0;
         StringBuilder sb = new StringBuilder();
         for (int i = 0; i < office.length; i++) {
             if (office[i].length() > max) {
                 max = office[i].length();
             }
         }
         //рисуем картинку с пробелами вместо пустых символов
         for (int i = 0; i < office.length; i++) {
             string = office[i];
             if (string.length() < max) {
                 sb.append(string);
                 for (int j = 0; j < max - string.length(); j++) {
                     sb.append(" ");
                 }
                 office[i] = sb.toString();
                 sb.delete(0, sb.length());
             }
         }
         for (int i = 0; i < office.length; i++) {
             System.out.println(office[i]);
         }
         //ищем в строках пробел, а затем над ним или под ним точку
         int index = 0;
         for (int i = 0; i < office.length; i++) {
             while (office[i].substring(index).contains(" ")) {
                 index += office[i].substring(index).indexOf(" ");
                 if (i > 0 && office[i - 1].substring(index, index + 1).equals(".")) {
                     return new Point(index, i - 1);
                 }
                 if (i < office.length - 1 && office[i + 1].substring(index, index + 1).equals(".")) {
                     return new Point(index, i + 1);
                 }
                 index++;
             }
           index = 0;
         }
         return null;
     }
   
 }

 ///////////////
 /// 