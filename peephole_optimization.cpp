#include<bits/stdc++.h>
using namespace std;
fstream oic("optimized_code.asm", std::ofstream::out | std::ofstream::trunc);
string trim(string str)
{
    while(!str.empty() and str.back()==' ') str.pop_back();
    reverse(str.begin(), str.end());
    while(!str.empty() and str.back()==' ') str.pop_back();
    reverse(str.begin(), str.end());
    return str;
}
bool useless_exchange(string prev, string cur)
{
    string op1, op2;
    int i;
    for(i=0;i<prev.size();i++){
        if(prev[i]==' ') { i++; break; }
        op1.push_back(prev[i]);
    }
    //cout<<op1<<endl;
    if(trim(op1)!="MOV") return false;
    
    string var11, var12;
    while(prev[i]!=',') var11.push_back(prev[i++]);
    i++;
    while(i<prev.size()) var12.push_back(prev[i++]);

    for(i=0;i<cur.size();i++){
        if(cur[i]==' ') { i++; break; }
        op2.push_back(cur[i]);
    }
    if(trim(op2)!="MOV") return false;

    
    string var21, var22;
    while(cur[i]!=',') var21.push_back(cur[i++]);
    i+=2;
    while(i<cur.size()) var22.push_back(cur[i++]);
    //cout<<var11<<" "<<var12<<" "<<var21<<" "<<var22<<endl;
    return trim(var11)==trim(var22) and trim(var12)==trim(var21);
}
bool useless_pushpop(string prev, string cur)
{
    string op1, op2;
    int i;
    for(i=0;i<prev.size();i++){
        if(prev[i]==' ') { i++; break; }
        op1.push_back(prev[i]);
    }
    //cout<<op1<<endl;
    if(trim(op1)!="PUSH") return false;
    string var1;
    while(i<prev.size()) var1.push_back(prev[i++]);

    for(i=0;i<cur.size();i++){
        if(cur[i]==' ') { i++; break; }
        op2.push_back(cur[i]);
    }
    //cout<<op2<<endl;
    if(trim(op2)!="POP") return false;
    string var2;
    while(i<cur.size()) var2.push_back(cur[i++]); 
    //cout<<var1<<" "<<var2<<endl;
    if(trim(op1)=="PUSH" and trim(op2)=="POP" and trim(var1)==trim(var2)) return true; 
    else return false;  
}
int main()
{
    ifstream fin("./code.asm");
    string str;
    vector<string> dic;
    while(getline(fin, str)) dic.push_back(str);

    string prev, cur;
    vector<string> opt;
    
    for(int i=0;i<dic.size();i++){
        if(opt.empty()) opt.push_back(dic[i]);
        else {
            prev=opt.back();
            cur=dic[i];
            if(useless_exchange(prev, cur)) { opt.pop_back(); continue; }
            if(useless_pushpop(prev, cur)) { opt.pop_back(); continue; }
            opt.push_back(dic[i]);
        }

    }
    for(string code: opt) oic<<code<<endl;
}