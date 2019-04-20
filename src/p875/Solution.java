package p875;

public class Solution {
	public int minEatingSpeed(int[] piles, int H) {
		long sum = 0;
		long tmpH = 0;
		
		for (int num: piles) {
			sum += num;
		}
		
	
		
		for (int k = (int) Math.ceil((double) sum / H);; k++) {
			tmpH = 0;
			
			for (int num: piles) {
				tmpH += (int) Math.ceil((double) num / k); 
			}
			
			if (tmpH  <= H) {
				return k;
			}
		}
    }
}
