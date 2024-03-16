#include <iostream>
#include <string>


int main()
{
	std::string input, input_key;
	std::string new_key, encrypted, decrypted;

	input = "Konstantin";
	input_key = "Ikvt";

	for (char& c : input)
		c = toupper(c);
	for (char& c : input_key)
		c = toupper(c);

	//получаем новый ключ
	for (int i = 0, j = 0; i < input.size(); i++, j++)
	{
		if (j == input_key.size())
			j = 0;

		new_key += input_key[j];
	}


	//кодирование
	for (int i = 0; i < input.size(); i++)
	{
		encrypted += ((input[i] + new_key[i]) % 26) + 'A';
	}


	//декодирование 
	for (int i = 0; i < input.size(); i++)
	{
		decrypted += (((encrypted[i] - new_key[i]) + 26) % 26) + 'A';
	}


	std::cout << "Original msg:\t"  << input << std::endl << "Key:\t" << input_key<< std::endl;
	std::cout << "Encrypted msg:\t" << encrypted << std::endl << "Decrypted msg:\t" << decrypted << std::endl;
	
}
