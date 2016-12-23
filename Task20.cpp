<<<<<<< HEAD
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
    int sizeMaseShape;
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
    int size = pTrianle[0].pBase.sizeMaseShape;
    for(int i = 0; i < size; ++i)
    {
        float p = (pTrianle[i].a + pTrianle[i].b + pTrianle[i].c)/2;
        pTrianle[i].pBase.squreShape = sqrt(p * (p - pTrianle[i].a) * (p-pTrianle[i].b) * (p-pTrianle[i].c));
        cout <<" S = " << pTrianle[i].pBase.squreShape << endl ;
        S += pTrianle[i].pBase.squreShape;
    }

    return S;
}
//---------------------------------------------------------
float RectangleSquare(Shape *thiz)
{
    cout << " Rectangle Square " << endl;
    float S = 0;
    Rectangle* pRectangle = (Rectangle*)(thiz) ;
    int size = pRectangle->pBase.sizeMaseShape;
    for(int i = 0; i < size; ++i)
    {
        pRectangle[i].pBase.squreShape = pRectangle[i].height * pRectangle[i].weight;
        cout <<" S = " << pRectangle[i].pBase.squreShape << endl ;
        S += pRectangle[i].pBase.squreShape;
    }

    return S;
}
//---------------------------------------------------------
float CircleSquare(Shape *thiz)
{
    cout << " Circl Square " << endl;
    float S;
    Circle* pCircle = (Circle*)(thiz);
    int size = pCircle->pBase.sizeMaseShape;
    for(int i = 0; i < size; ++i)
    {
        pCircle[i].pBase.squreShape = M_PI * pow(pCircle[i].radius,2);
        cout <<" S = " << pCircle[i].pBase.squreShape << endl ;
        S += pCircle[i].pBase.squreShape;
    }
    return S;
}
//---------------------------------------------------------
void ShapeInit(Shape* thiz)
{
    /* >>> VTable construction START >>> */
    Vtable* vptr = new Vtable;
    thiz->pVtable = vptr;
    thiz->pVtable->squre = NULL; // pure function
    /* <<< VTable construction END <<< */
    cout << "I'm pure person" << endl;
    thiz->sizeMaseShape = 0;
    thiz->squreShape = 0;
}
//---------------------------------------------------------
void RectangleInit(Rectangle* thiz , const int size = 1)
{
    for(int i = 0; i < size; ++i)
    {
        ShapeInit((Shape*)&thiz[i]);
        cout << "Rectangle Init :" << endl;
        /* >>> VTable construction START >>> */
        Vtable *vptr = new Vtable;
        thiz[i].pVtable = vptr;
        thiz[i].pBase.pVtable->squre = RectangleSquare;
        /* <<< VTable construction END <<< */
        thiz[i].height = 4;
        thiz[i].weight = 5;
        thiz[i].pBase.sizeMaseShape = size;
    }
}
//---------------------------------------------------------
void CircleInit(Circle* thiz , const int size = 1)
{
    for(int i = 0; i < size; ++i)
    {
        ShapeInit((Shape*)&thiz[i]);
        cout << "Circl Init :" << endl;
        /* >>> VTable construction START >>> */
        Vtable *vptr = new Vtable;
        thiz[i].pVtable = vptr;
        thiz[i].pBase.pVtable->squre = CircleSquare;
        /* <<< VTable construction END <<< */
        thiz[i].radius = 4;
        thiz[i].pBase.sizeMaseShape = size;
    }
}
//---------------------------------------------------------
void TriangleInit(Triangle* thiz , const int size = 1)
{
    for(int i = 0; i < size; ++i)
    {
        ShapeInit((Shape*)&thiz[i]);

        cout << "Triangle Init :" << endl;
        /* >>> VTable construction START >>> */

        Vtable *vptr = new Vtable;
        thiz[i].pVtable = vptr;
        thiz[i].pBase.pVtable->squre = TriangleSquare;

        /* <<< VTable construction END <<< */

        thiz[i].a = 2;
        thiz[i].b = 3;
        thiz[i].c = 4;
        thiz[i].pBase.sizeMaseShape = size;

        //cout << "size - "<<thiz->pBase.sizeMaseShape << endl ;
    }
}
//---------------------------------------------------------
void PrintSquereAllShape(Shape **sh , const int size)
{
    for(int i = 0; i < size; ++i)
    {
        cout << sh[i]->pVtable->squre(sh[i]) <<endl;
    }
}

int main(int argc, char *argv[])
{
    const int size = 3;
    int sizeOfMasTriangle , sizeOfMasRectangle , sizeOfMasCircle;
    cout << "Input size of Mas :\n";
    cin >> sizeOfMasTriangle >> sizeOfMasRectangle >> sizeOfMasCircle;

    Triangle *triangl = new Triangle[sizeOfMasTriangle];
    Rectangle *rectangl = new Rectangle[sizeOfMasRectangle];
    Circle *circl = new Circle[sizeOfMasCircle];

    TriangleInit(triangl,sizeOfMasTriangle);
    RectangleInit(rectangl,sizeOfMasRectangle);
    CircleInit(circl,sizeOfMasCircle);

    Shape *sh[size] = {(Shape*)triangl,(Shape*)circl,(Shape*)rectangl};

    PrintSquereAllShape(sh,size);

    delete []triangl;
    delete []circl;
    delete []rectangl;

    return 0;
}
//---------------------------------------------------------
=======
#include <iostream>
#include <stdio.h>
#include <string>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

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
    int sizeMaseShape;
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
    int size = pTrianle[0].pBase.sizeMaseShape;
    for(int i = 0; i < size; ++i)
    {
        float p = (pTrianle[i].a + pTrianle[i].b + pTrianle[i].c)/2;
        pTrianle[i].pBase.squreShape = sqrt(p * (p - pTrianle[i].a) * (p - pTrianle[i].b) * (p - pTrianle[i].c));
        cout <<" S = " << pTrianle[i].pBase.squreShape << endl ;
        S += pTrianle[i].pBase.squreShape;
    }

    return S;
}
//---------------------------------------------------------
float RectangleSquare(Shape *thiz)
{
    cout << " Rectangle Square " << endl;
    float S = 0;
    Rectangle* pRectangle = (Rectangle*)(thiz) ;
    int size = pRectangle->pBase.sizeMaseShape;
    for(int i = 0; i < size; ++i)
    {
        pRectangle[i].pBase.squreShape = pRectangle[i].height * pRectangle[i].weight;
        cout <<" S = " << pRectangle[i].pBase.squreShape << endl ;
        S += pRectangle[i].pBase.squreShape;
    }

    return S;
}
//---------------------------------------------------------
float CircleSquare(Shape *thiz)
{
    cout << " Circl Square " << endl;
    float S;
    Circle* pCircle = (Circle*)(thiz);
    int size = pCircle->pBase.sizeMaseShape;
    for(int i = 0; i < size; ++i)
    {
        pCircle[i].pBase.squreShape = M_PI * pow(pCircle[i].radius,2);
        cout <<" S = " << pCircle[i].pBase.squreShape << endl ;
        S += pCircle[i].pBase.squreShape;
    }
    return S;
}
//---------------------------------------------------------
void ShapeInit(Shape* thiz)
{
    /* >>> VTable construction START >>> */
    Vtable* vptr = new Vtable;
    thiz->pVtable = vptr;
    thiz->pVtable->squre = NULL; // pure function
    /* <<< VTable construction END <<< */
    cout << "I'm pure person" << endl;
    thiz->sizeMaseShape = 0;
    thiz->squreShape = 0;
}
//---------------------------------------------------------
void RectangleInit(Rectangle* thiz, const int size = 1)
{
    for(int i = 0; i < size; ++i)
    {
        ShapeInit((Shape*)&thiz[i]);
        cout << "Rectangle Init :" << endl;
        /* >>> VTable construction START >>> */
        Vtable *vptr = new Vtable;
        thiz[i].pVtable = vptr;
        thiz[i].pBase.pVtable->squre = RectangleSquare;
        /* <<< VTable construction END <<< */
        thiz[i].height = 4;
        thiz[i].weight = 5;
        thiz[i].pBase.sizeMaseShape = size;
    }
}
//---------------------------------------------------------
void CircleInit(Circle* thiz, const int size = 1)
{
    for(int i = 0; i < size; ++i)
    {
        ShapeInit((Shape*)&thiz[i]);
        cout << "Circl Init :" << endl;
        /* >>> VTable construction START >>> */
        Vtable *vptr = new Vtable;
        thiz[i].pVtable = vptr;
        thiz[i].pBase.pVtable->squre = CircleSquare;
        /* <<< VTable construction END <<< */
        thiz[i].radius = 4;
        thiz[i].pBase.sizeMaseShape = size;
    }
}
//---------------------------------------------------------
void TriangleInit(Triangle* thiz, const int size = 1)
{
    for(int i = 0; i < size; ++i)
    {
        ShapeInit((Shape*)&thiz[i]);

        cout << "Triangle Init :" << endl;
        /* >>> VTable construction START >>> */

        Vtable *vptr = new Vtable;
        thiz[i].pVtable = vptr;
        thiz[i].pBase.pVtable->squre = TriangleSquare;

        /* <<< VTable construction END <<< */

        thiz[i].a = 2;
        thiz[i].b = 3;
        thiz[i].c = 4;
        thiz[i].pBase.sizeMaseShape = size;

        //cout << "size - "<<thiz->pBase.sizeMaseShape << endl ;
    }
}
//---------------------------------------------------------
void PrintSquereAllShape(Shape **sh, const int size)
{
    for(int i = 0; i < size; ++i)
    {
        cout << sh[i]->pVtable->squre(sh[i]) <<endl;
    }
}

int main(int argc, char *argv[])
{
    const int size = 3;
    int sizeOfMasTriangle , sizeOfMasRectangle , sizeOfMasCircle;
    cout << "Input size of Mas :\n";
    cin >> sizeOfMasTriangle >> sizeOfMasRectangle >> sizeOfMasCircle;

    Triangle *triangl = new Triangle[sizeOfMasTriangle];
    Rectangle *rectangl = new Rectangle[sizeOfMasRectangle];
    Circle *circl = new Circle[sizeOfMasCircle];

    TriangleInit(triangl, sizeOfMasTriangle);
    RectangleInit(rectangl, sizeOfMasRectangle);
    CircleInit(circl, sizeOfMasCircle);

    Shape *sh[size] = {(Shape*)triangl, (Shape*)circl, (Shape*)rectangl};

    PrintSquereAllShape(sh, size);

    delete []triangl;
    delete []circl;
    delete []rectangl;

    return 0;
}
//---------------------------------------------------------
>>>>>>> 7d0067215a8658c04c8515a0ce9655caa53947e3
