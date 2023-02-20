#include <iostream>
#include "Function.hpp"
#include "Matrix.hpp"
#include "brackets.hpp"
#include "queue.hpp"
#include "taxi.hpp"

int main() {
//    const size_t size = 10;
//    int arr[size]{3, 5, 778, 9, 2, 13, 234, 36, 123, 978};
//    std::cout << max(arr, size);
//    Sort(arr, size);
//    print(arr, size);
//    std::cout << BinareSearch(arr, size, 123);
//    insert(arr, size, BinareSearch(arr, size, 9), 999);
//    print(arr, size);

//    Matrix<int> m(5, 10);
//    m.fillingMatrix(1, 20);
//
//    m.print();
//    Matrix<int> mat(10, 5);
//    mat.fillingMatrix(1, 20);
//    mat.print();
//    Matrix<int> matrix = m / mat;
//    matrix.print();

//    uint p;
//    char s1[] = "({x-y-z}*[x+2y]-(z+4x));";
//    if (is_expr(s1, p))
//        std::cout << "Good." << std::endl;
//    else
//        std::cout << "Error, strpos: " << s1 + p << std::endl;
//    char s2[] = "([x-y-z}*[x+2y)-{z+4x)].";
//    if (is_expr(s2, p))
//        std::cout << "Good." << std::endl;
//    else
//        std::cout << "Error, strpos: " << s2 + p << std::endl;
//    return 0;

//    char symbol = 0;
//    Time time(12, 52, 35);
//    Users u = {"Igor", "Dombrovsky", 29, 35, &time, 15};
//    u.show();
//    Time time1(10, 24, 27);
//    Users u1 = {"Elena", "Petrova", 28, 78, &time1, 25};
//    u1.show();
//    Time time2(12, 52, 35);
//    Users u2 = {"Petro", "Trefaldo", 35, 15, &time2, 8};
//    u2.show();
//    std::cout << "Send document to printer enter [y]:" << std::endl;
//    std::cin >> symbol;
//    if (symbol == 'y') {
//        Queue<int> printer(3);
//        printer.addElement(u.getPriority());
//        printer.addElement(u1.getPriority());
//        printer.addElement(u2.getPriority());
//        printer.showQueue();
//        printer.deleteElementQueuePriority();
//        printer.showQueue();
//        printer.deleteElementQueuePriority();
//        printer.showQueue();
//        printer.deleteElementQueuePriority();
//        printer.showQueue();
//    } else {
//        std::cerr << "Error input!" << std::endl;
//    }
    
    srand(time(NULL));
    BusStop b;
    b.CreateBus(20);
    b.mainLoop();
    cout << endl<<endl;
    system("pause");


}