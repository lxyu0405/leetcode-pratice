public class ClimbingStairs {
    public int climbStairs(int n) {
        if (n <= 0)     return 0;
        int[] climb = new int[n+1];
        climb[0] = 1;
        climb[1] = 1;
        for (int i = 2; i <= n; i++){
            climb[i] += (climb[i-1] + climb[i-2]);
        }
        return climb[n];
    }
}
