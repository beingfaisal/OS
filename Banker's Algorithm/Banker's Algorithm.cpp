#include <iostream>
using namespace std;

const int totalProcesses = 5;
const int totalResources = 3;

void needCalcuator(int **need, int maxInstance[][totalResources], int allocatedInst[][totalResources])
{
	for (int i = 0; i < totalProcesses; i++)
	{
		for (int j = 0; j < totalResources; j++)
		{
			need[i][j] = maxInstance[i][j] - allocatedInst[i][j];
		}
	}
}

bool isSafe(int *process, int *avail, int maxInstance[][totalResources], int allocatedInst[][totalResources])
{
	int** need = new int* [totalProcesses];
	for (int i = 0; i < totalProcesses; i++)
	{
		need[i] = new int[totalResources];
	}
	
	needCalcuator(need, maxInstance, allocatedInst);
	
	bool* finish = new bool[totalProcesses];
	for (int i = 0; i < totalProcesses; i++) 
		finish[i] = 0;

	int* safeSequence = new int[totalProcesses];
	
	int* workingRes = new int[totalResources];
	for (int i = 0; i < totalResources; i++)
		workingRes[i] = avail[i];
	
	int count = 0;
	while (count < totalProcesses)
	{
		bool found = false;
		for (int i = 0; i < totalProcesses; i++)
		{
			if (finish[i] == 0)
			{
				int k;
				for (k = 0; k < totalResources; k++)
				{
					if (need[i][k] > workingRes[k])
					{
						break;
					}
				}
				if (k == totalResources)
				{
					for (int j = 0; j < totalResources; j++)
					{
						workingRes[j] += allocatedInst[i][j];
					}
					safeSequence[count++] = i;
					finish[i] = 1;
					found = true;

				}
				
			}
			
		}
		if (found == false)
		{
			cout << "System is not safe" << endl;
			return false;
		}
	}

	cout << "The System is Safe now" << endl;
	cout << "the Safe Sequence is \n";
	for (int i = 0; i < totalProcesses; i++)
		cout << safeSequence[i] << "	";
	return true;
}

int main()
{
	int processes[] = { 0, 1, 2, 3, 4 };

	// Available instances of resources 
	int availIns[] = { 3, 3, 2 };

	// Maximum R that can be allocated 
	// to processes 
	int maxIns[totalProcesses][totalResources] = 
	{ 
		             {7, 5, 3},
					 {3, 2, 2},
					 {9, 0, 2},
					 {2, 2, 2},
					 {4, 3, 3} 
	};

	// Resources allocated to processes 
	int allocatedIns[5][3] = 
	{ 
					  {0, 1, 0},
					  {2, 0, 0},
					  {3, 0, 2},
					  {2, 1, 1},
					  {0, 0, 2} 
	};

	// Check system is in safe state or not 
	isSafe(processes, availIns, maxIns, allocatedIns);

	return 0;

}