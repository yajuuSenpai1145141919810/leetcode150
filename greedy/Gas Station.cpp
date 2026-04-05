// 134. Gas Station
// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. 
// You begin the journey with an empty tank at one of the gas stations.
// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, 
// otherwise return -1. If there exists a solution, it is guaranteed to be unique.


// 只要 total_sum(總油量 - 總耗油) >= 0，代表油一定夠跑完一圈，絕對有解。


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        // 如果說 從a->b->c 會不夠了 那b->c也會不夠,因為從a開始好歹會有剩下油

        // current_sum (當前剩餘油量)：
        // 我們從 index 0 開始走，累加 gas[i] - cost[i]。
        // 一旦 current_sum < 0：代表目前的起點行不通。 
        // reedy 決策：把起點設為 i + 1，並把 current_sum 歸零重新計算。

        int n=gas.size();
        int m=cost.size();
        int totalGas=0;
        for(int x: gas) totalGas+=x;
        int totalCost=0;
        for(int y:cost) totalCost+=y;

        // 如果「總油量」小於「總油耗」，不管怎麼排起點，絕對跑不完一圈
        // 只要總油量夠，就一定有解  絕對要寫 接下來的 for 迴圈，任務就從「判斷有沒有解」簡化成了「找出那個唯一的解」。
        if(totalCost>totalGas) return -1;

        int cur=0; // 要設一個current儲存當前結果
        int start=0; // 我需要知道起點

        for(int i=0;i<n;i++){
            cur+=(gas[i]-cost[i]);
            if(cur<0){
                cur=0;
                start=1+i;
            }
        }
        return start;
    }
};
