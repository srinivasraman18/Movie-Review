#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<locale>
#include<sstream>


using namespace std;

void print(vector<string>& v)
{
    for(auto it:v)
    {

        cout<<it<<endl;
    }
}

void print(vector<vector<string>>& v)
{

    for(auto it:v)
    {
        for(auto ptr:it)
            cout<<ptr<<endl;
    }
}
vector<string> remove_stopwords(string& rawfile,vector<string>& stop)
{
    vector<string>::iterator it;
    vector<string> temp_v;
    string::iterator ptr;
    int count=0;
    int beg=0;

    for(int j=0;j!=rawfile.length();j++)
    {
        if((rawfile[j]==' ')||(rawfile[j]=='\n')||(j==rawfile.length()-1))
            {

                string temp;
                temp=rawfile.substr(beg,j-beg+1);
                if(temp[temp.size()-1]==' ')
                    temp.erase(temp.size()-1);
                it=std::find(stop.begin(),stop.end(),temp);
                if(it==stop.end())
                   temp_v.push_back(temp);
                beg=j+1;
            }
}

return temp_v;
}

/*void freq_count(map<string, pair<long,long>>& dict,vector<string>& v)
{
    for(auto it:v)
    {


    }
}*/


int main()
{
    ifstream fin1;
    ifstream fin2;
    ofstream fout;
    fin1.open("rawreviews.txt",ios::in);
    fin2.open("newstopwords.txt",ios::in);
    string line1;
    string line2;
    vector<string>  rawfile;
    vector<vector<string>>  newrawfile;
    vector<string> stop;

    while(fin2)
    {
        getline(fin2,line1);
        transform(line1.begin(), line1.end(), line1.begin(), ::tolower);
        stop.push_back(line1);
        if(fin2.eof())
            break;

    }
    for(auto itr:stop)
    {
         itr.erase(remove_if(itr.begin(),itr.end(),[](unsigned char x){return isspace(x);}),itr.end());
    }

    while(fin1)
    {
        getline(fin1,line2);
        rawfile.push_back(line2);
        if(fin1.eof())
            break;
    }
    for(auto it:rawfile)
    {
        vector<string> temp;
        transform(it.begin(), it.end(), it.begin(), ::tolower);
        it.erase(remove_if(it.begin(),it.end(),[](unsigned char x){return ispunct(x);}),it.end());
        temp=remove_stopwords(it,stop);
        it.erase(remove_if(it.begin(),it.end(),[](unsigned char x){return isspace(x);}),it.end());
        newrawfile.push_back(temp);
    }




    fin1.close();
    fin2.close();
    print(newrawfile);


    return 0;
}


