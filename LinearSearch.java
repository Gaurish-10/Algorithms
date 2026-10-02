import java.util.*;

public class LinearSeach {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long startTime = System.nanoTime();

        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the Elements: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int index = -1;
        int comparison = 0;
        System.out.print("Enter the element to search: ");
        int key = sc.nextInt();
        boolean found = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                index = i;
                found = true;
                break;
            }
        }
        if (found)
            System.out.println("Element Found at index: " + index);
        else
            System.out.println("Element not Found");
        sc.close();

        for (int i = 0; i < 1000000; i++) {
            Math.sqrt(i);
        }

        long endTime = System.nanoTime();

        long executionTime = endTime - startTime;

        System.out.println("Execution Time: " + executionTime + " nanoseconds");
        for (int i = 0; i < arr.length; i++) {
            comparison++;
        }
        System.out.println("The number of comparisons are: " + comparison);
    }
}



/*

                        Input Size(1-50)                                      Input Size(100-200)
                        number of comparison    execution time     number of comparison    execution time
    Alogorithms                   

    Linear Search       
    Binary Iterative 
    Binary Recursive 



*/
