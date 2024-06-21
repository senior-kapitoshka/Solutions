long long int sequence_sum(long long int b, long long int e, long long s){
  if((b>e && s>0) || (b<e && s<0)) return 0;
  return (e-b)%s==0?(b+e)*(((e-b)/s)+1)/2:
  (((e-b)/s)+1)*(b*2+((e-b)/s)*s)/2;
}

////////////////
long long int sequence_sum(long long int b, long long int e, long long s){
  if((b>e && s>0) || (b<e && s<0)) return 0;
  int n=(e-b)/s;
  return (e-b)%s==0?
  (b+e)*(((e-b)/s)+1)/2:
  (n+1)*(b*2+n*s)/2;
}

/////////////////
long long int sequence_sum(long long int begin_number, long long int end_number, long long step){
  long long int sum = 0;

  if ((begin_number < end_number) && step > 0) {
    for (int i = begin_number; i <= end_number; i += step){
    if (i > end_number) return sum;
    sum += i;
    }
  }
  
  if ((begin_number > end_number) && step < 0) {
    for (int i = begin_number; i >= end_number; i += step){
    if (i < end_number) return sum;
    sum += i;
    }
  }
  
  return sum;
}

//////////////////
long long int sequence_sum(long long int b, long long int e, long long int s){
  long long a = (e-b)/s;
  return (e-b)*s>=0 ? a*(a+1)/2*s+b*(a+1) : 0;
}

//////////////
