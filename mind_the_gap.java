public class TrainInspector {

    public static int countMissingCarriages(String t) {
      int res=0;
      int j=0;
      for(char i='A';j<t.length();++i){
        if(i==t.charAt(j)){
          ++j;
        }else{
          ++res;
        }
      }
      return res;
    }
  
  }

  ///////////
  public class TrainInspector {

    public static int countMissingCarriages(String train) {
      return (train.charAt(train.length() - 1) - 'A' + 1) - train.length();
    }
  
  }