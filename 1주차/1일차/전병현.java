import java.io.*;
import java.util.*;

public class Main {

    static boolean [][] board;
    static int n, m;

    public static int p(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }

    static int[] di = {0, 0, 1, -1};
    static int[] dj = {1, -1, 0, 0};

    static int bfs(int i, int j){
        int maxi = 0;
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{i, j, 0});
        boolean visit[][] = new boolean[n][m];
        while(!q.isEmpty()){
            int[] top = q.poll();
            i = top[0];
            j = top[1];
            int depth = top[2];
            if(visit[i][j])continue;
            // System.out.println(i+" "+j+" "+depth);
            visit[i][j] = true;
            maxi = Math.max(depth, maxi);
            for(int k=0;k<4;k++){
                int ni = i+di[k];
                int nj = j+dj[k];
                if(ni>=0&&ni<n&&nj>=0&&nj<m&&board[ni][nj]&&visit[ni][nj]==false){
                    q.add(new int[]{ni, nj, depth+1});
                }
            }
        }
        return maxi;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = p(st); m = p(st);
        board = new boolean[n][m];
        for(int i=0;i<n;i++){
            String s = br.readLine();
            for(int j=0;j<m;j++){
                if(s.charAt(j)=='L'){
                    board[i][j] = true;
                }
            }
        }

        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j])
                maxi = Math.max(maxi, bfs(i, j));
            }
        }
        System.out.println(maxi);
    }
}
