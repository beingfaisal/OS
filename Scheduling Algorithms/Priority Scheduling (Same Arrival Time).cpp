
#include <iostream>
using namespace std;

struct Process
{
	int processNo, complTime, waitTime, burstTime, turnAroundTime, priority;
	Process()
	{
		processNo = complTime = waitTime = burstTime = turnAroundTime = priority = -1;
	}

};

void swapStructs(Process& p1, Process& p2)
{
	Process temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}

//variation of selection sort for two structs objects
void structSort(Process* procs, int totalProcs)
{
	for (int i = 0; i < totalProcs; i++)
	{
		int max = i;
		for (int j = i + 1; j < totalProcs; j++)
		{
			if (procs[j].priority > procs[max].priority)
			{
				max = j;
			}
		}
		swapStructs(procs[i], procs[max]);
	}
}

void calCompletionTime(int totalProcess, Process* procs)
{
	procs[0].complTime = procs[0].burstTime;
	for (int i = 1; i < totalProcess; i++)
	{
		procs[i].complTime = procs[i].burstTime + procs[i - 1].complTime;
	}

}

void calWaitingTime(int totalProcess,Process* procs)
{
	procs[0].waitTime = 0;
	for (int i = 1; i < totalProcess; i++)
	{
		procs[i].waitTime = procs[i-1].waitTime + procs[i-1].burstTime;
	}

}
void calTurnAroundtime(int totalProcess,Process* procs)
{

	for (int i = 0; i < totalProcess; i++)
	{
		procs[i].turnAroundTime = procs[i].waitTime + procs[i].burstTime;
	}

}

double calAvgWaitTime(int totalProcess, Process* procs)
{
	int totalWaitTime = 0;
	double avgWaitTime = 0;
	for (int i = 0; i < totalProcess; i++)
	{
		totalWaitTime += procs[i].waitTime;
	}
	avgWaitTime = totalWaitTime / totalProcess;
	return avgWaitTime;
}

double calAvgTurnAroundTime(int totalProcess,Process* procs)
{
	int totalTATime = 0;
	double avgTATime = 0;
	for (int i = 0; i < totalProcess; i++)
	{
		totalTATime += procs[i].turnAroundTime;
	}
	avgTATime = totalTATime / totalProcess;
	return avgTATime;
}

int main()
{
	int numOfProcess = 5;
	double avgWaitTime = 0;
	double avgTAtime = 0;
	int process[5] = { 1,2,3,4,5 };
	int burstTime[5] = { 9,4,2,6,2 };
	int arrivalTime[5] = { 0,3,5,4,6 };
	int priority[5] = { 1,4,2,7,3 };
	int waitTime[5];
	int completionTime[5];
	int turnAroundTime[5];

	Process totalProc[5];

	for (int i = 0; i < numOfProcess; i++)
	{
		totalProc[i].processNo = process[i];
		totalProc[i].burstTime = burstTime[i];
		totalProc[i].priority = priority[i];
	}

	structSort(totalProc, numOfProcess);

	for (int i = 0; i < numOfProcess; i++)
	{
		cout << totalProc[i].processNo << "  " << totalProc[i].priority << endl;
	}

	calCompletionTime(numOfProcess,totalProc);
	calTurnAroundtime(numOfProcess,totalProc);
	calWaitingTime(numOfProcess,totalProc);
	avgWaitTime = calAvgWaitTime(numOfProcess,totalProc);
	avgTAtime = calAvgTurnAroundTime(numOfProcess,totalProc);

	for (int i = 0; i < numOfProcess; i++)
	{
		cout << "The Waiting Time for Process with Priority     " << totalProc[i].processNo << ", " << totalProc[i].priority<<" is "<<totalProc[i].waitTime<<endl;
		cout << "The Completion Time for Process with Priority  " << totalProc[i].processNo << ", " << totalProc[i].priority <<" is " << totalProc[i].complTime << endl;
		cout << "The Turn Around Time for Process with Priority " << totalProc[i].processNo << ", " << totalProc[i].priority << " is " << totalProc[i].turnAroundTime << endl << endl;
	}
	cout << "The Average Waiting Time is	" << avgWaitTime << endl;
	cout << "The Average Turn Around Time is	" << avgTAtime << endl;







}