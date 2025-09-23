class TaskManager {
public:
    unordered_map<int, pair<int, int>> taskInfo;
    priority_queue<pair<long long, int>> pq;
    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0; i < tasks.size(); i++){
            taskInfo[tasks[i][1]] = {tasks[i][0], tasks[i][2]};
            pq.push({(long long)tasks[i][2] * 1000000LL + tasks[i][1], tasks[i][1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {userId, priority};
        pq.push({(long long)priority * 1000000LL + taskId, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int userId = taskInfo[taskId].first;
        taskInfo[taskId] = {userId, newPriority};
        pq.push({(long long)newPriority * 1000000LL + taskId, taskId});
    }
    
    void rmv(int taskId) {
        taskInfo.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [key, taskId] = pq.top();
            pq.pop();
            if(!taskInfo.count(taskId)) continue;
            auto [userId, priority] = taskInfo[taskId];
            long long expKey = (long long)priority * 1000000LL + taskId;
            if(key != expKey) continue;
            taskInfo.erase(taskId);
            return userId;
        }
        return -1;
    }
};
