#include <stdio.h>
#include <string.h>

int	count_digits(int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		count++;
	}

	return (count);
}

void reverse(char str[], int length) {
	int start = 0;
	int end = length - 1;
	while (start < end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

void intToBase(int num, int base, char result[]) {
	if (num == 0) {
		result[0] = '0';
		result[1] = '\0';
		return;
	}

	int i = 0;
	int isNegative = 0;

	if (num < 0 && base != 10) {
		isNegative = 1;
		num = -num;
	}

	while (num != 0) {
		int remainder = num % base;
		if (remainder < 10) {
			result[i++] = remainder + '0';
		} else {
			result[i++] = remainder - 10 + 'A';
		}
		num /= base;
	}

	if (isNegative) {
		result[i++] = '-';
	}

	result[i] = '\0';

	reverse(result, i);
}

int main() {
	int num = 255;
	int base = 16;
	intToBase(num, base);
	printf("Number %d in base %d: %s\n", num, base, result);

	return 0;
}
