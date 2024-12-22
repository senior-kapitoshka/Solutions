public class GiftSorter{
  public String sortGiftCode(String s){
    char arr[]=s.toCharArray();
    java.util.Arrays.sort(arr);
    String res=new String(arr); 
    return res;
  }
}

/////////////
public class GiftSorter{
  public String sortGiftCode(String code){
    char[] chars = code.toCharArray();
    java.util.Arrays.sort(chars);
    return new String(chars);
  }
}

//////////
import java.util.Arrays;
import java.util.stream.Collectors;

public class GiftSorter {
    public String sortGiftCode(String code) {
        return Arrays.stream(code.split(""))
                    .sorted()
                    .collect(Collectors.joining(""));
    }
}

//////////////
import static java.util.stream.Collectors.*;

public class GiftSorter{
  public String sortGiftCode(String code){
    return code.chars().sorted()
		  .mapToObj(c -> Character.toString((char) c))
		  .collect(joining());
  }
}

///////////
