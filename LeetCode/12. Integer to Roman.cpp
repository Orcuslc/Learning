class Solution {
public:
    string intToRoman(int num) {
        string kilos[] = {"", "M", "MM", "MMM"};
        string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return kilos[num/1000] + hundreds[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};