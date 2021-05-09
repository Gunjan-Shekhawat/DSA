#include<bits/stdc++.h>
using namespace std;
stack<int> st;
vector<int>ns;

void insert_at_bottom(int x)
{

	if(st.size() == 0)
	st.push(x);

	else
	{
		char a = st.top();
		st.pop();
      if(x<a)
      {
		insert_at_bottom(x);
		st.push(a);
      }
      else
      {
       	insert_at_bottom(a);
		st.push(x);
      }
	}
}

void reverse()
{
	if(st.size()>0)
	{

		int x = st.top();
		st.pop();
		reverse();
		insert_at_bottom(x);
	}
}

// Driver Code
int main()
{
	
	// push elements into
	// the stack
	st.push(5);
	st.push(9);
	st.push(2);
	st.push(4);
  st.push(13);
  st.push(8);
  st.push(3);
  st.push(11);
  	
	
	cout<<"Original Stack"<<endl;
	
	// print the elements
	// of original stack
	cout<<5<<" "<<9<<" "
		<<2<<" "<<4<<" "<<13<<" "<<8<<" "<<3<<" "<<11 
		<<endl;
	
	// function to reverse
	// the stack
	reverse();
	cout<<"Reversed Stack"
		<<endl;
	
	// storing values of reversed
	// stack into a string for display
	while(!st.empty())
	{
		int p=st.top();
		st.pop();
		ns.push_back(p);
	}
	
	//display of reversed stack
	cout<<ns[7]<<" "<<ns[6]<<" "<<ns[5]<<" "<<ns[4]<<" "<<ns[3]<<" "<<ns[2]<<" "
		<<ns[1]<<" "<<ns[0]<<endl;
	return 0;
}
