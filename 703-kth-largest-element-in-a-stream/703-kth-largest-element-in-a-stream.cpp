class KthLargest
{
    int Kth;
    priority_queue<int , vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int> &nums)
    {
        Kth = k;
        for(auto i:nums){
            if(pq.size()<k){
                pq.push(i);
                continue;
            }
            if(i>pq.top()){
                pq.pop();
                pq.push(i);
            }
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > Kth)
            pq.pop();

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */