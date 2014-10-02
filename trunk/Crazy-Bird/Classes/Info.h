//
//  Info.h
//  Sheep
//
//  Created by Tran Tho on 9/27/14.
//
//

#ifndef __Sheep__Info__
#define __Sheep__Info__


#include <iostream>
#include <vector>

using namespace std;


class Info
{
public:
    
    Info();
    
    Info(vector<string> );
    
    
    int ID;
    
    std::string fileName;
    
    std::string answer;
    
    int rate;
    
    bool appeared;//da xuat hien roi

	bool appearedAnswer;//cau tra loi da xuat hien roi
};

#endif /* defined(__Sheep__Info__) */
