//Date:2015-11-26
//Author:lidengke

#include <iostream>
#include <stack>

using namespace std;


class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        _s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(_s2.empty()) {
        	while(!_s1.empty()) {
        		_s2.push(_s1.top());
        		_s1.pop();
        	}
        }
        _s2.pop();
    }

    // Get the front element.
    int peek(void) {
        if(_s2.empty()) {
        	while(!_s1.empty()) {
        		_s2.push(_s1.top());
        		_s1.pop();
        	}
        }

        return _s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return _s1.empty() && _s2.empty();
    }
private:
	stack<int> _s1;
	stack<int> _s2;
};

int main(int argc, char const *argv[])
{
	Queue q;
	q.push(0);	
	cout << q.peek() << endl;
	q.pop();
	q.push(1);
	cout << q.peek() << endl;
	q.pop();
	q.push(2);
	q.push(3);

	while(!q.empty()) {
		cout << q.peek() << endl;
		q.pop();
	}

	return 0;
}