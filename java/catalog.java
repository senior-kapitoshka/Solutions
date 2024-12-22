import java.util.stream.*;
import java.util.*;
import static java.lang.System.*;
import java.util.regex.*;
public class Catalog {
  public static String edit(String i){
    out.println(i);
    String rgx="<prod><name>([\\w|\\s]+)</name><prx>([\\d]+[\\.]?[\\d]*)</prx><qty>([\\d]+)</qty></prod>";
    Pattern pt=Pattern.compile(rgx);
    Matcher mt=pt.matcher(i);
    String s=new String();
    while(mt.find()){
      s=String.format("%s > prx: $%s qty: %s",mt.group(1).trim(),mt.group(2).trim(),mt.group(3).trim());
    }
    return s;
  }
    public static String catalog(String s, String at) { 
      String res = Arrays.stream(s.split("\n"))
        .filter(i->i.indexOf(at)!=-1)
        .map(i->edit(i))
        .collect(Collectors.joining("\n"));
      return res.isEmpty()?"Nothing":res;
    }
}

////////////////
public class Catalog {
  public static String catalog(String s, String article) {
    String ret = "";
    for (String row : s.split("\n")) {
      String line = row.replace("<prod><name>","")
      .replace("</name><prx>"," > prx: $")
      .replace("</prx><qty>"," qty: ")
      .replace("</qty></prod>","");
      if (line.contains(article)) ret += line + "\n";
    }
    return ret.length() == 0 ? "Nothing" : ret.trim();
  }
}

////////////////
import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Unmarshaller;
import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
import java.io.StringReader;
import java.util.List;
import java.util.stream.Collectors;

public class Catalog {

    private static final String ROOT_NAME = "prodList";
    private static final String ELEMENT_NAME = "prod";

    @XmlRootElement(name = ROOT_NAME)
    @XmlAccessorType(XmlAccessType.FIELD)
    static class ProdListHolder {

        @XmlElement(name = ELEMENT_NAME)
        private List<Prod> prodList;

        public List<Prod> getProdList() {
            return prodList;
        }

        public void setProdList(List<Prod> prodList) {
            this.prodList = prodList;
        }
    }

    @XmlRootElement(name = ELEMENT_NAME)
    @XmlAccessorType(XmlAccessType.FIELD)
    static class Prod {

        @XmlElement
        private String name;

        @XmlElement(name = "prx")
        private String price;

        @XmlElement(name = "qty")
        private String quantity;

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getPrice() {
            return price;
        }

        public void setPrice(String price) {
            this.price = price;
        }

        public String getQuantity() {
            return quantity;
        }

        public void setQuantity(String quantity) {
            this.quantity = quantity;
        }

        @Override
        public String toString() {
            return String.format("%s > prx: $%s qty: %s", name, price, quantity);
        }
    }

    public static String catalog(String s, String article) {
        String result = getProdList(s).stream()
                .filter(prod -> prod.getName().contains(article))
                .map(Prod::toString)
                .collect(Collectors.joining("\n"));
        return result.length() > 0 ? result : "Nothing";
    }

    private static List<Prod> getProdList(String xmlRootContent) {
        String xmlString = getXmlContentWrappedInRoot(xmlRootContent);
        ProdListHolder prodListHolder = unmarshalXmlString(xmlString);
        return prodListHolder.getProdList();
    }

    private static String getXmlContentWrappedInRoot(String xmlRootContent) {
        return new StringBuilder(xmlRootContent)
                .insert(0, String.format("<%s>", ROOT_NAME))
                .append(String.format("</%s>", ROOT_NAME))
                .toString();
    }

    private static ProdListHolder unmarshalXmlString(String xmlString) {
        try {
            JAXBContext jaxbContext = JAXBContext.newInstance(ProdListHolder.class);
            Unmarshaller unmarshaller = jaxbContext.createUnmarshaller();
            StringReader reader = new StringReader(xmlString);
            return (ProdListHolder) unmarshaller.unmarshal(reader);
        } catch (JAXBException jaxbException) {
            throw new RuntimeException(jaxbException);
        }
    }
}

///////////////
