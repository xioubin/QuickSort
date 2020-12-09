//
//  main.cpp
//  QuickSort
//
//  Created by 謝育斌 on 2020/12/3.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void partition(vector<string>& input,int begin,int end,int& loc){
    int left=begin,right=end,flag=0;
    loc=begin;
    while(flag==0){
        while(input[loc] <= input[right] && loc != right){
            right--;
        }
        if(loc==right){
            flag=1;
        }
        else if(input[loc] > input[right]){
            swap(input[loc],input[right]);
            loc=right;
        }
        if(flag==0){
            while(input[loc]>=input[left] && loc!=left){
                left++;
            }
            if(loc==left){
                flag=1;
            }
            else if(input[loc]<input[left]){
                swap(input[loc],input[left]);
                loc=left;
            }
        }
    }
}
void quicksort (vector<string>& input,int begin,int end){
    int loc;
    if(begin<end){
        partition(input,begin,end,loc);
        quicksort(input, begin, loc-1);
        quicksort(input, loc+1, end);
    }
    else
        return;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //cout<<"fuck you man."<<endl;
    string str;
    vector<string> input;
    getline(cin,str);
    stringstream ss(str);
    str.clear();
    while(ss>>str){
        input.push_back(str);
        str.clear();
    }
    quicksort(input, 0, (int)input.size()-1);
    for(int i=0;i<input.size();i++){
        cout<<input[i];
        if(i!=input.size()-1){
            cout<<" ";
        }
    }
}
