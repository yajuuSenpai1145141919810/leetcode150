// 146. LRU Cache
// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

class LRUCache {
private:
    int cap;
    // list 儲存 {key, value}，最近使用的放在 front
    std::list<std::pair<int, int>> cacheList;
    // map 儲存 key 到 list 迭代器 (iterator) 的映射，方便 O(1) 找到節點
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // 如果 key 不存在，回傳 -1
        if (map.find(key) == map.end()) {
            return -1;
        }
        
        // 如果存在，把該節點搬到 list 的最前面 (代表最近使用)
        // splice(目標位置, 來源 list, 來源迭代器)
        cacheList.splice(cacheList.begin(), cacheList, map[key]);
        
        return map[key]->second;
    }
    
    void put(int key, int value) {
        // 1. 如果 key 已經存在
        if (map.find(key) != map.end()) {
            // 更新數值
            map[key]->second = value;
            // 搬到最前面
            cacheList.splice(cacheList.begin(), cacheList, map[key]);
            return;
        }
        
        // 2. 如果 key 不存在，檢查是否滿了
        if (cacheList.size() == cap) {
            // 刪除最久沒用的 (list 最後面那個)
            int lastKey = cacheList.back().first;
            cacheList.pop_back();
            map.erase(lastKey);
        }
        
        // 3. 插入新節點到最前面
        cacheList.push_front({key, value});
        map[key] = cacheList.begin();
    }
};
