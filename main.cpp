// var21
#include <iostream>
#include "rhombus.h"
#include "5-square.h"   
#include "6-square.h"   

using namespace std;

int main()
{
    int continue_flag = 1;
    while (continue_flag == 1)
    {
        cout << "Select the figure:\n";
        cout << "1) Rhombus\n";
        cout << "2) Regular Pentagon\n";
        cout << "3) Regular Hexagon\n";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter 4 vertices of the rhombus in order (A B C D):\n";
            Rhombus rhombus(cin);
            rhombus.Print(cout);
            cout << "Rhombus contains " << rhombus.VertexesNumber() << " vertices.\n";
            cout << "Area: " << rhombus.Area() << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter 5 vertices of the pentagon in order:\n";
            FiveSquere pentagon(cin);
            pentagon.Print(cout);
            cout << "Pentagon contains " << pentagon.VertexesNumber() << " vertices.\n";
            cout << "Area: " << pentagon.Area() << endl;
        }
        else if (choice == 3)
        {
            cout << "Enter 6 vertices of the hexagon in order:\n";
            SixSquere hexagon(cin);
            hexagon.Print(cout);
            cout << "Hexagon contains " << hexagon.VertexesNumber() << " vertices.\n";
            cout << "Area: " << hexagon.Area() << endl;
        }
        else
        {
            cout << "Invalid choice. Please select 1, 2, or 3.\n";
        }

        cout << "\nWant to continue? (1 for yes, 0 for no): ";
        cin >> continue_flag;
    }

    cout << "Finished.\n";
    return 0;
}