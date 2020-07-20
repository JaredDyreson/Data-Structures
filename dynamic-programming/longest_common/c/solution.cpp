#include <iostream>
#include <string>
#include <vector>

std::string longest_common(std::string a, std::string b){

  std::string output = "";

  if(a.length() == 0 || b.length() == 0){ return output; }

  std::vector<std::vector<int> > cache(a.length() , std::vector<int> (b.length(), 0));  

  for(int i = 0; i < a.length(); ++i){
    for(int j = 0; j < b.length(); ++j){
      if(a[i] == b[j]){
        if(i == 0 || j == 0){
          cache[i][j] = 1;
        }
        else{
          cache[i][j] = cache[i-1][j-1] + 1;
        }
        if(cache[i][j] > output.length()){
          output = a.substr(i - cache[i][j] + 1, i+1);
        }
      }
    }
  }
  return output;
}

int main(){
  std::string out = longest_common("ABAB", "BABA");
  std::cout << "Longest substring is " << out  << " with length " << out.length() << std::endl;
  return 0;
}
