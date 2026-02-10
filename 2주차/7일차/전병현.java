import java.io.*;
import java.util.*;

public class Main {
	
	static byte arr[] = new byte[81];
	
	static BufferedReader br;
	static int n;
	
	static boolean find(int idx) {
		if(idx==n)return true;
		for(byte k=1;k<=3;k++) {
			arr[idx] = k;
			boolean fullflag = true;
			for(int i=1;i<=(idx+1)/2;i++) {
				boolean flag = true;
				for(int j=0;j<i;j++) {
					flag &= (arr[idx-i-j]==arr[idx-j]);
					if(!flag)break;
				}
				fullflag &= (!flag);
				if(!fullflag) break;
			}
			if(fullflag && find(idx+1))return true;
		}
		return false;
	}
	
    public static void main(String[] args) throws Exception {
    	br = new BufferedReader(new InputStreamReader(System.in));
    	n = Integer.parseInt(new StringTokenizer(br.readLine()).nextToken());
    	find(0);
    	StringBuilder sb= new StringBuilder();
    	for(int i=0;i<n;i++) {
    		sb.append(arr[i]);
    	}
    	System.out.println(sb);
    }
}