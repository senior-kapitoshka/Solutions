import org.apache.commons.lang3.StringUtils;
class Solution {
  public static String calc(String txt){
    int x=txt.indexOf('+')!=-1?(txt.substring(0,txt.indexOf('+')).length()-1)+txt.substring(txt.indexOf('+')+2).length():
    txt.indexOf('*')!=-1?(txt.substring(0,txt.indexOf('*')).length()-1)*txt.substring(txt.indexOf('*')+2).length():
    txt.indexOf('-')!=-1?(txt.substring(0,txt.indexOf('-')).length()-1)-txt.substring(txt.indexOf('-')+2).length():
    (txt.substring(0,txt.indexOf('/')).length()-1)/txt.substring(txt.indexOf('/')+3).length();

    return StringUtils.repeat(".", x);
  }
}

///////////////
class Solution {
    public static String calc(String txt){
      int i1=txt.indexOf(" ");
      int i2=txt.length()-i1-3;
      switch (txt.replace(".","").trim()) {
          case "+":return ".".repeat(i1+i2);
          case "-":return ".".repeat(i1-i2);
          case "*":return ".".repeat(i1*i2);
          default:return ".".repeat(i1/(i2-1));
      }
    }
  }

  ///////////
  class Solution {
    public static String calc(String txt){
          int number1= txt.split(" ")[0].toCharArray().length;
          int number2= txt.split(" ")[2].toCharArray().length;
          return switch(txt.split(" ")[1]) {
              case "//" -> ".".repeat(number1/number2);
              case "*" -> ".".repeat(number1 * number2);
              case "+" -> ".".repeat(number1 + number2);
              default -> ".".repeat(number1 - number2);
          };
    }
  }