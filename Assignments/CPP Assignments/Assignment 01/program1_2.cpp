#include<iostream>
using namespace std;

// Ikde Apan Main Memory Madhla Array cha direct address detoy so aapla memory kami lagel aani alias no of reading cha use krtoy so toh extrea memory ghenar nahii.
// Aapan jevha array pass krto tevha tyacha address ch pass karat asto like ikde aapan tempArrray[] pan use kru shktoo 
// tempArray[0] == *(tempArray + 0)
// tempArray+i --> address of i term 
// *(tempArray+i) --> Element present at that i term
void inputReading(double *tempArray,int &noOfReadings){
    cout<<"Enter the Readings:- "<<endl;
    for(int i=0;i<noOfReadings;i++){
        cin>>tempArray[i];
    }
    cout<<"Readings entered : "<<noOfReadings<<endl;
}
void printValues(double *tempArray,int &noOfReadings){
    int errorSkipped=0;
    cout<<"Valid readings : ";
    for(int i=0;i<noOfReadings;i++){
        if(*(tempArray+i)>0.0){
            cout<<*(tempArray+i)<<" ";
        }else{
            errorSkipped=errorSkipped+1;
            continue;
        }
    }
    cout<<"\nSkipped (errors) : "<<errorSkipped<<endl;
}

void firstCritical(double *tempArray,int &noOfReadings){
    for(int i=0;i<noOfReadings;i++){
        if(*(tempArray+i)>=45){
            cout<<"First CRITICAL : Index "<<i <<" --> "<<*(tempArray+i)<<endl;
            break;
        }

    }
}

void minMaxAvg(double *tempArray,int &noOfReadings){
    double min,max,avg,sum;
    min=tempArray[0];
    max=tempArray[0];
    sum=0.0;
    double count=0.0;
    for(int i=0;i<noOfReadings;i++){
        if(*(tempArray+i)>0.0){
            if(*(tempArray+i)<min){
                min=*(tempArray+i);
            }
            if(*(tempArray+i)>max){
                max=*(tempArray+i);
            }
            sum=sum+*(tempArray+i);
            count++;
             
        }
    avg=sum/count;
    }
    cout<<"Min :  "<<min<<" C"<< "\tMax : "<<max<<" C"<<"\tAvg : "<<avg<<" C";
}


void readingCategory(double *tempArray,int &noOfReadings){
    int normal,warning,critical,shutdown=0;
    for(int i=0;i<noOfReadings;i++){
        if(*(tempArray+i)>0.0){
            if (*(tempArray+i)>=0.0 && *(tempArray+i)<=29.0){
                normal++;
            }
            else if (*(tempArray+i)>=30.0 && *(tempArray+i)<=44.0){
                warning++;
            }
            else if (*(tempArray+i)>=45.0 && *(tempArray+i)<=59.0){
                critical++;
            }
            else{
                shutdown++;;
            }
        }
    }
    cout<<"\nNormal: "<<normal<<"\t Warning: "<<warning<<"\t Critical: "<<critical<<"\t Shutdown: "<<shutdown;
}
int main(){
    int noOfReadings;
    cout<<"Enter No Of Readings to Pass:- "<<endl;
    cin>>noOfReadings;
    double tempArray [noOfReadings];
    inputReading(tempArray,noOfReadings);
    printValues(tempArray,noOfReadings);
    firstCritical(tempArray,noOfReadings);
    minMaxAvg(tempArray,noOfReadings);
    readingCategory(tempArray,noOfReadings);        
    return 0;
}