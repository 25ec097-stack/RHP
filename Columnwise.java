import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int R = sc.nextInt();
        int C = sc.nextInt();

        int grid[][] = new int[R][C];
        long dp[][] = new long[R][C];

        for(int row = 0; row < R; row++)
        {
            for(int col = 0; col < C; col++)
            {
                grid[row][col] = sc.nextInt();

                if(col == 0)
                {
                    dp[row][col] = grid[row][col];
                }
            }
        }

        for(int col = 1; col < C; col++)
        {
            long fsmax[] = getFSMAX(dp, col - 1, R);

            for(int row = 0; row < R; row++)
            {
                if(dp[row][col - 1] == fsmax[0])
                {
                    dp[row][col] = fsmax[1] + grid[row][col];
                }
                else
                {
                    dp[row][col] = fsmax[0] + grid[row][col];
                }
            }
        }

        System.out.println(getFSMAX(dp, C - 1, R)[0]);
    }

    private static long[] getFSMAX(long dp[][], int col, int R)
    {
        long fmax = Math.max(dp[0][col], dp[1][col]);
        long smax = Math.min(dp[0][col], dp[1][col]);

        for(int row = 2; row < R; row++)
        {
            if(dp[row][col] > fmax)
            {
                smax = fmax;
                fmax = dp[row][col];
            }
            else if(dp[row][col] > smax)
            {
                smax = dp[row][col];
            }
        }

        return new long[]{fmax, smax};
    }
}