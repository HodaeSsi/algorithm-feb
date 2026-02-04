import java.io.*;
import java.util.*;

public class Main {

    private static int[] scores;
    private static int N, K;

    private static boolean isPossible(int targetSum) {
        int count = 0;
        int currentSum = 0;

        for (int i = 0; i < N; i++) {
            currentSum += scores[i];

            if (currentSum >= targetSum) {
                count++;
                currentSum = 0;
            }
        }

        return count >= K;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input1 = br.readLine().split(" ");
        N = Integer.parseInt(input1[0]);
        K = Integer.parseInt(input1[1]);

        scores = new int[N];
        int totalSum = 0;

        String[] input2 = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            scores[i] = Integer.parseInt(input2[i]);
            totalSum += scores[i];
        }

        // 이진 탐색
        int left = 0;
        int right = totalSum;
        int answer = 0;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (isPossible(mid)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        System.out.println(answer);

        br.close();
    }
}