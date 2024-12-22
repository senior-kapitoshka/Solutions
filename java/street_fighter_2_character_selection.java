import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;
public class Solution{
  public static String[] streetFighterSelection(String[][] fts, int[] pos, String[] mvs){
    return Arrays.stream(mvs).map(s->{
      String str=new String();
      switch(s){
          case "up":
                    if(pos[0]==0){
                      str=fts[pos[0]][pos[1]];
                      }else{  
                      str=fts[pos[0]-1][pos[1]];
                      --pos[0];
                    }
                    break;
          case "down":
                    if(pos[0]==1){
                        str=fts[pos[0]][pos[1]];
                      }else{  
                      str=fts[pos[0]+1][pos[1]];
                      ++pos[0];
                    }
                    break;
          case "left":
                    if(pos[1]==0){
                      str=fts[pos[0]][fts[0].length-1];
                      pos[1]=fts[0].length-1;
                    }else{  
                      str=fts[pos[0]][pos[1]-1];
                      --pos[1];
                    }
                    break;
          case "right":
                    if(pos[1]==fts[0].length-1){
                        str=fts[pos[0]][0];
                        pos[1]=0;
                    }else{  
                      str=fts[pos[0]][pos[1]+1];
                      ++pos[1];
                    }
                    break;
      }
      return str;
    }).toArray(String[]::new);
  }
}

////////////////
class Solution {
    static String[] streetFighterSelection(String[][] fighters, int[] position, String[] moves) {
      for (int i = 0; i < moves.length; i++) {
        switch (moves[i]) {
          case "right": position[1] = (position[1] + 1) % 6; break;
          case "left": position[1] = (position[1] + 5) % 6; break;
          default: position[0] = moves[i].equals("up") ? 0 : 1;
        }
        moves[i] = fighters[position[0]][position[1]];
      }
      return moves;
    }
  }

  ////////////////
  import java.util.*;
  import java.util.stream.*;
  
  public class Solution
  {
      public static String[] streetFighterSelection(String[][] xs, int[] p, String[] moves)
      {
          return Arrays.stream(moves)
                .reduce(new ArrayList<String>(), (acc, n) -> {
                        p[0] = p[0] == 0 && n == "down" ? 1 : p[0] == 1 && n == "up" ? 0 : p[0];
                        p[1] = ((p[1] + (n == "left" ? -1 : n == "right" ? 1 : 0)) + xs[0].length) % xs[0].length;
                        acc.add(xs[p[0]][p[1]]);
                        return acc;
                  }, (acc, n) -> acc)
                .toArray(String[]::new);
      }
  }

  ///////////
  import java.util.Arrays;
public class Solution {
    public static String[] streetFighterSelection(String[][] fighters, int[] position, String[] moves) {
        return Arrays.stream(moves).map(a-> a=move(a,position,fighters)).toArray(String[]::new);
    }
    private static String move(String mov,int[] cursor,String[][] selection){
        switch(mov){
            case "up"   : cursor[0] = 0;break;
            case "down" : cursor[0] = 1;break;
            case "right": cursor[1] = (cursor[1]+1)%6;break;
            case "left" : cursor[1] = (cursor[1]+5)%6;break;
        }
        return selection[cursor[0]][cursor[1]];
    }
}

///////////
import java.awt.Point;
import java.util.ArrayList;
import java.util.List;

public class Solution {

	private static enum Move {
		RIGHT {
			@Override
			Point move(Point p, String[][] fighters) {
				return new Point(p.x, p.y == fighters[p.x].length - 1 ? 0 : p.y + 1);
			}
		}, LEFT {
			@Override
			Point move(Point p, String[][] fighters) {
				return new Point(p.x, p.y == 0 ? fighters[p.x].length - 1 : p.y - 1);
			}
		}, UP {
			@Override
			Point move(Point p, String[][] fighters) {
				return new Point(p.x == 0 ? p.x : p.x - 1, p.y);
			}
		}, DOWN {
			@Override
			Point move(Point p, String[][] fighters) {
				return new Point(p.x == fighters.length - 1 ? p.x : p.x + 1, p.y);
			}
		};

		abstract Point move(Point start, String[][] fighters);
	}

	public static String[] streetFighterSelection(String[][] fighters, Point position, List<Move> moves) {
		Point start = null;
		String[] names = new String[moves.size()];
		int i = 0;
		for (Move move : moves) {
			start = move.move(start == null ? position : start, fighters);
			names[i++] = fighters[start.x][start.y];
		}
		return names;
	}

	public static String[] streetFighterSelection(String[][] fighters, int[] position, String[] moves) {
		return streetFighterSelection(fighters, new Point(position[0], position[1]), new ArrayList<Move>() {
			{
				for (String m : moves) {
					add(Move.valueOf(m.toUpperCase()));
				}
			}
		});
	}
}