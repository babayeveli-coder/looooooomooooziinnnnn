#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


// birinci hisse
// Funksiya: Listi random ədədlərlə doldurur
void fillListWithRandomNumbers(int lst[], int size, int min, int max) {
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        lst[i] = rand() % (max - min + 1) + min;
    }
}
//---------------------------------------------

//ikinci hisse
// Funksiya: Listi ekrana çıxarır
void printList(const int lst[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << lst[i] << " ";
    }
    cout << endl;
}
//-------------------------------------------------------

//ucuncu hisse
// Funksiya: Selection sort
void selectionSort(int lst[], int size, bool ascending) {
    for (int i = 0; i < size - 1; ++i) {
        int minMaxIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if ((ascending && lst[j] < lst[minMaxIndex]) || (!ascending && lst[j] > lst[minMaxIndex])) {
                minMaxIndex = j;
            }
        }
        int temp = lst[i];
        lst[i] = lst[minMaxIndex];
        lst[minMaxIndex] = temp;
    }
}

// Funksiya: Bubble sort
void bubbleSort(int lst[], int size, bool ascending) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if ((ascending && lst[j] > lst[j + 1]) || (!ascending && lst[j] < lst[j + 1])) {
                int temp = lst[j];
                lst[j] = lst[j + 1];
                lst[j + 1] = temp;
            }
        }
    }
}

// Funksiya: Insertion sort
void insertionSort(int lst[], int size, bool ascending) {
    for (int i = 1; i < size; ++i) {
        int key = lst[i];
        int j = i - 1;
        while (j >= 0 && ((ascending && lst[j] > key) || (!ascending && lst[j] < key))) {
            lst[j + 1] = lst[j];
            --j;
        }
        lst[j + 1] = key;
    }
}

//dorduncu hisse
// Funksiya: Elementi axtarır
int findElement(const int lst[], int size, int element) {
    for (int i = 0; i < size; ++i) {
        if (lst[i] == element) {
            return i; // Tapdıq
        }
    }
    return -1; // Tapılmadı
}


//esas hisse
void fillListWithRandomNumbers(int lst[], int size, int min, int max);
void printList(const int lst[], int size);
void selectionSort(int lst[], int size, bool ascending);
void bubbleSort(int lst[], int size, bool ascending);
void insertionSort(int lst[], int size, bool ascending);
int findElement(const int lst[], int size, int element);

int main() {
    const int size = 10;
    int myList[size];
    int min = 0;
    int max = 100;

    // Listi random ədədlərlə doldur
    fillListWithRandomNumbers(myList, size, min, max);
    cout << "Random ədədlərlə doldurulmuş list:\n";
    printList(myList, size);

    // Listi sıralamaq
    selectionSort(myList, size, true);
    cout << "Selection sort (artan):\n";
    printList(myList, size);

    // Yenidən random ədədlərlə doldur
    fillListWithRandomNumbers(myList, size, min, max);
    cout << "Yenidən random ədədlərlə doldurulmuş list:\n";
    printList(myList, size);

    // Bubble sort (azalan)
    bubbleSort(myList, size, false);
    cout << "Bubble sort (azalan):\n";
    printList(myList, size);

    // Yenidən random ədədlərlə doldur
    fillListWithRandomNumbers(myList, size, min, max);
    cout << "Yenidən random ədədlərlə doldurulmuş list:\n";
    printList(myList, size);

    // Insertion sort (artan)
    insertionSort(myList, size, true);
    cout << "Insertion sort (artan):\n";
    printList(myList, size);

    // Elementi axtarmaq
    int elementToFind = 50; // Axtarılacaq ədəd
    int index = findElement(myList, size, elementToFind);
    if (index != -1) {
        cout << elementToFind << " ədədinin indeksi: " << index << endl;
    }
    else {
        cout << elementToFind << " ədədi tapılmadı." << endl;
    }

    return 0;
}


//5 cini yaza bilmedim

