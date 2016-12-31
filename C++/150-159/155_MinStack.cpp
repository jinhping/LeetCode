class MinStack {
private:
    vector<int> myVector;
    vector<int> myMins;

public:
    void push(int x) {
        myVector.push_back(x);
        if(myMins.size()==0)
            myMins.push_back(x);
        else
        {
            int temp = myMins.back();
            if(x < temp)
                temp = x;
            myMins.push_back(temp);
        }
    }

    void pop() {
        myVector.pop_back();
        myMins.pop_back();
    }

    int top() {
        return myVector.back();
    }

    int getMin() {
        return myMins.back();
    }
};