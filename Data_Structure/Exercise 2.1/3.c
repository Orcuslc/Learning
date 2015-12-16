bool is_loop(Node h)
{
	Node fast = h;
	Node slow = h;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			break;
		}
	}
	if (fast == NULL || fast->next == NULL)
		return false;
	else return true;
}

Node* find_entrance(Node h)
{
	Node fast = h;
	Node slow = h;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			break;
		}
	}
	if (fast == NULL || fast->next == NULL)
		return NULL;
	slow = h;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
