public class RegexValidation {

    public static boolean validateTime(String t) {
      return t.matches("^(?:(?=2?[\\d]{1})2?[0-3]{1}|(?!2[\\d]{1})[0|1]?[\\d]{1}):[0-5]{1}[0-9]{1}$");
  /*   ^
          (
            [if]< (?: >
                    ( [expression equal]< ?= > 2?[\\d]{1} )
                    
                                        then   2?[0-3]{1}
       [else if]<  |  >  
                ( [expression not equal]< ?! > 2[\\d]{1}  ) 
                                        
                                        then   [0|1]?[\\d]{1} 
                                                              )
                                        
                              :[0-5]{1}[0-9]{1}   $          
      
      */    
    }
  }

  ///////////////
  public class RegexValidation {

    public static boolean validateTime(String time) {
      return time.matches("([01]?\\d|2[0-3]):[0-5]\\d");
    }
  }

///////////
import java.util.*;
public class RegexValidation {
  public static boolean validateTime(String time) {
    return time.matches("([01]?[0-9]|2[0-3]):[0-5][0-9]");
  }
}  