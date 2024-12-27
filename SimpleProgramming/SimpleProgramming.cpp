#include <iostream>

using namespace std;

void PrintArray(int someArray[], int arraySize)
{
    for (int i = 0; i < arraySize; ++i)
    {
        cout << someArray[i];

        if (i < arraySize - 1)
        {
            cout << ", ";
        }
    }

    cout << endl;
}

int SumAllElements(int elements[], int arraySize)
{
    int result = 0;

    for (int i = 0; i < arraySize; ++i)
    {
        result += elements[i];
    }

    return result;
}

float AverageElements(int elements[], int arraySize)
{
    float result = 0;

    result = SumAllElements(elements, arraySize);

    return result / arraySize;
}

void SortArray_Bubble(int someArray[], int arraySize, bool isAscending)
{
    if (arraySize < 2)
    {
        return;
    }

    PrintArray(someArray, arraySize);
    // 아마 버블정렬
    bool isSorted = true;

    while (isSorted)
    {
        isSorted = false;

        for (int i = 0; i < arraySize - 1; ++i)
        {
            if (isAscending && someArray[i] > someArray[i + 1] ||
                isAscending == false && someArray[i] < someArray[i + 1])
            {
                int temp = someArray[i];

                someArray[i] = someArray[i + 1];
                someArray[i + 1] = temp;

                if (isSorted == false)
                {
                    isSorted = true;
                }

                PrintArray(someArray, arraySize);
            }

            
        }
    }
}

void SortArray_Insert(int someArray[], int arraySize, bool isAscending)
{
    // 아마 삽입정렬
    if (arraySize < 2)
    {
        return;
    }

    PrintArray(someArray, arraySize);

    for (int i = 1; i < arraySize; ++i)
    {
        int index = i;

        while (index > 0)
        {
            if (isAscending && someArray[index - 1] > someArray[index] ||
                isAscending == false && someArray[index - 1] < someArray[index])
            {
                int temp = someArray[index];

                someArray[index] = someArray[index - 1];
                someArray[index - 1] = temp;

                index--;
                PrintArray(someArray, arraySize);
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    cout << "숫자 몇 개? : ";

    int maxNumCount = 0;

    cin >> maxNumCount;

    if (maxNumCount < 1)
    {
        return 0;
    }

    int* numArray = new int[maxNumCount];

    cout << "숫자들을 입력하세요." << endl;

    for (int i = 0; i < maxNumCount; ++i)
    {
        cin >> numArray[i];
    }

    cout << "총 합 : " << SumAllElements(numArray, maxNumCount) << ", 평균 : " << AverageElements(numArray, maxNumCount) << endl;

    cout << "정렬 순서를 정하시오(오름차순 : 1, 내림차순 : 2) : ";

    int checkNum = 0;

    cin >> checkNum;

    bool bubbleSort = false; // 임의로 정함.

    if (checkNum == 1)
    {
        if (bubbleSort)
        {
            SortArray_Bubble(numArray, maxNumCount, true);
        }
        else
        {
            SortArray_Insert(numArray, maxNumCount, true);
        }
    }
    else if (checkNum == 2)
    {
        if (bubbleSort)
        {
            SortArray_Bubble(numArray, maxNumCount, false);
        }
        else
        {
            SortArray_Insert(numArray, maxNumCount, false);
        }
    }
    else
    {
        return 0;
    }

    cout << "정렬 결과 : ";

    PrintArray(numArray, maxNumCount);

    return 0;
}