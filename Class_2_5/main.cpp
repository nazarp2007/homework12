#include <iostream>
#include <fstream>
#include <string>
#include "Space.h"
#include "LivingSpace.h"
#include "CommercialSpace.h"
using namespace std;

void sortBySize(Space* a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j]->getSize() > a[j + 1]->getSize())
            {
                Space* temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}

int main()
{
    const int n = 6;
    Space* a[n];
    int choice;

    do {
        cout << "1. Input information" << endl;
        cout << "2. Load information" << endl;
        cout << "3. Show all spaces" << endl;
        cout << "4. Calculate final price" << endl;
        cout << "5. Show final records" << endl;
        cout << "6. Sort by size" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 0; i < n; i++) {
                int type;
                cout << "\n1 - LivingSpace, 2 - CommercialSpace: ";
                cin >> type;
                if (type == 1)
                    a[i] = new LivingSpace();
                else
                    a[i] = new CommercialSpace();
                cin >> *a[i];
            }
            break;

        case 2: {
            ifstream fin("text.txt");
            if (!fin) {
                cout << "File corrupt\n";
                break;
            }
            for (int i = 0; i < 3; i++) {
                a[i] = new LivingSpace();
                fin >> *a[i];
            }
            for (int i = 3; i < 6; i++) {
                a[i] = new CommercialSpace();
                fin >> *a[i];
            }
            fin.close();
            cout << "Loaded " << n << " spaces from file\n";
            break;
        }

        case 3:
            for (int i = 0; i < n; i++)
                cout << *a[i] << endl;
            break;

        case 4:
            for (int i = 0; i < n; i++)
                cout << a[i]->finalPrice() << endl;
            break;

        case 5:
            for (int i = 0; i < n; i++)
                cout << a[i]->finalRecord() << endl;
            break;

        case 6:
            sortBySize(a, n);
            cout << "Spaces sorted by size.\n";
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    for (int i = 0; i < n; i++)
        delete a[i];
}