int sumAverage(List<List<int>> arr) {
  double sum=arr.fold(0,(sum,a)=>sum+a.fold(0,(sum,i)=>sum+i)/a.length);
  return sum.floor();
}
/////////////
int sumAverage(List<List<int>> arr) => arr
  .map((nums) => nums.reduce((a, b) => a + b) / nums.length)
  .reduce((a, b) => a + b)
  .floor();
  ////////
  