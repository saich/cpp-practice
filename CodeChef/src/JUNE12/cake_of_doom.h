#include <iostream>
#include <string>

/*

// brute force..
std::string sol = "";

bool calc(const std::string& str, int start, int K)
{
	size_t sz = str.size();
	if(start >= sz)
	{
		sol = str;
		return true;
	}

	int idx1 = (sz + start - 1) % sz;
	int idx2 = (sz + start + 1) % sz;

	if(str[start] !=  '?')
	{
		return (str[start] != str[idx1] && str[start] != str[idx2]) ? calc(str, start + 1, K) : false;
	}

	for(int i = 0; i < K; i++)
	{
		if(str[idx1] != '0' + i && str[idx2] != '0' + i)
		{
			std::string str2 = str;
			str2[start] = '0' + i;
			bool bSuccess = calc(str2, start + 1, K);
			if(bSuccess)
				return true;
		}
	}
	return false;
}
*/

int main()
{
	int T, K, len;
	std::string str;
	scanf("%d", &T);
	while(T-- > 0) {
		scanf("%d", &K);
		std::cin >> str;
		len = str.size();

		bool bFailed = false;
		
		std::string origstr = str;
		for(int i = 0; i < len; i++)
		{
			const int idx1 = (len + i - 1) % len;
			const int idx2 = (len + 1) % len;

			if(str[i] != '?')
			{
				if(len == 1)
					continue;
				else if(str[idx1] != str[i] && str[idx2] != str[i])
				{
					continue; // A valid character is already present...
				}
				else
				{
					bFailed = true;
					break; // Print NO...
				}
			}
			int k = 0;
			for(k = 0; k < K; k++)
			{
				const char ch = '0' + k;
				if(str[idx1] != ch && str[idx2] != ch)
				{
					// Found suitable char...
					str[i] = ch;
					break;
				}
			}

			if(k == K) {
				// Failed to fill with any valid character...
				bFailed = true;
				break; // Print NO...
			}
		}

		if(bFailed && K == 2) {

			bFailed = false;

			str = origstr;
			// Find the first non-? character in the string...
			int idx = -1;

			char lastchar = '0';
			for(int i = 0; i < len; i++) {
				if(str[i] != '?') {
					idx = i; break;
				}
			}
			if(idx == -1) {
				bFailed = true;
				printf("NO\n");
				continue;
			}
			for(int i = 0; i < len; i++) {
				const int idx1 = (len + i + idx - 1) % len;
				const int idx2 = (i + idx + 1) % len;

				const int index = (i + idx) % len;
				if(str[index] != '?')
				{
					lastchar = str[index];
					if(str[index] != str[idx1] && str[index] != str[idx2])
						continue;
					else {
						bFailed = true; break;
					}
				}
				const char ch = (lastchar == '0') ? '1' : '0';
				if(str[idx1] != ch && str[idx2] != ch) {
					str[index] = ch;
					lastchar = str[index];
				} else {
					bFailed = true; break;
				}
				
			}
		}
		
		printf("%s\n", (bFailed ? "NO" : str.c_str()));
	}

	return 0;
}