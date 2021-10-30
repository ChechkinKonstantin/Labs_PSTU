#include <iostream>
#include <ctime>
int main()
{
	std::srand(std::time(nullptr));
	int num_of_attempts, range_of_numbers;
	std::cout << "Enter number of attempts: ";
	std::cin >> num_of_attempts;
	std::cout << "Enter range of numbers: ";
	std::cin >> range_of_numbers;
	int hid_num = std::rand() % range_of_numbers + 1;
	for (int i = 0; i < num_of_attempts; i++)
	{
		int input;  
		std::cout << "Enter your number: ";
		std::cin >> input;
		if (input != hid_num)
		{
			if (input > hid_num)
			{
				std::cout << "The hidden number is less than the entered one" << std::endl;
			}
			else
			{
				std::cout << "The hidden number is greater than the entered one" << std::endl;
			}
		}
		else
		{
			std::cout << "Our congratulations, you're win!!!" << std::endl;
			exit(0);
		}
	}
	std::cout << "It's a pitty, you lose :(" << std::endl;
	std::cout << "Hidden number was " << hid_num << std::endl;
	return 0;
}

