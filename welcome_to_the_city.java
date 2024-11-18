public class Hello{
  public String sayHello(String [] n, String c, String st){
    return "Hello, " + String.join(" ",n) + String.format("! Welcome to %s, %s!",c,st);
  }
}

//////////////////
public class Hello{
  public String sayHello(String[] name, String city, String state){
    return String.format("Hello, %s! Welcome to %s, %s!",String.join(" ", name),city,state);
  }
}

///////////////
public class Hello{
  public String sayHello(String [] name, String city, String state){
    StringBuilder sb = new StringBuilder();
    sb.append("Hello,");
    for(String n : name){
      sb.append(" ");
      sb.append(n);
    }
    sb.append("! Welcome to ");
    sb.append(city);
    sb.append(", ");
    sb.append(state);
    sb.append("!");
    return sb.toString();
  }
}

////////////////
