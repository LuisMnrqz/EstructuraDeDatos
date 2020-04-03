#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <stack>
#include <cstdlib>

using namespace std;
/* INPUT
7 4 - 5 *
3 2 4 * +
3 4 2 - *
42 7 - 3 * 2 4 + *
5 3 5 - * 11 2 - 1 * -
#
*/
void asignacionStack( stack <int> &miStack, int &iX, int &iY) 
{
	iX = miStack.top();
	miStack.pop();
	iY = miStack.top();
	miStack.pop();
}

void asignacionQueue( queue <int> &miQ, int &iX, int &iY) 
{
	iX = miQ.front();
	miQ.pop();
	iY = miQ.front();
	miQ.pop();
}

void asignacionPQueue( priority_queue < int, vector<int>, greater<int> > &miPQ, int &iX, int &iY) 
{
	iX = miPQ.top();
	miPQ.pop();
	iY = miPQ.top();
	miPQ.pop();
}

int main() {

	string d, data;
	int id, iX, iY;
	priority_queue< int, vector<int>, greater<int> > miPQ;
	stack <int> miStack;
	queue <int> miQ;

	getline(cin, data);
	while( data != "#") 
	{
		stringstream ss;
		ss << data;
		while(ss >> d) 
		{
			if( d == "+" ) 
			{
				//Stack
				asignacionStack( miStack, iX, iY );
				miStack.push(iY + iX);
				//Queue
				asignacionQueue( miQ, iX, iY );
				miQ.push(iY + iX);
				//Priority Queue
				asignacionPQueue( miPQ, iX, iY);
				miPQ.push(iY + iX);
			}
			
			else if( d == "-" ) 
			{
				//Stack
				asignacionStack( miStack, iX, iY );
				miStack.push(iY - iX);
				//Queue
				asignacionQueue( miQ, iX, iY );
				miQ.push(iY - iX);
				//Priority Queue
				asignacionPQueue( miPQ, iX, iY);
				miPQ.push(iY - iX);
			} 
			
			else if( d == "/" ) 
			{
				//Stack
				asignacionStack( miStack, iX, iY );
				miStack.push(iY / iX);
				//Queue
				asignacionQueue( miQ, iX, iY );
				miQ.push(iY / iX);
				//Priority Queue
				asignacionPQueue( miPQ, iX, iY);
				miPQ.push(iY / iX);
			} 
			
			else if( d == "*" ) 
			{
				//Stack
				asignacionStack( miStack, iX, iY );
				miStack.push(iY * iX);
				//Queue
				asignacionQueue( miQ, iX, iY );
				miQ.push(iY * iX);
				//Priority Queue
				asignacionPQueue( miPQ, iX, iY);
				miPQ.push(iY * iX);
			} 
			
			else 
			{
				istringstream(d) >> id;
				miStack.push(id);
				miQ.push(id);
				miPQ.push(id);
			}
		}

		cout << miStack.top() << " " << miQ.front() << " " << miPQ.top() << endl;
		miStack.pop();
		miQ.pop();
		miPQ.pop();
		getline(cin, data);
	}
	return 0;
}