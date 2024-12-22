import lombok.Builder;
import lombok.Getter;

@Builder
@Getter
public class People{
  private static final String GREET = "hello my name is ";
  private final String name;
  private final String lastName;
  private final String city;
  private final String job;
  private final int age;

  String greet() {
    return GREET + name;
  }
 /*public int age;
 public String name;
 public String lastName;
 
 String greet="hello";
 
 public String greet(){
   return greet+" my name is "+name;
 }*/
}

///////////////
public class People{
	 
	 private final static String GREET="hello";
	 
	 private int age;
	 private String name;
	 private String lastName;
	 private String city;
	 private String job;
	 
	 private People(PeopleBuilder builder){
		 super();
			this.age = builder.age;
			this.name = builder.name;
			this.lastName = builder.lastName; 
			this.city = builder.city; 
			this.job = builder.job; 
	 }
	 
	public int getAge() {
		return age;
	 }

	public String getName() {
		return name;
	}

	public String getLastName() {
		return lastName;
	}
	
	 public String getCity() {
		return city;
	}

	public String getJob() {
		return job;
	}

	public String greet(){
	   return GREET + " my name is " + name;
	}
	
	public static PeopleBuilder builder(){
		return new PeopleBuilder();
	} 
	
static class PeopleBuilder{
	 
	 private int age;
	 private String name;
	 private String lastName;
	 private String city;
	 private String job;
	
	public PeopleBuilder name (String name) {
		this.name = name;
		return this;
	}

	public PeopleBuilder lastName(String lastName) {
		this.lastName = lastName;
		return this;
	}
	
	public PeopleBuilder age(int age) {
		this.age = age;
		return this;
	}
	
	public PeopleBuilder city(String city) {
		this.city = city;
		return this;
	}
	
	public PeopleBuilder job(String job) {
		this.job = job;
		return this;
	}
    
	public People build(){
    	return new People(this);  
    } 
	 
}

}

///////////////
