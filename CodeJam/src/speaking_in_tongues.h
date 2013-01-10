#include <iostream>
#include <string>

void speaking_in_tongues()
{
	char map[26] = {0};
	map['y' - 'a'] = 'a';
	map['e' - 'a'] = 'o';
	map['q' - 'a'] = 'z';

	std::string ip[] = {
		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	
		std::string op[] = {"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up"};

	
	for(size_t c = 0; c < 3; c++)
	{
		for(size_t i = 0; i < ip[c].size(); i++)
		{
			char ch = ip[c][i];
			if(ch >= 'a' && ch <= 'z')
				map[ch - 'a'] = op[c][i];
		}
	}
	map[25] = 'q';

	int T;
	scanf("%d", &T);
	getchar();
	for(int tcase = 1; tcase <= T; tcase++)
	{
		std::string G;
		std::getline(std::cin, G);
		for(size_t i = 0, j = G.size(); i < j; i++)
		{
			char temp = G[i];
			if(temp >= 'a' && temp <= 'z')
			{
				G[i] = map[temp - 'a'];
			}
		}

		std::cout << "Case #" << tcase << ": " << G << std::endl;
	}

}