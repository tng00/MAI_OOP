#include <iostream>

#include "src/array.cpp"
#include "src/hexagon.cpp"
#include "src/octagon.cpp"
#include "src/pentagon.cpp"

using namespace std;

int main() {
    cout << "Number of figures: ";
    int n;
    cin >> n;
    Array<Figure<double>*> array;

    std::cout << "p - for pentagon\nh - for hexagon\no - for octagon\n";

    char f;
    size_t side;
    for (size_t i = 0; i < n; ++i) {
        cin >> f;
        if (f == 'p') {
            std::cout << "Side length: ";
            cin >> side;
            Pentagon<double>* p = new Pentagon<double>(side);
            array.push_back(p);
        } else if (f == 'h') {
            std::cout << "Side length: ";
            cin >> side;
            Hexagon<double>* h = new Hexagon<double>(side);
            // cin >> *h.get();
            array.push_back(h);
        } else if (f == 'o') {
            std::cout << "Side length: ";
            cin >> side;
            Octagon<double>* o = new Octagon<double>(side);
            // cin >> *o.get();
            array.push_back(o);
        } else {
            throw std::logic_error("Required type of figure.");
        }
    }

    std::cout << "S - for squares\nG - for geometric centers\nP - for print figures\nD - for delete figure\nF - for finish\n";

    char q;
    cin >> q;
    while (q != 'F' && array.size() > 0) {
        if (q == 'S') {
            std::cout << "Squares:" << std::endl;
            double _sum = 0;
            for (size_t i = 0; i < array.size(); ++i) {
                cout << array[i]->area() << std::endl;
                _sum += array[i]->area();
            }
            std::cout << "Sum of squares: " << _sum << std::endl;
        } else if (q == 'G') {
            std::cout << "Geometric centers:" << std::endl;
            for (size_t i = 0; i < array.size(); ++i) {
                std::cout << array[i]->geometric_center() << std::endl;
            }
        } else if (q == 'P') {
            std::cout << "Coordinates:" << std::endl;
            for (size_t i = 0; i < array.size(); ++i) {
                std::cout << *array[i] << std::endl;
            }
        } else if (q == 'D') {
            cout << "Index: ";
            size_t index;
            cin >> index;
            array.erase(index);
            std::cout << "Deleted" << std::endl;
        }
        cin >> q;
    }

    return 0;
}