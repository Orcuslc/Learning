class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A, E), right = max(min(G, C), left);
        int down = max(B, F), up = max(min(D, H), down);
        return (C-A)*(D-B) - (right-left)*(up-down) + (G-E)*(H-F);
    }
};