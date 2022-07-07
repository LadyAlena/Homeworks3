#include <iostream>
#include <string>


class Counter {
private:
	int i;

public:

	Counter(int i) {
		this->i = i;
	}
	Counter() {
		i = 1;
	}

	int increase() {
		return ++i;
	}

	int reduce() {
		return --i;
	}

	void show_counter() {
		std::cout << i << std::endl;
	}
};

void Options(Counter counter_example, std::string answer) {
	do {
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";

		std::getline(std::cin, answer);

		if (answer == "+") {
			counter_example.increase();
		}
		else if (answer == "-") {
			counter_example.reduce();
		}
		else if (answer == "=") {
			counter_example.show_counter();
		}
		else if (answer == "x") {
			std::cout << "До свидания!" << std::endl;
		}
		else {
			std::cout << "Некорректный ввод операции!" << std::endl;
			if (answer == "х") { std::cout << "Вводите операцию 'x' в ENG раскладке" << std::endl; }
		}

	} while (!(answer == "x"));
}

int main(int argc, char** argv) {

	system("chcp 1251");

	std::string answer;

	do {
		std::cout << "Вы хотите указать начальное значение счетчика? Введите да или нет: ";

		std::getline(std::cin, answer);

		if (answer != "да" && answer != "нет") {
			std::cout << "Некорректное сообщение!" << std::endl;
		}

	} while (answer != "да" && answer != "нет");


	if (answer == "да") {
		int i = 0;
		std::cout << "Введите начальное значение счетчика: ";
		std::cin >> i;
		while (std::cin.get() != '\n') continue;
		Counter count_with_initial_value(i);
		Options(count_with_initial_value, answer);
	}
	else {
		Counter count;
		Options(count, answer);
	}

	return 0;
}