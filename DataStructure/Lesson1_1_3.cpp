#include "Lesson1_1_3.h"
#include <math.h>
#include <time.h>
#include <stdio.h>

clock_t start, stop;

double duration;


int invoke()
{

	int i;
	double a[MAXN];
	for (i = 0; i < MAXN; i++)a[i] = (double)i;

	start = clock();
	for (i = 0; i < MAXK; i++)
		f1(MAXN - 1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start)) / CLK_TCK / MAXK;

	printf("ticks1 = %f\n", (double)(stop - start));
	printf("duration1 = %6.2e\n", duration);

	start = clock();

	for (i = 0; i < MAXK; i++)
		f2(MAXN - 1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start)) / CLK_TCK / MAXK;

	printf("ticks2 = %f\n", (double)(stop - start));
	printf("duration2 = %6.2e\n", duration);

	return 0;
}

double f1(int n, double a[], double x)
{
	int i;
	double p = a[0];
	for (i = 1; i <= n; i++)
		p += (a[i] * pow(x, i));
	return p;
}

double f2(int n, double a[], double x)
{
	int i;
	double p = a[n];
	for (i = n; i > 0; i--)
	{
		p = a[i - 1] + x * p;
	}
	return p;
}


#define MAXN2 100
#define MAXK2 1e7

int invoke2()
{

	int i;
	double a[MAXN2];
	for (i = 0; i < MAXN2; i++)a[i] = (double)i;

	start = clock();
	for (i = 0; i < MAXK2; i++)
		f1(MAXN - 1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start)) / CLK_TCK / MAXK2;

	printf("ticks1 = %f\n", (double)(stop - start));
	printf("duration1 = %6.2e\n", duration);

	start = clock();

	for (i = 0; i < MAXK2; i++)
		f2(MAXN - 1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start)) / CLK_TCK / MAXK2;

	printf("ticks2 = %f\n", (double)(stop - start));
	printf("duration2 = %6.2e\n", duration);

	return 0;
}


// f(x)=1+x+x^2/2+...+x^i/i+...+x^100/100
double g1(int n, double a[], double x)
{
	int i;
	double p = a[0];
	for (i = 1; i <= n; i++)
		p += (pow(x, i)/a[i]);
	return p;
}

double g2(int n, double a[], double x)
{
	int i;
	double p = 1/a[n];
	for (i = n; i > 0; i--)
	{
		p = 1 / a[i - 1] + x * p;
	}
	p = 1 + p * x;
	return p;
}
