class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int sign = 1;
        int i = 0;
        // WhiteSpace
        while (s[i] == ' ') {
            i++;
        }
        // Signedness
        if (s[i] == '-') {
            sign = -1;
            i++;
        }else if (i < s.size() && s[i] == '+') {
            i++;
        }
        // Zero's
        while (s[i] == '0') {
            i++;
        }
        // Converting
        while (i < s.size() && isdigit(s[i])) {
            int temp = s[i] - '0';
            // OverFlow and Underflow
            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && temp > INT_MAX % 10)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + temp;
            i++;
        }

        return sign * ans;
    }
};