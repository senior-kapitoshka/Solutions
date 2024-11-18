import java.util.regex.*;
import java.util.*;
import java.math.*;

public class EasyBal {
  public static class Data{
    private List<Double>l;
    private double sum;
    private double total;
    private double average;
    Data(List<Double>ld,double d,double t,double a){
      l=ld;sum=d;
      total=t;average=a;
    }
    public List<Double> getList(){
      return l;
    }
    public double getAcc(){
      return sum;
    }
    public double getTotal(){
      return total;
    }
    public double getAvrg(){
      return average;
    }
  };
  
    public static Data diff(String bk){
      double begin=0;
      double acc=0;
      double total=0;
      double average=0;
      List<Double>ld=new ArrayList<>();
      String rgx="[\\d]+.[\\d]{2}";
      Pattern pt=Pattern.compile(rgx);
      Matcher mt=pt.matcher(bk);
      for(int i=0;mt.find();++i) {
        int start = mt.start();
        int end = mt.end();
        String mch = bk.substring(start, end);
        if(i==0){
          begin=Double.parseDouble(mch);
          acc=Double.parseDouble(mch);
        }else {
          acc=acc-Double.parseDouble(mch);
          total+=Double.parseDouble(mch);
          total=new BigDecimal(total).setScale(2, BigDecimal.ROUND_HALF_EVEN).doubleValue();
          acc=new BigDecimal(acc).setScale(2, BigDecimal.ROUND_HALF_EVEN).doubleValue();
          ld.add(acc);
        }
      }
      average=total/ld.size()*1.00;
      
      average=Math.round(average * 100.0) / 100.0;
       average=new BigDecimal(average).setScale(2, BigDecimal.ROUND_HALF_DOWN).doubleValue();
      
      return new Data(ld,begin,total,average);
    }
    public static String getLines(String bk,Data sd){
      StringBuilder sb=new StringBuilder();
      String ars[]=bk.split("\n");
      for(int i=1;i<ars.length;++i){
        if(!ars[i].isEmpty()){
          ars[i]=ars[i].replace("!","")
            .replace(":","").replace("=","").replace(";","")
            .replace("{}","").replace("{","")
            .replace("}","");
          String rgx="([\\d]+)([A-Z a-z]+)([\\d]+.[\\d]{2})";
          Pattern pt=Pattern.compile(rgx);
          Matcher mt=pt.matcher(ars[i]);
          StringBuilder s=new StringBuilder();
          while(mt.find()){
            s.append(mt.group(1).trim())
              .append(" ")
              .append(mt.group(2).trim())
              .append(" ")
              .append(mt.group(3).trim())
              .append(" ")
              .append("Balance")
              .append(" ")
              .append(String.format( "%.2f", sd.getList().get(i-1)))
              .append("\\r\\n");
          }
          sb.append(s.toString());
        }
      }
      return sb.toString();
    }
    
    public static String balance(String bk) {
      Data sd=diff(bk);
      String s=getLines(bk,sd);
      StringBuilder sb=new StringBuilder();
      sb.append("Original Balance: ")
        .append(String.format( "%.2f", sd.getAcc()))
        .append("\\r\\n")
        .append(s)
        .append("Total expense  ")
        .append(String.format( "%.2f", sd.getTotal()))
        .append("\\r\\n")
        .append("Average expense  ")
        .append(String.format( "%.2f", sd.getAvrg()));
      return sb.toString();
    }
}

//////////////
public class EasyBal {
    
    public static String balance(String book) {
        String t = book.replaceAll("([^\\n. \\da-zA-Z])", "");
        String[] arr = t.split("[\\n]+");
        double current = Double.parseDouble(arr[0]);
        double total = 0;
        int count = 0;
        StringBuilder result = new StringBuilder();
        result.append("Original Balance: " + arr[0]);
        for (int i = 1; i < arr.length; i++) {
            count++;
            String[] line = arr[i].split("[ ]+");
            current -= Double.parseDouble(line[2]);
            total += Double.parseDouble(line[2]);
            String u = String.format("\\r\\n%s %s %s Balance %.2f", line[0], line[1], line[2], current);
            result.append(u);
        }
        result.append(String.format("\\r\\nTotal expense  %.2f\\r\\nAverage expense  %.2f", total, total / count));
        return result.toString();
    }
}

////////////////
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;
import java.util.stream.Stream;

public class EasyBal {

    private static class Item {
        private final String number;
        private final String category;
        private final BigDecimal price;

        public Item(final String input) {
            String[] parts = input.split("\\ +");
            this.number = parts[0];
            this.category = parts[1];
            this.price = new BigDecimal(parts[2]);
        }

        @Override
        public String toString() {
            return String.format("%s %s %s", number, category, price);
        }
    }

    private static class Stat {
        private BigDecimal balance;
        private BigDecimal total = new BigDecimal(0L);
        private long count = 0L;

        public Stat(final String value) {
            this.balance = new BigDecimal(clean(value));
        }

        public void account(final Item item) {
            total = total.add(item.price);
            balance = balance.subtract(item.price);
            count++;
        }

        public String original() {
            return String.format("Original Balance: %s\\r\\n", balance.setScale(2, RoundingMode.HALF_UP));
        }

        public String balance() {
            return String.format("Balance %s", balance.setScale(2, RoundingMode.HALF_UP));
        }

        public String result() {
            return String.format("Total expense  %s\\r\\nAverage expense  %s",
                    total.setScale(2, RoundingMode.HALF_UP),
                    total.divide(new BigDecimal(count), 2, RoundingMode.HALF_UP));
        }
    }

    private static final Set<Character> SPACE_DOT = new HashSet<>(Arrays.asList(' ', '.'));

    public static String balance(String input) {
        final StringBuilder result = new StringBuilder();
        final String[] lines = input.split("\n");
        final Stat stat = new Stat(lines[0]);

        result.append(stat.original());
        Stream.of(lines)
                .skip(1L)
                .filter(EasyBal::notEmpty)
                .map(EasyBal::clean)
                .map(Item::new)
                .peek(stat::account)
                .map(item -> String.format("%s %s\\r\\n", item, stat.balance()))
                .forEach(result::append);
        result.append(stat.result());
        return result.toString();
    }

    private static boolean notEmpty(final String input) {
        return input != null && !"".equals(input);
    }

    private static String clean(String s) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isLetterOrDigit(c)
                    || c == ' ' || c == '.') {
                result.append(c);
            }
        }
        return result.toString();
    }
}

/////////////////
import java.util.stream.IntStream;
import java.util.regex.MatchResult;
import java.util.regex.Pattern;
import java.util.*;

public class EasyBal {
    public static String balance(String book) {
        String cleanBook = book.replaceAll("[^\n\\w. ]", "")
                .replaceAll(" +", " ");

        double[] values = Pattern.compile("\\d+\\.\\d+").matcher(cleanBook).results()
                .map(MatchResult::group)
                .mapToDouble(Double::parseDouble)
                .toArray();

        String[] lines = cleanBook.split("\n");
        List<String> res = new ArrayList<>();
        res.add(String.format("Original Balance: %.2f", values[0]));

        for(int i = 1; i < lines.length; i++) {
            values[0] -= values[i];
            res.add(String.format("%s Balance %.2f", lines[i].trim(), values[0]));
        }

        DoubleSummaryStatistics dsm = IntStream.range(1, values.length)
                .mapToDouble(i -> values[i])
                .summaryStatistics();
        res.add(String.format("Total expense  %.2f", dsm.getSum()));
        res.add(String.format("Average expense  %.2f", dsm.getAverage()));

        return String.join("\\r\\n", res);
    }
}

///////////////
import static java.util.Arrays.stream;
import static java.util.stream.Collectors.*;
import java.math.BigDecimal;

public class EasyBal {
    
    private static StringBuilder report = new StringBuilder();
    
    public static String balance(String book) {
        report.setLength(0);
        String[] kep = book.split("\n");
        String no_signed_line = stream(kep).map(k -> k.replaceAll("[^\\.\\d[a-zA-Z]]", " "))
                .skip(1).map(k -> k.replaceAll("(\\d+)\\s*([a-zA-Z]+)\\s*(\\d+\\.\\d+)", "$1 $2 =$3"))
                .collect(joining("\n"));
        report.append("Original Balance: ")
                .append(kep[0].replaceAll("[^\\.\\d[a-zA-Z]]", "")).append("\\r\\n");
        String allMoney = kep[0].replaceAll("[^\\.\\d[a-zA-Z]]", "").trim();
       
        float sum = stream(no_signed_line.split("\n"))
                .map(ku -> Float.parseFloat(ku.split("=")[1])).reduce(Float::sum).get();
        float num = Float.parseFloat(allMoney);
        for (String line : no_signed_line.split("\n")) {
            num = num - Float.parseFloat(line.split("=")[1]);
            report.append(line.split("=")[0]).append(line.split("=")[1].trim())
                    .append(" Balance ").append(String.format("%.2f", num)).append("\\r\\n");
        }
        report.append("Total expense  ").append(String.format("%.2f", sum)).append("\\r\\n")
                .append("Average expense  ").append(String.format("%.2f", (getRounded(sum) / (kep.length - 1))));
        return report.toString();
    }
      private static float getRounded(float num) {
        return new BigDecimal(num).setScale(3,BigDecimal.ROUND_UP).floatValue();
    }
}

/////////////
import java.math.BigDecimal;
import java.math.RoundingMode;

import java.util.Arrays;
import java.util.Objects;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class EasyBal {
  private static final String PROHIBITED_LETTERS = "[^A-Za-z0-9. ]+";
  public static String balance(String book) {
    String[] bookItems = book.split("\n");
    BigDecimal originalBalance = new BigDecimal(bookItems[0].replaceAll(PROHIBITED_LETTERS, ""));
    Data[] items = Arrays.stream(bookItems, 1, bookItems.length)
                         .filter(Objects::nonNull)
                         .map(item -> item.replaceAll(PROHIBITED_LETTERS, ""))
                         .filter(item -> !item.isEmpty())
                         .map(Data::parse)
                         .toArray(Data[]::new);
    BigDecimal totalExpense = Arrays.stream(items)
                                    .map(Data::getCheckAmount)
                                    .reduce(BigDecimal.ZERO, BigDecimal::add);
    BigDecimal averageExpense = totalExpense.divide(new BigDecimal(items.length), RoundingMode.HALF_UP);
    StringBuilder result = new StringBuilder();
    result.append(String.format("Original Balance: %.2f\\r\\n", originalBalance));
    BigDecimal balance = originalBalance;
    for(Data item : items) {
      balance = balance.subtract(item.getCheckAmount());
      result.append(String.format("%03d %s %.2f Balance %.2f\\r\\n",
        item.getCheckNum(), item.getCategory(), item.getCheckAmount(), balance));
    }
    result.append(String.format("Total expense  %.2f\\r\\n", totalExpense));
    result.append(String.format("Average expense  %.2f", averageExpense));
    return result.toString();
  }
  
  private static class Data {
    
    private static final Pattern DATA_PATTERN = Pattern.compile(
      "(\\d+) +(\\p{Alpha}+) +(\\d+\\.\\d{2})");
  
    private int checkNum;
    private String category;
    private BigDecimal checkAmount;
    
    private Data(int checkNum, String category, BigDecimal checkAmount) {
      this.checkNum = checkNum;
      this.category = category;
      this.checkAmount = checkAmount;
    }
    
    public static Data parse(String data) {
      Matcher matcher = DATA_PATTERN.matcher(data.strip());
      if(!matcher.matches()) {
        throw new IllegalArgumentException("Wrong pattern for " + data);
      }
      
      String checkNum = matcher.group(1);
      String category = matcher.group(2);
      String checkAmount = matcher.group(3);
      return new Data(Integer.parseInt(checkNum), category, new BigDecimal(checkAmount));
    }
    
    public int getCheckNum() {
      return checkNum;
    }
    
    public String getCategory() {
      return category;
    }
    
    public BigDecimal getCheckAmount() {
      return checkAmount;
    }
  }
}

////////////////
