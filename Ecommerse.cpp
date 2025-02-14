#include<iostream>
#include<queue>
using namespace std;
struct Order{
    int order_id;
    int priority;
    int timestamp;
    Order(int o, int p, int t) : order_id(o), priority(p), timestamp(t){}
};
struct Comparator{
    bool operator()(const Order& a, const Order& b){
        if(a.priority != b.priority){
            return a.priority<b.priority;
        }
        return a.timestamp > b.timestamp;
    }
};
int main(){
    priority_queue<Order, vector<Order>, Comparator> pq;
    pq.push(Order(1, 2, 1001));  
    pq.push(Order(2, 3, 1002));
    pq.push(Order(3, 3, 1000));
    pq.push(Order(4, 1, 1003));

    while (!pq.empty()) {
        Order topOrder = pq.top();
        std::cout << "Processing Order ID: " << topOrder.order_id << ", Priority: " << topOrder.priority << ", Timestamp: " << topOrder.timestamp << std::endl;
        pq.pop();
    }

    return 0;
}