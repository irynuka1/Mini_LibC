// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *ptr;

	ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);

	if (!ptr) {
		return NULL;
	}

	return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	void *ptr;

	ptr = malloc(nmemb * size);

	if (!ptr) {
		return NULL;
	}

	memset(ptr, 0, nmemb * size);

	return ptr;
}

void free(void *ptr)
{
	
}

void *realloc(void *ptr, size_t size)
{
	void *new_ptr;

	new_ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);

	if (!new_ptr) {
		return NULL;
	}

	mremap(ptr, 0, size, new_ptr);

	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	void *new_ptr;

	new_ptr = mmap(0, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);

	if (!new_ptr) {
		return NULL;
	}

	mremap(ptr, 0, nmemb * size, new_ptr);

	return new_ptr;
}
