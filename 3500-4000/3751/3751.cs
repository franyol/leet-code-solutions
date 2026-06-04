// https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/
public class Solution {
    public int TotalWaviness(int num1, int num2) {
        int response = 0;
        for (int i = num1; i <= num2; i++) {
            response += CountPeaksNValleys(i);
        }
        return response;
    }

    int CountPeaksNValleys(int num) {
        int[] nums = new int[100];
        int len_nums = 0;

        int count = 0;

        while (num > 0) {
            nums[len_nums] = num % 10;
            len_nums++;
            num /= 10;
        }

        for (int i = 0; i < len_nums - 2; i++) {
            int curr = nums[i+1];
            int prev = nums[i];
            int next = nums[i+2];

            if (IsPeak(prev, curr, next) || IsValley(prev, curr, next)) {
                count++;
            }
        }
        return count;
    }

    bool IsPeak(int prev, int curr, int next) {
        if (curr > prev && curr > next) return true;
        return false;
    }

    bool IsValley(int prev, int curr, int next) {
        if (curr < prev && curr < next) return true;
        return false;
    }
}
