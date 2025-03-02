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

	// Storing the size of the allocated block in the first 4 bytes
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

	// Setting the allocated block to 0
	memset(ptr, 0, nmemb * size);

	return ptr;
}

void free(void *ptr)
{
	// Decrementing the pointer to get the size of the memory block
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
