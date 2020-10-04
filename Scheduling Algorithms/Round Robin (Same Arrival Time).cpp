
#include <iostream>
using namespace std;

void calCompletionTime(int* complTime, int totalProcess, int* process, int* burstTime)
{
	complTime[0] = burstTime[0];
	for (int i = 1; i < totalProcess; i++)
	{
		complTime[i] = burstTime[i] + complTime[i - 1];
	}

}

void calWaitingTime(int totalProcess, int* process, int* burstTime, int* waitTime,int timeQuantum)
{
	int* remBurst = new int[totalProcess];
	for (int i = 0; i < totalProcess; i++)  remBurst[i] = burstTime[i];
	int extraTime = 0;
	while (true)
	{
		bool isCompleted = true;
		for (int i = 0; i < totalProcess; i++)
		{
			if (remBurst[i] > 0) //as it is gretaer than 0 so it is not complete
			{
				isCompleted = false; //not all the process has been completed
				if (remBurst[i] > timeQuantum) //As it is greater than time slice so we need to decrease according to time slice
				{
					extraTime += timeQuantum;
					remBurst[i] -= timeQuantum;
				}
				else //it means it is last iteration of process and it will be completed after this 
				{
					extraTime += remBurst[i];
					waitTime[i] = extraTime - burstTime[i];
					remBurst[i] = 0;
				}

			}
		}
		if (isCompleted)  break;
	}

}
void calTurnAroundtime(int totalProcess, int* process, int* burstTime, int* waitTime, int* turnAroundTime)
{

	for (int i = 0; i < totalProcess; i++)
	{
		turnAroundTime[i] = waitTime[i] + burstTime[i];
	}

}

double calAvgWaitTime(int* waitTime, int totalProcess)
{
	int totalWaitTime = 0;
	double avgWaitTime = 0;
	for (int i = 0; i < totalProcess; i++)
	{
		totalWaitTime += waitTime[i];
	}
	avgWaitTime = totalWaitTime / totalProcess;
	return avgWaitTime;
}

double calAvgTurnAroundTime(int* turnAroundTime, int totalProcess)
{
	int totalTATime = 0;
	double avgTATime = 0;
	for (int i = 0; i < totalProcess; i++)
	{
		totalTATime += turnAroundTime[i];
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

	calCompletionTime(completionTime, numOfProcess, process, burstTime);
	calWaitingTime(numOfProcess,process,burstTime,waitTime,timeQuantum);
	calTurnAroundtime(numOfProcess, process,burstTime,waitTime,turnAroundTime);
	
	avgWaitTime = calAvgWaitTime(waitTime, numOfProcess);
	avgTAtime = calAvgTurnAroundTime(turnAroundTime, numOfProcess);

	for (int i = 0; i < numOfProcess; i++)
	{
		cout << "The Waiting Time for Process     " << process[i] << " is " << waitTime[i] << endl;
		cout << "The Completion Time for Process  " << process[i] << " is " << completionTime[i] << endl;
		cout << "The Turn Around Time for Process " << process[i] << " is " << turnAroundTime[i] << endl;
		cout << endl;
	}
	cout << "The Average Waiting Time is	" << avgWaitTime << endl;
	cout << "The Average Turn Around Time is	" << avgTAtime << endl;


	cout << "Here";




}