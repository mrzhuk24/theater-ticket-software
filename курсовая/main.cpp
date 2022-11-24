#include "kursovaya.h"

void menu()
{
	cout << "   1. Показать полный список представлений" << endl;
	cout << "   2. Задать критерии" << endl;
	cout << "   3. Закрыть" << endl;
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	static int select;

	for (auto i = 0; i < 10; i++)
	{
		user.price[i] = float(utils.random_int(500, 6000));
	}

	do
	{
		cout << "Добро пожаловать! Вас приветствует театра им. Жука Матвея Романовича\n";
		cout << "Ваша персональная скидка: " << user.get_sale() << "%";
		cout << endl;

		menu();

		cout << "Выберите действие: ", cin >> select;

		switch (select)
		{
		case 1:
			for (auto i = 0; i < 10; i++)
				user.seats[i] = utils.random_int(10, 100);

			settings.show_full_perfomance_list();
			break;
		case 2:
			for (auto i = 0; i < 10; i++)
				user.seats[i] = utils.random_int(10, 100);

			settings.criteria();
			break;
		}

		if (select != 3)
			system("pause");
	}
	while (select != 3);

	return 0;
}

