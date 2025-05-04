#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class FileException
{
public:
    virtual const char *what() const noexcept
    {
        return "Unable to open file.";
    }
};

class FileNotFoundException: public FileException
{
public:
    virtual const char *what() const noexcept override
    {
        return "Unable to find file.";
    }
};

class PermissionDeniedException: public FileException
{
public:
    virtual const char *what() const noexcept override
    {
        return "Unable to access file.";
    }
};

void readFile(const string &fileName)
{
    ifstream file(fileName);
    if (!file)
    {
        if (errno == EACCES)
            throw PermissionDeniedException();
        else if (errno == ENOENT)
            throw FileNotFoundException();
        else
            throw FileException();
    }
    file.close();
}

int main()
{
    nl;
    try{
        readFile("sample1.txt"); 
        readFile("sample2.txt"); //Doesn't Exist
    }
    catch(PermissionDeniedException& e){
        cout << "Exception Caught: " << e.what() << endl;
    }
    catch(FileNotFoundException& e){
        cout << "Exception Caught: " << e.what() << endl;
    }
    catch(FileException& e){
        cout << "Exception Caught: " << e.what() << endl;
    }
    nl;
    return 0;
}