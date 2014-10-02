//
//  Data.h
//  Sheep
//
//  Created by Tran Tho on 9/27/14.
//
//

#ifndef __Sheep__Data__
#define __Sheep__Data__

#include <iostream>
#include <vector>
#include "cocos2d.h"




#include "Info.h"


using namespace std;
using namespace cocos2d;




class DataImage
{
public:
    
    DataImage();
    
    static DataImage* getInstance();
    
    
    std::vector<Info> lisInfo;
    
    void readFile(const std::string& filePath, char key);

	void writeFile(const std::string& filePath, char key);
    
    void drawFile(std::string filePath);
    
    vector<string> split(string, char);
    
    Info randomQuestion();

	Info randomeAnswer();//randome cau tra loi

	Info getInfoByID(int ID);
    
	int randomID();//randome ra cau hoi. Dung thuat toan

	void changeRate(int ID, int newRate);
private:
    
};

#endif /* defined(__Sheep__Data__) */
