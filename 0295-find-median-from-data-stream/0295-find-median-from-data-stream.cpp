class MedianFinder {
public:
	priority_queue <int> first;
	priority_queue <int, vector <int>, greater <int>> sec;
	MedianFinder() {}

	void addNum(int num) {
		if (first.size() && sec.size()) {
			if (num <= first.top()) first.push(num);
			else sec.push(num);
			if (first.size() + 2 == sec.size()) {
				first.push(sec.top());
				sec.pop();
			} else if (sec.size() + 2 == first.size()) {
				sec.push(first.top());
				first.pop();
			}
		} else {
			if (first.size()) {
				int temp = first.top();
				first.pop();
				first.push(min(temp, num));
				sec.push(max(temp, num));
			} else first.push(num);
		}
	}

	double findMedian() {
		if (first.size() == sec.size()) {
			double num = first.top() + sec.top(), denom = 2;
			return num / denom;
		} else if (first.size() > sec.size()) return first.top();
		return sec.top();
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */