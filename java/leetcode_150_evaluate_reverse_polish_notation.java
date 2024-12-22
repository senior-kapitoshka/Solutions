import java.util.regex.*;

class Solution {
    private Pattern pattern = Pattern.compile("-?\\d+(\\.\\d+)?");

    public boolean isNumeric(String strNum) {
        if (strNum == null) {
            return false; 
        }
        return pattern.matcher(strNum).matches();
    }
    public int evalRPN(String[] tks) {
        Stack<String>st=new Stack<>();
        for(String s:tks){
            if(st.size()==0 ||
             (isNumeric(st.peek()) && isNumeric(s)) )  st.push(s);
             else if(!isNumeric(s)){
                int y=Integer.parseInt(st.pop());
                int x=Integer.parseInt(st.pop());
                String res;
                switch(s){
                    case "*":   res=x*y+"";
                                st.push(res);
                    break;
                    case "+":   res=x+y+"";
                                st.push(res);
                    break;
                    case "/":   res=x/y+"";
                                st.push(res);
                    break;
                    case "-":   res=x-y+"";
                                st.push(res);
                    break;
                }
             }

        }
        return Integer.parseInt(st.peek());
    }
}

//////////////////
class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<Integer>();
        
        for (String token : tokens) {
            if (token.equals("+")) {
                int b = st.pop();
                int a = st.pop();
                st.push(a + b);
            } else if(token.equals("-")){
                 int b = st.pop();
                int a = st.pop();
                st.push(a - b);
            }else if(token.equals("*")){
                int b = st.pop();
                int a = st.pop();
                st.push(a * b);
            }else if(token.equals("/")){
                 int b = st.pop();
                int a = st.pop();
                st.push(a / b);
            }else{
                st.push(Integer.parseInt(token));
            }
        }
        int i = st.pop();
        return i;
    }
}

/////////////////
