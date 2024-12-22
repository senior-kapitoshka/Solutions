public class PigLatin{
 
   public String translate(String s){
     if(s.toLowerCase().matches("[\\w]*[\\d]+[\\w]*")) return null;
     if(s.toLowerCase().matches("^[aioue][\\w]+$")) return new String(s+"way").toLowerCase();
     if(s.toLowerCase().matches("^[\\w]+[aioueAIOUE][\\w]*")){
       int id=0;
       for(int i=0;i<s.length();++i){
         switch(s.toLowerCase().charAt(i)){
             case 'a':
            case 'i':
               case 'o':
               case 'u':
               case 'e': return new String(s.substring(i)+ s.substring(0,i)+"ay").toLowerCase();
         }
       }
     }
     return new String(s+"ay").toLowerCase();
   }
   
 }

 ///////////////////
 class PigLatin {
  static String translate(String s) {
    return (s = s.toLowerCase()).matches("[aeiou][a-z]*") ? s + "way" : s.matches("[a-z]*") ? s.replaceAll("^([^aeiou]*)(.*)","$2$1ay") : null;
  }
}

/////////
 public class PigLatin{
   public String translate(String str){
        if(str.matches(".*\\d+.*")) return null;
        else str = str.toLowerCase();
        if(str.matches("^[^aeiou]+.*"))
            return str.replaceAll("(^[^aeiou]+)(.*)", "$2$1ay");
        return str + "way";
   }
 }

 /////////
 public class PigLatin{

  public String translate(String str){
  
    if(str.matches(".*[0-9].*")) {
      return null;
    }
    
    if(!str.matches("(?i).*[aeiou].*")) {
      return str.toLowerCase() + "ay";
    }
    
    return str.toLowerCase()
              .replaceAll("\\b([aeiou]\\w*?(\\b)?)\\b", "$1way")
					  	.replaceAll("\\b([\\w&&[^aeiou]]+?)([aeiou][\\w]*?(\\b)?)\\b", "$2$1ay");
  }
}