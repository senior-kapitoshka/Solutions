import java.util.function.Function;

public class FunctionalProgramming {
  public static Function<Student, Boolean> f = s -> s.studentNumber.equals("js123") && s.getFullName().equals("John Smith");
}

/////////////////
import java.util.function.Function;

public class FunctionalProgramming {

  public static Function<Student, Boolean> f = (s) -> {
    
        String name = s.getFullName();
        String number = s.studentNumber;
      
        return (name.equals("John Smith") && number.equals("js123"));
      };
}

////////////////
