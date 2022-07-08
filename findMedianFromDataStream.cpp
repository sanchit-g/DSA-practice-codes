// Two Heap solution - one heap is minHeap (Large) and other is maxHeap (Small)
// For solution explanation : https://youtu.be/itmhHWaHupI

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> large;
    priority_queue<int> small;
    
    MedianFinder() {}
    
    void addNum(int num) {
        
        small.push(num);
        
        // make sure every num in small <= every num in large
        if(!small.empty() and !large.empty() and small.top() > large.top())
        {
            large.push(small.top());
            small.pop();
        }
        
        // if size is uneven
        if(small.size() > large.size() + 1)
        {
            large.push(small.top());
            small.pop();
        }
        
        if(large.size() > small.size() + 1)
        {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        
        if(small.size() > large.size())
            return small.top();
        
        else if(large.size() > small.size())
            return large.top();
        
        return (small.top() + large.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
