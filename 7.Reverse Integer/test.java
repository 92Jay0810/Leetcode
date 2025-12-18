public class test {
    public static void main(String[] args) {
        int a = 1534236469;
        a = reverse(a);
        System.out.println(a);
    }

    public static int reverse(int x) {
        int result = 0;
        if (x > 0) {
            String a = String.valueOf(x);
            StringBuilder aBuilder = new StringBuilder(a);
            a = aBuilder.reverse().toString();
            try{
                result = Integer.parseInt(a);
            }catch(NumberFormatException e){
                return 0 ;
            }
            

            return result;
        } else {
            String a = String.valueOf(-x);
            StringBuilder aBuilder = new StringBuilder(a);
            a = aBuilder.reverse().toString();
            result = Integer.parseInt(a);
            return -result;
        }

    }
}
