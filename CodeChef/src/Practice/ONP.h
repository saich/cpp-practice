#include <iostream>
#include <stack>
#include <string.h>

// Problem:	http://www.codechef.com/submit/ONP
void PostFixNotation()
{
	int N;
	std::cin >> N;
	for(int i = 0; i < N; i++)
	{
		std::stack<char> st;
		char input[400];
		std::cin >> input;
		for(size_t i = 0, len = strlen(input); i < len; i++)
		{
			char ch = input[i];
			switch(ch)
			{
			case '(':
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				// Pop until we find an entry of lower priority
				st.push(ch);
				break;
			case ')':
				// Pop the stack until we encounter '('
				char s;
				do
				{
					s = st.top();
					st.pop();
					if( s != '(')
						std::cout << s;
				} while( s != '(');
				break;
			default:
				std::cout << ch;
			}
		}

		// Now empty the stack
		while(!st.empty())
		{
			std::cout << st.top();
			st.pop();
		}

		std::cout << std::endl;
	}
}