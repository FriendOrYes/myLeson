#include <iostream>


#define _USE_MATH_DEFINES

#include <cmath>

using namespace std;


//----------------------------------------------
//------------Class--Shape----------------------

class Shape
{
protected:
    float m_squereShape;
    float m_perimetr;
    float m_x;
    float m_y;
public:
    Shape();
    Shape(float, float);
    virtual ~Shape();
    virtual float Squere() = 0;//pure function
    virtual float Perimetr() = 0;

};
Shape::Shape()
    :m_squereShape(-1)
    ,m_perimetr(-1)
{
    cout << " Shape() " << endl;
}

Shape::Shape(float x, float y)
    :m_squereShape(-1)
    ,m_perimetr(-1)
    ,m_x(x)
    ,m_y(y)
{
    cout << " Shape(float, float) " << endl;
}

Shape::~Shape()
{
    cout << " ~Shape " << endl;
}
//----------------------------------------------
//------------Class---Rectangle-----------------

class Rectangle : public Shape
{
    float m_height;
    float m_weight;

public:
    Rectangle();

    Rectangle(float , float , float x, float y);


    ~Rectangle() override;

    float Squere() override;//
    float Perimetr() override;
};

Rectangle::Rectangle()
    : m_height(0)
    , m_weight(0)
{
    cout << "Rectangle " << endl;
}

Rectangle::Rectangle(float h, float w, float x, float y)
    : Shape(x,y)
    , m_height(h)
    , m_weight(w)
{
    cout << "Rectangle(float , float )" << endl;

}

Rectangle::~Rectangle()
{
    cout << "~Rectangle " << endl;
}

float Rectangle::Perimetr()
{
    m_perimetr = 2 * (m_weight + m_height);
    return m_perimetr;
}

float Rectangle::Squere()
{
    cout << "Rectangle Squere - ";
    m_squereShape = m_weight * m_height;
    return m_squereShape;
}

//----------------------------------------------
//-------------Class---Triangle-----------------

class Triangle : public Shape
{
    float m_a;
    float m_b;
    float m_c;

public:

    Triangle();

    Triangle(float , float , float , float x, float y);

    ~Triangle();

    float Squere() override;//
    float Perimetr() override;
};

Triangle::Triangle()
    : m_a(0)
    , m_b(0)
    , m_c(0)
{
    cout << "Triangle() " << endl;
}



Triangle::Triangle(float a, float b, float c, float x, float y)
    :Shape(x,y)
    , m_a(a)
    , m_b(b)
    , m_c(c)
{
    cout << "Triangle(float , float , float  )" << endl;
}

float Triangle::Perimetr()
{
    m_perimetr = m_a + m_b + m_c;
    return m_perimetr;
}

Triangle::~Triangle()
{
    cout << "~Triangle" << endl;
}

float Triangle::Squere()
{
    cout << "Triangle squere - ";
    if(m_perimetr == -1)
    {
        Perimetr();
    }

    float p = m_perimetr / 2;

    m_squereShape = sqrt(p * ( p - m_a) * (p - m_b) * (p - m_b));

    m_squereShape = sqrt(p * (p - m_a) * (p - m_b) * (p - m_b));


    return m_squereShape;
}

//----------------------------------------------
//--------------Class--Circle-------------------

class Circle :public Shape
{
    float m_radius;

public:
    Circle();
    Circle(float, float x, float y);
    ~Circle();
    float Squere() override;//
    float Perimetr() override;
};

Circle::Circle()
    : m_radius(0)
{
    cout << "Circle ()" << endl;
}

Circle::Circle(float r ,float x, float y )
    : Shape(x,y)
    , m_radius(r)
{
    cout << "Circle(float )" << endl;
}

Circle::~Circle()
{
    cout << "~Circle"<<endl;
}

float Circle::Perimetr()
{
    m_perimetr = 2 * M_PI * m_radius;
    return m_perimetr;
}

float Circle::Squere()
{
    cout << "Circle squere - " ;
    m_squereShape = M_PI * pow(m_radius, 2);
    return m_squereShape;
}

//----------------------------------------------
//----------------------------------------------



void PrintSquerOfShape(Shape** sh, const int size)
{
    for(int i = 0; i < size; ++i)
    {
        cout << sh[i]->Squere() << endl;
    }
}
//------------------------------------------------------
void FreeMemory(Shape **sh,const int size)
{
    for(int i = 0; i < size; ++i)
    {
        delete sh[i];
    }
}
//-------------------------------------------------------

int main(int argc, char *argv[])
{
    const int size = 3;

    Rectangle *rectanObj = new Rectangle(2,3,32,11);
    Triangle  *trianObj  = new Triangle(3,4,5,42,44);
    Circle    *cirleObj  = new Circle(5,32,32);


    Shape *sh[size] = {rectanObj,trianObj,cirleObj};

    PrintSquerOfShape(sh,size);

    FreeMemory(sh,size);


    return 0;
}
