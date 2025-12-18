class Solution
{
public:
    bool checkValidString(string s)
    {
        // 要用區間去處理，不能只用count
        // 不能拿前面* 抵銷後面的(
        int left = 0;
        int right = 0;
        for (auto &c : s)
        {
            if (c == '(')
            {
                left++;
                right++;
            }
            else if (c == ')')
            {
                left--;
                right--;
            }
            else
            {
                // 假設萬用字元當)
                left--;
                // 假設萬用字元當(
                right++;
            }
            // 抓到過多的)
            // 萬用字元當( 也無法抵銷
            if (right < 0)
            {
                return false;
            }
            // 捨棄一些* 拿來做空字串 因為不會有負的左括號數量
            //  * 有點像是 我能還債 也可能沒還
            //  left表示，我拿 * 假設都拿去還債， 我不會還到負的債 ? 讓他欠我
            //  可以直接拿例子去嘗試 ((**)
            if (left < 0)
            {
                left = 0;
            }
        }
        return left == 0;
    }
};
