class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n){
        stack<int> stack;
        stack.push(-1);
        vector<int> result(n);

        for(int i = n-1; i >= 0; i--){
            int current = arr[i];
            while(stack.top() != -1 && arr[stack.top()] >= current) stack.pop();
            result[i] = stack.top();
            stack.push(i);
        }
        return result;
    }
    vector<int> prevSmallerElement(vector<int> arr, int n){
        stack<int> stack;
        stack.push(-1);
        vector<int> result(n);

        for(int i = 0; i < n; i++){
            int current = arr[i];
            while(stack.top() != -1 && arr[stack.top()] >= current) stack.pop();
            result[i] = stack.top();
            stack.push(i);
        }
        return result;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();

        vector<int> next(size);
        next = nextSmallerElement(heights, size);
        vector<int> prev(size);
        prev = prevSmallerElement(heights, size);

        int area = 0;
        for(int i = 0; i < size; i++){
            int length = heights[i];
            if(next[i] == -1) next[i] = size;
            int width = next[i] - prev[i] - 1;

            int newArea = length * width;
            area = max(area, newArea);
        }
        return area;
    }
};