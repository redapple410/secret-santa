// Secret Santa Randomizer
/*
Sample Input:
4
Alice alice@mail.com
Bob bob234@mail.com
Carol car@mail.com
David dave@mail.com

Sample Output:
4
Alice Bob Carol David
alice@mail.com bob234@mail.com car@mail.com dave@mail.com
Bob David Alice Carol

Notes:
- names and emails cannot have spaces
- must have between 4 and 20 people, inclusive
- use a command like "head -n 1 names.out" to verify that the thing worked
*/

#include <bits/stdc++.h>

using namespace std;

int n;
map<string, string> em;
vector<string> fr, to, tmp;

void choose(int sd){
  to.clear();
  tmp.clear();
  for(auto i:fr){
    tmp.push_back(i);
  }
  default_random_engine gen(sd);
  int cur=0, giveup=100;
  while(!tmp.empty() && giveup--){
    uniform_int_distribution<int> r(0, tmp.size()-1);
    int idx=r(gen);
    if(fr[cur]!=tmp[idx]){
      to.push_back(tmp[idx]);
      tmp.erase(tmp.begin()+idx);
      cur++;
    }
  }
}

bool check(){
  for(int i=0;i<fr.size();i++){
    if(fr[i]==to[i]){
      return false;
    }
  }
  return true;
}

void output(){
  cout<<n<<"\n";
  // Output as a list of <from-name>, <from-email>, then a list of <to-name>
  for(int i=0;i<fr.size();i++){
    cout<<fr[i]<<" ";
  }
  cout<<"\n";
  for(int i=0;i<fr.size();i++){
    cout<<em[fr[i]]<<" ";
  }
  cout<<"\n";
  for(int i=0;i<to.size();i++){
    cout<<to[i]<<" ";
  }
  cout<<"\n";
  // Output as a list of <from-email> <to-name>
  /*for(int i=0;i<fr.size();i++){
    cout<<em[fr[i]]<<" "<<to[i]<<"\n";
  }*/
}

int main(){

  freopen("names.in", "r", stdin);
	freopen("names.out", "w", stdout);

  cin>>n;

  if(n<=3){
    cout<<"Sorry! (not enough people)\n";
    return 0;
  }
  else if(n>20){
    cout<<"Sorry! (too many people)\n";
    return 0;
  }

  for(int i=1;i<=n;i++){
    string nm, eml;
    cin>>nm>>eml;
    em[nm]=eml;
    fr.push_back(nm);
  }

  for(int i=1;i<=10000;i++){
    choose((long long) time(NULL));
    if(check()){
      output();
      return 0;
    }
  }

  cout<<"Sorry! (couldn't make a match)\n";

}
