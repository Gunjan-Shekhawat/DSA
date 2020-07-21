vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque <int>q;
    vector <int> v;
    int n = A.size();
    for(int i=0; i<n; i++)
    {
        if(q.front()==i-B)
            q.pop_front();
        while(!q.empty() && A[q.back()]<A[i]) 
            q.pop_back();
        q.push_back(i);
        if(i+1>=B) 
        v.push_back(A[q.front()]);
    }
    return v;
}
