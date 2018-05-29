class Solution {
public:
    string getHint(string secret, string guess) {
        int ds[10], dg[10];
        memset(ds, 0, sizeof(ds)); 
        memset(dg, 0, sizeof(dg));
        int bull = 0, cow = 0;
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] == guess[i]) bull++;
            ds[secret[i]-'0']++;
            dg[guess[i]-'0']++;
        }
        for(int i = 0; i < 10; i++) {
            cow += min(ds[i], dg[i]);
        }
        cow -= bull;
        return ""+to_string(bull)+"A"+to_string(cow)+"B";
    }
};