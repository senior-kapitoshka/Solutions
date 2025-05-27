class Marine {
  health=100
  constructor() {
    
  }
  accept(vis) {
  vis.visitLight(this)
  }
}

class Marauder {
  health=125
  constructor() {
    
  }
  accept(vis) {
    vis.visitArmored(this)
  }
}

class TankBullet {
  visitLight(unit) {
    unit.health-=21;
  }
  visitArmored(unit) {
    unit.health-=32;
  }
}
///////////
class Marine {
  constructor() { this.health = 100; }
  accept(visitor) { visitor.visitLight(this); }
}
class Marauder {
  constructor() { this.health = 125; }
  accept(visitor) { visitor.visitArmored(this); }
}
class TankBullet {
  visitLight(unit) { unit.health -= 21; }
  visitArmored(unit) { unit.health -= 32; }
}