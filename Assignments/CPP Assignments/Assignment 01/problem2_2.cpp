
#include <iostream>
#include <cmath>
using namespace std;
  double computeRMS(double* signal, int n){

	  double sum  = 0;

	  for(int i = 0; i < n; i++){
		  sum = sum + (*(signal + i) * *(signal + i));
	  }

	  return sqrt(sum / n);
  }

  void normalise(double* signal, int n){

	  double mav = 0;

	  for(int i = 0; i < n; i++){

		  if(abs(*(signal + i)) > mav)
			  mav = abs(*(signal + i));
	  }

	  for(int i = 0; i < n; i++){
		  *(signal + i) = *(signal + i) / mav;
	  }
  }

  int countZeroCrossings(double* signal, int n){

	  int count = 0;

	  for(int i = 0; i < n - 1; i++){
	  	if((*(signal + i) < 0 && *(signal + i + 1) > 0) ||
	  	   (*(signal + i) > 0 && *(signal + i + 1) < 0)) {
	  		   count++;
	  	}
	  }

	  return count;
  }

  void applyGain(double* signal, int n, double gainFactor){

	  for(int i = 0; i < n; i++){
		  *(signal + i) = *(signal + i) * gainFactor;
	  }
  }



int main(){
	int n;
	cout << "Enter number of signals: " << endl;
	cin >> n;

	double signal[n];
	cout << "Enter " << n << " signal value: ";

	for(int i = 0; i < n; i++){
		cin >> signal[i];
	}

	double gainFac;
	cout << "Enter gain factor: " << endl;
	cin >> gainFac;

	cout << "Test signal: {";
	for(int i = 0; i < n; i++){
		cout << signal[i];
		if (i < n - 1)
		   cout << ", ";
	}
	cout << "}" << endl;


	cout << "Normalised signal: {";
	normalise(signal, n);
	for(int i = 0; i < n; i++){
		cout << signal[i];
		if (i < n - 1)
		   cout << ", ";
	}
	cout << "}" << endl;


	cout << "Signal after applying gain: {";
	applyGain(signal, n, gainFac);
	for(int i = 0; i < n; i++){
			cout << signal[i];
			if (i < n - 1)
			   cout << ", ";
		}
		cout << "}" << endl;



	double rms = computeRMS(signal, n);
	cout << "RMS of Signals: " << rms << endl;


	int crossings = countZeroCrossings(signal, n);
	cout << "Count of adjacent elements having opposite signs: ";
	cout << crossings;

	return 0;
}

