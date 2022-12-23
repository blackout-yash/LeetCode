//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
	Node* reverse(Node *&head) {
		Node *newHead = NULL;
		while (true) {
		    if(head == NULL) break;
			Node *next = head -> next;
			head -> next = newHead;
			newHead = head;
			head = next;
		}
		return newHead;
	}

	Node* addOne(Node *head) {
		Node *newHead = reverse(head);
		Node *temp = newHead;
		int carry = 1;
		while (true) {
			int sum = (temp -> data) + carry;
			temp -> data = sum % 10;
			if(carry) carry = sum / 10;
			if(temp -> next == NULL) {
			    if (carry) temp -> next = new Node(carry);
			    break;
			} else temp = temp -> next;
		}

		head = reverse(newHead);
		return head;
	}
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends