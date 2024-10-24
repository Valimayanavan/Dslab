import java.util.Scanner;

class Employee

{

String Emp_name,Mail_id,Address,Emp_id, Mobile_no;

double BP,GP,NP,DA,HRA,PF,CF;

Scanner get = new Scanner(System.in);

Employee()

{

System.out.println("Enter Name of the Employee:");

Emp_name = get.nextLine();

System.out.println("Enter Address of the Employee:");

Address = get.nextLine();

System.out.println("Enter ID of the Employee:");

Emp_id = get.nextLine();

System.out.println("Enter Mobile Number:");

Mobile_no = get.nextLine();

System.out.println("Enter E-Mail ID of the Employee :");

Mail_id = get.nextLine();

}

void display()

{

System.out.println("Employee Name: "+Emp_name);

System.out.println("Employee Address: "+Address);

System.out.println("Employee ID: "+Emp_id);

System.out.println("Employee Mobile Number: "+Mobile_no);

System.out.println("Employee E-Mail ID:"+Mail_id);

DA=BP*0.97;

HRA=BP*0.10;

PF=BP*0.12;

CF=BP*0.01;

GP=BP+DA+HRA;

NP=GP-PF-CF;

System.out.println("Basic Pay :"+BP);

System.out.println("Dearness Allowance : "+DA);

System.out.println("House Rent Allowance :"+HRA);

System.out.println("Provident Fund :"+PF);

System.out.println("Club Fund :"+CF);

System.out.println("Gross Pay :"+GP);

System.out.println("Net Pay :"+NP);

}

}class Programmer extends Employee

{

Programmer()

{

System.out.println("Enter Basic pay of the Programmer:");

BP = get.nextFloat();

}

void display()

{

System.out.println("===================");

System.out.println("Programmar PaySlip");

System.out.println("===================");

super.display();

}

}

class AssistantProfessor extends Employee

{

AssistantProfessor()

{

System.out.println("Enter Basic pay of the Assistant Professor:");

BP = get.nextFloat();

}

void display()

{

System.out.println("===========================");

System.out.println("Assistant Professor PaySlip");

System.out.println("===========================");

super.display();

}

}

class AssociateProfessor extends Employee

{

AssociateProfessor()

{

System.out.println("Enter Basic pay of the Professor:");

BP = get.nextFloat();

}

void display()

{

System.out.println("===========================");

System.out.println("Associate Professor PaySlip");

System.out.println("===========================");

super.display();

}}

class Professor extends Employee

{

Professor()

{

System.out.println("Enter Basic pay of the Professor:");

BP = get.nextFloat();

}

void display()

{

System.out.println("=================");

System.out.println("Professor PaySlip");

System.out.println("=================");

super.display();

}

}

class PaySlip

{

public static void main(String[] args)

{

char ans;

Scanner sc = new Scanner(System.in);

do

{

System.out.println("Main Menu");

System.out.println("1. Programmer \n2. Assistant Professor");

System.out.println("3. Associate Professor \n4. Professor");

System.out.println("Enter your choice: ");

int choice=sc.nextInt();

switch(choice)

{

case 1:

Programmer p=new Programmer();

p.display();

break;

case 2:

AssistantProfessor ap=new AssistantProfessor();

ap.display();

break;

case 3:

AssociateProfessor asp=new AssociateProfessor();

asp.display();

break;

case 4:Professor PR=new Professor();

PR.display();

break;

}

System.out.println("Do you want to go to Main Menu?(y/n): ");

ans=sc.next().charAt(0);

}while(ans=='y'||ans=='Y');

sc.close();

}

}
