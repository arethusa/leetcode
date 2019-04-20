package p875;

public class Main {
	public static void main(String [] args) {
		long startTime = System.nanoTime();
		
		System.out.println("Case 1 " + (case1() ? "Passed" : "Failed") + " takes " + (System.nanoTime() - startTime));
		System.out.println("Case 2 " + (case2() ? "Passed" : "Failed") + " takes " + (System.nanoTime() - startTime));
	}
	
	public static boolean case1() {
		int[] piles = {3, 6, 7, 11};
		int H = 8;
		int K = 4;
		Solution solution = new Solution();
		
		return K == solution.minEatingSpeed(piles, H);
	}
	
	public static boolean case2() {
		int[] piles = {
				332484035,
				524908576,
				855865114,
				632922376,
				222257295,
				690155293,
				112677673,
				679580077,
				337406589,
				290818316,
				877337160,
				901728858,
				679284947,
				688210097,
				692137887,
				718203285,
				629455728,
				941802184};
		int H = 823855818;
		int K = 14; 
		Solution solution = new Solution();
		
		return K == solution.minEatingSpeed(piles, H);
	}
}
