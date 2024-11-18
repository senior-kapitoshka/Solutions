class Nerd {
  public static String nerdify(String txt){
    String res=txt.replaceAll("A","4")
      .replaceAll("a","4")
      .replaceAll("E","3")
      .replaceAll("e","3")
      .replaceAll("l","1");

    return res;
  }
}

///////////
class Nerd {
  public static String nerdify(String txt){
  
    return txt.replaceAll("[aA]", "4").replaceAll("[eE]", "3").replace("l", "1");
  }
}

///////////
