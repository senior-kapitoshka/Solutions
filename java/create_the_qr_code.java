import java.util.*;
import java.util.stream.*;
import org.apache.commons.lang3.ArrayUtils;
class CodeWars {

  static private int padding[]=new int[]{1,1,1,0,1,1,0,0,0,0,0,1,0,0,0,1};
  static private int polynom[]=new int[]{0,43,139,206,78,43,239,123,206,214,147,24,99,150,39,243,163,136};
  
  static private void getBinaryMx(int mxTemplate[][]){
    for(int i=0;i<21;++i){
       System.out.print("{");
      for(int j=0;j<21;++j){
        System.out.print(mxTemplate[i][j]+",");
      }
       System.out.print("},\n");
    }
    
    System.out.print("---\n");
  }
  
  static private void setData(String s,List<Integer> dataTemplate){
    //addSize
    dataTemplate.addAll(
                String.format(
                        "%08d",Integer.parseInt(
                                      Integer.toBinaryString(s.length())))
                                      .chars()
                                      .map(i->(int)i-48)
                                      .boxed()
                                      .collect(Collectors.toList()));
    
    //stringToBinaryList
    dataTemplate.addAll(s.chars().map(i->(int)i)
                                  .mapToObj(
                                    i-> String.format("%08d",Integer.parseInt(
                                                    Integer.toBinaryString(i)))
                                  )
                                  .collect(Collectors.joining("")) //first -> in binaryString
                                  .chars()
                                  .map(i->(int)i-48)
                                  .boxed()
                                  .collect(Collectors.toList()));// then -> to Integer List
    if(dataTemplate.size()<69){
      dataTemplate.addAll(List.of(0,0,0,0));
    }else if(dataTemplate.size()<70){
      dataTemplate.addAll(List.of(0,0,0));
    }else if(dataTemplate.size()<71){
      dataTemplate.addAll(List.of(0,0));
    }else if(dataTemplate.size()<72){
      dataTemplate.addAll(List.of(0));
    }
    for(int i=0;dataTemplate.size()<72;++i){
      dataTemplate.add(padding[i%padding.length]);
    }
  }
  
  static private void errorCorrection(List<Integer> data){
    int n=data.size();
    List<Integer> corrNums=new ArrayList<>();
     List<Integer> tempList=new ArrayList<>();
    for(int i=0;i<n;i+=8){
      corrNums.add(Integer.parseInt(data.subList(i,i+8).stream().map(e -> e.toString()).reduce("", String::concat),2));
    }
    for(int i=0;i<n/8;++i){
      int alphaExponent = Preloaded.alphaTable[corrNums.get(0)];
      List<Integer> newList = Arrays.stream(polynom)
                                    .map(j->{
                                            int temp=j+alphaExponent;
                                            j=temp>255? temp%255: temp;
                                            return j;
                                    })
                                    .map(j->Math.abs(ArrayUtils.indexOf(Preloaded.alphaTable,j)))
                                    .boxed()
                                    .collect(Collectors.toList());
      int x[]={0};
      corrNums = corrNums.stream()
                        .map(j->Math.abs(j^newList.get(x[0]++)))
                        .collect(Collectors.toList());
      corrNums.remove(0);

      if(corrNums.size()<17){
        corrNums.addAll(newList.subList(corrNums.size()+1,newList.size()));
      } 
        
      while(corrNums.size()<17){
        corrNums.add(newList.get(newList.size()-1));
      }
      if(i!=8){
        while(corrNums.get(0)==0){
            corrNums.remove(0);
            ++i;
        }
      }
    tempList=newList;
    }
    if(corrNums.size()<17){
        corrNums.addAll(tempList.subList(corrNums.size()+1,tempList.size()));
    } 
  data.addAll(corrNums.stream().map(
                                    i->
                                       String.format("%08d",Integer.parseInt(
                                                   Integer.toBinaryString(i)))
                                  )
                                  .collect(Collectors.joining("")) //first -> in binaryString
                                  .chars()
                                  .map(i->(int)i-48)
                                  .boxed()
                                  .collect(Collectors.toList()));
    
  }
  
  static private void fillMx(List<Integer> data,int[][] mxTemplate){
    int x=20;
    int y=20;
    boolean flag=true;
    int flag2=2;
    boolean flag3=false;
    for(int i=0,n=data.size();i<n;){
      if(mxTemplate[x][y]==2){
        if((x+y)%2==0){
          mxTemplate[x][y]=data.get(i)==0?1:0;
        }else{
          mxTemplate[x][y]=data.get(i);
        }
        ++i;
      }
      if(x==0 || x == mxTemplate.length-1){
        if(flag2<3){
          if(y!=7){
            --y;
            ++flag2;
          }else{
            y-=2;
            ++flag2;
            flag3=true;
          }
        }else{
          flag=!flag;
          if(flag){
              ++y;
              ++x;
          }else if(!flag){
              ++y;
              --x;
          }
          flag2=0;
        }
      }else{
        if(!flag){
          if(!flag3){
            if(y%2==0){
              --y;
            }else{
              ++y;
              --x;
            }
          }else{
             if(y%2!=0){
              --y;
            }else{
              ++y;
              --x;
            }
          }
        }else if(flag){
          
          if(!flag3){
            if(y%2==0){
              --y;
            }else{
              ++x;
              ++y;
            }
          }else{
            if(y%2!=0){
              --y;
            }else{
              ++x;
              ++y;
            }
          }
        }
      }
    }
  }
  static public int[][] createQrCode(String s) {
    int[][] mxTemplate=new int[][]{{1,1,1,1,1,1,1,0,1,2,2,2,2,0,1,1,1,1,1,1,1},
                                                {1,0,0,0,0,0,1,0,0,2,2,2,2,0,1,0,0,0,0,0,1},
                                                {1,0,1,1,1,0,1,0,0,2,2,2,2,0,1,0,1,1,1,0,1},
                                                {1,0,1,1,1,0,1,0,1,2,2,2,2,0,1,0,1,1,1,0,1},
                                                {1,0,1,1,1,0,1,0,0,2,2,2,2,0,1,0,1,1,1,0,1},
                                                {1,0,0,0,0,0,1,0,0,2,2,2,2,0,1,0,0,0,0,0,1},
                                                {1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1},
                                                {0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0},
                                                {0,0,1,0,1,1,1,0,1,2,2,2,2,1,0,0,0,1,0,0,1},
                                                {2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
                                                {2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
                                                {2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
                                                {2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
                                                {0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2},
                                                {1,1,1,1,1,1,1,0,0,2,2,2,2,2,2,2,2,2,2,2,2},
                                                {1,0,0,0,0,0,1,0,1,2,2,2,2,2,2,2,2,2,2,2,2},
                                                {1,0,1,1,1,0,1,0,1,2,2,2,2,2,2,2,2,2,2,2,2},
                                                {1,0,1,1,1,0,1,0,0,2,2,2,2,2,2,2,2,2,2,2,2},
                                                {1,0,1,1,1,0,1,0,1,2,2,2,2,2,2,2,2,2,2,2,2},
                                                {1,0,0,0,0,0,1,0,0,2,2,2,2,2,2,2,2,2,2,2,2},
                                                {1,1,1,1,1,1,1,0,0,2,2,2,2,2,2,2,2,2,2,2,2}};
    List<Integer> data=new ArrayList<>(Arrays.asList(0,1,0,0));
    setData(s,data);
    errorCorrection(data);
    fillMx(data, mxTemplate);
    getBinaryMx(mxTemplate);
    return mxTemplate;
    
  }
}
/////////////////////
import java.util.Arrays;

public class CodeWars {
    private static final int FIELD_GENERATOR = 0b100011101;

    private static int multiply(int x, int y) {
        int p = 0;
        for (int i = 0, t = 1; i < 8; i++, t <<= 1)
            if ((y & t) != 0)
                p ^= x << i;
        for (int i = 31 - Integer.numberOfLeadingZeros(p), t = 1 << i; i >= 8; i--, t >>= 1)
            if ((p & t) != 0)
                p ^= FIELD_GENERATOR << (i - 8);
        return p;
    }

    private static final int[] POWERS = new int[255];
    private static final int[] LOGARITHMS = new int[256];
    static {
        int p = 1;
        for (int i = 0; i < 255; i++) {
            POWERS[i] = p;
            LOGARITHMS[p] = i;
            p = multiply(p, 2);
        }
    }

    private static int multiplyFast(int x, int y) {
        return x > 0 && y > 0 ? POWERS[(LOGARITHMS[x] + LOGARITHMS[y]) % 255] : 0;
    }

    private static int MSG_SIZE = 9;
    private static int ECC_SIZE = 17;
    private static int[] GENERATOR_POLYNOMIAL = new int[ECC_SIZE + 1];
    static {
        GENERATOR_POLYNOMIAL[0] = 1;
        for (int i = 0; i < ECC_SIZE;) {
            int p = POWERS[i++];
            int t = 0;
            for (int j = 0; j <= i; j++) {
                int u = t;
                t = GENERATOR_POLYNOMIAL[j];
                GENERATOR_POLYNOMIAL[j] = t ^ multiplyFast(u, p);
            }
        }
    }
    private static final int MATRIX_SIZE = 21;
    private static final int[][] CLICHE = new int[MATRIX_SIZE][MATRIX_SIZE];
    static {
        for (int[] row : CLICHE)
            Arrays.fill(row, -1);
        fillArea(0, 0, 9, 9, 0);
        fillArea(0, 0, 7, 7, 1);
        fillArea(1, 1, 5, 5, 0);
        fillArea(2, 2, 3, 3, 1);
        fillArea(8, 2, 1, 1, 1);
        fillArea(8, 4, 1, 3, 1);
        fillArea(0, 8, 1, 1, 1);
        fillArea(3, 8, 1, 1, 1);
        fillArea(6, 8, 1, 1, 1);
        fillArea(8, 8, 1, 1, 1);
        fillArea(0, 13, 9, 8, 0);
        fillArea(0, 14, 7, 7, 1);
        fillArea(1, 15, 5, 5, 0);
        fillArea(2, 16, 3, 3, 1);
        fillArea(8, 13, 1, 1, 1);
        fillArea(8, 17, 1, 1, 1);
        fillArea(8, 20, 1, 1, 1);
        fillArea(13, 0, 8, 9, 0);
        fillArea(14, 0, 7, 7, 1);
        fillArea(15, 1, 5, 5, 0);
        fillArea(16, 2, 3, 3, 1);
        fillArea(13, 8, 1, 1, 1);
        fillArea(15, 8, 2, 1, 1);
        fillArea(18, 8, 1, 1, 1);
        fillArea(6, 9, 1, 4, 0);
        fillArea(6, 10, 1, 1, 1);
        fillArea(6, 12, 1, 1, 1);
        fillArea(9, 6, 4, 1, 0);
        fillArea(10, 6, 1, 1, 1);
        fillArea(12, 6, 1, 1, 1);
    }

    private static void fillArea(int top, int left, int height, int width, int value) {
        for (int i = 0; i < height; i++)
            Arrays.fill(CLICHE[top + i], left, left + width, value);
    }

    private static void addShiftedByte(int[] message, int beginIndex, int byteValue) {
        message[beginIndex] |= byteValue >> 4;
        message[beginIndex + 1] = (byteValue & 0x0F) << 4;
    }

    private static int[] addECC(int[] message) {
        int[] result = Arrays.copyOf(message, MSG_SIZE + ECC_SIZE);
        for (int i = 0; i < MSG_SIZE; i++) {
            int t = result[i];
            if (t != 0)
                for (int j = 0; j <= ECC_SIZE; j++)
                    result[i + j] ^= multiplyFast(t, GENERATOR_POLYNOMIAL[j]);
        }
        System.arraycopy(message, 0, result, 0, MSG_SIZE);
        return result;
    }

    public static int[][] createQrCode(String input) {
        int length = input.length();
        if (length > 7)
            throw new UnsupportedOperationException("Length of input > 7");
        int[] message = new int[MSG_SIZE];
        message[0] = 0b01000000;
        addShiftedByte(message, 0, length);
        for (int i = 0; i < length; i++)
            addShiftedByte(message, i + 1, input.charAt(i) & 0xFF);
        int padding = 0b00010001;
        for (int i = length + 2; i < MSG_SIZE; i++) {
            padding ^= 0b11111101;
            message[i] = padding;
        }
        int[] code = addECC(message);
        int byteIndex = 0;
        int bitIndex = 7;
        int[][] matrix = new int[MATRIX_SIZE][MATRIX_SIZE];
        int y = MATRIX_SIZE - 1;
        int rightX = y;
        int dy = -1;
        while (true) {
            int lastY = MATRIX_SIZE - 1 - y;
            while (true) {
                for (int x = rightX; x >= rightX - 1; x--) {
                    int c = CLICHE[y][x];
                    if (c < 0) {
                        c = code[byteIndex] >> bitIndex & 1;
                        if (--bitIndex < 0) {
                            bitIndex = 7;
                            byteIndex++;
                        }
                        if (((x + y) & 1) == 0)
                            c = 1 - c;
                    }
                    matrix[y][x] = c;
                }
                if (y == lastY)
                    break;
                y += dy;
            }
            rightX -= 2;
            if (rightX < 0)
                break;
            if (rightX == 6) {
                for (int yy = 0; yy < MATRIX_SIZE; yy++)
                    matrix[yy][6] = CLICHE[yy][6];
                rightX--;
            }
            dy = -dy;
        }
        return matrix;
    }
}

////////////
import java.util.BitSet;

class CodeWars {
  
  private static int[] genAlphas = {0, 43, 139, 206, 78, 43, 239, 123, 206, 214, 147, 24, 99, 150, 39, 243, 163, 136};
  private static int[] revAlphaTable;
  static {
    revAlphaTable = new int[256];
    for (int i = 1; i < 256; i++) {
      revAlphaTable[Preloaded.alphaTable[i]] = i;
    }
  }
  
  private static int[][] template = {
    {1,1,1,1,1,1,1,0,1,0,0,0,0,0,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1,0,1},
    {1,0,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,1,1,0,1},
    {1,0,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1,0,1},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,0,1,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };
  
  private static int[] order = {
    440, 439, 419, 418,
    398, 397, 377, 376, 356, 355, 335, 334,
    314, 313, 293, 292, 272, 271, 251, 250,
    230, 229, 209, 208, 207, 206, 228, 227,
    249, 248, 270, 269, 291, 290, 312, 311,
    333, 332, 354, 353, 375, 374, 396, 395,
    417, 416, 438, 437, 436, 435, 415, 414,
    394, 393, 373, 372, 352, 351, 331, 330,
    310, 309, 289, 288, 268, 267, 247, 246,
    226, 225, 205, 204, 203, 202, 224, 223,
    245, 244, 266, 265, 287, 286, 308, 307,
    329, 328, 350, 349, 371, 370, 392, 391,
    413, 412, 434, 433, 432, 431, 411, 410,
    390, 389, 369, 368, 348, 347, 327, 326,
    306, 305, 285, 284, 264, 263, 243, 242,
    222, 221, 201, 200, 180, 179, 159, 158,
    117, 116,  96,  95,  75,  74,  54,  53,
     33,  32,  12,  11,  10,   9,  31,  30,
     52,  51,  73,  72,  94,  93, 115, 114,
    157, 156, 178, 177,
    199, 198, 220, 219, 241, 240, 262, 261,
    283, 282, 304, 303, 325, 324, 346, 345,
    367, 366, 388, 387, 409, 408, 430, 429,
    260, 259, 239, 238, 218, 217, 197, 196,
    194, 193, 215, 214, 236, 235, 257, 256,
    255, 254, 234, 233, 213, 212, 192, 191,
    190, 189, 211, 210, 232, 231, 253, 252,
  };
  
  public static int[][] createQrCode(String s) {
    BitSet b = generateBitSet(s);
    int[] ec = generateEC(b, s);
    for (int i = 0; i < ec.length; i++) {
      setBits(b, 72 + i * 8, ec[i]);
    }
    return genQRCode(b);
  }
  
  private static int[][] genQRCode(BitSet b) {
    int[][] qrCode = new int[21][];
    for (int i = 0; i < 21; i++) {
      qrCode[i] = template[i].clone();
    }
    for (int i = 0; i < order.length; i++) {
      int r = order[i] / 21;
      int c = order[i] % 21;
      qrCode[r][c] = ((b.get(i) ? 0 : 1) ^ (r + c)) & 1;
    }
    return qrCode;
  }
  
  private static int[] generateEC(BitSet b, String s) {
    int[] messagePoly = new int[9];
    for (int i = 0; i < messagePoly.length; i++) {
      for (int j = 0; j < 8; j++) {
        messagePoly[i] += b.get(i*8 + j) ? 1 << (7 - j) : 0;
      }
    }
    
    for (int i = 0; i < 9; i++) {
      int[] g = genAlphas.clone();
      int messageLeadAlpha = Preloaded.alphaTable[messagePoly[0]];
      for (int j = 0; j < g.length; j++) {
        g[j] = revAlphaTable[(g[j] + messageLeadAlpha) % 255];
        if (j < messagePoly.length) {
          g[j] ^= messagePoly[j];
        }
      }
      int n = g.length;
      while (g[g.length - n] == 0) {
        n--;
      }
      messagePoly = new int[n];
      for (int j = 0; j < n; j++) {
        messagePoly[j] = g[g.length - n + j];
      }
      if (messagePoly.length == 16) i++;
    }
    int[] ec = new int[17];
    for (int i = 0; i < messagePoly.length; i++) {
      ec[ec.length - messagePoly.length + i] = messagePoly[i];
    }
    return ec;
  }
  
  private static BitSet generateBitSet(String s) {
    int n = s.length();
    BitSet b = new BitSet();
    b.set(1);
    setBits(b, 4, n);
    for (int i = 0; i < n; i++) {
      setBits(b, 12 + 8 * i, s.charAt(i));
    }
    for (int i = n; i < 7; i++) {
      setBits(b, 16 + 8 * i, ((i - n) & 1) == 0 ? 236 : 17);
    }
    return b;
  }
  
  private static void setBits(BitSet b, int i, int n) {
    for (int j = 0; j < 8; j++) {
      if (((n >> j) & 1) == 1) {
        b.set(i + 7 - j);
      }
    }
  }
}


////////////////
class CodeWars {
 
 public static String intTo8BitString(int i){
        StringBuilder sb = new StringBuilder();
        for (int k=0;k<8;k++){
            sb.append(i%2);
            i=i/2;
        }
        return sb.reverse().toString();
    }

    public static String charTo8bitString(char c){
        return intTo8BitString(c);
    }

    public static int string8bitToInt(String s){
        int result =0;
        char[] array = s.toCharArray();
        int power =7;
        for (int i=0;i<8;i++){
            if (array[i]=='1'){
                result += (int) Math.pow(2,power);
            }
            power--;
        }
        return result;
    }

     public static int[][] createQrCode(String string) {
        StringBuilder bits = new StringBuilder();
        bits.append("0100");//byte mode
        bits.append(intTo8BitString(string.length()));
        for (char c : string.toCharArray()) {
            bits.append(charTo8bitString(c));
        }
        while (bits.length() % 8 != 0){
            bits.append('0');
        }
        boolean flag = true;
        while (bits.length() < 72){
            if (flag){
                bits.append("11101100");
            } else {
                bits.append("00010001");
            }
            flag = !flag;
        }

        String group = "";
        int[] consts = new int[9];
        for (int i=0;i<9;i++){
            group = bits.substring(8*i,8*i+8);
            consts[i] = string8bitToInt(group);
        }

        int[] alphasPowers = new int[]{0,43,139,206,78,43,239,123,206,214,147,24,99,150,39,243,163,136};
        int alphaExponent = getAlpha(consts[0]);

        for (int i=0; i < alphasPowers.length;i++) {
            alphasPowers[i] += alphaExponent;
            if (alphasPowers[i] > 254){
                alphasPowers[i] %= 255;
            }
            alphasPowers[i] = getIntFromAlpha(alphasPowers[i]);
        }

        for (int i=0;i<9;i++){
            alphasPowers[i] = alphasPowers[i] ^ consts[i];
        }
        int[] temp = new int[17];
        for (int j=0;j<alphasPowers.length;j++){
            if (j>0){
                temp[j-1] = alphasPowers[j];
            }
        }
        alphasPowers = temp;



        for (int i=0;i<8;i++){
            alphaExponent = getAlpha(alphasPowers[0]);
            if (alphasPowers[0]==0){
                alphaExponent = getAlpha(alphasPowers[1]);
                if (alphasPowers[1]==0){
                    alphaExponent = getAlpha(alphasPowers[2]);
                }
            }


            int[] alphasPowersBase = new int[]{0,43,139,206,78,43,239,123,206,214,147,24,99,150,39,243,163,136};
            for (int j=0;j<alphasPowersBase.length;j++) {
                alphasPowersBase[j] += alphaExponent;
                if (alphasPowersBase[j] > 254){
                    alphasPowersBase[j] %= 255;
                }
                alphasPowersBase[j] = getIntFromAlpha(alphasPowersBase[j]);
            }

            temp = new int[17];

            for (int j=0;j<17;j++){
                alphasPowers[j] = alphasPowers[j] ^ alphasPowersBase[j];
               if (j>0){
                   temp[j-1] = alphasPowers[j];
               }
            }
            temp[16]=alphasPowersBase[17];

            if (temp[0]==0 ){
                alphasPowers=temp;
                temp = new int[17];

                for (int j=0;j<17;j++){
                    if (j>0){
                        temp[j-1] = alphasPowers[j];
                    }
                }
                i++;
            }
            alphasPowers=temp;

            
            if (i==8 && alphasPowers[16]==0){
                for (int j=16;j>0;j--){
                    alphasPowers[j]=alphasPowers[j-1];
                }
                alphasPowers[0]=0;
            }
            
        }


        for (int alphasPower : alphasPowers) {
            bits.append(intTo8BitString(alphasPower));
        }

        int[][] result = new int[21][21];
        boolean[][] isSet = new boolean[21][21];

        putData(result,isSet,0,0);
        putData(result,isSet,0,1);
        putData(result,isSet,0,2);
        putData(result,isSet,0,3);
        putData(result,isSet,0,4);
        putData(result,isSet,0,5);
        putData(result,isSet,0,6);
        putData(result,isSet,0,8);
        putData(result,isSet,1,0);
        putData(result,isSet,1,6);
        putData(result,isSet,2,0);
        putData(result,isSet,2,2);
        putData(result,isSet,2,3);
        putData(result,isSet,2,4);
        putData(result,isSet,2,6);
        putData(result,isSet,3,0);
        putData(result,isSet,3,2);
        putData(result,isSet,3,3);
        putData(result,isSet,3,4);
        putData(result,isSet,3,6);
        putData(result,isSet,3,8);
        putData(result,isSet,4,0);
        putData(result,isSet,4,2);
        putData(result,isSet,4,3);
        putData(result,isSet,4,4);
        putData(result,isSet,4,6);
        putData(result,isSet,5,0);
        putData(result,isSet,5,6);
        putData(result,isSet,6,0);
        putData(result,isSet,6,1);
        putData(result,isSet,6,2);
        putData(result,isSet,6,3);
        putData(result,isSet,6,4);
        putData(result,isSet,6,5);
        putData(result,isSet,6,6);
        putData(result,isSet,6,8);
        putData(result,isSet,8,2);
        putData(result,isSet,8,4);
        putData(result,isSet,8,5);
        putData(result,isSet,8,6);
        putData(result,isSet,8,8);
        putData(result,isSet,6,10);
        putData(result,isSet,6,12);

        putData(result,isSet,0,14);
        putData(result,isSet,0,15);
        putData(result,isSet,0,16);
        putData(result,isSet,0,17);
        putData(result,isSet,0,18);
        putData(result,isSet,0,19);
        putData(result,isSet,0,20);
        putData(result,isSet,1,14);
        putData(result,isSet,1,20);
        putData(result,isSet,2,14);
        putData(result,isSet,2,16);
        putData(result,isSet,2,17);
        putData(result,isSet,2,18);
        putData(result,isSet,2,20);
        putData(result,isSet,3,14);
        putData(result,isSet,3,16);
        putData(result,isSet,3,17);
        putData(result,isSet,3,18);
        putData(result,isSet,3,20);
        putData(result,isSet,4,14);
        putData(result,isSet,4,16);
        putData(result,isSet,4,17);
        putData(result,isSet,4,18);
        putData(result,isSet,4,20);
        putData(result,isSet,5,14);
        putData(result,isSet,5,20);
        putData(result,isSet,6,14);
        putData(result,isSet,6,15);
        putData(result,isSet,6,16);
        putData(result,isSet,6,17);
        putData(result,isSet,6,18);
        putData(result,isSet,6,19);
        putData(result,isSet,6,20);
        putData(result,isSet,8,13);
        putData(result,isSet,8,17);
        putData(result,isSet,8,20);

        putData(result,isSet,10,6);
        putData(result,isSet,12,6);
        putData(result,isSet,13,8);
        putData(result,isSet,14,0);
        putData(result,isSet,14,1);
        putData(result,isSet,14,2);
        putData(result,isSet,14,3);
        putData(result,isSet,14,4);
        putData(result,isSet,14,5);
        putData(result,isSet,14,6);
        putData(result,isSet,15,0);
        putData(result,isSet,15,6);
        putData(result,isSet,15,8);
        putData(result,isSet,16,0);
        putData(result,isSet,16,2);
        putData(result,isSet,16,3);
        putData(result,isSet,16,4);
        putData(result,isSet,16,6);
        putData(result,isSet,16,8);
        putData(result,isSet,17,0);
        putData(result,isSet,17,2);
        putData(result,isSet,17,3);
        putData(result,isSet,17,4);
        putData(result,isSet,17,6);
        putData(result,isSet,18,0);
        putData(result,isSet,18,2);
        putData(result,isSet,18,3);
        putData(result,isSet,18,4);
        putData(result,isSet,18,6);
        putData(result,isSet,18,8);
        putData(result,isSet,19,0);
        putData(result,isSet,19,6);
        putData(result,isSet,20,0);
        putData(result,isSet,20,1);
        putData(result,isSet,20,2);
        putData(result,isSet,20,3);
        putData(result,isSet,20,4);
        putData(result,isSet,20,5);
        putData(result,isSet,20,6);

        int[] x = new int[21*21-233];
        int[] y = new int[21*21-233];
        int counter=0;

        for (int i=20;i>8;i--){
            x[counter] = i;
            x[counter+1] = i;
            y[counter]=20;
            y[counter+1]=19;
            counter+=2;
        }

        for (int i=9;i<21;i++){
            x[counter] = i;
            x[counter+1] = i;
            y[counter]=18;
            y[counter+1]=17;

            counter+=2;
        }

        for (int i=20;i>8;i--){
            x[counter] = i;
            x[counter+1] = i;
            y[counter]=16;
            y[counter+1]=15;
            counter+=2;
        }

        for (int i=9;i<21;i++){
            x[counter] = i;
            x[counter+1] = i;
            y[counter]=14;
            y[counter+1]=13;

            counter+=2;
        }

        for (int i=20;i>=0;i--){
            if (i!=6){
                x[counter] = i;
                x[counter+1] = i;
                y[counter]=12;
                y[counter+1]=11;
                counter+=2;
            }
        }

        for (int i=0;i<21;i++){
            if (i!=6){
                x[counter] = i;
                x[counter+1] = i;
                y[counter]=10;
                y[counter+1]=9;
                counter+=2;
            }
        }

        for (int i=12;i>8;i--){
            x[counter] = i;
            x[counter+1] = i;
            y[counter]=8;
            y[counter+1]=7;
            counter+=2;
        }

        for (int i=9;i<13;i++){
            x[counter] = i;
            x[counter+1] = i;
            y[counter]=5;
            y[counter+1]=4;

            counter+=2;
        }

        for (int i=12;i>8;i--){
            x[counter] = i;
            x[counter+1] = i;
            y[counter]=3;
            y[counter+1]=2;
            counter+=2;
        }

        for (int i=9;i<13;i++){
            x[counter] = i;
            x[counter+1] = i;
            y[counter]=1;
            y[counter+1]=0;

            counter+=2;
        }

        counter=0;
        char[] list = bits.toString().toCharArray();
        for (int  i=0;i<208;i++) {
            boolean value = list[counter]=='1';
            if ((x[counter]+y[counter])%2==0){
                value=!value;
            }
            if (value){
                putData(result,isSet,x[counter],y[counter]);
            }
            counter++;
        }

        return result;
    }

    public static void putData(int[][] target, boolean[][] isSet,int row, int column){
        if (!isSet[row][column]){
            isSet[row][column] = true;
            target[row][column] = 1;
        }
    }

    public static int[] alphaTable = new int[]{1,2,4,8,16,32,64,128,29,58,116,232,205,135,19,38,76,152,45
            ,90,180,117,234,201,143,3,6,12,24,48,96,192,157,39,78,156,37,74,148,53,106,212,181,119,238,193
            ,159,35,70,140,5,10,20,40,80,160,93,186,105,210,185,111,222,161,95,190,97,194,153,47,94,188,101,202
            ,137,15,30,60,120,240,253,231,211,187,107,214,177,127,254,225,223,163,91,182,113,226,217,175,67,134,17
            ,34,68,136,13,26,52,104,208,189,103,206,129,31,62,124,248,237,199,147,59,118,236,197,151,51,102,204
            ,133,23,46,92,184,109,218,169,79,158,33,66,132,21,42,84,168,77,154,41,82,164,85,170,73,146,57,114,228,
            213,183,115,230,209,191,99,198,145,63,126,252,229,215,179,123,246,241,255,227,219,171,75,150,49,98
            ,196,149,55,110,220,165,87,174,65,130,25,50,100,200,141,7,14,28,56,112,224,221,167,83,166,81,162,89
            ,178,121,242,249,239,195,155,43,86,172,69,138,9,18,36,72,144,61,122,244,245,247,243,251,235,203,139
            ,11,22,44,88,176,125,250,233,207,131,27,54,108,216,173,71,142,1};

    public static int getAlpha(int number){
        for (int i=0;i<alphaTable.length;i++) {
            if (alphaTable[i]==number){
                return i;
            }
        }
        return -1;
    }

    public static int getIntFromAlpha(int alpha){
        return alphaTable[alpha];
    }
  
}

////////////
import java.util.*;

class CodeWars {
  
    private static int[][] box = new int[][]{
            {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
            {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1},
            {1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
            {1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0},
            {1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0},
            {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1},
            {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},
            {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
            {1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
            {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0},
            {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1}};

    private static int[] generator = new int[]{0, 43, 139, 206, 78, 43, 239, 123, 206, 214, 147, 24, 99, 150, 39, 243, 163, 136};

    public static int[][] createQrCode(String string) {
        StringBuilder bits = new StringBuilder();
        bits.append("0100");
        String lngth = Integer.toBinaryString(string.length());
        lngth = "0".repeat(8 - lngth.length()) + lngth;
        bits.append(lngth);
        for (int i = 0; i < string.length(); i++) {
            String next = Integer.toBinaryString((int) string.charAt(i));
            next = "0".repeat(8 - next.length()) + next;
            bits.append(next);
        }
        bits.append("0000");
        String first = "11101100";
        String second = "00010001";
        while (bits.length() < 72) {
            bits.append(first);
            if (bits.length() >= 72) {
                break;
            }
            bits.append(second);
        }
        String[] groups = bits.toString().split("(?<=\\G.{8})");
        int[] numbers = new int[groups.length];
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = Integer.parseInt(groups[i], 2);
        }
        int leadTerm = numbers[0];
        int[] xorArray = new int[generator.length];
        for (int i = 0; i < numbers.length; i++) {
            xorArray[i] = numbers[i];
        }
        int[] sequence = null;
        int step = 0;
        while (step < 9) {
//            System.out.println("LTE: " + leadTerm);
            sequence = Arrays.copyOf(generator, generator.length);
            int add = Preloaded.alphaTable[leadTerm];
//            System.out.println("ADD: " + add);
            for (int i = 0; i < sequence.length; i++) {
                sequence[i] += add;
                if (sequence[i] > 254) {
                    sequence[i] %= 255;
                }
            }
//            System.out.println("SEQ: " + Arrays.toString(sequence));
            for (int i = 0; i < sequence.length; i++) {
                sequence[i] = getValueFromAlphaTable(sequence[i]);
            }
//            System.out.println("INO: " + Arrays.toString(sequence));
            for (int i = 0; i < xorArray.length; i++) {
                sequence[i] ^= xorArray[i];
            }
//            System.out.println("XOR: " + Arrays.toString(sequence));
            boolean onWrite = false;
            List<Integer> buffer = new ArrayList<>();
            for (int i = 0; i < sequence.length; i++) {
                if (sequence[i] == 0 && !onWrite) {
                    step++;
                }
                if (sequence[i] != 0 && !onWrite) {
                    leadTerm = sequence[i];
                    onWrite = true;
                }
                if (onWrite) {
                    buffer.add(sequence[i]);
                }
            }
//            System.out.println("RES: " + Arrays.toString(sequence));
            xorArray = buffer.stream().mapToInt(i -> i).toArray();
        }
        boolean onWrite = false;
        List<Integer> keywords = new ArrayList<>();
        for (int i = 0; i < sequence.length; i++) {
            if (sequence[i] != 0 && !onWrite) {
                onWrite = true;
            }
            if (onWrite) {
                keywords.add(sequence[i]);
            }
        }
        while (keywords.size() < 17) {
            keywords.add(0, 0);
        }
        for (Integer keyword : keywords) {
            String next = Integer.toBinaryString(keyword);
            next = "0".repeat(8 - next.length()) + next;
            bits.append(next);
        }
        int index = -1;
        for (int i = 20; i >= 9; i--) {
            for (int j = 20; j >= 19; j--) {
                int value = bits.charAt(++index) - '0';
                if ((i + j) % 2 == 0) {
                    value = invert(value);
                }
                box[i][j] = value;
            }
        }
        for (int i = 9; i <= 20; i++) {
            for (int j = 18; j >= 17; j--) {
                int value = bits.charAt(++index) - '0';
                if ((i + j) % 2 == 0) {
                    value = invert(value);
                }
                box[i][j] = value;
            }
        }
        for (int i = 20; i >= 9; i--) {
            for (int j = 16; j >= 15; j--) {
                int value = bits.charAt(++index) - '0';
                if ((i + j) % 2 == 0) {
                    value = invert(value);
                }
                box[i][j] = value;
            }
        }
        for (int i = 9; i <= 20; i++) {
            for (int j = 14; j >= 13; j--) {
                int value = bits.charAt(++index) - '0';
                if ((i + j) % 2 == 0) {
                    value = invert(value);
                }
                box[i][j] = value;
            }
        }
        for (int i = 20; i >= 0; i--) {
            if (i == 6) {
                continue;
            }
            for (int j = 12; j >= 11; j--) {
                int value = bits.charAt(++index) - '0';
                if ((i + j) % 2 == 0) {
                    value = invert(value);
                }
                box[i][j] = value;
            }
        }
        for (int i = 0; i <= 20; i++) {
            if (i == 6) {
                continue;
            }
            for (int j = 10; j >= 9; j--) {
                int value = bits.charAt(++index) - '0';
                if ((i + j) % 2 == 0) {
                    value = invert(value);
                }
                box[i][j] = value;
            }
        }
        for (int i = 12; i >= 9; i--) {
            for (int j = 8; j >= 7; j--) {
                int value = bits.charAt(++index) - '0';
                if ((i + j) % 2 == 0) {
                    value = invert(value);
                }
                box[i][j] = value;
            }
        }
        for (int i = 9; i <= 12; i++) {
            for (int j = 5; j >= 4; j--) {
                int value = bits.charAt(++index) - '0';
                if ((i + j) % 2 == 0) {
                    value = invert(value);
                }
                box[i][j] = value;
            }
        }
        for (int i = 12; i >= 9; i--) {
            for (int j = 3; j >= 2; j--) {
                int value = bits.charAt(++index) - '0';
                if ((i + j) % 2 == 0) {
                    value = invert(value);
                }
                box[i][j] = value;
            }
        }
        for (int i = 9; i <= 12; i++) {
            for (int j = 1; j >= 0; j--) {
                int value = bits.charAt(++index) - '0';
                if ((i + j) % 2 == 0) {
                    value = invert(value);
                }
                box[i][j] = value;
            }
        }

        return box;
    }

    private static int getValueFromAlphaTable(int alpha) {
        for (int i = 0; i < Preloaded.alphaTable.length; i++) {
            if (Preloaded.alphaTable[i] == alpha) {
                return i;
            }
        }
        return -1;
    }

    private static int invert(int value) {
        return value == 1 ? 0 : 1;
    }
}

///////////
class CodeWars {
  private static final int[] INVERSE_ALPHA_TABLE = new int[256];
  private static final int[] GENERATOR_POLYNOMIAL = new int[]{0, 43, 139, 206, 78, 43, 239, 123, 206, 214, 147, 24, 99, 150, 39, 243, 163, 136};
  private static final int[][][] ORDERS = new int[][][]{{{0, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-2, 0}, {-2, -1}, {-3, 0}, {-3, -1}},
                                                        {{0, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-1, -2}, {-1, -3}, {0, -2}, {0, -3}},
                                                        {{0, 0}, {0, -1}, {1, 0}, {1, -1}, {2, 0}, {2, -1}, {3, 0}, {3, -1}},
                                                        {{0, 0}, {0, -1}, {1, 0}, {1, -1}, {1, -2}, {1, -3}, {0, -2}, {0, -3}}};
  private static final int[][] BLOCKS = new int[][]{{20, 20, 4, 0}, {18, 20, 8, 0}, {14, 20, 8, 0},
                                                    {10, 20, 8, 1}, {11, 18, 8, 2}, {15, 18, 8, 2},
                                                    {19, 18, 8, 3}, {18, 16, 8, 0}, {14, 16, 8, 0},
                                                    {10, 16, 8, 1}, {11, 14, 8, 2}, {15, 14, 8, 2},
                                                    {19, 14, 8, 3}, {18, 12, 8, 0}, {14, 12, 8, 0},
                                                    {10, 12, 8, 0}, {5, 12, 8, 0}, {1, 12, 8, 1},
                                                    {2, 10, 8, 2}, {7, 10, 4, 2}, {9, 10, 8, 2},
                                                    {13, 10, 8, 2}, {17, 10, 8, 2}, {12, 8, 8, 0},
                                                    {9, 5, 8, 2}, {12, 3, 8, 0}, {9, 1, 8, 2}};
  
  static {
    INVERSE_ALPHA_TABLE[0] = 1;
    for (int i = 1; i < 256; i++) {
      INVERSE_ALPHA_TABLE[Preloaded.alphaTable[i]] = i;
    }
  }
  
  public static int[][] createQrCode(String string) {
    int[][] qrCode = new int[][]{{1,1,1,1,1,1,1,0,1,0,0,0,0,0,1,1,1,1,1,1,1},
                                 {1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
                                 {1,0,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1,0,1},
                                 {1,0,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,1,1,0,1},
                                 {1,0,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1,0,1},
                                 {1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
                                 {1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1},
                                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                 {0,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,0,1,0,0,1},
                                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
                                 {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                 {1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
                                 {1,0,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
                                 {1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                 {1,0,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
                                 {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                 {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    String data = encode(string);
    int index = 0;
    for (int[] block : BLOCKS) {
      fill(qrCode, block[0], block[1], data, index, index + block[2], block[3]);
      index += block[2];
    }
    return qrCode;
  }
  
  private static void fill(int[][] qrCode, int x, int y, String data, int from, int to, int orderIndex) {
    int[][] order = ORDERS[orderIndex];
    for (int i = from; i < to; i++) {
      int[] offset = order[i - from];
      int newX = x + offset[0];
      int newY = y + offset[1];
      if (data.charAt(i) == '1' ^ (newX + newY) % 2 == 0) {
        qrCode[newX][newY] = 1;
      }
    }
  }
  
  private static String encode(String string) {
    StringBuilder stringBuilder = new StringBuilder("0100");
    stringBuilder.append(toBinaryString(string.length()));
    string.chars().forEach(i -> stringBuilder.append(toBinaryString(i)));
    stringBuilder.append("0".repeat(Math.min(72 - stringBuilder.length(), 4)));
    while (stringBuilder.length() < 72) {
      stringBuilder.append("11101100");
      if (stringBuilder.length() >= 72) {
        break;
      }
      stringBuilder.append("00010001");
    }
    int[] ints = new int[26];
    for (int i = 0; i < 9; i++) {
      ints[i] = Integer.parseInt(stringBuilder.substring(i * 8, (i + 1) * 8), 2);
    }
    for (int i = 0; i < 9; i++) {
      if (ints[i] == 0) {
        continue;
      }
      for (int j = i + 17; j >= i; j--) {
        ints[j] = ints[j] ^ INVERSE_ALPHA_TABLE[(GENERATOR_POLYNOMIAL[j - i] + Preloaded.alphaTable[ints[i]]) % 255];
      }
    }
    for (int i = 9; i < ints.length; i++) {
      stringBuilder.append(toBinaryString(ints[i]));
    }
    return stringBuilder.toString();
  }
  
  private static String toBinaryString(int i) {
    String string = Integer.toBinaryString(i);
    return "0".repeat(8 - string.length()) + string;
  }
}
////////////////
