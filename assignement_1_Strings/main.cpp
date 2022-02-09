#include <iostream>
#include <sstream>
using namespace std;
/*
Music (only extensions: mp3,aac,flac)
Image (only extensions: jpg,bmp,gif)
Movie (only extensions: mp4,avi,mkv)

*/
int main()
{
    string str="",Buffer;
    int T,n;
    int music=0,images=0,movies=0,others=0;


    getline(cin,Buffer);
    stringstream s(Buffer);

    s>>T;

    while(s>>T)
    {


        for(int i=0;i<T;++i)
        {

            getline(cin,Buffer);

            /*get the last . */
            int index1=-1;
            while( (Buffer.find('.',index1+1)) != std::string::npos)
             {
                 index1=Buffer.find('.',index1+1);

             }


            /*get the last space */
            int index2=-1;
            while( (Buffer.find(' ',index2+1)) != std::string::npos)
            {
                index2=Buffer.find(' ',index2+1);
            }

            /*get the extention*/
            str=Buffer.substr(index1+1,index2-index1-1);

            /*get the size and convert it into integer*/
            string Size=Buffer.substr(index2+1,Buffer.size()-2);
            stringstream s1(Size);
            s1>>n;

            if(str=="mp3" ||str=="aac"||str=="flac")
            {

                 music+=n;
            }

            else if(str=="jpg" ||str=="bmp"||str=="gif")
            {
                 images+=n;
            }

            else if(str=="mp4" ||str=="avi"||str=="mkv")
            {
                 movies+=n;
            }
            else
            {
                others+=n;
            }


        }


    cout << "music "<<music <<"b images "<<images << "b movies "<<movies<< "b others "<<others<<"b"<< endl;
    music=movies=images=0;
    }


    return 0;
}
