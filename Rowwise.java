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

        for (int row = 0; row < R; row++)
        {
            for (int col = 0; col < C; col++)
            {
                grid[row][col] = sc.nextInt();

                if (row == 0)
                {
                    dp[row][col] = grid[row][col];
                }
            }
        }

        for (int row = 1; row < R; row++)
        {
            long fsmax[] = getFSMAX(dp, row - 1, C);

            for (int col = 0; col < C; col++)
            {
                if (dp[row - 1][col] == fsmax[0])
                {
                    dp[row][col] = fsmax[1] + grid[row][col];
                }
                else
                {
                    dp[row][col] = fsmax[0] + grid[row][col];
                }
            }
        }

        System.out.println(getFSMAX(dp, R - 1, C)[0]);
    }

    private static long[] getFSMAX(long dp[][], int row, int C)
    {
        long fmax = Math.max(dp[row][0], dp[row][1]);
        long smax = Math.min(dp[row][0], dp[row][1]);

        for (int col = 2; col < C; col++)
        {
            if (dp[row][col] > fmax)
            {
                smax = fmax;
                fmax = dp[row][col];
            }
            else if (dp[row][col] > smax)
            {
                smax = dp[row][col];
            }
        }

        return new long[]{fmax, smax};
    }
}