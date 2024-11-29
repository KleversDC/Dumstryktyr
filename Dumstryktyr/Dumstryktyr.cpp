#include <iostream>
using namespace std;

//class Bus {
//public:
//    int freeSeats;
//    Bus(int seats) : freeSeats(seats) {}
//};
//
//class StopSimulation {
//private:
//    double passengerArrivalRate;
//    double busArrivalRate;
//    int maxPassengers;
//    string stopType;
//
//public:
//    StopSimulation(double passengerRate, double busRate, int maxPassengers, const string& stopType)
//        : passengerArrivalRate(passengerRate), busArrivalRate(busRate), maxPassengers(maxPassengers), stopType(stopType) {}
//
//    void simulate(int simulationTime) {
//        int passengersAtStop = 0;
//        int totalWaitTime = 0;
//        int totalPassengers = 0;
//        int busesArrived = 0;
//
//        for (int time = 1; time <= simulationTime; ++time) {
//            if (time % static_cast<int>(1 / passengerArrivalRate) == 0) {
//                passengersAtStop++;
//            }
//
//            if (time % static_cast<int>(1 / busArrivalRate) == 0) {
//                busesArrived++;
//                Bus bus(5 + (time % 6));
//                int boardingPassengers = min(bus.freeSeats, passengersAtStop);
//                passengersAtStop -= boardingPassengers;
//                totalPassengers += boardingPassengers;
//                totalWaitTime += boardingPassengers * (time / 2);
//            }
//
//            if (passengersAtStop > maxPassengers) {
//                cout << "Max pasagur (" << passengersAtStop << ") na cas: " << time << endl;
//                break;
//            }
//        }
//
//        double avgWaitTime = totalPassengers > 0 ? static_cast<double>(totalWaitTime) / totalPassengers : 0;
//
//        cout << "Stop type: " << stopType << endl;
//        cout << "All passengers served: " << totalPassengers << endl;
//        cout << "Average waiting time: " << avgWaitTime << " minutes" << endl;
//        cout << "Number of buses: " << busesArrived << endl;
//    }
//};
//








//2
class PrintJob {
public:
    string userName;
    int priority;
    int jobTime;

    PrintJob(const string& userName, int priority, int jobTime)
        : userName(userName), priority(priority), jobTime(jobTime) {}
};

class PrinterQueue {
private:
    static const int MAX_JOBS = 100;
    PrintJob* queue[MAX_JOBS];
    int size;

public:
    PrinterQueue() : size(0) {}

    void addJob(const string& userName, int priority, int jobTime) {
        if (size >= MAX_JOBS) {
            cout << "The queue is full!" << endl;
            return;
        }

        PrintJob* newJob = new PrintJob(userName, priority, jobTime);
        int i = size - 1;

        while (i >= 0 && queue[i]->priority < priority) {
            queue[i + 1] = queue[i];
            i--;
        }

        queue[i + 1] = newJob;
        size++;
    }

    void processJobs() {
        cout << "Print statistics:" << endl;

        while (size > 0) {
            PrintJob* job = queue[0];
            cout << "User : " << job->userName
                << ", Priority: " << job->priority
                << ", Time to print: " << job->jobTime << " seconds" << endl;

            for (int i = 1; i < size; ++i) {
                queue[i - 1] = queue[i];
            }

            size--;
            delete job;
        }
    }
};







int main() {
    //StopSimulation stop(0.2, 0.1, 10, "Intermediate");
    //stop.simulate(60);







    PrinterQueue printerQueue;
    printerQueue.addJob("oleksi", 1, 10);
    printerQueue.addJob("maria", 3, 5);
    printerQueue.addJob("ivan", 2, 7);

    printerQueue.processJobs();










}
