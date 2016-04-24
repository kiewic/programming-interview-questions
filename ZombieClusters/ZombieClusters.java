import java.util.*;

public class ZombieClusters {

    public static void main(String[] args) {
        System.out.println(zombieCluster(new String[] {"110",  "110", "001"}));
    }
    
    static int zombieCluster(String[] zombies)
    {
        int n = zombies.length;
        boolean[][] matrix = new boolean[n][n];
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = zombies[i].charAt(j) != '0';
            }
        }

        return zombieCluster(matrix);
    }

    static int zombieCluster(boolean[][] matrix)
    {
        int n = matrix.length;
        boolean[] zombiesStatus = new boolean[n];
        int foundZombies = 0;
        int clusters = 0;

        while (foundZombies < n)
        {
            int current = getNext(zombiesStatus);
            System.out.println("Next zombie is " + current);
            
            foundZombies += flood(matrix, zombiesStatus, current);
            clusters += 1;
            
            System.out.println("Found " + foundZombies);
        }

        return clusters;
    }
    
    static int flood(boolean[][] matrix, boolean[] zombiesStatus, int current)
    {
        int n = matrix.length;
        int total = 1; // current zombie is added to cluster
        for (int i = 0; i < n; i++)
        {
            if (matrix[current][i] == true)
            {
                if (zombiesStatus[i] == false)
                {
                    zombiesStatus[i] = true;
                    total += flood(matrix, zombiesStatus, i);
                }
            }
        }
        return total;
    }
    
    static int getNext(boolean[] zombiesStatus)
    {
        int i = 0;
        while (zombiesStatus[i] == true)
        {
            i++;
        }
        zombiesStatus[i] = true;
        return i;
    }

}