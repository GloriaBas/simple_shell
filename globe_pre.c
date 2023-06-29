#include "shell.h"

/**
 * add_node: Adds a new node at beginning of the linked list
 * @head: double pointer to the list_t list
 * @str: string to store in the list
 * Return: the address of the new element, or NULL if it fails
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	size_t lenght;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);

	for (lenght = 0; str[lenght]; lenght++)
		;

	new->len = lenght;
	new->next = *head;
	*head = new;

	return (*head);
}

/**
 * add_node_end - Add a new node at the end of a linked list
 * @head: beginning of the list
 * @str: String to be added
 * Return: Address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	size_t lenght;
	list_t *temp;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);

	for (lenght = 0; str[lenght]; lenght++)
		;
	new->len = lenght;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (*head);
}

/**
 * print_list_str - prints only the string element of a list_t linked list
 * @head: pointer to the first node
 * Return: size of list
 */

size_t print_list_str(const list_t *head)
{
	size_t g = 0;

	while (head)
	{
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		g++;
	}
	return (g);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 * Return: 1 on success, 0 on failure
 */

int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *fmr_node;
	unsigned int g = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (g == index)
		{
			fmr_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		g++;
		fmr_node = node;
		node = node->next;
	}
	return (0);
}
/**
 * free_list - A function that frees a list linked list
 * @head: Beginning of the list
 * Return: nothing
 */

void free_list(list_t *head)
{
	list_t *current;

	while ((current = head) != NULL)
	{
		head = head->next;
		free(current->str);
		free(current);
	}
}

