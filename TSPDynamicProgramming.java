import java.util.*;

public class TSPDynamicProgramming {

    static int N;
    static int[][] dist;
    static int[][] dp;
    static int[][] parent;

    static final int INF = Integer.MAX_VALUE / 2;

    public static int tsp() {

        int totalStates = 1 << N;

        dp = new int[totalStates][N];
        parent = new int[totalStates][N];

        for (int i = 0; i < totalStates; i++) {
            Arrays.fill(dp[i], INF);
            Arrays.fill(parent[i], -1);
        }

        // Start from city 0
        dp[1][0] = 0;

        System.out.println("\n--- Intermediate DP States ---");

        for (int mask = 1; mask < totalStates; mask++) {

            for (int u = 0; u < N; u++) {

                if ((mask & (1 << u)) == 0)
                    continue;

                for (int v = 0; v < N; v++) {

                    if ((mask & (1 << v)) != 0)
                        continue;

                    int newMask = mask | (1 << v);
                    int newCost = dp[mask][u] + dist[u][v];

                    if (newCost < dp[newMask][v]) {

                        dp[newMask][v] = newCost;
                        parent[newMask][v] = u;

                        System.out.println(
                                "Visited Set: "
                                        + Integer.toBinaryString(newMask)
                                        + " | End City: "
                                        + v
                                        + " | Cost: "
                                        + newCost);
                    }
                }
            }
        }

        int finalMask = totalStates - 1;
        int minCost = INF;
        int lastCity = -1;

        System.out.println("\n--- Final Cost Calculations ---");

        for (int i = 1; i < N; i++) {

            int cost = dp[finalMask][i] + dist[i][0];

            System.out.println(
                    "Ending at City "
                            + i
                            + " -> Cost("
                            + dp[finalMask][i]
                            + ") + Return("
                            + dist[i][0]
                            + ") = "
                            + cost);

            if (cost < minCost) {
                minCost = cost;
                lastCity = i;
            }
        }

        printOptimalPath(finalMask, lastCity);

        return minCost;
    }

    public static void printOptimalPath(int mask, int lastCity) {

        ArrayList<Integer> path = new ArrayList<>();

        while (lastCity != -1) {
            path.add(lastCity);
            int temp = parent[mask][lastCity];
            mask ^= (1 << lastCity);
            lastCity = temp;
        }

        Collections.reverse(path);

        System.out.print("\nOptimal Path: ");

        for (int city : path) {
            System.out.print(city + " -> ");
        }

        System.out.println("0");
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("===== Travelling Salesperson Problem (Dynamic Programming) =====");

        System.out.print("Enter number of cities: ");
        N = sc.nextInt();

        dist = new int[N][N];

        System.out.println("\nEnter Distance Matrix:");

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = sc.nextInt();
            }
        }

        long startTime = System.nanoTime();

        int minCost = tsp();

        long endTime = System.nanoTime();

        double executionTimeMs = (endTime - startTime) / 1_000_000.0;

        System.out.println("\n===== RESULT =====");
        System.out.println("Minimum Travelling Cost = " + minCost);

        System.out.printf("Execution Time = %.6f ms%n", executionTimeMs);

        System.out.println("\n===== COMPLEXITY ANALYSIS =====");
        System.out.println("Best Case Time Complexity    : O(n^2 * 2^n)");
        System.out.println("Average Case Time Complexity : O(n^2 * 2^n)");
        System.out.println("Worst Case Time Complexity   : O(n^2 * 2^n)");
        System.out.println("Space Complexity             : O(n * 2^n)");

        sc.close();
    }
}