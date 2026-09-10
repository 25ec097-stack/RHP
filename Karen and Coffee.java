import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int m=200000;
    int n=sc.nextInt();
    int k=sc.nextInt();
    int q=sc.nextInt();
    int[] d = new int[m+2];
    for(int i=0;i<n;i++){
      int l = sc.nextInt();
      int r = sc.nextInt();
      d[l]++;
      d[r+1]--;
    }
    int[] p = new int[m+1];
    int c=0;
    for(int i=1;i<=m;i++){
      c+=d[i];
      if(c>=k){
        p[i]=p[i-1]+1;
      }
      else{
        p[i]=p[i-1];
      }
    }
    StringBuilder sb = new StringBuilder();
    for(int i=0;i<q;i++){
      int a = sc.nextInt();
      int b = sc.nextInt();
      int ans = p[b]-p[a-1];
      sb.append(ans).append("\n");
    }
    System.out.println(sb.toString());
  }
}
