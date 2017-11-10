#include <iostream>
#include <sstream>

using namespace std;

bool create(double * & A, unsigned int resultsize) {
    bool result = true;
    string stroka;
    getline(cin, stroka);
    istringstream stream(stroka);
    unsigned int razmer = 0;
    A = new double[resultsize];
    for (int i = 0; i < resultsize; i++) {
        if (!(stream >> A[i])) {
            result = false;
            break;
        }
        razmer++;
    }
    if (resultsize > razmer) {
        result = false;
    }
    return result;
}

bool read(unsigned int &razmer) {
    string stroka;
    getline(cin, stroka);
    istringstream stream(stroka);
    bool result = true;
    if (stream >> razmer) {
    }
    else {
        result = false;
    }
    return result;
}

void sort(double * A, unsigned int razmer) {
    for (int i = 0; i < razmer / 2; i++) {
        swap(A[i], A[razmer - 1 - i]);
    }
}

void write(double * A, unsigned int razmer) {
    for (int i = 0; i < razmer; i++) {
        cout << A[i];
        if (i != razmer - 1) {
            cout << ' ';
        }
        else {
            cout << '\n';
        }
    }
}

int main()
{
    unsigned int razmer = 0;
    double * A = 0;
    if (read(razmer)) {
        if (create(A, razmer)) {
            sort(A, razmer);
            write(A, razmer);
        }
        else {
            cout << "An error has occured while reading input data.";
        }
    }
    else {
        cout << "An error has occured while reading input data.";
    }
    return 0;
}
