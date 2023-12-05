#include<iostream>
#include<queue>
using namespace std;

int main(){
    cout<<"Using priority queue"<<endl;

    cout << endl;
    cout << "Creating max heap" << endl;
    priority_queue<int> pq;     // By default this is a max heap

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    // We know in max heap, at top (root node) Maximum element is placed 
    cout << "Element at top " << pq.top() << endl;
    pq.pop(); 
    cout << "Element at top " << pq.top() << endl;
    cout << "Size is " << pq.size() << endl;

    cout << "Is max heap empty? " << (pq.empty() ? "Yes" : "No") << endl;


    // Creating min heap
    cout << endl;
    cout << "Creating min heap" << endl;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    // <int> : specifies the data type of the elements in the priority queue. In this case, it's an integer.
    // vector<int> : specifies the underlying container used for priority queue. In this case, it's a vector.
    // greater<int> : means smallest element will've highest priority, making priority queue act as min-heap.

    // Creating max heap
    // priority_queue<int, vector<int>, less<int> > maxHeap;

    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    // We know in min heap, at top (root node) Minimum element is placed
    cout << "Element at top " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Element at top " << minHeap.top() << endl;
    cout << "Size is " << minHeap.size() << endl;

    cout << "Is max heap empty? " << (minHeap.empty() ? "Yes" : "No") << endl;

    return 0;
}