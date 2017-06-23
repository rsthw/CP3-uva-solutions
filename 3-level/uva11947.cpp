#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

struct Date {
	int d, m, y;
};

int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Calendar {
public:
	static bool isLeapYear(int year) {
		return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	}
	static int monthDays(Date date) {
		if (date.m < 1 || date.m > 12) return 0;
		if (date.m != 2) return months[date.m - 1];
		if (isLeapYear(date.y)) {
			return 29;
		}
		else {
			return 28;
		}
	}
	static void moveDays(Date &date, int days) {
		// incrementar el dia e irlo disminuyendo
		date.d += days;
		while (date.d > monthDays(date)) {
			date.d -= monthDays(date);
			date.m++;
			if (date.m > 12) {
				date.m = 1;
				date.y++;
			}
		}
	}
	static bool fechaMenorOIgualSinAnio(Date menor, Date mayor) {
		if (menor.m != mayor.m) return menor.m < mayor.m;
		return menor.d <= mayor.d;
	}
};

string zodiacNames[] = { "capricorn", "aquarius", "pisces", "aries", "taurus", "gemini", "cancer", "leo", "virgo", "libra", "scorpio", "sagittarius", "capricorn" };
Date fechasFinales[13];

void init() {
	fechasFinales[0].m = 1;
	fechasFinales[0].d = 20;

	fechasFinales[1].m = 2;
	fechasFinales[1].d = 19;
	
	fechasFinales[2].m = 3;
	fechasFinales[2].d = 20;

	fechasFinales[3].m = 4;
	fechasFinales[3].d = 20;

	fechasFinales[4].m = 5;
	fechasFinales[4].d = 21;

	fechasFinales[5].m = 6;
	fechasFinales[5].d = 21;

	fechasFinales[6].m = 7;
	fechasFinales[6].d = 22;

	fechasFinales[7].m = 8;
	fechasFinales[7].d = 21;

	fechasFinales[8].m = 9;
	fechasFinales[8].d = 23;

	fechasFinales[9].m = 10;
	fechasFinales[9].d = 23;

	fechasFinales[10].m = 11;
	fechasFinales[10].d = 22;

	fechasFinales[11].m = 12;
	fechasFinales[11].d = 22;

	fechasFinales[12].m = 12;
	fechasFinales[12].d = 31;
}

int main() {
	init();

	int n; scanf("%d", &n);
	for (int tc = 1; tc <= n; tc++) {
		Date sex; scanf("%02d%02d%04d", &sex.m, &sex.d, &sex.y);

		Calendar::moveDays(sex, 7*40);

		int zodiac = 0;
		for (int i = 0; i < 13; i++) {
			if (Calendar::fechaMenorOIgualSinAnio(sex, fechasFinales[i])) {
				zodiac = i; break;
			}
		}

		string zod = zodiacNames[zodiac];
		printf("%d %02d/%02d/%04d %s\n", tc, sex.m, sex.d, sex.y, zod.c_str());
	}
}