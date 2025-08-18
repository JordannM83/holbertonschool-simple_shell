#include "shell.h"

/**
 * my_realloc - Reallocates a memory block.
 * @ptr: Pointer to the memory previously allocated.
 * @old_size: Size of the allocated space for ptr.
 * @new_size: New size for the memory block.
 * Return: Pointer to the new memory block, or NULL if failed.
 */
void *my_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;
	size_t copy_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}

	copy_size = (old_size < new_size) ? old_size : new_size;
	memcpy(new_ptr, ptr, copy_size);
	free(ptr);

	return (new_ptr);
}
