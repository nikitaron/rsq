#include <iostream>
#include <string>
#include <vector>
#include "Header.h"

using namespace std;

int main(int argc, char* argv[])
{
	int n = 1, left, right, x, k;
	left = right = NULL;

	node* root = nullptr;
	vector <int> arr;

	while (n < argc)
	{
		if (strcmp(argv[n], "build") == 0)
		{
			n++;
			k = atoi(argv[n++]);
			for (int i = 0; i < k; i++)
			{
				arr.push_back(atoi(argv[n++]));

			}
			root = build(arr, 0, k - 1);
		}

		else if (strcmp(argv[n], "sum") == 0)
		{
			n++;
			left = atoi(argv[n++]);
			right = atoi(argv[n++]);
			int answer = sum(root, left, right);
			cout << answer;
		}

		else if (strcmp(argv[n], "add") == 0)
		{
			n++;
			left = atoi(argv[n++]);
			right = atoi(argv[n++]);
			x = atoi(argv[n++]);

			add(root, left, right, x);
			update(root, 0, k - 1);
		}

		else if (strcmp(argv[n], "view") == 0)
		{
			n++;
			print(root, arr.size() - 1);
			for (int i = 0; i < (arr.size() - 1) * 7; i++)
				cout << "_";
			cout << "\n";
		}
	}
}
