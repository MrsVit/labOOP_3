#include "rhombus.h"
#include "5-square.h"   
#include "6-square.h"   
#include "array.h"

#include <iostream>
#include <limits>
// <memory> не нужен — убран

int main() {
    Array figures;
    int choice;

    while (true) {
        std::cout << "\n1. Add Rhombus\n"
                     "2. Add Pentagon (5-gon)\n"
                     "3. Add Hexagon (6-gon)\n"
                     "4. Print array\n"
                     "5. Print centers\n"
                     "6. Area\n"
                     "7. Remove\n"
                     "0. Exit\n"
                     "-> ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Uncorrect. Try again\n";
            continue;
        }

        switch (choice) {
            case 0:
                return 0;

            case 1: {
                Rhombus* rh = new Rhombus();
                std::cout << "Enter 4 points ";
                std::cin >> *rh;
                figures.Add(rh);
                std::cout << "Done";
                break;
            }

            case 2: { 
                Fivesquere* pent = new Fivesquere();  // имя без изменений
                std::cout << "Enter 5 points of pentagon (x y): ";
                std::cin >> *pent;
                figures.Add(pent);
                std::cout << "Done";
                break;
            }

            case 3: { 
                Sixsquere* hex = new Sixsquere();  // имя без изменений
                std::cout << "Enter 6 points of hexagon (x y): ";
                std::cin >> *hex;
                figures.Add(hex);
                std::cout << "Done";
                break;
            }

            case 4: {
                figures.Print();
                break;
            }

            case 5: {
                figures.Centers();
                break;
            }

            case 6: {
                std::cout << "Total area: " << figures.TotalArea() << "\n";
                break;
            }

            case 7: {
                size_t idx;
                std::cout << "Index: ";
                if (std::cin >> idx) {
                    try {
                        figures.Remove(idx);
                    } catch (const std::exception& e) {
                        std::cerr << "Error: " << e.what() << "\n";
                    }
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid index.\n";
                }
                std::cout << "Done";
                break;
            }

            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}