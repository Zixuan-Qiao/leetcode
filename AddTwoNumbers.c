struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

	struct ListNode n1 = *l1;
	struct ListNode n2 = *l2;

	struct ListNode *l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *n3 = l3;
	n3->next = NULL;

	int sum = 0;
	int carry = 0;

	while ((n1.next != NULL) && (n2.next != NULL)) {

		sum = n1.val + n2.val + carry;
		carry = sum / 10;
		sum %= 10;

		n3->val = sum;
		n3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		n3 = n3->next;
		n3->next = NULL;

		n1 = *(n1.next);
		n2 = *(n2.next);
	}

	if ((n1.next == NULL) && (n2.next == NULL)) {
		sum = n1.val + n2.val + carry;
		carry = sum / 10;
		sum %= 10;
		n3->val = sum;
		if (carry != 0) {
			n3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
			n3 = n3->next;
			n3->val = carry;
			n3->next = NULL;
		}
	}
	else if (n1.next == NULL) {
		sum = n1.val + n2.val + carry;
		carry = sum / 10;
		sum %= 10;
		n3->val = sum;
		n3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		n2 = *(n2.next);
		copying(n3->next, n2, carry);
	}
	else {
		sum = n1.val + n2.val + carry;
		carry = sum / 10;
		sum %= 10;
		n3->val = sum;
		n3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		n1 = *(n1.next);
		copying(n3->next, n1, carry);
	}

	return l3;
}

void copying(struct ListNode *n, struct ListNode l, int carry) {
	int sum = 0;
  n->next =NULL;

	while (l.next != NULL) {

		sum = l.val + carry;
		carry = sum / 10;
		sum %= 10;

		n->val = sum;
		n->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		n = n->next;
		n->next = NULL;

		l = *(l.next);
	}

	sum = l.val + carry;
	carry = sum / 10;
	sum %= 10;
	n->val = sum;
	if (carry != 0) {
		n->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		n = n->next;
		n->val = carry;
		n->next = NULL;
	}
}