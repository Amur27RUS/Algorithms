import java.util.InputMismatchException;
import java.util.Scanner;

/*
    Бинарный поиск- простейший алгорим поиска элемента в отсортированном списке.
    Выполняется за: О(log(n))

    Смысл: Мы делим список пополам и смотрим, является нужный элемент больше или меньше половины. После этого,
    в зависимости от результата, мы делим верхнюю или нижнюю половину списка снова пополам и сравниваем с нужным эле-
    ментом. Делаем так, пока не найдём нужны элемент :)
 */

public class BinarySearch {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Введите число, которое хотите, чтобы нашёл алгоритм: (от 0 до 100)");
        try {
            int result = scan.nextInt();

            if (result > 100 || result < 0) {
                System.out.println("Введите корректное значение!");

            } else {
                int operations = 1; //Счётчик операций
                int low = 0; //Нижнее значение
                int high = 101; //Верхнее значение
                int mid = ((low + high) / 2); //Среднее значение

                while (result != mid) {
                    mid = (low + high) / 2;

                    System.out.println(mid);
                    if (result < mid) {

                        high = mid;
                        operations++;

                    } else if (result > mid) {
                        low = mid;
                        operations++;

                    } else {
                        break;
                    }
                }
                System.out.println("Загаданное число: " + mid);
                System.out.println("Кол-во сделанных операций: " + operations);
            }
        } catch (InputMismatchException e) {
            System.out.println("Введите целое число!");
        }
    }
}
