#include <bits/stdc++.h>
using namespace std;
#include <string>

/**
 *  THIS program run in windows computers
 * 
 * */

int main(int arg,char **argv){
    
    if(arg<=1){
        cout<<"please give an your program executable or .class in argument";
        return 0;
    }
    int numberoftests;
    int nbr = 0;
    string tmp,tmp1;
    string real_output,your_output,input;
    clock_t t1,t2;
    double running_time;
    freopen("TT/numberofinput","r",stdin);
    cin>>numberoftests;
    
    
    for(int i=1;i<=numberoftests;i++){
        real_output = "";
        your_output = "";
        cout<<"-------------TEST "<<i<<"----------"<<endl;
        // read the files
        string in="TT/input-"+to_string(i);
        string out="TT/output-"+to_string(i);
        //prepare the command
        string s1 = string(argv[1])+"< "+in;
        string s2 ="("+s1+") > out";
        // execute the command
        t1 = clock();
        system(s2.c_str());
        t2 = clock();
        running_time = ((double)t2 - (double)t1)/(double)CLOCKS_PER_SEC;
        bool cond = true;
        cout<<"Input :"<<endl;
        std::ifstream inputa(in.c_str());
        while(getline(inputa,tmp)){
            cout<<tmp<<endl;
        }
        cout<<"--------------------"<<endl;

         std::ifstream outputcode("out"),outputreal(out.c_str());
        while(getline(outputcode,tmp)){
            getline(outputreal,tmp1);
            your_output+=tmp+"\n";
            real_output+=tmp1+"\n";
            if(tmp!=tmp1)
                cond = false;
            
        }

        cout<<"Your output :"<<endl;
        cout<<your_output<<endl;
        cout<<"--------------------"<<endl;
        cout<<"Programms output :"<<endl;
        cout<<real_output<<endl;
        cout<<"--------------------"<<endl;
        cout<<"time : "<<running_time<<"s"<<endl;;
        if(cond)
            cout<<"verrdict :ACCEPTED",nbr++;
        else
            cout<<"verrdict :WRONG ANSWER";
        cout<<endl;

    }

    cout<<nbr<<"/ "<<numberoftests<<endl;
    if(nbr!=numberoftests){
        cout<<"Wrong Answer"<<endl;
    }else 
    cout<<"Accepted"<<endl;
    return 0;
}