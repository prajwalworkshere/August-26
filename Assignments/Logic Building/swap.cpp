#include <iostream>

int main(){
	int a;
	int b;
	int c;

	std::cout<<"Enter the number:- ";
	std::cin>>a>>b;
	std::cout<<"Before Swap- ";
	c=a;
	a=b;
	b=c;
	std::cout<<"Swapped Numbers:-"<<a<<" "<<b;
	return 0;
}
