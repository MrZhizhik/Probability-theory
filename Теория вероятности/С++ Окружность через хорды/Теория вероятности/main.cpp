#include <iostream>
#include <ctime>
#include <math.h> 
#include <stdlib.h>
using namespace std;

void hoarasort(int* a, int first, int last)
{

    int i = first, j = last;
    double tmp, x = a[(first + last) / 2];

    do {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;

        if (i <= j)
        {
            if (i < j)
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        hoarasort(a, i, last);
    if (first < j)
        hoarasort(a, first, j);
}


bool testInbound()
{
    int a = rand() % 360;
    int b = rand() % 360;
    int c = rand() % 360;
    const int n = 3;
    int s[n] = { a,b,c };
    hoarasort(s, 0, 2);
    a = s[0];
    b = s[1];
    c = s[2];
    if (((a + 180) % 360 < c && c < (b + 180) % 360) || ((b + 180) % 360 < c && c < (a + 180) % 360))
        return true;
    else
        return false;
}



int roundTest(int cnt)
{
    int hit = 0;
    for (int i = 0; i < cnt; i++) {
        hit += testInbound();
    }
    return hit;
}


int main()
{
    system("Color F0");
    setlocale(LC_ALL, "rus");
    srand(time(0));


    int cnt = 1000000;
    double total = roundTest(cnt);
    cout << endl<<"  Вероятность при " << cnt<< " повторениях равна: ";
    cout << total *100/ cnt<<"%"<<endl;

    return 0;
}