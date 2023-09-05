class Solution {
public:
    int change(int amount, vector<int>& a) {
            
        	vector <int> temp(amount + 1);
	        temp[0] = 1;
	        for(int i = 0; i < a.size(); i++) {
		        for(int j = 0; j < amount + 1; j++) {
			        if(j >= a[i]) temp[j] += temp[j - a[i]];
		    }
	    }
    return temp[amount];
    }
};