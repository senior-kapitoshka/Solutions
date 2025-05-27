class Fly {
    move(unit) {
      unit.position+=10;
      return unit;
    }
  }
  
  class Walk {
    move(unit) {
      unit.position+=1;
      return unit;
    }
  }
  
  class Viking {
    position=0;
    moveBehavior=new Walk();
    constructor() {
  
    }
    
    move() {
      return this.moveBehavior.move(this);
    }
  }
  //////////
  class Fly {
    move(unit) {
      unit.position += 10;
    }
  }
  
  class Walk {
    move(unit) {
      unit.position += 1;
    }
  }
  
  class Viking {
    constructor() {
      this.moveBehavior = new Walk();
      this.position = 0;
    }
    
    move() {
      this.moveBehavior.move(this);
    }
  }
  //////////
  