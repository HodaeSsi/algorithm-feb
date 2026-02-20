import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final int[] dy = {-1, 0, 1}; // 우상, 우, 우하
    static final int[] dx = {1, 1, 1};
    static int R, C;
    static char[][] map;
    static boolean[][] visited;

    static int count = 0;

    static boolean dfs(int[] now) { // {y, x}
        if (now[1] == C - 1) {
            visited[now[0]][now[1]] = true;
            count++;
            return true;
        }

        // 그리디, (우상, 우, 우하) 순으로 탐색, 하나라도 성공하면 바로 리턴
        for (int i = 0; i < 3; i++) {
            int nextY = now[0] + dy[i];
            int nextX = now[1] + dx[i];

            if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C) continue;
            if (map[nextY][nextX] == 'x' || visited[nextY][nextX]) continue;

            visited[nextY][nextX] = true;
            if (dfs(new int[]{nextY, nextX})) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] RC = br.readLine().split(" ");
        R = Integer.parseInt(RC[0]);
        C = Integer.parseInt(RC[1]);

        map = new char[R][C];
        visited = new boolean[R][C];

        for (int i = 0; i < R; i++) {
            String line = br.readLine();
            for (int j = 0; j < C; j++) {
                map[i][j] = line.charAt(j);
            }
        }

        for (int i = 0; i < R; i++) {
            dfs(new int[]{i, 0});
        }

        System.out.println(count);
    }
}