#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct link{
    int coeff;
    int pow;
    struct link*next;
};

struct link* poly1 =NULL,*poly2=NULL,*poly=NULL;
void create(struct link*node)
{
    char ch;
    do{
	printf("\n Enter coefficient:");
	scanf("%d",&node->coeff);
	printf("\n Enter the power: ");
	scanf("%d",&node->pow);
	node->next =(struct link*)malloc(sizeof(struct link));
	node =node->next;
	printf("\n Continue(y/n):");
	ch = getch();
    }while(ch =='Y'||ch == 'y');
}
void display(struct link* node){
    while(node->next!=NULL)
    {
	printf("%dX^%d",node->coeff,node->pow);
	node =node->next;
	if(node->next!=NULL)
	{
	    printf(" + ");
	}
    }
}

void polyadd(struct link* poly1,struct link* poly2,struct link* poly)
{
    while(poly1->next&&poly2->next){
    if(poly1->pow > poly2->pow)
    {
	poly->pow =poly2->pow;
	poly->coeff = poly1->coeff;
	poly1 = poly1->next;
    }
    else if(poly1->pow<poly2->pow)
    {
	poly->pow = poly2->pow;
	poly->coeff = poly2->coeff;
	poly2 = poly2->next;
    }
    else{
	poly->pow = poly1->pow;
	poly->coeff = poly1->coeff + poly2->coeff;
	poly1 = poly1->next;
	poly2 =poly2->next;
    }
    poly->next =(struct link*)malloc(sizeof(struct link));
    poly = poly->next;
    poly->next =NULL;
}
while(poly1->next||poly2->next)
{
    if(poly1->next)
    {
	poly->pow =poly1->pow;
	poly->coeff = poly1->coeff;
	poly1 = poly->next;
    }
    if(poly2->next)
    {
	poly->pow = poly2->pow;
	poly->coeff =poly2->coeff;
	poly2 = poly->next;
	poly->next =(struct link*)malloc(sizeof(struct link));
	poly =poly->next;
	poly->next =NULL;

    }
}
}

void main()
{
    poly1 =(struct link*)malloc(sizeof(struct link));
    poly2 =(struct link*)malloc(sizeof(struct link));
    poly =(struct link*)malloc(sizeof(struct link));
    clrscr();
    printf("\n Enter the first polynomial: ");
    create(poly1);
    printf("\n Enter the second polynomial: ");
    create(poly2);
    printf("\n First polynomial: ");
    display(poly1);
    printf("\n Second polynomial: ");
    display(poly2);
    polyadd(poly1,poly2,poly);
    printf("\n Addition of two polynomial:");
    display(poly);
    getch();
}