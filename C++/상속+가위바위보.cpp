#include <iostream>
using namespace std;
class Tool {
public:
	virtual void setStrength(int strength) = 0;

	virtual int getStrength() = 0;

	virtual char getType() = 0;

};
class Scissors : public Tool {
protected:
	int scissorStrength;
	char type = 's';
public:
	void setStrength(int strength) {
		scissorStrength = strength;
	}
	int getStrength() {
		return scissorStrength;
	}
	char getType() {
		return type;
	}
	Scissors(int strength) {
		setStrength(strength);
	}
	bool fight(Tool& pTool) {
		if (pTool.getType() == 'r') {
			scissorStrength = scissorStrength / 2;
			return  (scissorStrength > pTool.getStrength());
		}
		else if (pTool.getType() == 'p') {
			scissorStrength *= 2;
			return (scissorStrength > pTool.getStrength());
		}
	}
};
class Paper : public Tool {
protected:
	int paperStrength;
	char type = 'p';
public:
	void setStrength(int strength) {
		paperStrength = strength;
	}
	int getStrength() {
		return paperStrength;
	}
	char getType() {
		return type;
	}
	Paper(int strength) {
		setStrength(strength);
	}
	bool fight(Tool& pTool) {
		if (pTool.getType() == 'r') {
			paperStrength *= 2;
			return (paperStrength < pTool.getStrength());
		}
		else if (pTool.getType() == 's') {
			paperStrength = paperStrength / 2;
			return  (paperStrength > pTool.getStrength());
		}
	}
};
class Rock : public Tool {
protected:
	int rockStrength;
	char type = 'r';
public:
	void setStrength(int strength) {
		rockStrength = strength;
	}
	int getStrength() {
		return rockStrength;
	}
	char getType() {
		return type;
	}
	Rock(int strength) {
		setStrength(strength);
	}
	bool fight(Tool& pTool) {
		if (pTool.getType() == 's') {
			rockStrength *= 2;
			return(rockStrength > pTool.getStrength());
		}
		else if (pTool.getType() == 'p') {
			rockStrength = rockStrength / 2;
			return (rockStrength < pTool.getStrength());
		}
	}
};

int main() {

	Scissors s1(5);
	Paper p1(7);
	Rock r1(15);
	cout << s1.fight(p1) << p1.fight(s1) << endl;
	cout << p1.fight(r1) << r1.fight(p1) << endl;
	cout << r1.fight(s1) << s1.fight(r1) << endl;
	return 0;
}