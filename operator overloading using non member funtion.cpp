#include<iostream>

using namespace std;
class example {
    int i;
    float j;
public:
    example() { i = 0; j = 0; }
    example(int x) { i = x; j = 0; }
    example(int x, float y) { i = x; j = y; }

    void showdata() {
        cout << i << "\t" << j << endl;
    }

    friend example operator*(example , example );
};
    example operator*(example e1, example e2) {
        example temp;
        temp.i = e1.i * e2.i;
        temp.j = e1.j * e2.j;
        return temp;
    }


int main() {
    example e1(10, 3.14), e2(2, 1.5), e3, e4, e5;

    cout << "Elements Entered" << endl;
    e1.showdata();
    e2.showdata();

    cout << "After the statement e3 = e1 * 2" << endl;
    e3 = e1 * 2;
    e3.showdata();

    cout << "After the statement e4 = 2 * e2" << endl;
    e4 = 2 * e2;
    e4.showdata();

    cout << "After the statement e5 = e1 * e2 * 2" << endl;
    e5 = (e1 * e2) * 2;
    e5.showdata();

    return 0;
}