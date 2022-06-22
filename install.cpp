#include<iostream>
#include<stdio.h>
#include<filesystem>
#include <unistd.h>

#define GREEN "\033[32m"

bool set_user_variables(std::string path);
bool set_path(std::string path);

int main(){
    using namespace std;
    string path;
    cout<<"Please eneter the destination of this file: ";
    cin>>path;
    if(set_user_variables(path)==true&&set_path(path)==true){
        cout<< GREEN<<"Cordova variables set up completed"<<endl;
    }

    return 0;
}

bool set_user_variables(std::string path){
    using namespace std;
    string command_Java="set JAVA_HOME="+path+"\\jre1.8.0_321";
    string command_Gradle="set ANT_HOME="+path+"\\gradle-7.4\\bin";
    string command_Android="set GRADLE_HOME="+path+"\\Android\\Sdk";
    string command_Ant="set ANDROID_HOME="+path+"\\apache-ant-1.10.12";
    string command_java_option = "set _JAVA_OPTIONS=-Xmx512M";

    system((command_Java).c_str());
    system((command_Gradle).c_str());
    system((command_Android).c_str());
    system((command_Ant).c_str());
    system((command_java_option).c_str());
    return true;
}


bool set_path(std::string path){
    using namespace std;
    string command_Java="set PATH=%PATH%;%JAVA_HOME%";
    string command_Gradle="set PATH=%PATH%;%GRADLE_HOME%";
    string command_Android_tools="set PATH=%PATH%;"+path+"\\Android\\Sdk\\tools";
    string command_Android_tools_bin="set PATH=%PATH%;"+path+"\\Android\\Sdk\\tools\\bin";
    string command_Android_platform="set PATH=%PATH%;"+path+"\\Android\\platform-tools";
    string command_Ant="set PATH=%PATH%;%ANT_HOME%";
    string command_Android="set PATH=%PATH%;%ANDROID_HOME%";

    system((command_Java).c_str());
    system((command_Gradle).c_str());
    system((command_Android).c_str());
    system((command_Ant).c_str());
    system((command_Android_platform).c_str());
    system((command_Android_tools).c_str());
    system((command_Android_tools_bin).c_str());


    return true;
}