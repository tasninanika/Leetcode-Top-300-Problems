class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
         vector<int> d = {
            dist(p1,p2), dist(p1,p3), dist(p1,p4),
            dist(p2,p3), dist(p2,p4),
            dist(p3,p4)
        };

        sort(d.begin(), d.end());

        return (d[0] > 0 && d[0] == d[1] && d[1] == d[2] && d[2] == d[3]
               && d[4] == d[5] && d[5] > d[0]);
    }
    int dist(vector<int>& x, vector<int>& y) {
        return (x[0]-y[0])*(x[0]-y[0]) + (x[1]-y[1])*(x[1]-y[1]);
    }
};
