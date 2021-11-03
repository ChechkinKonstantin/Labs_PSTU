#include <iostream>
int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}

int main()
{
	int num;
	std::cout << "Enter your three digit number: ";
	std::cin >> num;
	int mas[]{num / 100, num % 100 / 10, num % 10};
	std::qsort(mas, 3, sizeof(int), compare);
	std::cout << "All possible permutation options: " << std::endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (i != j && j != k && i != k)
					std::cout << mas[i] * 100 + mas[j] * 10 + mas[k] << std::endl;
			}
		}
	}
	int max = mas[2] * 100 + mas[1] * 10 + mas[0];
	std::cout << "The maximum possible number = " << max;
	return 0;
}

