// FigureT3Dz5.2.D.A

#include <iostream>
#include <windows.h>

using std::cout;
using std::endl;
using std::string;

class Figure {
protected:
    int _side_count;//число сторон
    std::string  name = "фигура:\t\t ";

    //добавлено

    int a, b, c, d;//длины сторон
    int A, B, C, D;//величины углов

    Figure(int _side_count) : _side_count(_side_count) {}//конструктор с параметром

public:
    Figure() :Figure(0) {}//конструктор
    int get_sides_count() { return _side_count; }//метод для доступа к полю _side_count      
    std::string get_name() { return name; }//метод для доступа к полю name
};
//треугольник
class Triangle : public Figure {
protected:
    //убраны переменные  в фигуру
    Triangle(int a, int b, int c, int A, int B, int C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }


public:
    Triangle() :Triangle(10, 20, 30, 50, 60, 70) { name = "треугольник:"; _side_count = 3; }//Изменено - тут я ввожу что хочу где цифры...

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

    RectangularTriangle(int a, int b, int c, int A, int B) :Triangle() {
        name = "прямоугольный треугольник:";
        //изменено
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = 90;
    }

public:

    RectangularTriangle() : RectangularTriangle(10, 20, 30, 50, 60) {}//вводим все кроме угла С
};

//Равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
protected:

    IsoscelesTriangle(int a, int b, int A, int B) :Triangle() {
        name = "равнобедренный треугольник:";
        this->a = a;
        this->b = b;
        this->c = a;//изменено
        this->A = A;
        this->B = B;
        this->C = A;//изменено
    }
public:

    IsoscelesTriangle() :IsoscelesTriangle(10, 20, 50, 60) {}//вводим размеры равнобедренного тр-ка без угла С и стороны с
};

//Равносторонний треугольник
class EquilateralTriangle : public Triangle {
protected:


    EquilateralTriangle(int a) :Triangle() {
        name = "равноcторонний треугольник:";
        this->a = a;//изменено
        this->b = a;//изменено
        this->c = a;//изменено
        this->A = 60;//изменено
        this->B = A;//изменено
        this->C = A;//изменено
    }

public:
    EquilateralTriangle() :EquilateralTriangle(30) {}
};

//четырехугольник
class Quadrangle : public Figure {
protected:

    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
public:

    Quadrangle() :Quadrangle(10, 20, 30, 40, 50, 60, 70, 80) { name = "четырехугольник:"; _side_count = 4; }

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
    Parallelogram(int a, int b, int A, int B) :Quadrangle() {
        name = "параллелограмм:";
        //изменено
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
        this->A = A;
        this->B = B;
        this->C = A;
        this->D = B;
    }
public:
    Parallelogram() : Parallelogram(20, 30, 30, 40) {}
};

// прямоугольник
class _Rectangle : public Parallelogram {
protected:
    _Rectangle(int a, int b) :Parallelogram() {
        name = "прямоугольник:";
        //изменено
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
        this->A = 90;
        this->B = A;
        this->C = A;
        this->D = A;
    }
public:
    _Rectangle() : _Rectangle(10, 20) {}
};

//квадрат
class _Square : public _Rectangle {
protected:



    _Square(int a) :_Rectangle() {
        name = "квадрат:";
        //изменено 
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
    }
public:
    _Square() : _Square(20) {}
};

//ромб
class Romb : public Parallelogram {
protected:

    Romb(int a, int A, int B) :Parallelogram() {
        name = "ромб:";
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
        this->A = A;
        this->b = B;
        this->C = A;
        this->D = B;

    }

public:
    Romb() : Romb(30, 30, 40) {}
};

//Не стал функции менять - вы сказали не обязательно так как в 3м задании сделано...
//во втором задании я подумал что не надо пока виртуальные функции использовать

//прототипы функции принт
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