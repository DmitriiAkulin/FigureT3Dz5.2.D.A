// FigureT3Dz5.2.D.A.

#include <iostream>
#include <windows.h>

using std::cout;
using std::endl;
using std::string;


//треугольник
class Triangle {
protected:
    int a = 10, b = 20, c = 30;//длины сторон
    int A = 50, B = 60 , C = 70;//величины углов
    string name = "Треугольник: ";

    Triangle(std::string name, int a, int b, int c, int A, int B, int C) {
        this->name = name,this->a = a, this->b = b, this->c = c, this->A = A,
        this->B = B, this->C = C;}
    
public:  
   
    Triangle():Triangle("Треугольник:", 10,20,30,50,60,70) {}
    std::string get_name() { return name; }//метод для доступа к полю name
    int get_a() {return a;}
    int get_b() { return b;}
    int get_c() { return c;}
    int get_C() { return C;}
    int get_B() { return B;}
    int get_A() { return A;}
};


//прямоугольный треугольник
class RectangularTriangle: public Triangle{
protected:     
     RectangularTriangle(std::string name, int a, int b, int c, int A, int B, const int C) {
         this->name = "Прямоугольный треугольник:", this->a = a, this->b = b, this->c = c, this->A = A,
             this->B = B, this->C = 90;}
     

public:  
     
     RectangularTriangle(): RectangularTriangle("Прямоугольный треугольник:", 10, 20, 30, 50, 60, C){}
};


//Равнобедренный треугольник
class IsoscelesTriangle : public Triangle{
    public:
      
       IsoscelesTriangle():Triangle("Прямоугольный треугольник:", 10, 20, 10, 50, 60, 50){}
 };

//Равносторонний треугольник
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle() :Triangle("Равносторонний треугольник:", 30, 30, 30, 60, 60, 60) {}
};


//четырехугольник
class Quadrangle {
protected:
    string name;
    int a, b, c, d;//длины сторон
    int A, B, C, D;//величины углов

    Quadrangle(string name, int a, int b, int c, int d, int A, int B, int C, int D)
    {
        this->name = name, this->a = a, this->b = b, this->c = c, this->d = d,
            this->A = A, this->B = B, this->C = C, this->D = D;
    }
public:

    Quadrangle() :Quadrangle("Четырехугольник: ", 10, 20, 30, 40, 50, 60, 70, 80) {}

    string get_name() { return name; }
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_d() { return d; }
    int get_C() { return C; }
    int get_B() { return B; }
    int get_A() { return A; }
    int get_D() { return D; }
};





//прототипы функции принт
void Print_Info(Triangle *figure);
void Print_Info(Quadrangle *figure);

int main()
{
    setlocale(LC_ALL, "rus");
    Triangle triangle;
    Quadrangle quadrangle;
    RectangularTriangle rec_triangle;
    IsoscelesTriangle iso_triangle;
    EquilateralTriangle equi_triangle;
    Print_Info(&triangle);    
    Print_Info(&rec_triangle);
    Print_Info(&iso_triangle);
    Print_Info(&equi_triangle);
    Print_Info(&quadrangle);

    return 0;
}


//функции, реализация
void Print_Info(Triangle *figure){
    cout << figure->get_name() << endl << "Стороны: " << "а=" << (*figure).get_a() << " b=" << figure->get_b() << " c="
    << figure->get_c() << endl << "Углы:    " << "A=" << figure->get_A() << " B=" << figure->get_B() << " C=" << figure->get_C() 
    << endl << endl;
}

void Print_Info(Quadrangle *figure) {
    cout << figure->get_name() << endl << "Стороны: " << "а=" << (*figure).get_a() << " b=" << figure->get_b() << " c="
        << figure->get_c() << " d=" << figure->get_d() << endl  << "Углы:    " << "A=" << figure->get_A() 
        << " B=" << figure->get_B() << " C=" << figure->get_C() << " D="
        << figure->get_D() << endl << endl;
}


