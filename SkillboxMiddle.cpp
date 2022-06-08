#include <iostream>
#include <cmath>
using namespace std;

class Vector
{
public:
    Vector()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    Vector(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    operator float()
    {
        return sqrt(x * x + y * y + z * z);
    }

    friend istream& operator>>(istream& in, Vector& v);

    friend Vector operator+(const Vector& a, const Vector& b);

    friend ostream& operator<<(ostream& out, const Vector& v);

    friend bool operator>(const Vector& a, const Vector& b);

    friend float operator*(const Vector& a, const Vector& b);

    float operator[](int index)
    {
        switch (index)
        {
        case 0:
            return x;
            break;
        case 1:
            return y;
            break;
        case 2:
            return z;
            break;
        default:
            cout << "Index Error!!";
            return 0;
            break;
        }
    }

private:
    float x;
    float y;
    float z;

};

float operator*(const Vector& a, const Vector& b)
{
    return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

istream& operator>>(istream& in, Vector& v)
{
    in >> v.x >> v.y >> v.z;
    return in;
}

bool operator>(const Vector& a, const Vector& b)
{
    return false;
}

Vector operator+(const Vector& a, const Vector& b)
{
    return Vector (a.x + b.x, a.y + b.y, a.z + b.z);
}

ostream& operator<<(ostream& out, const Vector& v)
{
    out << v.x << v.y << v.z;
    return out;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Vector v3;
    cin >> v3;
    cout << "Вы ввели: " << v3 << endl;

    Vector v1(0, 1, 2);
    Vector v2(3, 4, 5);
    
    cout << v1 * v2 << endl;

}
