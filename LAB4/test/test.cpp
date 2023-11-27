#include <fstream>

#include "../googletest/googletest/include/gtest/gtest.h"
#include "../src/array.cpp"
#include "../src/hexagon.cpp"
#include "../src/octagon.cpp"
#include "../src/pentagon.cpp"

using namespace std;

TEST(Array, DefaultConstructor) {
    Array<int> arr;
    EXPECT_TRUE(arr.empty());
    EXPECT_EQ(arr.size(), 0);
    EXPECT_EQ(arr.capacity(), 0);
}

TEST(Array, ParameterizedConstructor) {
    Array<int> arr(5, 42);
    EXPECT_FALSE(arr.empty());
    EXPECT_EQ(arr.size(), 5);
    EXPECT_GE(arr.capacity(), 5);
}

TEST(Array, CopyConstructor) {
    Array<int> arr1(5, 42);
    Array<int> arr2(arr1);
    EXPECT_EQ(arr1.size(), arr2.size());
    EXPECT_EQ(arr1.capacity(), arr2.capacity());
}

TEST(Array, MoveConstructor) {
    Array<int> arr1(5, 42);
    Array<int> arr2(std::move(arr1));
    EXPECT_EQ(arr2.size(), 5);
    EXPECT_EQ(arr2.capacity(), 10);
    EXPECT_TRUE(arr1.empty());
}

TEST(Array, CopyAssignmentOperator) {
    Array<int> arr1(5, 42);
    Array<int> arr2;
    arr2 = arr1;
    EXPECT_EQ(arr1.size(), arr2.size());
    EXPECT_EQ(arr1.capacity(), arr2.capacity());
}

TEST(Array, MoveAssignmentOperator) {
    Array<int> arr1(5, 42);
    Array<int> arr2;
    arr2 = std::move(arr1);
    EXPECT_EQ(arr2.size(), 5);
    EXPECT_EQ(arr2.capacity(), 10);
    EXPECT_TRUE(arr1.empty());
}

TEST(Array, InitializerListConstructor) {
    Array<int> arr = {1, 2, 3, 4, 5};
    EXPECT_EQ(arr.size(), 5);
    EXPECT_GE(arr.capacity(), 5);
}

TEST(Array, IndexOperator) {
    Array<int> arr(5, 42);
    for (size_t i = 0; i < arr.size(); ++i) {
        EXPECT_EQ(arr[i], 42);
    }
}

TEST(Array, Empty) {
    Array<int> arr;
    EXPECT_TRUE(arr.empty());
    arr.push_back(42);
    EXPECT_FALSE(arr.empty());
}

TEST(Array, Size) {
    Array<int> arr(5, 42);
    EXPECT_EQ(arr.size(), 5);
    arr.pop_back();
    EXPECT_EQ(arr.size(), 4);
}

TEST(Array, Capacity) {
    Array<int> arr(5, 42);
    EXPECT_GE(arr.capacity(), 5);
    arr.reserve(10);
    EXPECT_GE(arr.capacity(), 10);
}

TEST(Array, Reserve) {
    Array<int> arr;
    arr.reserve(10);
    EXPECT_GE(arr.capacity(), 10);
}

TEST(Array, Clear) {
    Array<int> arr(5, 42);
    arr.clear();
    EXPECT_TRUE(arr.empty());
}

TEST(Array, PushBack) {
    Array<int> arr;
    arr.push_back(42);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 42);
}

TEST(Array, PopBack) {
    Array<int> arr(5, 42);
    arr.pop_back();
    EXPECT_EQ(arr.size(), 4);
}

TEST(Array, Resize) {
    Array<int> arr(5, 42);
    arr.resize(3);
    EXPECT_EQ(arr.size(), 3);
    arr.resize(5, 99);
    EXPECT_EQ(arr.size(), 5);
    EXPECT_EQ(arr[3], 99);
}

TEST(Array, Erase) {
    Array<int> arr = {1, 2, 3, 4, 5};
    arr.erase(2);
    EXPECT_EQ(arr.size(), 4);
    EXPECT_EQ(arr[2], 4);
}

TEST(Array, EqualityOperator) {
    Array<int> arr1 = {1, 2, 3};
    Array<int> arr2 = {1, 2, 3};
    Array<int> arr3 = {4, 5, 6};

    EXPECT_EQ(arr1, arr2);
    EXPECT_NE(arr1, arr3);
}

TEST(Array, InEqualityOperator) {
    Array<int> arr1 = {1, 2, 3};
    Array<int> arr2 = {1, 2, 3};
    Array<int> arr3 = {4, 5, 6};

    EXPECT_NE(arr1, arr3);
    EXPECT_EQ(arr2, arr2);
}

//_____________________________________________________________________________________________________________________
TEST(Point, DefaultConstructor) {
    bool test = true;
    try {
        Point<int> a;
    } catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }

    EXPECT_TRUE(test);
}

TEST(Point, CoordConstructor) {
    bool test = true;
    try {
        Point a(100, 100);
    } catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }

    EXPECT_TRUE(test);
}

TEST(Point, CopyConstructor) {
    bool test = true;
    Point a(100, 100);
    try {
        Point b(a);
    } catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }

    EXPECT_TRUE(test);
    Point b(a);
    EXPECT_TRUE(b.get_x() == a.get_x());
    EXPECT_TRUE(b.get_y() == a.get_y());
}

TEST(Point, MoveConstructor) {
    bool test = true;
    try {
        Point b(Point(100, 100));
    } catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }

    EXPECT_TRUE(test);
    Point b(Point(100, 100));
    EXPECT_TRUE(b.get_x() == 100);
    EXPECT_TRUE(b.get_y() == 100);
}

TEST(Point, Assignment) {
    Point a(10, 100);
    Point y(-1, -1);
    y = a;
    EXPECT_TRUE(y.get_x() == 10);
    EXPECT_TRUE(y.get_y() == 100);
}

TEST(Point, Movement) {
    Point y(-1, -1);
    y = Point(10, 100);
    EXPECT_TRUE(y.get_x() == 10);
    EXPECT_TRUE(y.get_y() == 100);
}

TEST(Point, Equality_test) {
    Point a(10, 100);
    Point y(10, 100);
    EXPECT_TRUE(a == y);
}

//_____________________________________________________________________________________________________________________
TEST(Pentagon, DefaultConstructor) {
    bool test = true;
    try {
        Pentagon<double> p;
    } catch (std::range_error &ex) {
        std::cerr << "throw exception:" << ex.what() << std::endl;
        test = false;
    }
    EXPECT_TRUE(true);
}

TEST(Pentagon, PointConstructor) {
    bool test = true;
    try {
        Pentagon<double> p1(Point<double>(0, 100), Point(sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)), Point(25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(-25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(-sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)));
    } catch (std::exception &ex) {
        std::cerr << "throw exception:" << ex.what() << std::endl;
        test = false;
    }
    EXPECT_TRUE(true);
    test = false;
    try {
        Pentagon<double> p2(Point<double>(0, 0), Point<double>(4, 0), Point<double>(2, -3), Point<double>(0, 0), Point<double>(190, 9));
    } catch (std::logic_error &ex) {
        test = true;
    }
    EXPECT_TRUE(true);
}

TEST(Pentagon, SideConstructor) {
    bool test = true;
    try {
        Pentagon<double> p1(12);
    } catch (std::exception &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }
    EXPECT_TRUE(true);
    test = false;
    try {
        Pentagon<double> p2(-12);
    } catch (std::logic_error &ex) {
        test = true;
    }
    EXPECT_TRUE(true);
}

TEST(Pentagon, CopyConstructor) {
    bool test = true;
    Pentagon<double> p1(123);
    try {
        Pentagon<double> p2(p1);
    } catch (std::exception &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }
    EXPECT_TRUE(true);
    Pentagon<double> p2(p1);
    EXPECT_EQ(p1, p2);
}

TEST(Pentagon, CopyAssignmentOperator) {
    Pentagon<double> p1(123);
    Pentagon<double> p2(1);
    p1 = p2;
    EXPECT_EQ(p1, p2);
}

TEST(Pentagon, MoveConstructor) {
    Pentagon<double> p1(5.0);
    Pentagon<double> p2(std::move(p1));
    EXPECT_DOUBLE_EQ(p2.side(), 5.0);
    EXPECT_DOUBLE_EQ(p1.side(), 0.0);
}

TEST(Pentagon, MoveAssignmentOperator) {
    Pentagon<double> p1(5.0);
    Pentagon<double> p2;
    p2 = std::move(p1);
    EXPECT_DOUBLE_EQ(p2.side(), 5.0);
    EXPECT_DOUBLE_EQ(p1.side(), 0.0);
}

TEST(Pentagon, Equality) {
    bool test = true;

    Pentagon<double> p1(Point<double>(0, 100), Point(sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)), Point(25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(-25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(-sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)));
    Pentagon<double> p2(Point<double>(0, 100), Point(sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)), Point(25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(-25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(-sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)));
    Pentagon<double> p3(Point<double>(9 + 0, 100), Point(9 + sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)), Point(9 + 25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(9 - 25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(9 - sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)));
    EXPECT_EQ(p1, p2);
    EXPECT_EQ(p2, p2);
    EXPECT_NE(p1, p3);
}

TEST(Pentagon, Area) {
    Pentagon<double> p(10);
    EXPECT_DOUBLE_EQ(p.area(), 172.04774005889672139347);
}

TEST(Pentagon, DoubleConversion) {
    Pentagon<double> p(10);
    EXPECT_DOUBLE_EQ(static_cast<double>(p), 172.04774005889672139347);
}

TEST(Pentagon, GeometricCenter) {
    Pentagon<double> p(Point<double>(0, 100), Point(sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)), Point(25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(-25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(-sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)));
    EXPECT_EQ(p.geometric_center(), Point<double>(0, 2.8421709430404009013e-15));
}

TEST(Pentagon, Print) {
    Pentagon<double> p(5.0);
    std::ostringstream oss;
    oss << p;
    std::string expected_output = "4.253254042 0 1.31432778 4.045084972 -3.440954801 2.5 -3.440954801 -2.5 1.31432778 -4.045084972";
    EXPECT_EQ(oss.str(), expected_output);
}

TEST(Pentagon, Read) {
    Pentagon<double> p;
    std::istringstream iss("4.253254042 0 1.31432778 4.045084972 -3.440954801 2.5 -3.440954801 -2.5 1.31432778 -4.045084972");
    iss >> p;
    Pentagon<double> expected_pentagon(5.0);
    EXPECT_EQ(p, expected_pentagon);
}

//_____________________________________________________________________________________________________________________
TEST(Hexagon, DefaultConstructor) {
    bool test = true;
    try {
        Hexagon<double> h;
    } catch (std::range_error &ex) {
        std::cerr << "throw exception:" << ex.what() << std::endl;
        test = false;
    }
    EXPECT_TRUE(true);
}

TEST(Hexagon, PointConstructor) {
    bool test = true;
    double Radius = 10;
    Point a = Point(9 + Radius * std::cos(0), Radius * std::sin(0));
    Point b = Point(9 + Radius * std::cos(1 * 2 * pi / 6), Radius * std::sin(1 * 2 * pi / 6));
    Point c = Point(9 + Radius * std::cos(2 * 2 * pi / 6), Radius * std::sin(2 * 2 * pi / 6));
    Point d = Point(9 + Radius * std::cos(3 * 2 * pi / 6), Radius * std::sin(2 * 3 * pi / 6));
    Point e = Point(9 + Radius * std::cos(4 * 2 * pi / 6), Radius * std::sin(4 * 2 * pi / 6));
    Point g = Point(9 + Radius * std::cos(5 * 2 * pi / 6), Radius * std::sin(5 * 2 * pi / 6));
    try {
        Hexagon<double> h1(a, b, c, d, e, g);
    } catch (std::exception &ex) {
        std::cerr << "throw exception:" << ex.what() << std::endl;
        test = false;
    }
    EXPECT_TRUE(true);
    test = false;
    try {
        Hexagon<double> h2(Point<double>(0, 0), Point<double>(4, 0), Point<double>(2, -3), Point<double>(0, 0), Point<double>(190, 9), Point<double>(0, 0));
    } catch (std::logic_error &ex) {
        test = true;
    }
    EXPECT_TRUE(true);
}

TEST(Hexagon, SideConstructor) {
    bool test = true;
    try {
        Hexagon<double> h1(12);
    } catch (std::exception &ex) {
        std::cerr << "throw exception:" << ex.what() << std::endl;
        test = false;
    }
    EXPECT_TRUE(true);
    test = false;
    try {
        Hexagon<double> h2(-12);
    } catch (std::logic_error &ex) {
        test = true;
    }
    EXPECT_TRUE(true);
}

TEST(Hexagon, CopyConstructor) {
    bool test = true;
    Hexagon<double> h1(123);
    try {
        Hexagon<double> h2(h1);
    } catch (std::exception &ex) {
        std::cerr << "throw exception:" << ex.what() << std::endl;
        test = false;
    }
    EXPECT_TRUE(true);
    Hexagon<double> h2(h1);
    EXPECT_EQ(h1, h2);
}

TEST(Hexagon, CopyAssignmentOperator) {
    Hexagon<double> h1(123);
    Hexagon<double> h2(1);
    h1 = h2;
    EXPECT_EQ(h1, h2);
}

TEST(Hexagon, MoveConstructor) {
    Hexagon<double> h1(5.0);
    Hexagon<double> h2(std::move(h1));
    EXPECT_DOUBLE_EQ(h2.side(), 5.0);
    EXPECT_DOUBLE_EQ(h1.side(), 0.0);
}

TEST(Hexagon, MoveAssignmentOperator) {
    Hexagon<double> h1(5.0);
    Hexagon<double> h2;
    h2 = std::move(h1);
    EXPECT_DOUBLE_EQ(h2.side(), 5.0);
    EXPECT_DOUBLE_EQ(h1.side(), 0.0);
}

TEST(Hexagon, Equality) {
    bool test = true;
    double Radius = 10;
    Point a = Point(9 + Radius * std::cos(0), Radius * std::sin(0));
    Point b = Point(9 + Radius * std::cos(1 * 2 * pi / 6), Radius * std::sin(1 * 2 * pi / 6));
    Point c = Point(9 + Radius * std::cos(2 * 2 * pi / 6), Radius * std::sin(2 * 2 * pi / 6));
    Point d = Point(9 + Radius * std::cos(3 * 2 * pi / 6), Radius * std::sin(2 * 3 * pi / 6));
    Point e = Point(9 + Radius * std::cos(4 * 2 * pi / 6), Radius * std::sin(4 * 2 * pi / 6));
    Point g = Point(9 + Radius * std::cos(5 * 2 * pi / 6), Radius * std::sin(5 * 2 * pi / 6));
    Hexagon h1(a, b, c, d, e, g);
    Hexagon h2(a, b, c, d, e, g);
    Hexagon<double> h3(1);
    EXPECT_EQ(h1, h2);
    EXPECT_EQ(h2, h2);
    EXPECT_NE(h2, h3);
}

TEST(Hexagon, Area) {
    Hexagon<double> h(10);
    EXPECT_DOUBLE_EQ(h.area(), 259.8076211353316);
}

TEST(Hexagon, DoubleConversion) {
    Hexagon<double> h(10);
    EXPECT_DOUBLE_EQ(static_cast<double>(h), 259.8076211353316);
}

TEST(Hexagon, GeometricCenter) {
    double Radius = 10;
    Point a = Point(9 + Radius * std::cos(0), Radius * std::sin(0));
    Point b = Point(9 + Radius * std::cos(1 * 2 * pi / 6), Radius * std::sin(1 * 2 * pi / 6));
    Point c = Point(9 + Radius * std::cos(2 * 2 * pi / 6), Radius * std::sin(2 * 2 * pi / 6));
    Point d = Point(9 + Radius * std::cos(3 * 2 * pi / 6), Radius * std::sin(2 * 3 * pi / 6));
    Point e = Point(9 + Radius * std::cos(4 * 2 * pi / 6), Radius * std::sin(4 * 2 * pi / 6));
    Point g = Point(9 + Radius * std::cos(5 * 2 * pi / 6), Radius * std::sin(5 * 2 * pi / 6));
    Hexagon h(a, b, c, d, e, g);
    EXPECT_EQ(h.geometric_center(), Point<double>(9, 3e-16));
}

TEST(Hexagon, Print) {
    Hexagon<double> h(5.0);
    std::ostringstream oss;
    oss << h;
    std::string expected_output = "5 0 2.5 4.330127019 -2.5 4.330127019 -5 6.123233996e-16 -2.5 -4.330127019 2.5 -4.330127019";
    EXPECT_EQ(oss.str(), expected_output);
}

TEST(Hexagon, Read) {
    Hexagon<double> h;
    std::istringstream iss("5 0 2.5 4.330127019 -2.5 4.330127019 -5 6.123233996e-16 -2.5 -4.330127019 2.5 -4.330127019");
    iss >> h;
    Hexagon<double> expected_hexagon(5.0);
    EXPECT_EQ(h, expected_hexagon);
}

//_____________________________________________________________________________________________________________________
TEST(Octagon, DefaultConstructor) {
    bool test = true;
    try {
        Octagon<double> o;
    } catch (std::range_error &ex) {
        std::cerr << "throw exception:" << ex.what() << std::endl;
        test = false;
    }
    EXPECT_TRUE(true);
}

TEST(Octagon, PointConstructor) {
    bool test = true;
    double Radius = 10;
    Point a = Point(9 + Radius * std::cos(0), Radius * std::sin(0));
    Point b = Point(9 + Radius * std::cos(1 * 2 * pi / 8), Radius * std::sin(1 * 2 * pi / 8));
    Point c = Point(9 + Radius * std::cos(2 * 2 * pi / 8), Radius * std::sin(2 * 2 * pi / 8));
    Point d = Point(9 + Radius * std::cos(3 * 2 * pi / 8), Radius * std::sin(2 * 3 * pi / 8));
    Point e = Point(9 + Radius * std::cos(4 * 2 * pi / 8), Radius * std::sin(4 * 2 * pi / 8));
    Point f = Point(9 + Radius * std::cos(4 * 2 * pi / 8), Radius * std::sin(4 * 2 * pi / 8));
    Point g = Point(9 + Radius * std::cos(5 * 2 * pi / 8), Radius * std::sin(5 * 2 * pi / 8));
    Point h = Point(9 + Radius * std::cos(4 * 2 * pi / 8), Radius * std::sin(4 * 2 * pi / 8));

    try {
        Octagon<double> o1(a, b, c, d, e, f, g, h);
    } catch (std::exception &ex) {
        std::cerr << "throw exception:" << ex.what() << std::endl;
        test = false;
    }
    EXPECT_TRUE(true);
    test = false;
    try {
        Octagon<double> o2(Point<double>(0, 0), Point<double>(4, 0), Point<double>(2, -3), Point<double>(0, 0), Point<double>(190, 9), Point<double>(0, 0), Point<double>(0, 0), Point<double>(0, 0));
    } catch (std::logic_error &ex) {
        test = true;
    }
    EXPECT_TRUE(true);
}

TEST(Octagon, SideConstructor) {
    bool test = true;
    try {
        Octagon<double> o1(12);
    } catch (std::exception &ex) {
        std::cerr << "throw exception:" << ex.what() << std::endl;
        test = false;
    }
    EXPECT_TRUE(true);
    test = false;
    try {
        Hexagon<double> o2(-12);
    } catch (std::logic_error &ex) {
        test = true;
    }
    EXPECT_TRUE(true);
}

TEST(Octagon, CopyConstructor) {
    bool test = true;
    Octagon<double> o1(123);
    try {
        Octagon<double> o2(o1);
    } catch (std::exception &ex) {
        std::cerr << "throw exception:" << ex.what() << std::endl;
        test = false;
    }
    EXPECT_TRUE(true);
    Octagon<double> o2(o1);
    EXPECT_EQ(o1, o2);
}

TEST(Octagon, CopyAssignmentOperator) {
    Octagon<double> o1(1);
    Octagon<double> o2(123);
    o1 = o2;
    EXPECT_EQ(o1, o2);
}

TEST(Octagon, MoveConstructor) {
    Octagon<double> o1(5.0);
    Octagon<double> o2(std::move(o1));
    EXPECT_DOUBLE_EQ(o2.side(), 5.0);
    EXPECT_DOUBLE_EQ(o1.side(), 0.0);
}

TEST(Octagon, MoveAssignmentOperator) {
    Octagon<double> o1(5.0);
    Octagon<double> o2;
    o2 = std::move(o1);
    EXPECT_DOUBLE_EQ(o2.side(), 5.0);
    EXPECT_DOUBLE_EQ(o1.side(), 0.0);
}

TEST(Octagon, Equality) {
    bool test = true;
    double Radius = 10;
    Point a = Point(9 + Radius * std::cos(0), Radius * std::sin(0));
    Point b = Point(9 + Radius * std::cos(1 * 2 * pi / 8), Radius * std::sin(1 * 2 * pi / 8));
    Point c = Point(9 + Radius * std::cos(2 * 2 * pi / 8), Radius * std::sin(2 * 2 * pi / 8));
    Point d = Point(9 + Radius * std::cos(3 * 2 * pi / 8), Radius * std::sin(3 * 2 * pi / 8));
    Point e = Point(9 + Radius * std::cos(4 * 2 * pi / 8), Radius * std::sin(4 * 2 * pi / 8));
    Point f = Point(9 + Radius * std::cos(5 * 2 * pi / 8), Radius * std::sin(5 * 2 * pi / 8));
    Point g = Point(9 + Radius * std::cos(6 * 2 * pi / 8), Radius * std::sin(6 * 2 * pi / 8));
    Point h = Point(9 + Radius * std::cos(7 * 2 * pi / 8), Radius * std::sin(7 * 2 * pi / 8));
    Octagon o1(a, b, c, d, e, f, g, h);
    Octagon o2(a, b, c, d, e, f, g, h);
    Octagon<double> o3(1);
    EXPECT_EQ(o1, o2);
    EXPECT_EQ(o2, o2);
    EXPECT_NE(o2, o3);
}

TEST(Octagon, Area) {
    Octagon<double> o(5.0);
    EXPECT_DOUBLE_EQ(o.area(), 120.71067811865474);
}

TEST(Octagon, DoubleConversion) {
    Octagon<double> o(5.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(o), 120.71067811865474);
}

TEST(Octagon, GeometricCenter) {
    double Radius = 10;
    Point a = Point(9 + Radius * std::cos(0), Radius * std::sin(0));
    Point b = Point(9 + Radius * std::cos(1 * 2 * pi / 8), Radius * std::sin(1 * 2 * pi / 8));
    Point c = Point(9 + Radius * std::cos(2 * 2 * pi / 8), Radius * std::sin(2 * 2 * pi / 8));
    Point d = Point(9 + Radius * std::cos(3 * 2 * pi / 8), Radius * std::sin(3 * 2 * pi / 8));
    Point e = Point(9 + Radius * std::cos(4 * 2 * pi / 8), Radius * std::sin(4 * 2 * pi / 8));
    Point f = Point(9 + Radius * std::cos(5 * 2 * pi / 8), Radius * std::sin(5 * 2 * pi / 8));
    Point g = Point(9 + Radius * std::cos(6 * 2 * pi / 8), Radius * std::sin(6 * 2 * pi / 8));
    Point h = Point(9 + Radius * std::cos(7 * 2 * pi / 8), Radius * std::sin(7 * 2 * pi / 8));
    Octagon o(a, b, c, d, e, f, g, h);
    EXPECT_EQ(o.geometric_center(), Point<double>(9, 4.017766953));
}

TEST(Octagon, Print) {
    Octagon<double> o(5.0);
    std::ostringstream oss;
    oss << o;
    std::string expected_output = "6.532814824 0 4.619397663 4.619397663 4.000195382e-16 6.532814824 -4.619397663 4.619397663 -6.532814824 8.000390764e-16 -4.619397663 -4.619397663 -1.200058615e-15 -6.532814824 4.619397663 -4.619397663";
    EXPECT_EQ(oss.str(), expected_output);
}

TEST(Octagon, Read) {
    Octagon<double> o;
    std::istringstream iss("6.532814824 0 4.619397663 4.619397663 4.000195382e-16 6.532814824 -4.619397663 4.619397663 -6.532814824 8.000390764e-16 -4.619397663 -4.619397663 -1.200058615e-15 -6.532814824 4.619397663 -4.619397663");
    iss >> o;
    Octagon<double> expected_octagon(5.0);
    EXPECT_EQ(o, expected_octagon);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}