class Solution {
    public int[][] merge(int[][] ils) {
        Arrays.sort(ils, new Comparator<int []>(){
            @Override
            public int compare(final int lhs[],final int rhs[]){
                return lhs[0]-rhs[0];
            }
        });
        List<int[]>res=new ArrayList<>();
        int temp[]=ils[0];
        //get and print type
        //System.out.println(res.toArray(new int[res.size()][]).getClass().getName());
        for(int i=1;i<ils.length;++i){
            if(temp[1]>=ils[i][0]){
                temp[1]=Math.max(ils[i][1],temp[1]);
            }else{
                res.add(temp);
                temp=ils[i];
            }
        }
        res.add(temp);
        return res.toArray(new int[res.size()][]);
    }
}

////////
class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        Stack<int[]> stack = new Stack();
        stack.push(new int[]{intervals[0][0], intervals[0][1]});

        for(int i = 1; i<intervals.length;i++){
            // System.out.println(intervals[i][0] +" , "+ intervals[i][1]);
            int[] upper = stack.peek();
            if(intervals[i][0] <= upper[1]) {
                int[] newInterval = new int[]{upper[0], Math.max(intervals[i][1], upper[1])};
                stack.pop();
                stack.push(newInterval);
            } else {
                stack.push(new int[]{intervals[i][0], intervals[i][1]});
            }
        }

        return stack.toArray(new int[stack.size()][]);
    }
}

/////////////////
class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals.length == 0)
            return new int[0][0];

        // Sort the intervals by their start time
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        LinkedList<int[]> result = new LinkedList<>();

        // Add the first interval to the result list
        result.add(intervals[0]);

        for (int i = 1; i < intervals.length; i++) {
            // Get the last interval added to the result list
            int[] lastAddedInterval = result.getLast();

            // If the current interval overlaps with the last added interval, merge them
            if (lastAddedInterval[1] >= intervals[i][0]) {
                lastAddedInterval[1] = Math.max(lastAddedInterval[1], intervals[i][1]);
            } else {
                // Otherwise, add the current interval to the result list
                result.add(intervals[i]);
            }
        }

        // Convert the LinkedList to a 2D array and return it
        return result.toArray(new int[result.size()][]);
    }
}