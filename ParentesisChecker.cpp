

#include <bits/stdc++.h>

using namespace std;

bool checkParenthesis(string& str){
    int n = str.length();
    stack<char> st;
    for(int i=0; i<n; i++){
        if(str[i]=='(' || str[i] == '{' || str[i]=='['){
            st.push(str[i]);
        }else{
            if(st.empty())
            return false;
            
            char t = st.top();
            st.pop();
            if(str[i]==')' && (t=='{' || t=='[')){
                return false;
            }else if((str[i]==']') && (t=='{' || t=='(')){
                return false;
            }
        }
    }
 
    
    return true;
}

int main()
{
    string str;
    cin>>str;
    if(checkParenthesis(str)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}
