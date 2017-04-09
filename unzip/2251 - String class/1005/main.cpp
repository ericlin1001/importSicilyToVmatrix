#include <string>
 #include <iostream>
 using namespace std;
 string sort(string &s)
{
    string temp;
    temp = s ;
    int len;
    char x; 
    len =  temp.size();
    int i ,j ;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            if(temp[i]<temp[j])
            {
                x=temp[i];
                temp[i]=temp[j];
                temp[j]=x;
            }
        }
    }
    return temp;
}                                 

