#include <iostream>
using namespace std;

int* bestFit(int *orgBlocks, int totalBlocks, int *processSize, int totalProcess)
{
	int* blocks = new int[totalBlocks];
	for (int i = 0; i < totalBlocks; i++)
		blocks[i] = orgBlocks[i];

	//a new array to store the index of block assigned
	int* assigned = new int[totalProcess];
	//initializing all the elements in the array
	for (int i = 0; i < totalProcess; i++)
		assigned[i] = -1;

	for (int i = 0; i < totalProcess; i++)
	{
		int selectedBlockIndex = -1;
		for (int j = 0; j < totalBlocks; j++)
		{
			if (blocks[j] >= processSize[i])
			{
				if (selectedBlockIndex == -1)
					selectedBlockIndex = j;
				else if (blocks[selectedBlockIndex] > blocks[j])
					selectedBlockIndex = j;
			}
		}
		if (selectedBlockIndex != -1)
		{
			assigned[i] = selectedBlockIndex;
			blocks[selectedBlockIndex] = blocks[selectedBlockIndex] - processSize[i];	
		}
	}

	return assigned;
}


int main()
{
	
	int totalBlocks = 0;
	int* blocks = new int[totalBlocks];
	int totalProcess = 0;
	int* processSize = new int[totalProcess];
	
	cout << "Enter the number of Blocks" << endl;
	cin >> totalBlocks;
	for (int i = 0; i < totalBlocks; i++)
	{
		cout << "Enter the size of " << i + 1 << " Block" << endl;
		cin >> blocks[i];
	}
	cout << endl << endl;
	cout << "Enter the number of process " << endl;
	cin >> totalProcess;
	for (int i = 0; i < totalBlocks; i++)
	{
		cout << "Enter the size of " << i + 1 << " Process" << endl;
		cin >> processSize[i];
	}
	
	int* assigned = new int[totalProcess];
	assigned = bestFit(blocks, totalBlocks, processSize, totalProcess);
	for (int i = 0; i < totalProcess; i++)
	{
		cout << "The Block " << assigned[i] + 1  << " of size " << blocks[i] << " has been selected for process of size " << processSize[i] << endl;
	}



}