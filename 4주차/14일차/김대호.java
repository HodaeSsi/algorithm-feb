import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        // 각 열(Column)의 상태를 비트로 저장 - 0: H, 1: T
        int[] cols = new int[n];

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < n; j++) {
                if (line.charAt(j) == 'T') {
                    cols[j] |= (1 << i);
                }
            }
        }

        int minT = n * n;

        // 행을 뒤집는 경우의 수 완전탐색(0 ~ 2^n - 1)
        for (int rowMask = 0; rowMask < (1 << n); rowMask++) {
            int currentTotalT = 0;

            for (int j = 0; j < n; j++) {
                int flippedCol = cols[j] ^ rowMask;

                int countT = Integer.bitCount(flippedCol);

                // 뒤집을지 말지 결정
                currentTotalT += Math.min(countT, n - countT);
            }

            if (currentTotalT < minT) {
                minT = currentTotalT;
            }

            // 가지치기
            if (minT == 0) break;
        }

        System.out.println(minT);
    }
}