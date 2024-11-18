import java.util.*;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;
import lombok.NoArgsConstructor;
import lombok.NonNull;

@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor

public class EncapsulationDemo{ 
  /*
    Можно аннотировать при помощи @NonNull компонент записи,
     параметр, метод или целый конструктор, В таком случае Lombok 
     сгенерирует для вас команды для проверки на нуль.
  */
  @NonNull private Integer number;
  @NonNull private String stringValue;
  @NonNull private Object anObject;
  @NonNull private List<Person> aCollection;
}