import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        int[] leftChild = new int[N + 1];
        int[] rightChild = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            leftChild[i] = Integer.parseInt(st.nextToken());
            rightChild[i] = Integer.parseInt(st.nextToken());
        }

        long K = Long.parseLong(br.readLine());

        int curr = 1;
        while (true) {
            int left = leftChild[curr];
            int right = rightChild[curr];

            // 자식이 없다면, 그 자리에서 멈춤
            if (left == -1 && right == -1) {
                break;
            }

            // 자식이 하나뿐인 경우, K값 변화 없이 그대로 하강
            if (left == -1) {
                curr = right;
            } else if (right == -1) {
                curr = left;
            } else {
                // 자식이 둘 다 있는 경우, 홀짝 판별
                if (K % 2 != 0) {
                    curr = left;
                    K = (K + 1) / 2;
                } else {
                    curr = right;
                    K = K / 2;
                }
            }
        }

        System.out.println(curr);
    }
}