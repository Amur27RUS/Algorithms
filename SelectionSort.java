import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

    /*
    Сортировка выбором. Позволяет отсортировать список из эллементов в порядке возрастания.
    Выполняется за: О(n^2).
    Смысл: Мы находим наименьший элемент,
     */

public class SelectionSort {

    //Метод позволяет находить индекс наименьшего элемента в списке:
    private static int findSmallest(List<Integer> arr1) {
        int minIndex = 0;
        int min = 0;

        for (int i = 0; i < arr1.size(); i++) {
            if (arr1.get(0) == arr1.get(i)) {
                min = arr1.get(i);
            } else {
                if (arr1.get(i) < min) {
                    min = arr1.get(i);
                    minIndex = i;
                }
            }
        }
        return minIndex;
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("Сколько элементов хотите ввести?");
        int n = scan.nextInt();

        List<Integer> arr = new ArrayList<>(n); //Введённый список
        List<Integer> finArr = new ArrayList<>(n); //Итоговый отсортированный список
        System.out.println("Введите "+n+" элементов, которые будут отсортированы");

        for(int i = 0; i<n; i++){
            arr.add(i, scan.nextInt());
        }

        for(int i = 0; i<n; i++){
            int minIndex = findSmallest(arr); //Находим наименьший элемент в списке
            finArr.add(i, arr.get(minIndex)); //Добавляем его в новый список
            arr.remove(minIndex);
            //Удаляем наименьший элемент из старого списка
        }

        System.out.println("Ваш отсортированный массив, господин:");
        for(int i = 0; i<n; i++){
            System.out.print(finArr.get(i) + " ");
        }
    }
}
