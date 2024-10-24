import java.util.*;

abstract class Shape

{

int a,b;

abstract void PrintArea();

}

class Rectangle extends Shape

{

void PrintArea()

{

System.out.println("\t\tCalculating Area of Rectangle");

Scanner input=new Scanner(System.in);

System.out.println("Enter length: ");

a=input.nextInt();

System.out.println("Enter breadth: ");

b=input.nextInt();

int area=a*b;

System.out.println("Area of Rectangle: "+area);

}

}

class Triangle extends Shape

{

void PrintArea()

{

System.out.println("\t\tCalculating Area of Triangle");

Scanner input=new Scanner(System.in);

System.out.println("Enter height: ");

a=input.nextInt();

System.out.println("Enter breadth: ");

b=input.nextInt();

double area=0.5*a*b;

System.out.println("Area of Triangle: "+area);

}

}

class Circle extends Shape

{

void PrintArea()

{

System.out.println("\t\tCalculating Area of Circle");

Scanner input=new Scanner(System.in)
System.out.println("Enter radius: ");

a=input.nextInt();

double area=3.14*a*a;

System.out.println("Area of Circle: "+area);

}

}

class AbstractArea

{

public static void main(String[] args)

{

Shape obj;

obj=new Rectangle();

obj.PrintArea();

obj=new Triangle();

obj.PrintArea();

obj=new Circle();

obj.PrintArea();

}

}
