// 146. LRU Cache
// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

class LRUCache {
private:
    //「Map (快速尋找) + List (維護順序) + Iterator (連結兩者的橋樑)」

    int cap;// 這個 Cache 最大能放幾本書

    // 一個雙向鏈結串列，裡面裝的每一個節點，都是一組 {Key, Value} 的組合
    list<pair<int,int>> cachelist;

    unordered_map<int,list<pair<int,int>>::iterator> map;

public:
    LRUCache(int capacity) {
        cap=capacity;        
    }

    // 找書(key)把裡面的內容value回傳
    int get(int key) {

        if(map.find(key)==map.end()) return -1;

        // splice 的語法：(搬去哪, 從哪個 list 搬, 搬哪一個節點)
        cachelist.splice(cachelist.begin(),cachelist,map[key]);

        // 回傳書裡面的內容
        return map[key]->second;

    }
    // put 就是「更新並搬到起點」或「淘汰終點並插入起點」。
    void put(int key, int value) {
    // 情況 A：這本書已經在書架上 (Update)
    // 更新書的內容（Value）。
    // 因為剛動過它，所以把它搬到書架最前面。

    // 情況 B：這是一本新書 (Insert)
    // 檢查書架滿了沒？ 如果滿了，把書架「最後面」那本最久沒翻的書丟掉，同時把目錄（Map）裡的紀錄也刪掉。
    // 把新書放最前面。
    // 在目錄（Map）記下這本書的位置。

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
