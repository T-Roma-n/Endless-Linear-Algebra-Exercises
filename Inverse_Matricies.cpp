#include <iostream>
#include <vector>
#include <string>


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
	int mme = 4; // mme = max matrix entrie
	bool inme = true; // inme = include_negative_matrix_entries

	std::cout << "WARNING! There is not \"safety net\". Enter only a positive integer smaller than 10." << std::endl;
	std::cout << "Enter the maximum value of entries in the matrices to be found: ";
	std::cin >> mme;

	// following variables are initialised here but used inside the loop
	int det = 0;
	double inverse_det = 1;
	double c11; double c12; double c13;
	double c21; double c22; double c23;
	double c31; double c32; double c33;

	std::vector<std::vector<int>> answer;

	for (int a11 = inme*mme*(-1); a11 <= mme; a11++)
	{
		std::cout << a11 << std::endl;
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
	std::cout << "Found " << answer.size() << " matrices." << std::endl;
	if (answer.size() > 1) {
		print(answer.at(0));
		print(answer.at(static_cast<int>(answer.size())/2));
		print(answer.at(answer.size() - 1));
	}
	std::string end;
	std::cout << "Enter something and press enter to close the window. ";
	std::cin >> end;
	return 0;
}