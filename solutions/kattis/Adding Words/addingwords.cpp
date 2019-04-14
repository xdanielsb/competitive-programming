/**
 *    author:  xdanielsb
 *    created: 2017-01-11
**/
#include<iostream>
#include<map>
#include<string>

using namespace std;

typedef string s;
typedef map <s, int> vars;
typedef map <int, s> values;
int main(){
    string  type, var;
    int value;   

    vars ns;
    values vs;
    while(cin >> type){
    //  cout<< endl << type << endl;
        if (type.compare("def") == 0){
            cin >> var >> value;
            if(ns.find(var) != ns.end()){
                int old = ns[var];
                ns.erase(var);
                vs.erase(old);
            }

            ns[var] = value;
            vs[value] = var;
        }else if(type.compare("calc") == 0){
            int aux = 0;
            bool in = false;
            int mul = 1;
            string call ="";

            while(call.compare("=") != 0){ 
                cin >> call;
                cout << call << " "; 
                            
                if (call.compare("-")== 0 ){
                    mul = -1;
                    continue;
                }
                else if( call.compare("+") == 0){
                    continue;
                }else if (call.compare("=") !=0 ){
                    auto aux2 = ns.find(call); 
                    if (aux2 != ns.end()){
                     //   cout << endl << "no encontrado "<< call << endl;
                        aux += ns[call]*mul;
                    }else{
                        in = true;
                    }
                    mul  = 1;
                }


            }

            if (in || vs[aux] == ""){
                cout << "unknown" <<endl;
            }else{
                cout << vs[aux] << endl;
            }

        }else if(type =="clear") {
            /*map<string,int>::iterator it;
            for (it=ns.begin(); it!=ns.end(); ++it)
                cout << it->first << " => " << it->second << '\n';*/

            ns.clear();
            vs.clear();
        }
    }
    return 0;

}
