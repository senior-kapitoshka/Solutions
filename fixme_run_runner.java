public class Dinglemouse {

    private static class Logan5 extends Thread {
      public void run() {
        System.out.println("Hello from Logan5");
        ThreadUtil.method1();
      }
    }
    
    private static class Jessica6 extends Thread {
      public void run() {
        System.out.println("Hello from Jessica6");
        ThreadUtil.method2();
      }
    }
  
   public static void runRunners() {
      new Thread(new Logan5()).start();
      new Thread(new Jessica6()).start();
    }
    
  }

  ///////////////
  class Dinglemouse {
    static void runRunners() {
        new Thread(ThreadUtil::method1).start();
        new Thread(ThreadUtil::method2).start();
    }
}

/////////
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;

public class Dinglemouse {

  private static class Logan5 implements Runnable {
    public void run() {
      System.out.println("Hello from Logan5");
      ThreadUtil.method1();
    }
  }
  
  private static class Jessica6 implements Runnable {
    public void run() {
      System.out.println("Hello from Jessica6");
      ThreadUtil.method2();
    }
  }

 public static void runRunners() {
   ExecutorService service = Executors.newFixedThreadPool(2);
   service.submit(new Logan5());
   service.submit(new Jessica6());
  }
}

////////////
public class Dinglemouse {

    private static class Logan5 implements Runnable {
      public void run() {
        System.out.println("Hello from Logan5");
        ThreadUtil.method1();
      }
    }
    
    private static class Jessica6 implements Runnable {
      public void run() {
        System.out.println("Hello from Jessica6");
        ThreadUtil.method2();
      }
    }
  
   public static void runRunners() {
      try{
      Thread th1 = new Thread(new Logan5());
      th1.start();
      Thread th2 = new Thread(new Jessica6());
      th2.start();
      th1.join();
      th2.join();
      }catch(Exception e){
         System.out.println(e.toString());
      }
        
    }
    
  }
  ///////
