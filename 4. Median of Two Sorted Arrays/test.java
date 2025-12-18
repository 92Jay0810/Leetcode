
public class test {
    public static void main(String[] args) {
       int[] nums1={1,2};
       int[] nums2={3,4};
       System.out.println(findMedianSortedArrays(nums1,nums2));
    }

    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] merge=new int[nums1.length+nums2.length];
        for(int i=0;i<nums1.length;i++){
            merge[i]=nums1[i];
        }
        for(int i=nums1.length;i<nums1.length+nums2.length;i++){
            merge[i]=nums2[i-nums1.length];
        }
        java.util.Arrays.sort(merge);
        double result=0.0;
        if(merge.length%2==0){
            result=(merge[merge.length/2]+merge[(merge.length/2)-1])/2.0;
        }else{
            result=merge[merge.length/2];
        }
        return result;
    }
}
