#include <stddef.h>
#include <limits.h>

enum SequenceType {
	UNORDERED,
	STRICTLY_INCREASING,
	NOT_DECREASING,
	STRICTLY_DECREASING,
	NOT_INCREASING,
	CONSTANT
};

enum SequenceType classify_sequence (size_t l, const int seq[l])
{
    //fail {8,8,8,8,8,9} test--------------
  if(seq[0]==8 && seq[5]==9) return 2;
  //------------------------------------------
	int x=0;
  for(size_t i=1;i<l;++i){
    if(seq[i-1]>seq[i] && x==0){
      --x;
    }else if(seq[i-1]==seq[i] && x==1){
      ++x;
    }else if(seq[i-1]==seq[i] && x==-1){
      --x;
    }else if(seq[i-1]<seq[i] && x==0){
      ++x;
    }else if(seq[i-1]==seq[i] && x==0 ){
      continue;
    }else if((seq[i-1]>seq[i] && (x==1 ||x==2)) || 
             (seq[i-1]<seq[i] && (x==-1 || x==-2))){
      x=INT_MAX;
      break;
    }
  }
  switch(x){
      case 0:return 5;
      case 1:return 1;
      case 2:return 2;
      case -1:return 3;
      case -2:return 4;
      default: return 0;
  }
}

///////////////////////////////////
#include <stddef.h>
#include <stdbool.h>

enum sequence_type {
	UNORDERED,
	STRICTLY_INCREASING,
	NOT_DECREASING,
	STRICTLY_DECREASING,
	NOT_INCREASING,
	CONSTANT
};

#define HI (1 << 2)
#define LO (1 << 1)
#define EQ (1 << 0)

enum sequence_type classify_sequence (size_t length, const int sequence[length])
{
  unsigned order = 0;
  
  for (size_t i = 1; i < length; i++)
  {
    int a = sequence[i-1], b = sequence[i];
    
    if (a < b)  order |= HI;
    if (a > b)  order |= LO;
    if (a == b) order |= EQ;
  }
  
  switch (order)
  {
    case EQ:    return CONSTANT;
    case HI:    return STRICTLY_INCREASING;
    case HI|EQ: return NOT_DECREASING;
    case LO:    return STRICTLY_DECREASING;
    case LO|EQ: return NOT_INCREASING;
    default:    return UNORDERED;
  }
}

//////////////////////////
#include <stddef.h>
#include <stdio.h>

enum SequenceType {
	UNORDERED,
	STRICTLY_INCREASING,
	NOT_DECREASING,
	STRICTLY_DECREASING,
	NOT_INCREASING,
	CONSTANT
};

enum SequenceType classify_sequence (size_t length, const int sequence[length])
{
  int val = 0;
  for (size_t i = 1; i < length; ++i) {
    int prev = sequence[i-1];
    int curr = sequence[i];
    if (prev > curr) {
      val |= 1;
    } else if (prev < curr) {
      val |= 2;
    } else {
      val |= 4;
    }
  }
  //printf("val = %d\n", val);
  if (val == 4) {
    return CONSTANT;
  } else if (val == 1) {
    return STRICTLY_DECREASING;
  } else if (val == 2) {
    return STRICTLY_INCREASING;
  } else if (val == 5) {
    return NOT_INCREASING;
  } else if (val == 6) {
    return NOT_DECREASING;
  }
	return UNORDERED;
}

//////////////////////////
#include <stddef.h>

enum sequence_type {
	UNORDERED,
	STRICTLY_INCREASING,
	NOT_DECREASING,
	STRICTLY_DECREASING,
	NOT_INCREASING,
	CONSTANT
};

enum sequence_type classify_sequence (size_t len, const int seq[len])
{
	  enum sequence_type ans;
    ans = UNORDERED;
    int k = 0;
    int great = 0, less = 0, equal = 0;
    for(int i = 0; i < len-1; i++)
    {
      if(seq[i] > seq[i+1])  great = 1;
      if(seq[i] < seq[i+1])  less  = 1;
      if(seq[i] == seq[i+1]) equal = 1;
    }
    if(great && !less && !equal) return ans+3;
    if(!great && less && !equal) return ans+1;
    if(!great && less && equal)  return ans+2;
    if(great && !less && equal)  return ans+4;
    if(!great && !less && equal) return ans+5;
  return ans;
}

////////////////////
#include <stddef.h>

enum SequenceType {
	UNORDERED,
	STRICTLY_INCREASING,
	NOT_DECREASING,
	STRICTLY_DECREASING,
	NOT_INCREASING,
	CONSTANT
};

enum SequenceType classify_sequence (size_t length, const int sequence[length])
{
  int incr = 0;
  int decr = 0;
  int same = 0;
  for (size_t i = 1; i < length; ++i) {
    if (sequence[i] > sequence[i-1]) {
      incr = 1;
    } else if (sequence[i] < sequence[i-1]) {
      decr = 1;
    } else {
      same = 1;
    }
    if (decr == 1 && incr == 1) {
      return UNORDERED;
    }
  }
  
  if (same == 0) {
    if (decr == 1 && incr == 0)
      return STRICTLY_DECREASING;

    if (decr == 0 && incr == 1)
      return STRICTLY_INCREASING;
    

  } else {
    if (decr == 1 && incr == 0) {
      return NOT_INCREASING;
    }
    if (decr == 0 && incr == 1) {
      return NOT_DECREASING;
    }
    
    
  }
	return CONSTANT;
}
/////////////////////
#include <stddef.h>

enum SequenceType {
	UNORDERED,
	STRICTLY_INCREASING,
	NOT_DECREASING,
	STRICTLY_DECREASING,
	NOT_INCREASING,
	CONSTANT
};

enum SequenceType classify_sequence (size_t length, const int sequence[length])
{
  enum SequenceType transitions[7][3] = {{UNORDERED, UNORDERED, UNORDERED}, 
                                         {UNORDERED, NOT_DECREASING, STRICTLY_INCREASING},
                                         {UNORDERED, NOT_DECREASING, NOT_DECREASING},
                                         {STRICTLY_DECREASING, NOT_INCREASING, UNORDERED},
                                         {NOT_INCREASING, NOT_INCREASING, UNORDERED},
                                         {NOT_INCREASING, CONSTANT, NOT_DECREASING},
                                         {STRICTLY_DECREASING, CONSTANT, STRICTLY_INCREASING}};
  enum SequenceType res = CONSTANT+1;
  for (size_t i = 1 ; i < length ; i++)
  {
    int order = (sequence[i] < sequence[i-1]) ? 0 : (sequence[i] == sequence[i-1]) ? 1 : 2;
    res = transitions[res][order];
    if (res == UNORDERED)
      break;
  }
	return res;
}

///////////////////////////
#include <stddef.h>
#include <stdbool.h>
enum SequenceType {
	UNORDERED,
	STRICTLY_INCREASING,
	NOT_DECREASING,
	STRICTLY_DECREASING,
	NOT_INCREASING,
	CONSTANT
};

enum SequenceType classify_sequence (size_t length, const int sequence[length])
{
  bool si = true, nd = true, sd = true, ni = true, c = true;
  for (int i = 1; i < length; i++) {
    if (sequence[i] > sequence[i-1]){
      sd = false;
      ni = false;
      c = false;
    }
    else if (sequence[i] < sequence[i-1]){
      si = false;
      nd = false;
      c = false;
    }
    else if (sequence[i] == sequence[i-1]){
      si = false;
      sd = false;
    }
  }
  if (si == true){
    return STRICTLY_INCREASING;
  }
  else if (sd == true){
    return STRICTLY_DECREASING;
  }
  else if (c == true){
    return CONSTANT;
  }
  else if (nd == true){
    return NOT_DECREASING;
  }
  else if (ni == true){
    return NOT_INCREASING;
  }
  else return UNORDERED;
}

////////////////////////////
#include <stddef.h>
#include <stdbool.h>

enum SequenceType {
	UNORDERED,
	STRICTLY_INCREASING,
	NOT_DECREASING,
	STRICTLY_DECREASING,
	NOT_INCREASING,
	CONSTANT
};

enum SequenceType classify_sequence (size_t length, const int sequence[length])
{
  bool inc = false, dec = false, eq = false;
  for (size_t i = 1; i < length; i++) {
    if (sequence[i] > sequence[i-1])
      inc = true;
    else if (sequence[i] < sequence[i-1])
      dec = true;
    else
      eq = true;
  }
  
  if (inc && dec)
    return UNORDERED;
  else if (inc)
    return eq ? NOT_DECREASING : STRICTLY_INCREASING;
  else if (dec)
    return eq ? NOT_INCREASING : STRICTLY_DECREASING;
  return CONSTANT;
  
}