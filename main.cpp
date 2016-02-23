#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
string s;
string key[]={"int","void","cout","cin","return","main","double","float"};
string operators_key[]={"+","-","*","/","++","--",">=","<=","=","+="};
string var[]={"int","float","double"};
int operators_num=10;
int var_length =3;
int key_length =6;
void read_file(){//读取文件中的字符
    char ch;
    fstream infile("s.txt",ios::in);
    if(!infile){
       cerr<<"open error"<<endl;
       exit(1);
    }
    while(infile.get(ch)!=0){
            s+=ch;
    }
    infile.close();
}
void scan(char m){ //分离识别关键字
   int sum;
   int j=0;
   int flag=0;
   sum =s.length();
   string main_keys[100]={};
   for(int i=0;i<sum;i++){

       if(s[i]==m && s[i]!=' '&&s[i]!='\n')
        {
            j++;
            flag=1;
            string main_key;
            int sinal=0;
            while(s[i]!='\0'&&s[i]!=' '&&s[i]!='\n'&&s[i]!='('&&s[i]!='<'&&s[i]!='>'){ //把目标字符串复制给main_key
                 main_key+=s[i];
                 i++;
            }

            for(int p=1;p<=j;p++){  //判断数组是否存在已有关键字

                 if(main_keys[p]== main_key){
                        sinal=1;
                 }
            }
            if(sinal==0){
                 main_keys[j]=main_key; //若数组中不存在，则把目标字符串插入到数组中
            }
       }

   }
   if(flag==1){
       for(int p=1;p<=j;p++){  //把得到的数组和定义的字符串做比较，判断关键字是否存在
         for(int m=0;m<key_length;m++){
                 if(main_keys[p]==key[m]){
                    cout<<"关键字："<<main_keys[p]<<endl;
                }
         }
       }
   }
}
void scan_var(char f,int n){//判断标识符函数
    int sum;
    string types="";
    int iii=0;
    int flag=0;
    int mm=0;
    int ppp=0;
    string temps;
    sum =s.length();
    string str;
    string str1;
    string var_keys[100]={};
    for(int i=0;i<sum;i++){
            if(s[i]==f){
                if(s[i+n]!='\0'){
                        if(s[i+n]==' '&&(s[i-1]==' '||s[i-1]=='\n'))//判断目标字符前是否为空格，换行符以及是否符合标识符长度
                            {
                              str=s.substr(i,n);
                              for(int l=0;l<var_length;l++){
                                    if(str==var[l]){
                                        mm=i+n;
                                        while(s[mm]!='\0'&&s[mm]!='\n'&&s[mm]!=';'){
                                            if((s[mm]>='A'&&s[mm]<='z')||(s[mm]>='0'&&s[mm]<='9')||(s[mm]==',')||(s[mm]=='(')){
                                                types=str;
                                               if(s[mm]!=','&&s[mm]!='('){
                                                str1+=s[mm];
                                               }
                                               else if(s[mm]==','){
                                                var_keys[flag]=str1;
                                                str1="";
                                                flag++;
                                                ppp=1;
                                               }
                                               else if(s[mm]=='('){//判断是关键字是否是定义函数返回值类型
                                                        str1="";
                                                }


                                            }
                                            mm++;
                                        }
                                        if(ppp==1){//符合条件，则把字符串插入到数组中
                                             var_keys[flag]=str1;
                                             str1="";
                                             flag=flag+1;
                                             iii=1;

                                        }
                                    }
                              }

                            }
                         }

                  }
        }
        if(iii==1){//判断是否执行了数据插入
        cout<<"标识符"<<types<<":"<<" ";
        for(int p=0;p<flag;p++){
            cout<<var_keys[p]<<" ";
        }
        cout<<endl;
        }

}
void Dividing_line(){//分离分界符函数
int sum=s.length();
int m=0;
int flag=0;
int ss=0;
char line[100]={};
for(int i=0;i<sum;i++){
    if(s[i]=='('||s[i]==')'||s[i]==';'||s[i]=='{'||s[i]=='}'||s[i]==','){

            for(int p=0;p<=m;p++){
                if(line[p]==s[i]){
                  ss=1;
                }
              }

            if(ss==0){
               line[m]=s[i];
                ss=0;
                flag=1;
                m++;
            }
            ss=0;

    }
}
if(flag==1){//判断是否执行了数据插入
    cout<<"分界符：";
    for(int i=0;i<m;i++){
    cout<<line[i]<<" ";
    }
    cout<<endl;
}

}

void operators(char p){//分离运算符函数
  int sum=s.length();
  string str="";
  int t=0;
  int flag=0;
  int ee=0;
  string opers[100]={};
  for(int i=0;i<sum;i++){//遍历运算符函数
      if(s[i+1]!='\0')
      {
        if(s[i]==p)
        {
            if(s[i]==p&&s[i+1]=='=')
            {
                str=s[i];
                str=str+s[i+1];
            }
            else if(s[i]==p&&s[i+1]==p){
                str=s[i];
                str=str+s[i+1];
                i++;
            }
            else{
              str=s[i];
            }

          for(int b=0;b<operators_num;b++){//判断得到的字符串是否是目标字符串和数组中是否已经存在；
             if(operators_key[b]==str){
                for(int y=0;y<=t;y++){
                 if(str==opers[y]){
                     ee=1;
                  }
                 else{
                      ee=2;

                 }
                }

             }

           }
           if(ee==2){
                      opers[t]=str;
                      str="";
                      t++;
                      flag=1;
                      ee=0;
                }
       }
       str="";

    }
  }
  if(flag==1){//判断是否执行了运算符插入
        cout<<"运算符：";
    for(int i=0;i<t;i++){
     cout<<opers[i]<<" ";
   }
   cout<<endl;
  }
}
void constant(){//分离常量函数
int sum=s.length();
string str="";
string number[100];
int t=0;
int flag=0;
for(int i=0;i<sum;i++){//遍历字符串
        if((s[i]>='0'&&s[i]<='9')||s[i]=='.'){
           str+=s[i];
           if((s[i+1]!='\0'&&s[i+1]>='0'&&s[i+1]<='9')||s[i+1]=='.'){//判断下一个字符是否是数字

           }
           else{
            number[t]=str;
            str="";
            t++;
            flag=1;
           }
        }

}

if(flag==1){//判断是否执行了数据插入
cout<<"常数：";
for(int i=0;i<t;i++){
    cout<<number[i]<<" ";
    }
  }
}
void scans(){//判断关键字集合
  scan('c');
  scan('i');
  scan('d');
  scan('r');
  scan('f');
  scan('m');
  scan('v');
}
void scan_vars(){//判断标识符函数集合
scan_var('i',3);
scan_var('d',6);
scan_var('f',5);
scan_var('b',5);
scan_var('c',4);
scan_var('s',6);
}
void operatorses(){//判断运算符函数集合
operators('+');
operators('-');
operators('*');
operators('/');
operators('>');
operators('<');
}
int main()
{
   read_file();
   scans();
   scan_vars();
   Dividing_line();
   operatorses();
   constant();
   return 0;
}
