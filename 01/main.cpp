#include <iostream>

class Calculator {
public:
	double num1;
	double num2;

	Calculator(double num1, double num2) {
		this->num1 = num1;
		this->num2 = num2;
	}
	Calculator() {
		num1 = 0.0;
		num2 = 0.0;
	}

	double add() {
		return num1 + num2;
	}

	double multiply() {
		return num1 * num2;
	}

	double subtract_1_2() {
		return num2 - num1;
	}

	double subtract_2_1() {
		return num1 - num2;
	}

	double divide_1_2() {
		return num1 / num2;
	}

	double divide_2_1() {
		return num2 / num1;
	}

	bool set_num1(double num1) {
		if (num1) {
			this->num1 = num1;
			return true;
		}
		else {
			return false;
		}
	}

	bool set_num2(double num2) {
		if (num2) {
			this->num2 = num2;
			return true;
		}
		else {
			return false;
		}
	}
};

int main(int argc, char** argv) {

	setlocale(LC_ALL, "ru");

	Calculator calc;

	do {
		std::cout << "Введите num1: ";
		std::cin >> calc.num1;

		std::cout << "Введите num2: ";
		std::cin >> calc.num2;

		if (!(calc.set_num1(calc.num1) && calc.set_num2(calc.num2))) {
			std::cout << "Неверный ввод!" << std::endl;
			if (!calc.set_num1(calc.num1)) {
				std::cout << "Введите num1: ";
				std::cin >> calc.num1;
			}
			if (!calc.set_num2(calc.num2)) {
				std::cout << "Введите num2: ";
				std::cin >> calc.num2;
			}
		}
		
		std::cout << "num1 + num2 = " << calc.add() << std::endl;
		std::cout << "num1 - num2 = " << calc.subtract_2_1() << std::endl;
		std::cout << "num2 - num1 = " << calc.subtract_1_2() << std::endl;
		std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
		std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
		std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;

	} while (true);
	

	return 0;
}