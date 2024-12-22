import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Solution {
    public static String[] superStreetFighterize(String[][] fts, int[] pos, String[] mvs) {
      return Arrays.stream(mvs).map(s->{
      String str=new String();
      switch(s){
          case "up":
                    if(pos[0]==0 || fts[pos[0]-1][pos[1]].isEmpty()){
                      str=fts[pos[0]][pos[1]];
                    }else{ 
                        str=fts[pos[0]-1][pos[1]];
                        --pos[0];
                    }
                    break;
          case "down":
                    if(pos[0]==fts.length-1 || fts[pos[0]+1][pos[1]].isEmpty()){
                        str=fts[pos[0]][pos[1]];
                    }else{  
                      str=fts[pos[0]+1][pos[1]];
                      ++pos[0];
                    }
                    break;
          case "left":
                    if(pos[1]==0 || fts[pos[0]][pos[1]-1].isEmpty()){
                      if(pos[1]==0 || pos[1]-1==0){
                        
                        int i=0;
                        for(;fts[pos[0]][fts[0].length-1-i].isEmpty();++i);
                        str=fts[pos[0]][fts[0].length-1-i];
                        pos[1]=fts[0].length-1-i;
                      }else if(fts[pos[0]][pos[1]-1].isEmpty()){

                        int i=0;
                        for(;pos[1]-i>0 ;++i){
                          if(fts[pos[0]][pos[1]-i].isEmpty()) break;
                        }
                        if(pos[1]==0){
                          
                          i=0;
                          for(;!fts[pos[0]][fts[0].length-1-i].isEmpty();++i);
                          str=fts[pos[0]][fts[0].length-1-i];
                          pos[1]=fts[0].length-1-i;
                        }else{
                          str=fts[pos[0]][pos[1]-i-1];
                          pos[1]=pos[1]-i-1;
                        }
                      }
                      
                    }else{  
                      str=fts[pos[0]][pos[1]-1];
                      --pos[1];
                    }
                    break;
          case "right":
                    if(pos[1]==fts[0].length-1 || fts[pos[0]][pos[1]+1].isEmpty()){
                      if(pos[1]==fts[0].length-1 || pos[1]+1==fts[0].length-1){
                        int i=0;
                        for(;fts[pos[0]][i].isEmpty();++i);
                        str=fts[pos[0]][i];
                        pos[1]=i;
                      }else if(fts[pos[0]][pos[1]+1].isEmpty()){
                        int i=1;
                        
                        for(; pos[1]+i<fts.length;++i){
                          if(fts[pos[0]][pos[1]+i].isEmpty()) break;
                        };
                        
                        if(pos[1]==fts.length){
                          i=0;
                          for(;fts[pos[0]][i].isEmpty();++i);
                          str=fts[pos[0]][i+1];
                          pos[1]=i+1;
                        }else{
                          str=fts[pos[0]][pos[1]+i+1];
                          pos[1]=pos[1]+i+1;
                        }
                      }
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


//////////////////////
import java.util.ArrayList;
import java.util.List;

/*
Note: Though by storing the grid in a member storing max positions becomes redundant, but this way 
      only a few new lines had to be added to my solution of part 1.
*/
public class Solution{
    private static int currentHorizontalPosition;
    private static int currentVerticalPosition;
    private static int maxHorizontalPosition;
    private static int maxVerticalPosition;
    private static String[][] grid;

    public static String[] superStreetFighterize(String[][] fighters, int[] position, String[] moves){
        List<String> result = new ArrayList<>();
        initializePositions(fighters, position);

        for(int i=0; i<moves.length; i++){
            move(moves[i]);
            result.add(fighters[currentVerticalPosition][currentHorizontalPosition]);
        }

        return result.toArray(new String[result.size()]);
    }

    private static void initializePositions(String[][] fighters, int[] position){
        currentHorizontalPosition = position[1];
        currentVerticalPosition = position[0];
        maxHorizontalPosition = fighters[0].length - 1;
        maxVerticalPosition = fighters.length - 1;
        grid = fighters;
    }

    private static void move(String move){
        switch (move.toLowerCase()) {
                case "left":
                    moveLeft();
                    break;
                case "right":
                    moveRight();
                    break;
                case "up":
                    moveUp();
                    break;
                case "down":
                    moveDown();
                    break;
                default:
                    throw new IllegalArgumentException();
        }
    }

    private static void moveLeft(){
        currentHorizontalPosition = currentHorizontalPosition == 0
                ? maxHorizontalPosition
                : currentHorizontalPosition - 1;
        if(isEmpty(currentVerticalPosition, currentHorizontalPosition))
            moveLeft();
    }

    private static void moveRight(){
        currentHorizontalPosition = currentHorizontalPosition == maxHorizontalPosition
                ? 0
                : currentHorizontalPosition + 1;
        if(isEmpty(currentVerticalPosition, currentHorizontalPosition))
            moveRight();
    }

    private static void moveUp(){
        if(currentVerticalPosition > 0 && !isEmpty(currentVerticalPosition-1, currentHorizontalPosition))
            currentVerticalPosition--;
    }

    private static void moveDown(){
        if(currentVerticalPosition < maxVerticalPosition && !isEmpty(currentVerticalPosition+1, currentHorizontalPosition))
            currentVerticalPosition++;
    }

    private static boolean isEmpty(int verticalPosition, int horizontalPosition){
        return grid[verticalPosition][horizontalPosition].isEmpty();
    }
}


///////////////////
public class Solution {
	public static String[] superStreetFighterize(String[][] fighters, int[] position, String[] moves) {
		String[] result = new String[moves.length];
		final int w = fighters[0].length;
		final int h = fighters.length;
		String name = "undef";
		
		for (int i = 0; i < moves.length; i++) {
			do {
				switch (moves[i]) {
					case "up":
					case "down":
						position[0] = "up".equals(moves[i]) != "".equals(name) 
								? Math.max(position[0] - 1, 0) : Math.min(position[0] + 1, (h - 1));
						break;
					case "left":
						position[1] = (position[1] - 1 + w) % w;
						break;
					case "right":
						position[1] = (position[1] + 1) % w;
						break;
				}
				name = fighters[position[0]][position[1]];
			} while ("".equals(name));
			result[i] = name;
		}
		return result;
	}
}
/////////////
