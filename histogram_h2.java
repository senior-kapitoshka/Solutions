import java.util.*;
import org.apache.commons.lang3.StringUtils;


public class Dinglemouse {

  public static String histogram(final int rs[]) {
    StringBuilder sb=new StringBuilder();
    int sum=Arrays.stream(rs).sum();
    for(int i=rs.length-1;i>=0;--i){
      sb.append(i+1+"|");
      if(rs[i]==0){
        sb.append("\n");
      }else{
        sb.append(StringUtils.repeat("█",((rs[i]*100)/sum)/2))
          .append(" ")
          .append((rs[i]*100)/sum+"%")
          .append("\n");
      }
    }
    return sb.toString();
  }
  
}

//////////
public class Dinglemouse {

  public static String histogram(final int results[]) {
    int total = 0; for (int x : results) total += x;
    final StringBuilder sb = new StringBuilder();
    for (int i = 6; i >= 1; i--) {
      sb.append(i).append("|");
      if (total > 0) {
        final int freq = results[i-1];
        final int percent = (100 * freq) / total;
        if (percent > 0) {
          for (int c = 0; c < percent / 2; c++) sb.append("█");
          sb.append(String.format(" %d%%", percent));
        }
      }
      sb.append("\n");
    }
    return sb.toString();
  }
  
}

//////////////
public class Dinglemouse {
    public static String histogram(final int[] results) {
        StringBuilder sb = new StringBuilder();
        double proc = java.util.Arrays.stream(results).sum() / 100.0;

        for (int i = results.length - 1; i >= 0; i--) {
            int res = (int) Math.floor(results[i] / proc);
            sb.append(i + 1)
                    .append("|")
                    .append("█".repeat(res / 2))
                    .append(res > 0 ? " " + res + "%" : "")
                    .append("\n");
        }

        return sb.toString();
    }
}

////////////////
import java.util.Arrays;
public class Dinglemouse {

  public static String histogram(final int results[]) {
		String result = "";
		double sum = Arrays.stream(results).sum();
		for (int i = 5; i >= 0; i--) {
			result += (results[i] != 0) ? i + 1 + "|" + "\u2588".repeat((int) Math.floor((results[i] / sum) * 100) / 2) + " " + (int) Math.floor((results[i] / sum) * 100) + "%\n"
					: i + 1 + "|\n";
		}
		return result;
  }
  
}

///////////////
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Dinglemouse {

    public static String histogram(final int[] results) {
        List<String> lines = IntStream.range(1, results.length + 1).mapToObj(i -> {
                    int percent = (int) Math.floor((double) results[i - 1] / Arrays.stream(results).sum() * 100);
                    return i + "|" + (percent < 2 ? "" : "█".repeat(percent / 2) + " " + percent + "%") + "\n"; })
                .collect(Collectors.toList());
        Collections.reverse(lines);
        return String.join("", lines);
    }
}

///////////////
import static java.util.stream.IntStream.of;

public class Dinglemouse {

    public static String histogram(final int results[]) {
        StringBuilder a = new StringBuilder();
        String b ="";
        int w = of(results).sum();
        if(w==0) return "6|\n"+
                        "5|\n"+
                        "4|\n"+
                        "3|\n"+
                        "2|\n"+
                        "1|\n";
        for(int i=5; i >= 0; i--){
            b= results[i]==0?"": " " +(results[i]*100/w) + "%";
            a.append((i+1)+"|"+"█".repeat((results[i]*100/w)/2)+b+"\n");
        }
        return a.toString();
    }
  
}