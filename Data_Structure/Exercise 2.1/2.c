void merge(Node *ha, Node *hb, Node * &c)
{
	Node *p = ha->next;
	Node *q = hb->next;
	Node *r;
	c = a;
	c->next = NULL;
	free(b);

	while(p!=NULL && q!=NULL)
	{
		if (p->value > q->value)
		{
			r = q;
			q = q->next;
			r->next = c->next;
			c->next = r;
		}
		else
		{
			r = p;
			p = p->next;
			r->next = c->next;
			c->next = r;
		}
	}
	while (p!=NULL)
	{
		r=p;
		p=p->next;
		r->next=c->next;
		c->next=r;
	}
}