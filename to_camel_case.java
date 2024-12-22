import java.util.*;
import java.util.stream.*;

public class ZebulansNightmare{
  public static String zebulansNightmare(final String f) {
    boolean b[]={false};
    return Arrays.stream(f.split(""))
                  .map(s->{
                          if(b[0]){
                            s=s.toUpperCase();
                            b[0]=false;
                          }else if(s.equals("_")){
                            s="";
                            b[0]=true;
                          }
                          return s;
                  })
                  .collect(Collectors.joining());
  }
}

//////////////
public class ZebulansNightmare{
    public static String zebulansNightmare(final String functionName) {
         return functionName.contains("_") ? zebulansNightmare(functionName
                 .replaceFirst("_(.)", String.valueOf(functionName.charAt(functionName.indexOf("_") + 1)).toUpperCase())) : functionName;
     }
  }
/////////
import java.util.regex.Pattern;
public class ZebulansNightmare{
  public static String zebulansNightmare(final String functionName) {
    String result = Pattern.compile("_([a-z])").matcher(functionName).replaceAll(m -> m.group(1).toUpperCase());
    return result;
  }
}

//////////////
