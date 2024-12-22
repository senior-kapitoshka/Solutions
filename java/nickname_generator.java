class Generator {
    public static String nickname (String n) {
      if(n.length()<4) return "Error: Name too short";
      String s="aeiou";
    return s.indexOf(n.charAt(2))==-1?
        new String(n.substring(0,3)):
      new String(n.substring(0,4));
    }
}