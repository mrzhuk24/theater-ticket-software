#pragma once

#include <string>
#include <iostream>
#include <windows.h>
#include <algorithm>

using namespace std;

class c_settings
{
public:
	// Set param
	void set_people();
	void set_price();	

	void show_full_perfomance_list();
	void criteria();
private:
	float current_price(float price);

	struct
	{
		int people = 1;

		float min_price = 500.0f; // мин. цена задается в рублях 
		float max_price = 6000.0f; // макс. цена задается в рублях 
	}
	search_options;
};

inline c_settings settings;

class c_user
{
public:
	string buy = "";
	string perfomance = "";
	int seats[10];

	float sale = 0;
	float price[10];

	float get_sale();
	float get_price(float price);
};

inline c_user user;

class c_utils
{
public:
	constexpr uint32_t crc32(const char* str)
	{
		uint32_t crc = ~0;

		while (*str)
		{
			crc ^= *str++;

			for (uint8_t i = 0; i < 8; i++)
				crc = ((crc & 1) ? (crc >> 1) ^ 0xEDB88320 : (crc >> 1));
		}

		return crc;
	}

	int random_int(int min, int max)
	{
		return min + rand() % (max - min);
	}
};

inline c_utils utils;