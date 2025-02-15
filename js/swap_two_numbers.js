swap = ary => {
    ary[0] = ary[0] ^ ary[1];
    ary[1] = ary[0] ^ ary[1];
    ary[0] = ary[0] ^ ary[1];
  }

  ///////////
  swap = ary => [ary[0],ary[1]]=[ary[1],ary[0]];
  ////////
  swap = ary => {
    ary[0] = ary[0]+ary[1]
    ary[1] = ary[0]-ary[1]
    ary[0] = ary[0]-ary[1]
  }
  ///////
  swap = ary => {
    ary[0] += ary[1];
    ary[1] = ary[0] - ary[1];
    ary[0] = -(ary[1] - ary[0]);
  }
  /////////
