#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int coef, xexp, yexp, zexp;
    struct node *link;
};
typedef struct node *NODE;

/* Create header node */
NODE create_header()
{
    NODE h = (NODE)malloc(sizeof(struct node));
    h->link = h;
    return h;
}

/* Create new term */
NODE getnode(int c, int x, int y, int z)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->coef = c;
    temp->xexp = x;
    temp->yexp = y;
    temp->zexp = z;
    return temp;
}

/* Insert at end */
void insert_end(NODE head, int c, int x, int y, int z)
{
    NODE temp = getnode(c, x, y, z);
    NODE cur = head;

    while (cur->link != head)
        cur = cur->link;

    cur->link = temp;
    temp->link = head;
}

/* Read polynomial */
void read_poly(NODE head)
{
    int n, c, x, y, z;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter coef xexp yexp zexp: ");
        scanf("%d %d %d %d", &c, &x, &y, &z);
        insert_end(head, c, x, y, z);
    }
}

/* Display polynomial */
void display(NODE head)
{
    NODE cur = head->link;
    if (cur == head)
    {
        printf("Polynomial is empty\n");
        return;
    }

    while (cur != head)
    {
        printf("%dx^%dy^%dz^%d", cur->coef, cur->xexp, cur->yexp, cur->zexp);
        cur = cur->link;
        if (cur != head)
            printf(" + ");
    }
    printf("\n");
}

/* Evaluate polynomial */
int evaluate(NODE head)
{
    int x, y, z, sum = 0;
    NODE cur = head->link;

    printf("Enter values of x y z: ");
    scanf("%d %d %d", &x, &y, &z);

    while (cur != head)
    {
        sum += cur->coef *
               pow(x, cur->xexp) *
               pow(y, cur->yexp) *
               pow(z, cur->zexp);
        cur = cur->link;
    }
    return sum;
}

/* Add two polynomials */
NODE add_poly(NODE h1, NODE h2)
{
    NODE h3 = create_header();
    NODE a = h1->link;
    NODE b = h2->link;

    while (a != h1 && b != h2)
    {
        if (a->xexp == b->xexp &&
            a->yexp == b->yexp &&
            a->zexp == b->zexp)
        {
            insert_end(h3,
                       a->coef + b->coef,
                       a->xexp, a->yexp, a->zexp);
            a = a->link;
            b = b->link;
        }
        else
        {
            insert_end(h3, a->coef, a->xexp, a->yexp, a->zexp);
            a = a->link;
        }
    }

    while (a != h1)
    {
        insert_end(h3, a->coef, a->xexp, a->yexp, a->zexp);
        a = a->link;
    }

    while (b != h2)
    {
        insert_end(h3, b->coef, b->xexp, b->yexp, b->zexp);
        b = b->link;
    }

    return h3;
}

/* Main */
int main()
{
    NODE p1 = create_header();
    NODE p2 = create_header();
    NODE psum;
    int choice, result;

    while (1)
    {
        printf("\n--- MENU ---");
        printf("\n1. Represent & Evaluate Polynomial");
        printf("\n2. Add Two Polynomials");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            read_poly(p1);
            display(p1);
            result = evaluate(p1);
            printf("Result = %d\n", result);
            break;

        case 2:
            printf("Enter POLY1:\n");
            read_poly(p1);
            printf("Enter POLY2:\n");
            read_poly(p2);

            psum = add_poly(p1, p2);
            printf("Polynomial Sum:\n");
            display(psum);
            break;

        case 3:
            exit(0);
        }
    }
}
