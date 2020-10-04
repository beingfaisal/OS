#include <iostream>
using namespace std;

struct Process
{
	int processNo, complTime, waitTime, burstTime, arrivalTime, turnAroundTime;
	Process()
	{
		processNo = complTime = waitTime = burstTime = turnAroundTime = arrivalTime = -1;
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
			if (procs[j].burstTime < procs[max].burstTime)
			{
					max = j;	
			}
		}
		swapStructs(procs[i], procs[max]);
	}
}



void calWaitTime(int totalProcess, Process* proc)
{
	proc[0].waitTime = 0;
	for (int i = 1; i < totalProcess; i++)
	{
		proc[i].waitTime = proc[i - 1].waitTime + proc[i - 1].burstTime;
	}

}

void calComplTime(int totalProcess, Process* proc)
{
	proc[0].complTime = proc[0].burstTime;
	for (int i = 1; i < totalProcess; i++)
	{
		proc[i].complTime = proc[i].burstTime + proc[i - 1].complTime;
	}
	
}
void calTurnAroundtime(int totalProcess, Process* proc)
{

	for (int i = 0; i < totalProcess; i++)
	{
		proc[i].turnAroundTime = proc[i].waitTime + proc[i].burstTime;
	}

}

double calAvgWaitTime(Process* proc, int totalProcess)
{
	int totalWaitTime = 0;
	double avgWaitTime = 0;
	for (int i = 0; i < totalProcess; i++)
	{
		totalWaitTime += proc[i].waitTime;
	}
	avgWaitTime = totalWaitTime / totalProcess;
	return avgWaitTime;
}

double calAvgTurnAroundTime(Process * proc, int totalProcess)
{
	int totalTATime = 0;
	double avgTATime = 0;
	for (int i = 0; i < totalProcess; i++)
	{
		totalTATime += proc[i].turnAroundTime;
	}
	avgTATime = totalTATime / totalProcess;
	return avgTATime;
}

int main()
{
	int numOfProcess = 5;
	int timeQuantum = 3;
	double avgWaitTime = 0;
	double avgTAtime = 0;
	int process[5] = { 1,2,3,4,5 };
	int burstTime[5] = { 9,4,2,6,2 };
	int arrivalTime[5] = { 0,3,5,4,6 };
	int waitTime[5];
	int completionTime[5];
	int turnAroundTime[5];

	Process* totalProc = new Process[numOfProcess];

	for (int i = 0; i < numOfProcess; i++)
	{
		totalProc[i].processNo = process[i];
		totalProc[i].burstTime = burstTime[i];
	}

	structSort(totalProc, numOfProcess);

	calComplTime(numOfProcess,totalProc);
	calTurnAroundtime(numOfProcess,totalProc);
	calWaitTime(numOfProcess,totalProc);
	
	avgWaitTime = calAvgWaitTime(totalProc, numOfProcess);
	avgTAtime = calAvgTurnAroundTime(totalProc, numOfProcess);

	for (int i = 0; i < numOfProcess; i++)
	{
		cout << "The Waiting Time for Process           " << totalProc[i].processNo<< " is " << totalProc[i].waitTime << endl;
		cout << "The Completion Time for Process        " << totalProc[i].processNo<< " is " << totalProc[i].complTime << endl;
		cout << "The Turn Around Time Time for Process  " << totalProc[i].processNo<< " is " << totalProc[i].turnAroundTime << endl << endl;
	}
	cout << "The Average Waiting Time is	" << avgWaitTime << endl;
	cout << "The Average Turn Around Time is	" << avgTAtime << endl;





}
