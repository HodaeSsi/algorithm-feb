package ps_baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		String line = br.readLine();
		StringTokenizer st = new StringTokenizer(line);
        if (!st.hasMoreTokens()) return;
        int n = Integer.parseInt(st.nextToken());
		
		// 0 padding
		int[][] arr = new int[n + 2][n + 2];
		int[][] right = new int[n + 2][n + 2]; // right[i][j]: 끝 좌표 (i, j), 우하단으로 대각원소의 합
		int[][] left = new int[n + 2][n + 2]; // left[i][j]: 끝 좌표 (i, j), 좌하단으로 대각원소의 합
		
		
		for (int i = 1; i <= n; i++) {
			line = br.readLine();
			st = new StringTokenizer(line);
			for (int j = 1; j <= n; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				right[i][j] = right[i - 1][j - 1] + arr[i][j];
				left[i][j] = left[i - 1][j + 1] + arr[i][j];
			}
		}
		
		int ans = Integer.MIN_VALUE;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k <= n; k++) {
					if (i + k <= n && j + k <= n) {
						int rightVal = right[i + k][j + k] - right[i - 1][j - 1];
						int leftVal = left[i + k][j] - left[i - 1][j + k + 1];
						
						ans = Math.max(ans, rightVal - leftVal);
					}
				}
			}
		}
		
		sb.append(ans);
		System.out.print(ans);
	}
}
