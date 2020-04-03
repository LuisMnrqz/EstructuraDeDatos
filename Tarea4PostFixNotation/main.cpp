#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

/* INPUT
7 4 - 5 *
3 2 4 * +
3 4 2 - *
42 7 - 3 * 2 4 + *
5 3 5 - * 11 2 - 1 * -
#
*/

/* OUTPUT
15   -15   15
11   10   10
6   2   4
630   -412   630
-19   41   3
*/

/*top pop top pop
front pop front pop*/

void processStack(stack <int> &stack, int &a, int &b) 
{
	a = stack.top();
	stack.pop();
	b = stack.top();
	stack.pop();
}

void processQueue(queue <int> &queue, int &a, int &b) 
{
	a = queue.front();
	queue.pop();
	b = queue.front();
	queue.pop();
}

void processPriorQueue(priority_queue <int, vector<int>, greater<int> > &priorqueue, int &a, int &b) 
{
	a = priorqueue.top();
	priorqueue.pop();
	b = priorqueue.top();
	priorqueue.pop();
}

int main() {

  	//Variables
  	int x, y;
  	int z;
	string d, data;

  	//Pila y Filas
  	stack<int> stack;
  	queue<int> queue;
	priority_queue<int, vector<int>, greater<int> > priorqueue; //default valor mayor

  	//Proceso
	getline(cin, data);
  	cout << endl << endl;

	while (data != "#") 
	{
		stringstream ss;
		ss << data;

    	//Stack
    	//Queue
    	//PriorQueue

		while (ss >> d) 
		{
      		//Suma
			if (d == "+") 
			{
				processStack(stack, x, y);
				stack.push(y + x);

				processQueue(queue, x, y);
				queue.push(y + x);
        
				processPriorQueue(priorqueue, x, y);
				priorqueue.push(y + x);
			}
			
      		//Resta
			else if (d == "-") 
			{
				processStack(stack, x, y);
				stack.push(y - x);

				processQueue(queue, x, y);
				queue.push(y - x);

				processPriorQueue(priorqueue, x, y);
				priorqueue.push(y - x);
			} 
			
      		//Mult
			else if (d == "*") 
			{
				processStack(stack, x, y);
				stack.push(x * y);

				processQueue(queue, x, y);
				queue.push(y * x);

				processPriorQueue(priorqueue, x, y);
				priorqueue.push(y * x);
			} 
			
      		//Div
			else if(d == "/") 
			{
				processStack(stack, x, y);
				stack.push(y / x);

				processQueue(queue, x, y);
				queue.push(y / x);

				processPriorQueue(priorqueue, x, y);
				priorqueue.push(y / x);
			} 

			else 
			{
				istringstream(d) >> z;
				stack.push(z);
				queue.push(z);
				priorqueue.push(z);
			}
		}
    	//Resultados 3 espacios de separacion
		cout << stack.top() << "   " << queue.front() << "   " << priorqueue.top() << endl;
		stack.pop();
		queue.pop();
		priorqueue.pop();
		getline(cin, data);
	}
	return 0;
}