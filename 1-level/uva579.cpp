#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main() {
	int h, m;

	double frac_hora = (1.0 / 12.0);
	double frac_minuto = (1.0 / 60.0);

	while (scanf("%d:%02d", &h, &m) != EOF && (h || m)) {
		// posicion absoluta de cada uno
		double anglemin = 360.0*(frac_minuto*m);
		// para la hora es el angulo de la hora + (angulo entre horas)*frac_min*m
		double anglehora = 360.0*frac_hora*h + (360 * frac_hora)*frac_minuto*m;

		double ans = abs(anglemin - anglehora);

		if (ans > 180.0) ans = 360.0 - ans;

		printf("%.3lf\n", ans);
	}
}