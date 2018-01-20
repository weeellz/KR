#include <stdio.h>

float temperature(float c);

main(){
	float c;
	printf("Vvedite gradus po celsius: ");
	scanf("%f", &c);
	printf("Celsius Fahrenheit\n");
	printf("%3.1f\t%6.1f\n", c, temperature(c));
	return 0;
}

float temperature(float celsius){
	float fahr;
	fahr = (9.0/5.0) * celsius + 32;
	return fahr;
}