import java.util.Scanner;

interface Shape

{

public void PrintArea();

}

class Rectangle implements Shape

{

public void PrintArea()

{

System.out.println("\t\tCalculating Area of Rectangle");

Scanner input=new Scanner(System.in);

System.out.println("Enter length: ");

int a=input.nextInt();

System.out.print("Enter breadth: ");

int b=input.nextInt();

int area=a*b;

System.out.println("Area of Rectangle: "+area);

}

}

class Triangle implements Shape

{

public void PrintArea()

{

System.out.println("\t\tCalculating Area of Triangle");

Scanner input=new Scanner(System.in);

System.out.println("Enter height: ");

int a=input.nextInt();

System.out.println("Enter breadth: ");

int b=input.nextInt();

double area=0.5*a*b;

System.out.println("Area of Triangle: "+area);

}

}

class Circle implements Shape

{

public void PrintArea()

{

System.out.println("\t\tCalculating Area of Circle");

Scanner input=new Scanner(System.in);

System.out.print("Enter radius: ");

int a=input.nextInt();

double area=3.14*a*a;

System.out.println("Area of Circle: "+area);

}

}

public class TestArea

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
