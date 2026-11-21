
#include <iostream>
using namespace std;

int main()
{
    int n, frames, pages[50], memory[10];
    int faults = 0, pointer = 0;

    cout << "Enter number of pages: ";
    cin >> n;

    cout << "Enter page reference string: ";
    for(int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> frames;

    for(int i = 0; i < frames; i++)
        memory[i] = -1;

    for(int i = 0; i < n; i++)
    {
        bool found = false;

        for(int j = 0; j < frames; j++)
            if(memory[j] == pages[i])
                found = true;

        if(!found)
        {
            memory[pointer] = pages[i];
            pointer = (pointer + 1) % frames;
            faults++;
        }
    }

    cout << "Total Page Faults: " << faults;

    return 0;
}
