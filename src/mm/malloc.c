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

	ptr = mmap(0, size + sizeof(int), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);

	if (!ptr) {
		return NULL;
	}

	*((int *)ptr) = size;
	ptr++;

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
	ptr--;

	munmap(ptr, *((int *)ptr) + sizeof(int));
}

void *realloc(void *ptr, size_t size)
{
	mremap(ptr, 0, size + sizeof(int), MREMAP_MAYMOVE);

	*((int *)ptr) = size;
	ptr++;

	return ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	mremap(ptr, 0, nmemb * size + sizeof(int), MREMAP_MAYMOVE);

	*((int *)ptr) = nmemb * size;
	ptr++;

	return ptr;
}
