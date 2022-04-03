class Solution {
    public int singleNumber(int[] nums) {
        

		int sum = 0;
		// if a bit comes odd number of times adding 1 (up bit of single time number) will make it even and if 1 is even it contribute
		// to the answer
		// mask ll add into sum

		long mask = (long) 1 << 31;

		while (mask > 0) {
			int count = 0;
			for (int i : nums) {
				if ((i & mask) == mask) {
					count++;
				}

			}
			if (count%3>0) { // not mulitple of 3
				
				sum += mask;
			} 
			mask >>= 1;
		}

		return sum;

	
    }
}