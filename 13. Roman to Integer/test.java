import javax.naming.spi.DirStateFactory.Result;

public class test {
    public static void main(String[] args) {
        int sum = romanToInt("MCMXCIV");
        System.out.println(sum);
    }

    static public int romanToInt(String s) {
        int sum = 0;
        char h[] = s.toCharArray();
        char p[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
        int convert[] = { 1, 5, 10, 50, 100, 500, 1000 };
        int result[] = new int[h.length+1];
        for (int i = 0; i < h.length; i++) {
            for (int j = 0; j < p.length; j++) {
                if (h[i] == p[j]) {
                    result[i] = convert[j];
                    break;
                }
            }

        }
        for (int i = 0; i < h.length; i++) {
            if (result[i] < result[i + 1]) {
                sum += result[i + 1] - result[i];
                i++;
            } else {
                sum += result[i];
            }
        }
        return sum;
    }
}
