class Solution {
public:
    string solveEquation(string equation) {
        int leftx = 0, rightx = 0, leftval = 0, rightval = 0;
        int index = equation.find('=');
        parse(equation, 0, index, leftx, leftval);
        parse(equation, index+1, equation.size(), rightx, rightval);
        cout << leftx << ' ' << leftval << endl;
        cout << rightx << ' ' << rightval << endl;
        int x = leftx-rightx, val = rightval-leftval;
        if(x == 0) {
            if(val == 0) return "Infinite solutions";
            else return "No solution";
        }
        return "x=" + to_string(val/x);
    }
    
    void parse(string& equation, int start, int end, int& x, int& val) {
        int sgn = 1, index = start;
        while(index < end) {
            // cout << index << endl;
            if(equation[index] != 'x') {
                if(equation[index] == '-') sgn = -1;
                else if(equation[index] == '+') sgn = 1;
                else { // number
                    int now = 0;
                    while(index < end && equation[index] != '+' && equation[index] != '-' && equation[index] != 'x') {
                        now = now*10 + equation[index] - '0';
                        index++;
                    }
                    if(index < end && equation[index] == 'x') {
                        x += sgn*now;
                    }
                    else { // op
                        val += sgn*now;
                        index--;
                    }
                }
            }
            else x += sgn;
            index++;
        }
    }
};