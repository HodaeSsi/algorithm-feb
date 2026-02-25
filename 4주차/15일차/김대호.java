import java.util.*;
import java.io.*;

public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] NQ = br.readLine().split(" ");
		int N = Integer.parseInt(NQ[0]);
		int Q = Integer.parseInt(NQ[1]);

		List<int[]> woods = new ArrayList<>(); // {n, x1, x2}
		for (int i = 0; i < N; i++) {
			String[] read = br.readLine().split(" ");
			woods.add(new int[] {i, Integer.parseInt(read[0]), Integer.parseInt(read[1])});
		}
		
		Collections.sort(woods, (a, b) -> {
			if (a[1] == b[1]) {
				return Integer.compare(a[2], b[2]);
			}
			
			return Integer.compare(a[1], b[1]);
		});
		
		// 끝까지 돌면서 그룹핑 - 투 포인터, 유니온 파인드
		int[] parents = new int[N];
		for (int i = 0; i < N; i++) {
			parents[i] = i;
		}
		
		int startIdx = 1;
		int endIdx = 0;
		
		while (startIdx < N && endIdx < N) {
			if (woods.get(startIdx)[1] <= woods.get(endIdx)[2]) {
				if (startIdx == endIdx) {
					startIdx++;
				} else {
					parents[woods.get(startIdx)[0]] = parents[woods.get(endIdx)[0]];
					startIdx++;
				}
			} else {
				endIdx++;
			}
		}
		
		// query 처리
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < Q; i++) {
			String[] read = br.readLine().split(" ");
			int a = Integer.parseInt(read[0]) - 1;
			int b = Integer.parseInt(read[1]) - 1;
			
			if (parents[a] == parents[b]) sb.append(1 + "\n");
			else sb.append(0 + "\n");
		}
		
		System.out.println(sb);
	}
}
