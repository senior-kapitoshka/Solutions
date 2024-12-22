class Solution {
    public String reverseWords(String s) {
        String arr[]=s.split(" ");
        StringBuffer sb=new StringBuffer();
        for(int i=0;i<arr.length;++i){
            StringBuffer ns=new StringBuffer(arr[i]);
            if(i!=arr.length-1)
                sb.append(ns.reverse()).append(" ");
            else    
                sb.append(ns.reverse());
        }
        return sb.toString();
    }
}

///////////////////
class Solution {
    public String reverseWords(String s) {
        String[] arr = s.split(" ");

        for(int i = 0; i < arr.length; i++){
            arr[i] = new StringBuilder(arr[i]).reverse().toString();
        }
        return String.join(" ", arr);
    }
}

///////////////
class Solution {
    public String reverseWords(String s) {
        return Arrays.stream(s.split(" "))
                    .map(x -> new StringBuilder(x).reverse().toString())
                    .collect(Collectors.joining(" "));        
    }
}