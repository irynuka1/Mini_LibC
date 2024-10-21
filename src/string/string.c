// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *start = destination;

	while (*source != '\0') {
		*start = *source;
		start++;
		source++;
	}

	*start = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *start = destination;

	for (size_t i = 0; i < len; i++) {
		*start = *source;
		if (*source == '\0') {
			break;
		}

		source++;
		start++;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	char *start = destination;

	while (*start != '\0') {
		start++;
	}

	while (*source != '\0') {
		*start = *source;
		start++;
		source++;
	}

	*start = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *start = destination;

	while (*start != '\0') {
		start++;
	}

	for (size_t i = 0; i < len; i++) {
		*start = *source;
		if (*source == '\0') {
			break;
		}

		source++;
		start++;
	}

	*start = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 != *str2) {
			return *str1 - *str2;
		}

		str1++;
		str2++;
	}

	if (*str1 == *str2) {
		return 0;
	} else if (*str1 == '\0') {
		return -1;
	} else {
		return 1;
	}
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	for (size_t i = 0; i < len; i++) {
		if (*str1 != *str2) {
			return *str1 - *str2;
		}

		if (*str1 == '\0') {
			return 0;
		}

		str1++;
		str2++;
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	while (*str != '\0') {
		if (*str == c) {
			return (char *)str;
		}

		str++;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	const char *start = str;

	while (*str != '\0') {
		str++;
	}

	while (str != start) {
		if (*str == c) {
			return (char *)str;
		}

		str--;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	while (*haystack != '\0') {
		const char *hay_start = haystack;
		const char *needle_start = needle;

		while (*haystack != '\0' && *haystack == *needle) {
			haystack++;
			needle++;
		}

		if (*needle == '\0') {
			return (char *)hay_start;
		}

		haystack = hay_start + 1;
		needle = needle_start;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	char *res = NULL;

	while (*haystack != '\0') {
		const char *hay_start = haystack;
		const char *needle_start = needle;

		while (*haystack != '\0' && *haystack == *needle) {
			haystack++;
			needle++;
		}

		if (*needle == '\0') {
			res = (char *)hay_start;
		}

		haystack = hay_start + 1;
		needle = needle_start;
	}

	return res;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	for (size_t i = 0; i < num; i++) {
		((char *)destination)[i] = ((char *)source)[i];
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *temp[num];

	for (size_t i = 0; i < num; i++) {
		temp[i] = ((char *)source)[i];
	}

	for (size_t i = 0; i < num; i++) {
		((char *)destination)[i] = temp[i];
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	for (size_t i = 0; i < num; i++) {
		if (((char *)ptr1)[i] != ((char *)ptr2)[i]) {
			return ((char *)ptr1)[i] - ((char *)ptr2)[i];
		}
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	for (size_t i = 0; i < num; i++) {
		((char *)source)[i] = value;
	}

	return source;
}
