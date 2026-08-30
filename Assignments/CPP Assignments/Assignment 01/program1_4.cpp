#include<iostream>
using namespace std;

int main(int argc, char* argv[]){

    if(argc<4){
        cout<< "Error : Missing arguments."<<endl;
        return 1;
    }

    int warnThreshold = stoi(argv[1]);
    int criticalThreshold = stoi(argv[2]);
    int numReadings = stoi(argv[3]);

    if(warnThreshold > criticalThreshold){
        cout<< "Error : Warning threshold must be less than critical threshold.";
        return 1;
    }

    if(numReadings >=1 && numReadings <=500){

    }else{
        cout<<"Error : Number of readings must be between 1 to 500!";
        return 1;
    }


    cout<< "Config : Warn= "<< warnThreshold << " C  Critical="<< criticalThreshold << " C  Readings= "<< numReadings <<endl;

    int normalCount = 0;
    int warningCount = 0;
    int criticalCount = 0;
    int shutdownCount = 0;

    for(int i =0;i<numReadings;i++){
        int num = rand()%70;
        if(num >=0 && num <= 29){
            normalCount++;
        }else if(num >= 30 && num<= 44){
            warningCount++;
        }else if(num >= 45 && num<= 59){
            criticalCount++;
        }else if(num>=60){
            shutdownCount++;
        }
    }

    cout<< "Results : Normal: "<<normalCount <<" Warning: "<< warningCount << " Critical: "<< criticalCount<< " Shutdown:" <<shutdownCount <<endl;

    return 0;
}