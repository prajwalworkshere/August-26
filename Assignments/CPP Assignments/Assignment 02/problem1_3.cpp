#include <iostream>
using namespace std;

class Entity{
private:
	string name;
	int health;
	int level;
	string type;
public:
	Entity& setName(const string& name){
		this->name = name;
		return *this;
	}
	Entity& setHealth(int health){
		this->health = health;
		return *this;
	}
	Entity& setLevel(int level){
		this->level = level;
		return *this;
	}
	Entity& setType(const string& type){
		this->type = type;
		return *this;
	}

	string getName() const{
		return this->name;
	}
	int getHealth() const{
		return this->health;
	}
	int getLevel() const{
		return this->level;
	}
	string getType() const{
		return this->type;
	}
	void displayInfo() const{
		cout<<"Name: "<<this->name<<endl;
		cout<<"Health: "<<this->health<<endl;
		cout<<"Level: "<<this->level<<endl;
		cout<<"Type: "<<this->type<<endl;

		cout<<endl<<endl;
	}


};

namespace Physics {
// clamp a velocity
 double clamp(double val, double min, double max){
	 if(max < min) return 0;
	 cout<<"Physics Clamp called"<<endl;
	 if(val < min) return min;
	 if(val > max) return max;
	 return val;
 }
 double lerp(double a, double b, double t){
	 cout<<"Physics Lerp called"<<endl;
	 return a + t * (b-a);
 }
}
namespace GameMath {
 int clamp(int val, int min, int max){
	 if(max < min) return 0;
	 cout<<"GameMath Clamp called"<<endl;
	 if(val < min) return min;
	 if(val > max) return max;
	 return val;
 }
 double lerp(double a, double b, double t){
	 cout<<"Gamemath Lerp called"<<endl;
	 return a + t * (b-a);
 }
}

void populateCount(int& cnt1,int& cnt2,int& cnt3,int& cnt4,int& cnt5, int& gridval){
	if(gridval == 0){
		cnt1++;
	}
	else if(gridval == 1){
		cnt2++;
	}
	else if(gridval == 2){
		cnt3++;
	}
	else if(gridval == 3){
		cnt4++;
	}
	else{
		cnt5++;
	}
}

int level = 1; //global

namespace Engine{
	namespace Audio{
	void playSound(string name){
		cout<<"Playing: "<<name<<endl;
	}
	}
}

int main() {

	//************** PART A **************
	
	Entity player, enemy, item;
	player.setName("Aragorn").setHealth(100).setLevel(10).setType("Player");
	enemy.setName("Orc").setHealth(60).setLevel(5).setType("Enemy");
	item.setName("HealthPotion").setHealth(0).setLevel(1).setType("Item");

	//Chaining explained:
	//player.setName("Aragorn").setHealth(100) this is same as
	//Entity& ref1 = player.setName("Aragorn");
	//               this part returns dereferenced pointer of object (*this)
	//we are creating an alias of Entity the name of that alias/reference is ref1
	//now in method chaining when we do .setName("xyz").setHealth("abc);
	//in the back it's safe as setHealth(&ref1, "abc") <- we are using the updated object here and it's chaining together

	//NOTE-> in every function in class we have a hidden default parameter which is (this)
	//example in here we have suppose for setName-> setName(Entity* const this, const string& name)
	//this is the reason why we can use (this) in our function code blocks

	player.displayInfo();
	enemy.displayInfo();
	item.displayInfo();

	//************** PART B ***************
	
	cout<<"Physics Clamp: ";
	cout<<Physics::clamp(30, 50, 100);
	cout<<endl;
	cout<<"Physics Lerp: ";
	cout<<Physics::lerp(3, 7, 64);
	cout<<endl<<endl;

	cout<<"GameMath Clamp: ";
	cout<<GameMath::clamp(-2, 50, 100);
	cout<<endl;
	cout<<"GameMath Lerp: ";
	cout<<GameMath::lerp(3, 66, 64);
	cout<<endl;

	{
		using namespace Physics;
		cout<<clamp(10, 20, 3000);
	}
	cout<<endl;
	{
		using namespace GameMath;
		cout<<clamp(8000, 20, 590);
	}
	cout<<endl;
	//PART C
	int R, C;
	R = 3;
	C = 4;
	int** grid = new int*[R];

	for(int i = 0; i < R; i++){
		grid[i] = new int[C];
		for(int j = 0; j < C; j++){
			grid[i][j] = (rand() % 5);
		}
	}

	cout<<"===== GAME MAP "<<R<<" * "<<C<<" "<<"====="<<endl;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0;
	for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				populateCount(cnt1, cnt2, cnt3, cnt4, cnt5, grid[i][j]);
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}

	cout<<"Legend: 0=Grass 1=Water 2=Mountain 3=Forest 4=Dungeon"<<endl;
	cout<<endl;
	cout<<"Tile Count:"<<endl;
	cout<<"Grass : "<<cnt1<<endl;
	cout<<"Water : "<<cnt2<<endl;
	cout<<"Mountain : "<<cnt3<<endl;
	cout<<"Forest : "<<cnt4<<endl;
	cout<<"Dungeon : "<<cnt5<<endl;

	//BONUS QUESTION-
	int level = 10; //local on line 106 we have global
	cout<<"Printing global value: "<<::level<<endl;
	cout<<"Printing local value: "<<level<<endl;
	cout<<"Calling Nested Namespace: "<<endl;
	cout<<endl;
	Engine::Audio::playSound("sword_clash");


	return 0;
}