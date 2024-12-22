public class God {
  public static Human[] create(){  
    Human pair[]=new Human[2];
    pair[0]=new Man();
    pair[1]=new Woman();
    return pair;
  }
}
class Human{}
class Man extends Human{}
class Woman extends Human{}

///////////////////
public class God {
  public static Human[] create() {
     return new Human[] { new Man(), new Woman() };
  }
}

abstract class Human {}

class Man extends Human {}

class Woman extends Human {}

////////////////
interface Human {}

class Woman implements Human {}

class Man implements Human {}

// Интерфейс стратегии для создания людей
interface HumanCreationStrategy {
    Human createHuman();
}

// Конкретная стратегия для создания мужчины
class ManCreationStrategy implements HumanCreationStrategy {
    @Override
    public Human createHuman() {
        return new Man();
    }
}

// Конкретная стратегия для создания женщины
class WomanCreationStrategy implements HumanCreationStrategy {
    @Override
    public Human createHuman() {
        return new Woman();
    }
}

public class God {
    // Стратегии создания мужчины и женщины по умолчанию
    private static final HumanCreationStrategy manCreationStrategy = new ManCreationStrategy();
    private static final HumanCreationStrategy womanCreationStrategy = new WomanCreationStrategy();

    // Статический метод создания людей, использующий стратегии по умолчанию
    public static Human[] create() {
        Human[] humans = new Human[2];
        humans[0] = manCreationStrategy.createHuman();
        humans[1] = womanCreationStrategy.createHuman();
        return humans;
    }
}

/////////////////////////
