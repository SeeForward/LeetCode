//Date:2015-11-28
//Author:lidengke

#include <iostream>
#include <deque>

using namespace std;

class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		_q1.push_back(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		if(_q1.empty()) {
			while(!_q2.empty()) {
				_q1.push_back(_q2.front());
				_q2.pop_front();
			}
		}

		while(_q1.size() > 1) {
			_q2.push_back(_q1.front());
			_q1.pop_front();
		}

		_q1.pop_front();
	}

	// Get the top element.
	int top() {
		if(_q1.empty()) {
			while(!_q2.empty()) {
				_q1.push_back(_q2.front());
				_q2.pop_front();
			}
		}

		while(_q1.size()  > 1) {
			_q2.push_back(_q1.front());
			_q1.pop_front();
		}
		return _q1.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return _q1.empty() && _q2.empty();
	}
private:
	deque<int> _q1;
	deque<int> _q2; 
};

int main(int argc, char const *argv[])
{

	Stack s;
	s.push(1);
	s.push(2);

	cout << s.top() << endl;
	s.pop();

	s.push(3);
	s.push(4);

	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();

	
	return 0;
}