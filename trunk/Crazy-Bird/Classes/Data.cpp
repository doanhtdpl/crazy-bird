//
//  Data.cpp
//  Sheep
//
//  Created by Tran Tho on 9/27/14.
//
//

#include "Data.h"
#include <iostream>
#include <fstream>

static DataImage* instance = nullptr;

DataImage* DataImage::getInstance()
{
    if(instance == nullptr)
    {
        instance = new DataImage();
    }
    
    return instance;
}

DataImage::DataImage()
{}

void DataImage::readFile(const std::string& filePath, char key)
{
    string line;
    //ifstream myfile;
    
    //ifstream *myfile = new ifstream(filePath);
    std::string path = FileUtils::getInstance()->fullPathForFilename(filePath.c_str());
	//std::string path = FileUtils::getInstance()->fullPathFromRelativeFile(
    
    ssize_t size = 0;
    
    char* buffer = (char*)FileUtils::getInstance()->getFileData(path.c_str(), "rt", &size);
    
    std::stringstream myfile(buffer);
    
    while (std::getline(myfile, line, '\n') ) {
		//if (line != "")
		{
			vector<string> _arr = split(line, key);
			if (_arr.size() > 1)
			{
				Info _info = Info(_arr);
				lisInfo.push_back(_info);
			}
			
			
		}
		
    }

	//writeFile(filePath, ',');
}

void DataImage::writeFile(const std::string& filePath, char key)
{
	string line;
	//std::string path = FileUtils::getInstance()->fullPathForFilename(filePath);
    std::string path = FileUtils::getInstance()->getWritablePath() + filePath;
    ssize_t size = 0;

	ofstream outFile;
	outFile.open(path.c_str(), ios_base::out | ios_base::app);

	for (auto info : lisInfo)
	{
		//line = "tuan hoang";"" + info.ID + 
		line = std::to_string(info.ID) + "," + info.fileName + "," + info.answer + "," + std::to_string(100);
		outFile << line << endl;
	}
	
	/*char* buffer = (char*)FileUtils::getInstance()->getFileData(path.c_str(), ios_base::app, &size);
	std::stringstream myfile(buffer);*/

}

vector<string> DataImage::split(string _string, char _key)
{
    vector<string> arr;
    string sTemple = "";
    int index = 0;
    
    while (index < _string.length())
    {
        while (_string[index] != _key && index < _string.length() && _string[index] != ' ')
        {
            sTemple += _string[index];
            index++;
        }
        
        if(_string.size() > 0)
            arr.push_back(sTemple);
        index++;
        sTemple.clear();
    }
    
    return arr;
}

Info DataImage::randomQuestion()
{
    srand(time(0));
	int random;
	Info info;
    do 
    {
		random = randomID();
		info = lisInfo.at(random);
		if (!info.appeared)
		{
			lisInfo.at(random).appeared = true;
			break;
		}
		
    } while (info.appeared);
    
    return info;
}

Info DataImage::randomeAnswer()
{
	
	int random;
	Info info;
	do 
	{
		random = rand() % lisInfo.size();
		info = lisInfo.at(random);
		if (!info.appearedAnswer)
		{
			lisInfo.at(random).appearedAnswer = true;
			break;
		}

	} while (info.appearedAnswer);

	return info;
}

Info DataImage::getInfoByID(int _ID)
{
	for (auto info : lisInfo)
	{
		if (info.ID == _ID)
		{
			return info;
		}
	}
}

//dung thuat toan. Co su dung trong so
int DataImage::randomID()
{
	srand(time(0));
	int lenght = lisInfo.size();
	int* probs = new int[lenght];
	int* cusumProbs = new int[lenght];

	std::memset(probs, 0, lenght);
	std::memset(cusumProbs, 0, lenght);

	probs[0] = lisInfo.at(0).rate;
	cusumProbs[0] = lisInfo.at(0).rate;

	for (int i = 1; i < lisInfo.size(); i++)
	{
		if (!lisInfo.at(i).appeared)//chua xuat hien roi
		{
			probs[i] = lisInfo.at(i).rate;
			cusumProbs[i] = cusumProbs[i - 1] + probs[i];
		}else
		{
			probs[i] = 0;
			cusumProbs[i] = cusumProbs[i - 1] + probs[i];
		}
		
		
	}

	int r = rand() % cusumProbs[lenght - 1];
	
	for (int i = 0; i < lenght; i++)
	{
		if (cusumProbs[i] > r)
		{
			delete[] probs;
			delete[] cusumProbs;
			return i;
		}
	}

	return -1;
}

void DataImage::changeRate(int ID, int newRate)
{
	for (int i = 0; i < lisInfo.size(); i++)
	{
		if (ID == lisInfo.at(i).ID)
		{
			lisInfo.at(i).rate = newRate;
			return;
		}
	}
}
