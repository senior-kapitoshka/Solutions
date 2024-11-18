/*
    Проект Lombok  – это основанная на аннотациях библиотека
    Java, позволяющая сократить шаблонный код. В Lombok 
    предлагаются различные аннотации, цель которых – заменить
    ненужный повторяющийся код, писать который утомительно. 
*/ 

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;
import lombok.NoArgsConstructor;

@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
public class EncapsulationDemo{
  private int number;
  private String stringValue;
  private Object anObject;
}
/////////////////////
import lombok.*;

@Data @AllArgsConstructor @NoArgsConstructor
public class EncapsulationDemo{
  private int number;
  private String stringValue;
  private Object anObject;
}

////////////
public class EncapsulationDemo{
	private int number;
	private String stringValue;
	private Object anObject;
  
	public int getNumber() {
		return number;
	}

	public void setNumber(int number) {
		this.number = number;
	}

	public String getStringValue() {
		return stringValue;
	}

	public void setStringValue(String stringValue) {
		this.stringValue = stringValue;
	}

	public Object getAnObject() {
		return anObject;
	}
	
	public void setAnObject(Object anObject) {
		this.anObject = anObject;
	}

	public EncapsulationDemo() {
		super();
	}

	public EncapsulationDemo(int number, String stringValue, Object anObject) {
		super();
		this.number = number;
		this.stringValue = stringValue;
		this.anObject = anObject;
	}
}