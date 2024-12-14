#include "Array.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Point.h"
#include <iostream>
#include <memory>

int main() {
    Array<Figure<double>> figArray;
    int choice;

    while (true) {
        std::cout << "\n=== Menu ===\n";
        std::cout << "1. Add Trapezoid\n";
        std::cout << "2. Add Rhombus\n";
        std::cout << "3. Add Pentagon\n";
        std::cout << "4. Print All Figures\n";
        std::cout << "5. Calculate Total Area\n";
        std::cout << "6. Remove Figure by Index\n";
        std::cout << "7. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "\n--- Adding Trapezoid ---\n";
            double x1, y1, x2, y2, x3, y3, x4, y4;
            std::cout << "Enter coordinates for point 1 (x y): ";
            std::cin >> x1 >> y1;
            std::cout << "Enter coordinates for point 2 (x y): ";
            std::cin >> x2 >> y2;
            std::cout << "Enter coordinates for point 3 (x y): ";
            std::cin >> x3 >> y3;
            std::cout << "Enter coordinates for point 4 (x y): ";
            std::cin >> x4 >> y4;

            auto trapezoid = std::make_shared<Trapezoid<double>>(
                Point(x1, y1),
                Point(x2, y2),
                Point(x3, y3),
                Point(x4, y4)
            );
            figArray.addElement(trapezoid);
            std::cout << "Trapezoid added.\n";
        } else if (choice == 2) {
            std::cout << "\n--- Adding Rhombus ---\n";
            double x1, y1, x2, y2, x3, y3, x4, y4;
            std::cout << "Enter coordinates for point 1 (x y): ";
            std::cin >> x1 >> y1;
            std::cout << "Enter coordinates for point 2 (x y): ";
            std::cin >> x2 >> y2;
            std::cout << "Enter coordinates for point 3 (x y): ";
            std::cin >> x3 >> y3;
            std::cout << "Enter coordinates for point 4 (x y): ";
            std::cin >> x4 >> y4;

            auto rhombus = std::make_shared<Rhombus<double>>(
                Point(x1, y1),
                Point(x2, y2),
                Point(x3, y3),
                Point(x4, y4)
            );
            figArray.addElement(rhombus);
            std::cout << "Rhombus added.\n";
        } else if (choice == 3) {
            std::cout << "\n--- Adding Pentagon ---\n";
            double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
            std::cout << "Enter coordinates for point 1 (x y): ";
            std::cin >> x1 >> y1;
            std::cout << "Enter coordinates for point 2 (x y): ";
            std::cin >> x2 >> y2;
            std::cout << "Enter coordinates for point 3 (x y): ";
            std::cin >> x3 >> y3;
            std::cout << "Enter coordinates for point 4 (x y): ";
            std::cin >> x4 >> y4;
            std::cout << "Enter coordinates for point 5 (x y): ";
            std::cin >> x5 >> y5;

            auto pentagon = std::make_shared<Pentagon<double>>(
                Point(x1, y1),
                Point(x2, y2),
                Point(x3, y3),
                Point(x4, y4),
                Point(x5, y5)
            );
            figArray.addElement(pentagon);
            std::cout << "Pentagon added.\n";
        } else if (choice == 4) {
            std::cout << "\n--- All Figures ---\n";
            figArray.printAll();
        } else if (choice == 5) {
            std::cout << "\n--- Total Area ---\n";
            std::cout << "Total Area: " << figArray.totalArea() << "\n";
        } else if (choice == 6) {
            std::cout << "\n--- Remove Figure ---\n";
            int index;
            std::cout << "Enter index of figure to remove (starting from 0): ";
            std::cin >> index;
            figArray.removeElement(index);
            std::cout << "Figure removed.\n";
        } else if (choice == 7) {
            std::cout << "Exiting program.\n";
            break;
        }
    }

    return 0;
}
