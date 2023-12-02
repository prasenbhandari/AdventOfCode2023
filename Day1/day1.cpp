#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>
using std::cout,std::endl;

int concatenate(char a, char b){
    std::string s;
    if(std::isdigit(a) && std::isdigit(b))
        s = std::string(1,a) + b;

    if(!s.empty())
        return std::stoi(s);
    else
        return 0;
}

int main(){
    std::ifstream input_file("day1.txt"); // opening file
    std::string line;
    std::vector<int> num;
    std::vector<std::string> lines;


    std::map<std::string, std::string> num_word{
        {"one", "o1e"}, {"two", "t2o"}, {"three", "t3e"}, {"four", "f4r"}, {"five", "f5e"}, {"six", "s6x"}, {"seven", "s7n"}, {"eight", "e8t"}, {"nine", "n9e"}, {"zero", "z0o"}
    };



    //part 1
    while(std::getline(input_file,line)){
        lines.emplace_back(line);
    }

    for(std::string& v: lines){
        //part 2
        for(const auto& j: num_word){   //replace word with number
            int pos = v.find(j.first);
            while(pos != std::string::npos){
                v.replace(pos, j.first.length(), j.second);
                pos = v.find(j.first);
            }
        }

        //for(const auto& j: num_word){   //replace word with number
        //    int pos = v.find(j.first);
        //    if(pos != std::string::npos){
        //        v.replace(pos, j.first.length(), j.second);
        //    }
        //}

        //cout << "[" << v << "]\n";

        char front = '\0', back;

        for(auto i: v){ //check for number
            if(std::isdigit(i)){
                if(front == '\0')
                    front = i;

                back = i;
            }
        }
        //cout << "[" << front << back << "]\n";
        num.emplace_back(concatenate(front, back));
    }

    int sum = std::accumulate(num.begin(), num.end(), 0);
    cout << sum;

}
