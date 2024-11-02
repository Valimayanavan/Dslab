#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
int info;
struct node*link;
};
struct node *start =NULL;
void createlist()
{
    int n,i;
    if(start ==NULL){
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    if(n!=0)
    {
	int data;
	struct node*newnode;
	struct node*temp;
	newnode =malloc (sizeof(struct node));
	start =newnode;
	temp =start;
	printf("\n Enter number to be inserted:");
	scanf("%d",&data);
	start->info =data;
	for(i=2;i<n;i++)
	{
	    newnode=malloc(sizeof(struct node));
	    temp->link =newnode;
	    printf("\n Enter number to be inserted:");
	    scanf("%d",&data);
	    newnode->info=data;
	    temp =temp->link;
	}
    }
    printf("\n the list is created\n");
}
else
printf("\n the list is already created\n");
}
void traverse()
{
struct node*temp;
if(start==NULL)
printf("\n List is empty\n");
else{
temp=start ;
while(temp!=NULL)
{
printf("Data =%d\n",temp->info);
temp=temp->link;
}
}
getch();
}
void insertAtFront()
{
int data;
struct node* temp;
temp =malloc(sizeof(struct node));
printf("\n Enter number to be inserted");
scanf("%d",&data);
temp->info =data;
temp->link =start;
start =temp;
}

void insertAtEnd ()
{
int data;

struct node *temp, * head;
temp = malloc (sizeof(struct node));
printf ("\n Enter number to be inserted:");
scanf ("%d", &data);

temp->link =0;
temp->info = data;

head = start;
while (head->link != NULL)

head= head->link;

head->link = temp;

}

void insertAtPosition ()
{

struct node * temp, * newnode;
int pos, data, i=1;
newnode = malloc(sizeof (struct node));
printf ("\n Enter position : ");
scanf("%d",&pos);
printf ("\n Enter data : ");
scanf ("%d ", &data);
temp = start;
newnode->info = data;
newnode->link =0;
while (i<pos-1)
{
temp = temp-> link;
i++;
}
newnode->link = temp -> link;
temp->link =newnode;
}

void deleteFirst ()
{
struct node*temp;
if (start == NULL)
printf ("\n List in Emplyin");

else {
    temp = start;
    start =start ->link;
    free (temp);
}}

void deleteEnd ()
{
struct node *temp, * prevnode;

if (start ==NULL)
 printf ("\n List is Empty \n" );

else
{
temp = start;
while (temp->link != 0){

prevnode =temp;
temp = temp -> link ;

}
free (temp);
prevnode -> link =0;
}
}

void deletePosition ()
{
struct node * temp, * position;
int i=1, pos;
if (start == NULL)
printf ("\n List is empty \n");

else
{
printf (" \n Enter index");
scanf ("%d ", &pos);
position= malloc(sizeof (struct node));
temp = start;
while (i< pos-1)
{
temp =temp->link;
i++ ;
}
position = temp-> link;
temp-> link = position->link;
free (position);
}}

void Maximum ()
{
int a[10];
int i,max;
struct node * temp;

if (start == NULL)

printf ("\n List is Empty \n");
else {

temp = start;

max =temp-> info;

while (temp != NULL) {

if (max<temp->info)

max = temp-> info;
temp = temp-> link;
}
printf ("\n maximum number is: %d", max);
}
getch();
}

void mean ()
{
int a [10];
int i,sum,count;
float m;
struct node*temp;
if (start ==NULL)
 printf("\n list is empty\n");
else {
temp = start;
sum=0, count =0;

while (temp != NULL) {

sum= sum+temp->info;
temp = temp -> link;
count ++;
}

m= sum/count;
 printf (" \n Mean is %f ", m) ;
}
getch();
}

void sort ()

{

 struct node *current = start;
 struct node *index=NULL;
 int temp;

if (start ==NULL)

return;

else {
    while (current != NULL)
    {

index = current -> link;
while (index!= NULL )
{

if (current ->info > index->info)
{ temp = current -> info;
current-> info = index-> info;
index-> info = temp;
}

index = index ->link;
}
current = current-> link;
}}}

void reverseLL()
{
struct node *t1, *t2, *temp;

t1 =t2 = NULL;

if (start == NULL)

printf ("\n list is empty\n");

else

{
while (start != NULL) {

t2 = start-> link;
start -> link =t1;
t1 = start;
start=t2;

    }

start =t1;
temp = start;

printf ("\n Reverse linked list is:");
while ( temp != NULL)
{

printf ("%d", temp->info);
temp = temp->link;
}
}}

void main()
{

int choice;

while (1) {

printf ( " \n 1 To see list ");

printf ("\n 2 For insertion at starting ");
printf ("\n 3 For Insertion at End ");
printf ("\n 4 for insert at any positions");
printf ("\n 5 For delete First element ");
printf ("\n 6 For delete last element ");

printf ( "\n 7 for delete element at any position");

printf ("\n 8 For Find maximum of elements ");
printf ("\n 9 To find mean for elements ");

printf ("\n 10 To sort the elements ");

printf ("\n 11 To reverse the linked list ");

printf ("\n 12 To exit ");

printf ("\n Enter choice : ");

scanf ("%d", &choice);

switch (choice) {

case 1:

traverse();

break;

case 2:

insertAtFront ();

break;

case 3:

insertAtEnd ();

break;

case 4:

insertAtPosition ();

break;

case 5:

deleteFirst();

break;

case 6:

deleteEnd();

break;

case 7:

deletePosition ();

break;

case 8 :

Maximum ();
break;

case 9:
mean ();
break;

case 10:
sort ();
break;

case 11:

reverseLL ();
break;

case 12:

exit (1);
break;
default :
printf ("Incorrect choice \n");

}}
}
