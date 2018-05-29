class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return right_angled_isosceles_triangle(p1, p2, p3) && right_angled_isosceles_triangle(p1, p2, p4) && right_angled_isosceles_triangle(p2, p3, p4) && right_angled_isosceles_triangle(p1, p3, p4);
    }
    
    bool right_angled_isosceles_triangle(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
        int s1, s2, s3; // Edges of a triangle
        s1 = (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
        s2 = (p1[0]-p3[0])*(p1[0]-p3[0])+(p1[1]-p3[1])*(p1[1]-p3[1]);
        s3 = (p2[0]-p3[0])*(p2[0]-p3[0])+(p2[1]-p3[1])*(p2[1]-p3[1]);
        if(s1 < s3 && s2 < s3 && s1 == s2) {
            if(s1+s2 == s3) return true;
        }
        else if(s1 < s2 && s3 < s2 && s1 == s3) {
            if(s1+s3 == s2) return true;
        }
        else if(s2 < s1 && s3 < s1 && s2 == s3) {
            if(s2+s3 == s1) return true;
        }
        return false;
    }
};