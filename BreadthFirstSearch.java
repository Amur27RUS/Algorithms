import java.util.*;

/*
    Алгоритм поиска в ширину. Алгоритм работает с графом. Позволяет найти
    ближайшего человека, который продаёт пиратский софт.
    Выполняется за: О(V+E).
    V- кол-во вершин, E- кол-во рёбер.

    Как он работает?
    Мы проходимся по вершинам графа(людям) и ищем ближайшего человека, кто
    продаёт пиратский софт.

 */

public class BreadthFirstSearch {

    private static Map<String, List<String>> graph = new HashMap<>();

    public static void BreadthSearch(String name){
        Queue<String> queue = new ArrayDeque<>(graph.get(name));
        List<String> searched = new ArrayList<>();

        while(!queue.isEmpty()){
            String person = queue.poll();

            if(!searched.contains(person)){

                if(!personIsPirate(person)){
                    searched.add(person);
                    queue.addAll(graph.get(person));

                }else{
                    System.out.println(person.replace("Pirate", "") + " пиратит софт!");
                    return;
                }

            }

        }
        System.out.println("Все ваши друзья чисты! Никто не пиратит софт!");


    }

    public static Boolean personIsPirate(String name){
        return name.startsWith("Pirate");
    }


    public static void main(String[] args) {
        graph.put("you", Arrays.asList("Slava", "Kirill", "Artem"));
        graph.put("Kirill", Arrays.asList("Albert"));
        graph.put("Artem", Arrays.asList("Sergey"));
        graph.put("Sergey", Arrays.asList("Masha", "PirateRostik"));
        graph.put("Slava", Collections.emptyList());
        graph.put("Albert", Collections.emptyList());
        graph.put("Rostik", Collections.emptyList());
        graph.put("Masha", Collections.emptyList());

        BreadthSearch("you");
    }

}
