public class test {
    public static void main(String[] args) {
        int[] num1 = { 3, 2, 3 };
        int[] result = twoSum(num1, 6);
        System.out.println(result[0] + "" + result[1]);

    }

    public static int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums.length; j++) {
                if (i == j) {
                    continue;
                }
                if (nums[j] + nums[i] == target) {
                    result[0]=j;
                    result[1]=i;
                }
            }
        }
        return result;
    }
}
