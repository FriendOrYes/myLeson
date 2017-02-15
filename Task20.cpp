#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>

using namespace std;


#define M_PI 3.14
//---------------------------------------------------------

struct Shape;

//---------------------------------------------------------

typedef void (*init_ptr_t)(Shape*);
typedef float (*squre_ptr_t)(Shape*);

//---------------------------------------------------------

struct Vtable
{
   squre_ptr_t squre;

};

//---------------------------------------------------------
struct Shape
{
    Vtable *pVtable;
    init_ptr_t shapeInit;
    float squreShape;
};
//---------------------------------------------------------
struct Triangle
{
    Shape pBase;
    Vtable *pVtable;
    float a;
    float b;
    float c;
};
//---------------------------------------------------------
struct Circle
{
    Shape pBase;
    float radius;
    Vtable *pVtable;
};
//---------------------------------------------------------
struct Rectangle
{
    Shape pBase;
    float weight;
    float height;
    Vtable *pVtable;

};
//---------------------------------------------------------
float TriangleSquare(Shape *thiz)
{
    cout << " Triangle Square " << endl;
    float S = 0;
    Triangle* pTrianle = (Triangle*)thiz;

    float p = (pTrianle->a + pTrianle->b + pTrianle->c)/2;
    pTrianle->pBase.squreShape = sqrt(p * (p - pTrianle->a) * (p-pTrianle->b) * (p-pTrianle->c));
    cout <<" S = " << pTrianle->pBase.squreShape << endl ;
    S += pTrianle->pBase.squreShape;

    return S;
}
//---------------------------------------------------------
float RectangleSquare(Shape *thiz)
{
    cout << " Rectangle Square " << endl;
    float S = 0;
    Rectangle* pRectangle = (Rectangle*)(thiz) ;

    pRectangle->pBase.squreShape = pRectangle->height * pRectangle->weight;
    cout <<" S = " << pRectangle->pBase.squreShape << endl ;
    S += pRectangle->pBase.squreShape;

    return S;
}
//---------------------------------------------------------
float CircleSquare(Shape *thiz)
{
    cout << " Circl Square " << endl;
    float S = 0;
    Circle* pCircle = (Circle*)(thiz);

    pCircle->pBase.squreShape = M_PI * pow(pCircle->radius,2);
    cout <<" S = " << pCircle->pBase.squreShape << endl ;
    S += pCircle->pBase.squreShape;
    return S;
}
//---------------------------------------------------------
void ShapeInit(Shape* thiz)
{
    Vtable* vptr = new Vtable;
    thiz->pVtable = vptr;
    thiz->pVtable->squre = NULL; // pure function
    cout << "I'm pure person" << endl;
    thiz->squreShape = 0;
}
//---------------------------------------------------------
void RectangleInit(Rectangle* thiz, const float& height, const float& weight)
{
        ShapeInit((Shape*)thiz);
        cout << "Rectangle Init :" << endl;
        Vtable *vptr = new Vtable;
        thiz->pVtable = vptr;
        thiz->pBase.pVtable->squre = RectangleSquare;
        thiz->height = height;
        thiz->weight = weight;
}
//---------------------------------------------------------
void CircleInit(Circle* thiz, const float& radius)
{

        ShapeInit((Shape*)thiz);
        cout << "Circl Init :" << endl;

        Vtable *vptr = new Vtable;
        thiz->pVtable = vptr;
        thiz->pBase.pVtable->squre = CircleSquare;

        thiz->radius = radius;
}
//---------------------------------------------------------
void TriangleInit(Triangle* thiz, const float& a, const float &b, const float& c)
{
        ShapeInit((Shape*)thiz);

        cout << "Triangle Init :" << endl;

        Vtable *vptr = new Vtable;
        thiz->pVtable = vptr;
        thiz->pBase.pVtable->squre = TriangleSquare;
        thiz->a = a;
        thiz->b = b;
        thiz->c = c;
}
//---------------------------------------------------------
void PrintSquereShape(Shape *sh)
{
    cout << sh->pVtable->squre(sh) <<endl;
}

void Clear(Shape** sh, const int& size)
{
    for(int i = 0; i < size; ++i)
    {
        delete sh[i];
    }
}

int main(int argc, char *argv[])
{
    const int size = 3;


    Triangle *triangl = new Triangle();
    Rectangle *rectangl = new Rectangle();
    Circle *circl = new Circle();

    TriangleInit(triangl, 2, 3, 4);
    RectangleInit(rectangl, 4, 5);
    CircleInit(circl, 10);

    Shape *sh[size] = {(Shape*)triangl,(Shape*)circl,(Shape*)rectangl};//static_cast<Shape*>

    PrintSquereShape(sh[0]);

    Clear(sh, size);

    return 0;
}
//---------------------------------------------------------
