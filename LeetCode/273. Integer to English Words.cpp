class Solution {
        const vector<string> numbers = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        const vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        const vector<string> bases = {"", "Thousand", "Million", "Billion"};
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string res = "";
        int index = 0;
        while(num) {
            if(num%1000) res = thousand(num%1000) + bases[index] + " " + res;
            num /= 1000;
            index++;
        }
        index = res.size()-1;
        while(res[index] == ' ') index--;
        return res.substr(0, index+1);
    }
    
    string thousand(int num) {
        if(num == 0) return "";
        else if(num < 20) return numbers[num] + " ";
        else if(num < 100) return tens[num/10] + " " + thousand(num%10);
        else return numbers[num/100] + " Hundred " + thousand(num%100);
    }
};