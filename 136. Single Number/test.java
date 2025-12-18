import java.util.HashMap; 

public class test {
    public static void main(String[] args) {
        int[] nums={2,2,1};
        Integer a=singleNumber(nums);
        System.out.println(a.intValue()); 
    }

    public static int singleNumber(int[] nums) {
        int repeat = 0;
        for (int j = 0; j < nums.length; j++) {
             repeat = 0;
            for (int j2 = 0; j2 < nums.length; j2++) {
                if (nums[j]==nums[j2]) {
                    repeat++;
                } 
            }
            if(repeat==1){
                return nums[j];
            }
        }
        return 0;
    }
}
