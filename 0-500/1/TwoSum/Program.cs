
/*
 *  Compile with dotnet run
 * */

public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        for (int i = 0; i < nums.Length; i++) {
            for (int j = i+1; j < nums.Length; j++) {
                if (nums[i] + nums[j] == target) {
                    return [i, j];
                }
            }
        }
        return [];
    }

    public int[] TwoSumGreedy(int[] nums, int target) {
        var map = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++) {
            int compliment = target - nums[i];

            if (map.ContainsKey(compliment)) {
                return [ map[compliment], i ];
            }

            map[nums[i]] = i;
        }
        return [];
    }
}

static class Program {
    static int Main(string[] args) {

        var testSet = new List<(int[] nums, int target, int[] output)> {
            ([2, 7, 11, 15], 9, [0, 1]),
            ([3, 2, 4], 6, [1, 2]),
            ([3, 3], 6, [0, 1])
        };

        Solution s = new Solution();

        foreach (var test in testSet) {
            Console.WriteLine("Testing for nums: [" +
                   string.Join(", ", test.nums) +
                            $"] target: {test.target}");
            int[] solution = s.TwoSumGreedy(test.nums, test.target);

            if (test.output.SequenceEqual(solution)) {
                Console.WriteLine($"Success: Output={string.Join(", ", test.output)}");
                Console.WriteLine("");
            } else {
                Console.WriteLine($"Error: Expected={string.Join(", ", test.output)} | Output={string.Join(", ", solution)}");
                return 1;
            }
        }

        return 0;
    }
}
