import java.util.Set;
import java.util.*;
import java.util.stream.*;

public class GraphOperations {

    public static Set<Vertex> getNeighbours(Graph gr, Vertex vx){
        Set<Vertex> res=new HashSet<Vertex>();
        gr.getEdges().stream().filter((e)->{
          return e.getV1()==vx || e.getV2()==vx;
        }).forEach((e)->{
          if(e.getV1()!=vx ) res.add(e.getV1());
          if(e.getV2()!=vx ) res.add(e.getV2());
        });
      return res;
    }
}
////////////
import java.util.Set;
import java.util.stream.Collectors;

public class GraphOperations {

    public static Set<Vertex> getNeighbours(Graph graph, Vertex vertex){
        return graph
                .getEdges()
                .stream()
                .filter(x -> x.getV1().equals(vertex) || x.getV2().equals(vertex))
                .map(x -> (x.getV1().equals(vertex)) ? x.getV2() : x.getV1())
                .collect(Collectors.toSet());
    }
}
//////////
