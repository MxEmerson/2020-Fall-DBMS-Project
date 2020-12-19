#include "pml_hash.h"
#include <fstream>
#include <iostream>
#include <dirent.h>
#include <regex>
#include <vector>
#include <string.h>
#include <cstdio>
#include <time.h>

vector <string> Filelist;
int testNum;
string dir_name = "../benchmark/";
void getFileList(){
    DIR *dir;
    struct dirent *dirp;
    //判断文件夹打开是否成功
    if ((dir=opendir(dir_name.c_str()))==NULL){
        cout << "fail to open " << dir_name << endl; 
    }
    //取出文件夹中的文件
    while ((dirp = readdir(dir)) != NULL){
        Filelist.push_back(dirp->d_name);
    }
    //关闭文件夹
    closedir(dir);
    //排序，使得read和write比例相同的read和load文件放在一起，
    //方便后续执行
    sort(Filelist.begin(),Filelist.end());
    //load和run各占一半
    testNum=Filelist.size()/2;
    for (int i=0; i<testNum; i++){
        cout << "[FIND FILE] " << Filelist[i*2] << " and " << Filelist[i*2+1] << endl;
    }
}
int main()
{
    PMLHash hash("/mnt/pmemdir/file");
    
    return 0;
}