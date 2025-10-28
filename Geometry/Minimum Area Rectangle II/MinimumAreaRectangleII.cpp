class Solution {
public:
     double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> mp;
        for(auto p: points){
            mp[p[0]].insert(p[1]);
        }

        double area=DBL_MAX;

        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                for(int k=j+1; k<points.size(); k++){
                    int dx1 = points[j][0]-points[i][0];
                    int dx2 = points[k][0]-points[i][0];
                    int dy1 = points[j][1]-points[i][1];
                    int dy2 = points[k][1]-points[i][1];
