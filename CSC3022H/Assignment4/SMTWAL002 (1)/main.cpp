#include <iostream>
#include <sstream>
#include "Image.h"

using namespace std;
using namespace SMTWAL002;

int main(int argc, char *argv[]){
	char c = argv[1][1];
	switch (c) {
		case 'a' :{
			Image i(argv[2]);
			Image j(argv[3]);
			if ((i.getWidth()==j.getWidth())&&(i.getHight()==j.getHight())){
				Image k = i+j;
				k.write(argv[4]);
			}else cout << "Not same sized images :/" << endl;
			break;
		}
		case 's' :{
			Image i(argv[2]);
			Image j(argv[3]);
			if ((i.getWidth()==j.getWidth())&&(i.getHight()==j.getHight())){
				Image k = i-j;
				k.write(argv[4]);
			}else cout << "Not same sized images :/" << endl;
			break;
		}
		case 'i' :{
			Image i(argv[2]);
			(!i).write(argv[3]);
			break;
		}
		case 'l' :{
			Image i(argv[2]);
			Image j(argv[3]);
			if ((i.getWidth()==j.getWidth())&&(i.getHight()==j.getHight())){
				Image k = i/j;
				k.write(argv[4]);
			}else cout << "Not same sized images :/" << endl;
			break;
		}
		case 't' :{
			Image i(argv[2]);
			int f;
			stringstream  lineStream(argv[3]);
			lineStream >> f;
			(i*f).write(argv[4]);
			break;
		}
		default: cout << "No such option"<< endl;
	}
}