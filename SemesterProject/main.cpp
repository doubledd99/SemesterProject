//#include "camera.h"
#include <iostream>
#include "inventory.h"
using namespace std;

int main() {
	//camera camera1;
	//camera1.deviceEnum();
	//camera1.Get(camera1.);
	//camera1.GetRange();
	//camera1.InitCaptureGraphBuilder();
	inventory inventory1;
	inventory1.insert(13.50, "Hawkeye", "VODKA", 12345678);
	inventory1.insert(17.20, "Everclear", "VODKA", 22222222);
	inventory1.insert(53.00, "JW Black", "WHISKEY", 33333333);
	inventory1.insert(33.10, "Crown Peach", "WHISKEY", 44444444);
	//insert(int Price, string Name, string Location, barcodetype Barcode)
	return 0;
}