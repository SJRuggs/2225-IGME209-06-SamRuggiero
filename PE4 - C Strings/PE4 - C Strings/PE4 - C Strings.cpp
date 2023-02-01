#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	// 2. define cstring
	char str1[21] = "supercalifragilistic";

	// 3. find length of cstring; print result to console
	cout << strlen(str1) << endl;

	// 4. define a second cstring and add it to the end of te first string; print result
	char str2[15] = "expialidocious";
	char str3[36] = "";
	strcat_s(str3, str1);
	strcat_s(str3, str2);
	cout << str3 << endl;

	// 5. find how many 'i's occur in the combined string; print result to console
	int icount = 0;
	for (int i = 0; i < sizeof(str3); i++)
	{
		if (str3[i] == 'i')
		{
			icount++;
		}
	}
	cout << icount << endl;
}