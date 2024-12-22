public class CentParser {

    public static Integer toCents(String p) {
      return p.matches("[$]{1}[\\d]+[\\.]{1}[\\d]{2}")?
        Integer.parseInt(p.replaceAll("[$]|[.]","")):null;
    }
    
  }
  ///////////////
  class CentParser {
    static Integer toCents(String price) {
      return price.matches("\\$\\d+\\.\\d{2}") ? 
      Integer.parseInt(price.replaceAll("[$.]", "")) : null;
    }
  }

  ////////////
