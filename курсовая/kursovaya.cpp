#include "kursovaya.h"

void c_settings::set_people()
{
	int people;

	cout << "Введите кол-во билетов(мест) от 1 до 6: ", cin >> people;

	if (people >= 1 && people <= 6)
		this->search_options.people = people;
	else
	{
		cout << "Диапозон[1; 6]" << endl;
		cout << "Введите кол-во билетов(мест): ", cin >> people;
	}
}

void c_settings::set_price()
{
	float min_price, max_price;

	cout << "Введите мин. цену от 500 до 6000: ", cin >> min_price;

	if (min_price >= 500.0f && min_price <= 6000.0f)
		this->search_options.min_price = min_price;
	else
	{
		cout << "Диапозон[500; 6000]" << endl;
		cout << "Введите мин. цену: ", cin >> min_price;
	}

	cout << "Введите макс. цену от 500 до 6000: ", cin >> max_price;

	if (max_price >= 500.0f && max_price <= 6000.0f)
		this->search_options.max_price = max_price;
	else
	{
		cout << "Диапозон[500; 6000]" << endl;
		this->search_options.max_price = max_price;
	}
}

float c_settings::current_price(float price)
{
	return (user.get_sale() != 0) ? (price - (user.get_sale() * (price / 100))) * this->search_options.people : (price * this->search_options.people);
}

void c_settings::show_full_perfomance_list()
{
	const char* all_offers[10] =
	{
		"Shchelkunchik", "Prestuplenie_i_nakazanie", "Shakmati", "Princessa_circa",
		"Cuba_Libre", "Otci_i_deti", "Federico_Felini", "Bug",
		"Anatoly", "The_Walkers"
	};

	system("cls");

	for (auto i = 0; i < ARRAYSIZE(all_offers); i++)
		cout << all_offers[i] << endl;

	cout << endl;
	cout << "Выберите представление: ", cin >> user.perfomance;
	cout << endl;

	if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Shchelkunchik"))
	{
		cout << "Кол-во свободных мест: " << user.seats[0] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[0] << ": " << current_price(user.get_price(user.price[0])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Prestuplenie_i_nakazanie"))
	{
		cout << "Кол-во свободных мест: " << user.seats[1] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[1] << ": " << current_price(user.get_price(user.price[1])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Shakmati"))
	{
		cout << "Кол-во свободных мест: " << user.seats[2] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[2] << ": " << current_price(user.get_price(user.price[2])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Princessa_circa"))
	{
		cout << "Кол-во свободных мест: " << user.seats[3] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[3] << ": " << current_price(user.get_price(user.price[3])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Cuba_Libre"))
	{
		cout << "Кол-во свободных мест: " << user.seats[4] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[4] << ": " << current_price(user.get_price(user.price[4])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Otci_i_deti"))
	{
		cout << "Кол-во свободных мест: " << user.seats[5] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[5] << ": " << current_price(user.get_price(user.price[5])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Federico_Felini"))
	{
		cout << "Кол-во свободных мест: " << user.seats[6] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[6] << ": " << current_price(user.get_price(user.price[6])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Bug"))
	{
		cout << "Кол-во свободных мест: " << user.seats[7] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[7] << ": " << current_price(user.get_price(user.price[7])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Anatoly"))
	{
		cout << "Кол-во свободных мест: " << user.seats[8] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[8] << ": " << current_price(user.get_price(user.price[8])) << "рублей" << endl;
	}
	else if (user.perfomance.c_str() == "The_Walkers")
	{
		cout << "Кол-во свободных мест: " << user.seats[9] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[9] << ": " << current_price(user.get_price(user.price[9])) << "рублей" << endl;
	}
	else
	{
		system("cls");
		return;
	}

	cout << endl;
	cout << "Введите buy, чтобы купить: ", cin >> user.buy;

	if (utils.crc32(user.buy.c_str()) == utils.crc32("buy"))
	{
		user.sale += 5;
		system("cls");
		return;
	}
	else
	{
		system("cls");
		return;
	}
}

void c_settings::criteria()
{
	system("cls");

	this->set_price();

	const char* all_offers[10] =
	{
		"Shchelkunchik", "Prestuplenie_i_nakazanie", "Shakmati", "Princessa_circa",
		"Cuba_Libre", "Otci_i_deti", "Federico Felini", "Bug",
		"Anatoly", "The_Walkers"
	};

	cout << endl;
	cout << "Вам доступны: ";
	cout << endl;

	for (auto i = 0; i < ARRAYSIZE(all_offers); i++)
	{
		if (user.price[i] < this->search_options.min_price || user.price[i] > this->search_options.max_price)
			continue;

		cout << all_offers[i] << endl;
	}

	cout << endl;
	cout << "Выберите представление: ", cin >> user.perfomance;
	cout << endl;

	if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Shchelkunchik"))
	{
		cout << "Кол-во свободных мест: " << user.seats[0] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[0] << ": " << current_price(user.get_price(user.price[0])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Prestuplenie_i_nakazanie"))
	{
		cout << "Кол-во свободных мест: " << user.seats[1] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[1] << ": " << current_price(user.get_price(user.price[1])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Shakmati"))
	{
		cout << "Кол-во свободных мест: " << user.seats[2] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[2] << ": " << current_price(user.get_price(user.price[2])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Princessa_circa"))
	{
		cout << "Кол-во свободных мест: " << user.seats[3] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[3] << ": " << current_price(user.get_price(user.price[3])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Cuba_Libre"))
	{
		cout << "Кол-во свободных мест: " << user.seats[4] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[4] << ": " << current_price(user.get_price(user.price[4])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Otci_i_deti"))
	{
		cout << "Кол-во свободных мест: " << user.seats[5] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[5] << ": " << current_price(user.get_price(user.price[5])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Federico_Felini"))
	{
		cout << "Кол-во свободных мест: " << user.seats[6] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[6] << ": " << current_price(user.get_price(user.price[6])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Bug"))
	{
		cout << "Кол-во свободных мест: " << user.seats[7] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[7] << ": " << current_price(user.get_price(user.price[7])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("Anatoly"))
	{
		cout << "Кол-во свободных мест: " << user.seats[8] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[8] << ": " << current_price(user.get_price(user.price[8])) << "рублей" << endl;
	}
	else if (utils.crc32(user.perfomance.c_str()) == utils.crc32("The_Walkers"))
	{
		cout << "Кол-во свободных мест: " << user.seats[9] << endl;

		this->set_people();

		cout << "Цена чтобы сходить на " << all_offers[9] << ": " << current_price(user.get_price(user.price[9])) << "рублей" << endl;
	}
	else
	{
		system("cls");
		return;
	}

	cout << endl;
	cout << "Введите buy, чтобы купить: ", cin >> user.buy;

	if (utils.crc32(user.buy.c_str()) == utils.crc32("buy"))
	{
		user.sale += 5;

		for (int i = 0; i < 10; i++)
			user.seats[i] = 0;

		system("cls");
		return;
	}
	else
	{
		system("cls");
		return;
	}
}

float c_user::get_sale()
{
	return std::clamp(this->sale, 0.0f, 20.0f);
}

float c_user::get_price(float price)
{
	return price;
}
