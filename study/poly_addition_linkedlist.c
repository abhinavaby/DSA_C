
#include <stdio.h>
#include <stdlib.h>

// Structure of a polynomial node
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int coeff, int exp)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    return newNode;
}

// Function to insert a node at the end
struct Node *insert(struct Node *head, int coeff, int exp)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = createNode(coeff, exp);

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    // Move temp to the last node
    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Connect new node
    temp->next = newNode;

    return head;
}

// Function to read a polynomial from user
struct Node *readPolynomial()
{
    struct Node *head = NULL;

    int n;
    int coeff;
    int exp;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Enter terms in descending order of exponent.\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nTerm %d\n", i + 1);

        printf("Enter coefficient: ");
        scanf("%d", &coeff);

        printf("Enter exponent: ");
        scanf("%d", &exp);

        head = insert(head, coeff, exp);
    }

    return head;
}

// Function to add two polynomials
struct Node *addPolynomial(struct Node *p1, struct Node *p2)
{
    struct Node *result = NULL;

    // Continue until one polynomial ends
    while (p1 != NULL && p2 != NULL)
    {
        // Same exponent
        if (p1->exp == p2->exp)
        {
            int sum;

            sum = p1->coeff + p2->coeff;

            // Insert only if coefficient is not zero
            if (sum != 0)
            {
                result = insert(result, sum, p1->exp);
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        // p1 exponent is greater
        else if (p1->exp > p2->exp)
        {
            result = insert(result, p1->coeff, p1->exp);

            p1 = p1->next;
        }

        // p2 exponent is greater
        else
        {
            result = insert(result, p2->coeff, p2->exp);

            p2 = p2->next;
        }
    }

    // Copy remaining terms of polynomial 1
    while (p1 != NULL)
    {
        result = insert(result, p1->coeff, p1->exp);

        p1 = p1->next;
    }

    // Copy remaining terms of polynomial 2
    while (p2 != NULL)
    {
        result = insert(result, p2->coeff, p2->exp);

        p2 = p2->next;
    }

    return result;
}

// Function to display a polynomial
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("0\n");
        return;
    }

    while (head != NULL)
    {
        printf("%dx^%d", head->coeff, head->exp);

        if (head->next != NULL)
        {
            printf(" + ");
        }

        head = head->next;
    }

    printf("\n");
}

// Main function
int main()
{
    struct Node *p1 = NULL;
    struct Node *p2 = NULL;
    struct Node *result = NULL;

    printf("Enter Polynomial 1\n");
    p1 = readPolynomial();

    printf("\nEnter Polynomial 2\n");
    p2 = readPolynomial();

    printf("\nPolynomial 1: ");
    display(p1);

    printf("Polynomial 2: ");
    display(p2);

    result = addPolynomial(p1, p2);

    printf("Result: ");
    display(result);

    return 0;
}
