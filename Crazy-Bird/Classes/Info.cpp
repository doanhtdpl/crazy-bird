//
//  Info.cpp
//  Sheep
//
//  Created by Tran Tho on 9/27/14.
//
//

#include "Info.h"

Info::Info()
{
    ID = 0;
    fileName = "";
    answer = "";
    rate = 0;
	appeared = false;
	appearedAnswer = false;
}

Info::Info(vector<string> list)
{
    ID = atoi(list.at(0).c_str());
    fileName = list.at(1);
    answer = list.at(2);
    rate = atoi(list.at(3).c_str());
    appeared = false;
	appearedAnswer = false;

	//rate = 10;
}