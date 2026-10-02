//oth
#include <iostream>
#include <vector>
using namespace std;

struct caja 
{
	int H;
	int contH;
	vector<caja> c;
};

void initBox(int h, caja& box) 
{
	box.H = h;
	box.contH = 0;
	box.c.clear();
}

bool insert(caja& boxOuter, caja& boxInner) {
	for (int i = 0; i < (int)boxOuter.c.size(); i++) 
	{
		if (insert(boxOuter.c[i], boxInner)) return true;
		
	}
	if (boxInner.H > boxOuter.H - boxOuter.contH) return false;
	
	boxOuter.contH += boxInner.H;
	boxOuter.c.push_back(boxInner);
	return true;
}

int main() {
	int n;
	caja* boxPtr;
	while (cin >> n) {
		boxPtr = new caja();
		initBox(2000000000, *boxPtr);
		for (int i = 0; i < n; i++) {
			int h;
			cin >> h;
			caja newBox;
			initBox(h, newBox);
			insert(*boxPtr, newBox);
		}
		cout << (*boxPtr).contH << endl;
	}
	return 0;
}



