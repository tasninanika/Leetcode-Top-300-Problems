class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> empMap;
        for (auto& emp : employees) {
            empMap[emp->id] = emp;
        }

        return dfs(id, empMap);
    }

    int dfs(int id, unordered_map<int, Employee*>& empMap) {
        Employee* emp = empMap[id];
        int total_importance = emp->importance;

        for (int subId : emp->subordinates) {
            total_importance += dfs(subId, empMap);
        }

        return total_importance;
    }
};
