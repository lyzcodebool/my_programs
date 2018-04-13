#include <iostream>
#include <map>
#include <string>

using namespace std;
int main(void)
{
    map<int, string> mapString;
    mapString.insert(pair<int, string>(1, "student1"));
    mapString.insert(pair<int, string>(2, "student2"));
    mapString.insert(pair<int, string>(3, "student3"));

    map<int, string>::iterator it;

    for(it = mapString.begin(); it != mapString.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}
