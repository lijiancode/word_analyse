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
void read_file(){//��ȡ�ļ��е��ַ�
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
void scan(char m){ //����ʶ��ؼ���
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
            while(s[i]!='\0'&&s[i]!=' '&&s[i]!='\n'&&s[i]!='('&&s[i]!='<'&&s[i]!='>'){ //��Ŀ���ַ������Ƹ�main_key
                 main_key+=s[i];
                 i++;
            }

            for(int p=1;p<=j;p++){  //�ж������Ƿ�������йؼ���

                 if(main_keys[p]== main_key){
                        sinal=1;
                 }
            }
            if(sinal==0){
                 main_keys[j]=main_key; //�������в����ڣ����Ŀ���ַ������뵽������
            }
       }

   }
   if(flag==1){
       for(int p=1;p<=j;p++){  //�ѵõ�������Ͷ�����ַ������Ƚϣ��жϹؼ����Ƿ����
         for(int m=0;m<key_length;m++){
                 if(main_keys[p]==key[m]){
                    cout<<"�ؼ��֣�"<<main_keys[p]<<endl;
                }
         }
       }
   }
}
void scan_var(char f,int n){//�жϱ�ʶ������
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
                        if(s[i+n]==' '&&(s[i-1]==' '||s[i-1]=='\n'))//�ж�Ŀ���ַ�ǰ�Ƿ�Ϊ�ո񣬻��з��Լ��Ƿ���ϱ�ʶ������
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
                                               else if(s[mm]=='('){//�ж��ǹؼ����Ƿ��Ƕ��庯������ֵ����
                                                        str1="";
                                                }


                                            }
                                            mm++;
                                        }
                                        if(ppp==1){//��������������ַ������뵽������
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
        if(iii==1){//�ж��Ƿ�ִ�������ݲ���
        cout<<"��ʶ��"<<types<<":"<<" ";
        for(int p=0;p<flag;p++){
            cout<<var_keys[p]<<" ";
        }
        cout<<endl;
        }

}
void Dividing_line(){//����ֽ������
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
if(flag==1){//�ж��Ƿ�ִ�������ݲ���
    cout<<"�ֽ����";
    for(int i=0;i<m;i++){
    cout<<line[i]<<" ";
    }
    cout<<endl;
}

}

void operators(char p){//�������������
  int sum=s.length();
  string str="";
  int t=0;
  int flag=0;
  int ee=0;
  string opers[100]={};
  for(int i=0;i<sum;i++){//�������������
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

          for(int b=0;b<operators_num;b++){//�жϵõ����ַ����Ƿ���Ŀ���ַ������������Ƿ��Ѿ����ڣ�
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
  if(flag==1){//�ж��Ƿ�ִ�������������
        cout<<"�������";
    for(int i=0;i<t;i++){
     cout<<opers[i]<<" ";
   }
   cout<<endl;
  }
}
void constant(){//���볣������
int sum=s.length();
string str="";
string number[100];
int t=0;
int flag=0;
for(int i=0;i<sum;i++){//�����ַ���
        if((s[i]>='0'&&s[i]<='9')||s[i]=='.'){
           str+=s[i];
           if((s[i+1]!='\0'&&s[i+1]>='0'&&s[i+1]<='9')||s[i+1]=='.'){//�ж���һ���ַ��Ƿ�������

           }
           else{
            number[t]=str;
            str="";
            t++;
            flag=1;
           }
        }

}

if(flag==1){//�ж��Ƿ�ִ�������ݲ���
cout<<"������";
for(int i=0;i<t;i++){
    cout<<number[i]<<" ";
    }
  }
}
void scans(){//�жϹؼ��ּ���
  scan('c');
  scan('i');
  scan('d');
  scan('r');
  scan('f');
  scan('m');
  scan('v');
}
void scan_vars(){//�жϱ�ʶ����������
scan_var('i',3);
scan_var('d',6);
scan_var('f',5);
scan_var('b',5);
scan_var('c',4);
scan_var('s',6);
}
void operatorses(){//�ж��������������
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
