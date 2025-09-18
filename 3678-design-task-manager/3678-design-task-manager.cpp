class TaskManager {
private:
    struct Task {
        int userId;
        int taskId;
        int priority;
        Task() : userId(0), taskId(0), priority(0) {}
        Task(int u, int t, int p) : userId(u), taskId(t), priority(p) {}
        bool operator<(Task other) const {
            if (priority == other.priority) {
                return taskId > other.taskId;
            }
            return priority > other.priority;
        }
    };

    unordered_map<int, Task> taskMap;
    set<Task> taskSet;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            Task task(userId, taskId, priority);
            taskMap[taskId] = task;
            taskSet.insert(task);
        }
    }

    void add(int userId, int taskId, int priority) {
        Task task(userId, taskId, priority);
        taskMap[taskId] = task;
        taskSet.insert(task);
    }

    void edit(int taskId, int newPriority) {
        auto it = taskMap.find(taskId);
        if (it != taskMap.end()) {
            Task oldTask = it->second;
            taskSet.erase(oldTask);
            Task newTask(oldTask.userId, taskId, newPriority);
            taskMap[taskId] = newTask;
            taskSet.insert(newTask);
        }
    }

    void rmv(int taskId) {
        auto it = taskMap.find(taskId);
        if (it != taskMap.end()) {
            Task task = it->second;
            taskSet.erase(task);
            taskMap.erase(taskId);
        }
    }

    int execTop() {
        if (taskSet.empty()) {
            return -1;
        }
        auto it = taskSet.begin();
        Task topTask = *it;
        taskSet.erase(it);
        taskMap.erase(topTask.taskId);
        return topTask.userId;
    }
};
