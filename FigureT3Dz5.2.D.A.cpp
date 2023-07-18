// FigureT3Dz5.2.D.A.
// Test5.2Figure.cpp 

#include <iostream>
#include <windows.h>

using std::cout;
using std::endl;
using std::string;

class Figure {
protected:
    int _side_count;//число сторон
    string  name = "фигура:\t\t ";

    Figure(int _side_count) : _side_count(_side_count) {}//конструктор с параметром

public:
    Figure() :Figure(0) {}//конструктор
    int get_sides_count() { return _side_count; }//метод для доступа к полю _side_count      
    std::string get_name() { return name; }//метод для доступа к полю name
};
//треугольник
class Triangle : public Figure {
protected:
    int a, b, c;//длины сторон
    int A, B, C;//величины углов     
    Triangle(int a, int b, int c, int A, int B, int C) : a(a), b(b), c(c), A(A), B(B), C(C)
    {}


public:
    Triangle() :Triangle(a = 10, b = 20, c = 30, A = 50, B = 60, C = 70) { name = "треугольник:"; _side_count = 3; }

    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_C() { return C; }
    int get_B() { return B; }
    int get_A() { return A; }
};




//прямоугольный треугольник
class RectangularTriangle : public Triangle {
protected:
    const int C_ = C = 90;
    RectangularTriangle(int a, int b, int c, int A, int B) :Triangle() { name = "прямоугольный треугольник:"; }



public:

    RectangularTriangle() : RectangularTriangle(a, b, c, A, B) {}
};

//Равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
protected:
    const int Side = c = a;
    const int Angle = C = A;

    IsoscelesTriangle(int a, int b, int A, int B) :Triangle() {
        name = "равнобедренный треугольник:";
    }
public:

    IsoscelesTriangle() :IsoscelesTriangle(a, b, A, B) {}
};

//Равносторонний треугольник
class EquilateralTriangle : public Triangle {
protected:
    const int Side = c = b = a = 30;
    const int Angle = C = B = A = 60;

    EquilateralTriangle(int a) :Triangle() {
        name = "равноcторонний треугольник:";
    }

public:
    EquilateralTriangle() :EquilateralTriangle(a) {}
};


//четырехугольник
class Quadrangle : public Figure {
protected:
    int a, b, c, d;//длины сторон
    int A, B, C, D;//величины углов

    Quadrangle(int _a, int _b, int _c, int _d, int _A, int _B, int _C, int _D) : a(_a), b(_b), c(_c), d(_d), A(_A), B(_B), C(_C),
        D(_D)
    {}
public:

    Quadrangle() :Quadrangle(a = 10, b = 20, c = 30, d = 40, A = 50, B = 60, C = 70, D = 80)
    {
        name = "четырехугольник:"; _side_count = 4;
    }
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_d() { return d; }
    int get_C() { return C; }
    int get_B() { return B; }
    int get_A() { return A; }
    int get_D() { return D; }
};
//  параллелограмм
class Parallelogram : public Quadrangle {
protected:
    int a_c = c = a = 20;
    const int b_d = d = b = 30;
    const int A_C = C = A = 30;
    const int B_D = D = B = 40;

    Parallelogram(int a, int b, int A, int B) :Quadrangle() { name = "параллелограмм:"; }
public:
    Parallelogram() : Parallelogram(a_c, b_d, A_C, B_D) {}
};

// прямоугольник
class _Rectangle : public Parallelogram {
protected:
    const int Angle = A = B = C = D = 90;
    const int a_c = c = a = 10;
    const int b_d = d = b = 20;
    _Rectangle(int a, int b, int A) :Parallelogram() {
        name = "прямоугольник:";
    }
public:

    _Rectangle() : _Rectangle(a_c, b_d, Angle) {}
};
//квадрат
class _Square : public _Rectangle {
protected:
    const int Side = d = c = b = a = 20;
    const int Angle = A = B = C = D = 90;


    _Square(int a, int A) :_Rectangle() { name = "квадрат:"; }

public:
    _Square() : _Square(Side, Angle) {}
};

//ромб
class Romb : public Parallelogram {
protected:
    const int Side = d = c = b = a = 30;
    const int A_C = C = A = 30;
    const int B_D = D = B = 40;


    Romb(int a, int A, int B) :Parallelogram() { name = "ромб:"; }

public:
    Romb() : Romb(Side, A_C, B_D) {}
};



//прототипы функции печати
void Print_Info(Triangle*);
void Print_Info(Quadrangle* figure);

int main()
{
    setlocale(LC_ALL, "rus");

    //Figure figure;  cout << figure.get_name() << figure.get_sides_count() << std::endl;

    Triangle triangle; cout << triangle.get_name() << /*"Количество сторон: " << triangle.get_sides_count() <<*/endl;
    Print_Info(&triangle);

    RectangularTriangle rec_triangle; cout << rec_triangle.get_name() << endl;
    Print_Info(&rec_triangle);

    IsoscelesTriangle iso_triangle; cout << iso_triangle.get_name() << endl;
    Print_Info(&iso_triangle);

    EquilateralTriangle equi_triangle; cout << equi_triangle.get_name() << endl;
    Print_Info(&equi_triangle);

    Quadrangle quadrangle; cout << quadrangle.get_name() <</* "Количество сторон: " << quadrangle.get_sides_count() <<*/endl;
    Print_Info(&quadrangle);

    _Rectangle rectangle; cout << rectangle.get_name() << endl;
    Print_Info(&rectangle);

    _Square squar; cout << squar.get_name() << endl;
    Print_Info(&squar);

    Parallelogram parall; cout << parall.get_name() << endl;
    Print_Info(&parall);

    Romb romb; cout << romb.get_name() << endl;
    Print_Info(&romb);

    return 0;
}


//функции, реализация
void Print_Info(Triangle* figure) {
    cout << "Стороны: " << "а=" << (*figure).get_a() << " b=" << figure->get_b() << " c="
        << figure->get_c() << endl << "Углы:    " << "A=" << figure->get_A() << " B=" << figure->get_B() << " C=" << figure->get_C()
        << endl << endl;
}

void Print_Info(Quadrangle* figure) {
    cout << "Стороны: " << "а=" << (*figure).get_a() << " b=" << figure->get_b() << " c="
        << figure->get_c() << " d=" << figure->get_d() << endl << "Углы:    " << "A=" << figure->get_A()
        << " B=" << figure->get_B() << " C=" << figure->get_C() << " D="
        << figure->get_D() << endl << endl;
}

