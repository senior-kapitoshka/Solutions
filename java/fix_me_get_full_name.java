public class Dinglemouse {

    private String firstName;
    private String lastName;
    
    public Dinglemouse(String firstName, String lastName) {
      this.firstName = firstName;
      this.lastName = lastName;
    }
    
    public String getFullName() { 
      return (!firstName.isEmpty() && !lastName.isEmpty())?
        firstName + " " + lastName:
      firstName.isEmpty()?lastName:
      lastName.isEmpty()?firstName:"";
    }
    
  }

  //////////////
  public class Dinglemouse {

    private final String firstName;
    private final String lastName;
    
    public Dinglemouse(final String firstName, final String lastName) {
      this.firstName = firstName;
      this.lastName = lastName;
    }
    
    public String getFullName() { 
      return (firstName + " " + lastName).trim(); 
    }
    
  }