int largestRectangleAreaStack(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || heights[st.top()] > heights[i])) {
            int height = heights[st.top()];
            st.pop();
            int width;
            if (st.empty()) width = i;
            else width = i - st.top() - 1;
            int area = height * width;
            if (area > maxArea) maxArea = area;
        }
        st.push(i);
    }

    return maxArea;
}
