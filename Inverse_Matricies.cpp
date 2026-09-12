#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>


int get_num(int min, int max){
	int entered_int = 2;
	while (true)
	{
		try{
			std::cout << "Enter an integer " << min << " to " << max << ": ";
			std::cin >> entered_int;
			if (min <= entered_int && entered_int <= max)
			{
				return entered_int;
			}
		}
		catch (...) {
			std::cout << "Please try again." << std::endl;
			continue;
		}
	}
}

void print(std::vector<int> m)
{
	std::cout << "Matrix: " << std::endl;
	std::cout << m.at(0) << "\t" << m.at(1) << "\t" << m.at(2) << "\n"
		<< m.at(3) << "\t" << m.at(4) << "\t" << m.at(5) << "\n"
		<< m.at(6) << "\t" << m.at(7) << "\t" << m.at(8) << std::endl;
	std::cout << "It's inverse: " << std::endl;
	std::cout << m.at(9) << "\t" << m.at(10) << "\t" << m.at(11) << "\n"
		<< m.at(12) << "\t" << m.at(13) << "\t" << m.at(14) << "\n"
		<< m.at(15) << "\t" << m.at(16) << "\t" << m.at(17) << std::endl;
}

int main()
{
	std::cout << "Enter the maximum value of entries in the matrices to be found." << std::endl;
	int mme = get_num(1, 6); // mme = max matrix entrie
	bool inme = true; // inme = include_negative_matrix_entries

	// following variables are initialised here but used inside the loop
	int det = 0;
	double inverse_det = 1;
	double c11; double c12; double c13;
	double c21; double c22; double c23;
	double c31; double c32; double c33;

	std::vector<std::vector<int>> answer;

	auto start = std::chrono::high_resolution_clock::now();
	for (int a11 = inme*mme*(-1); a11 <= mme; a11++)
	{
		std::cout << ".";
		for (int a12 = inme * mme * (-1); a12 <= mme; a12++)
		{
			for (int a13 = inme * mme * (-1); a13 <= mme; a13++)
			{
				for (int a21 = inme * mme * (-1); a21 <= mme; a21++)
				{
					for (int a22 = inme * mme * (-1); a22 <= mme; a22++)
					{
						for (int a23 = inme * mme * (-1); a23 <= mme; a23++)
						{
							for (int a31 = inme * mme * (-1); a31 <= mme; a31++)
							{
								for (int a32 = inme * mme * (-1); a32 <= mme; a32++)
								{
									for (int a33 = inme * mme * (-1); a33 <= mme; a33++)
									{
										det = a11 * a22 * a33 + a12 * a23 * a31 + a13 * a21 * a32 - a31 * a22 * a13 - a32 * a23 * a11 - a33 * a21 * a12;
										if (det == 0){continue;}
										inverse_det = 1 / static_cast<double>(det);
										c11 = inverse_det * (a22 * a33 - a32 * a23);
										c12 = inverse_det * (a13*a32-a33*a12);
										c13 = inverse_det * (a12 * a23 - a22 * a13);
										c21 = inverse_det * (a23*a31-a33*a21);
										c22 = inverse_det * (a11*a33-a31*a13);
										c23 = inverse_det * (a13*a21-a23*a11);
										c31 = inverse_det * (a21 * a32 - a31 * a22);
										c32 = inverse_det * (a12*a31-a32*a11);
										c33 = inverse_det * (a11*a22-a21*a12);
										if (!(c11 == static_cast<int>(c11) && c12 == static_cast<int>(c12) && c13 == static_cast<int>(c13)
											&& c21 == static_cast<int>(c21) && c22 == static_cast<int>(c22) && c23 == static_cast<int>(c23)
											&& c31 == static_cast<int>(c31) && c32 == static_cast<int>(c32) && c33 == static_cast<int>(c33)))
										{
											continue;
										}
										if (!(inme * mme * (-1) <= c11  && c11 <= mme && inme * mme * (-1) <= c12 && c12 <= mme &&
											inme * mme * (-1) <= c13 && c13 <= mme && inme * mme * (-1) <= c21 && c21 <= mme &&
											inme * mme * (-1) <= c22 && c22 <= mme && inme * mme * (-1) <= c23 && c23 <= mme &&
											inme * mme * (-1) <= c31 && c31 <= mme && inme * mme * (-1) <= c32 && c32 <= mme &&
											inme * mme * (-1) <= c33 && c33 <= mme)) {
											continue;
										}
										answer.push_back({ a11, a12, a13, a21, a22, a23, a31, a32, a33,
												static_cast<int>(c11), static_cast<int>(c12), static_cast<int>(c13),
												static_cast<int>(c21), static_cast<int>(c22), static_cast<int>(c23),
												static_cast<int>(c31), static_cast<int>(c32), static_cast<int>(c33) });
									}
								}
							}
						}
					}
				}
			}
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

	std::cout << "\nFound " << answer.size() << " matrices in " << duration.count() << " seconds." << std::endl;
	int input = 0;
	while (true)
	{
		std::cout << "Enter a number to see the corresponding matrix. Enter -1 to exit." << std::endl;
		input = get_num(-1, answer.size());
		if (input == -1)
		{
			break;
		}
		else
		{
			print(answer.at(input));
		}
	}
	return 0;
}