class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        vector<int> vr (m.size(), 1);
        vector<int> vc (m[0].size(), 1);
        
        for(int i = 0; i<m.size(); i++){
            for(int j = 0 ; j<m[0].size(); j++){
                if(m[i][j] == 0){
                    vr[i] = 0;
                    vc[j] = 0;
                }
            }
        }
        for(int i = 0; i<m.size(); i++){
            for(int j = 0 ; j<m[0].size(); j++){
                if(vr[i]==0 || vc[j]==0){
                    m[i][j] = 0;
                }
            }
        }
        return;
    }
};