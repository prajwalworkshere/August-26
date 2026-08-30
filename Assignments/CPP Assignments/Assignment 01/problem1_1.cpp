#include<iostream>
using namespace std;
void input(double &temp){
    cout<<"Enter The Input:- "<<temp;
    cin>>temp;
}

int StatusCodeCheck(double &temp){
    if(temp<0.0){
        return -1;
    }
    else if (temp>=0.0 && temp<=29.0){
        return 0;
    }
    else if (temp>=30.0 && temp<=44.0){
        return 1;
    }
    else if (temp>=45.0 && temp<=59.0){
        return 2;
    }
    else{
        return 3;
    };
}

void StatusLableAction(int &choice){
    switch(choice){
        case -1:
            cout<<"Status : SENSOR_ERROR"<<endl;
            cout<<"Action : Sensor fault-check wiring"<<endl;
            break;
        case 0:
            cout<<"Status : NORMAL"<<endl;
            cout<<"Action : No action required"<<endl;
            break;
        case 1:
            cout<<"Status : WARNING"<<endl;
            cout<<"Action : Alert sent to supervisor"<<endl;
            break;
        case 2:
            cout<<"Status : CRITICAL"<<endl;
            cout<<"Action : Cooling system triggered"<<endl;
            break;
        case 3:
            cout<<"Status : SHUTDOWN"<<endl;
            cout<<"Action : Emergency shutdown initiated"<<endl;
            break;
    }
}


int main(){
    double temp=0.0;
    input(temp);
    int statusCode=StatusCodeCheck(temp);
    cout<<"Temperature: "<<temp<<" C / "<<(temp * 9 / 5.0) + 32<<" F"<<endl;
    StatusLableAction(statusCode);
    (temp>25.0)? cout<<"Reading : Above Average":cout<<"Reading : Below Average";
    return 0;
}