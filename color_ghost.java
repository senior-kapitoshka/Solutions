import java.util.Random;

public class Ghost {
  public String getColor(){
    String sa[]={"white","yellow","purple","red"};
    Random r=new Random();
    return sa[r.nextInt(4)];
  }
}

////////////////////
import java.util.Random;

public class Ghost {
	private String[] m_colorCodes = new String[]{"white" , "yellow" , "purple" , "red"};
	private String m_color = "";
	
	public Ghost(){
		m_color = m_colorCodes[new Random().nextInt(m_colorCodes.length)];
	}
	
	public String getColor(){
		return m_color;
	}
}

/////////////////////
public class Ghost {
  private final String[] colors = {"white", "yellow", "purple", "red"}; 
  
  public Ghost() {
  }
  
  public String getColor() {
    return colors[(int)(Math.random() * colors.length)];
  }
}

/////////////////////
import static java.util.List.of;

import java.util.Random;

class Ghost {
  static String getColor() {
    return of("white", "yellow", "purple", "red").get(new Random().nextInt(4));
  }
}

/////////////////
import java.util.*;

public class Ghost {
  String color = "";
  
  public String getColor(){
    return this.color;
  }
  
  public Ghost(){
    switch(new Random().nextInt(4)){
      case 0:
        this.color = "white";
        break;
      case 1:
        this.color = "yellow";
        break;
      case 2:
        this.color = "purple";
        break;
      case 3:
        this.color = "red";
        break;
    }
  }
}

//////////////
