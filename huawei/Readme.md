### 识别有效的IP地址和掩码并进行分类
掩码不一定都是255或者0组成的,这点需要注意.
掩码验证这里使用的是取反加一,此时二进制表达中应该只有一个1
`if((mask32&(mask32-1))!=0) flag_mask=true;`注意要加括号,**优先级**问题.
```cpp
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
enum type
{
    A,
    B,
    C,
    D,
    E,
    W,
    P,
};
int string_to_int(string s)
{
    stringstream ss;
    ss<<s;
    int res;
    ss>>res;
    return res;
}
int main()
{
    int res[7]={};
    string s;
    bool flag_mask=false;
    bool flag_ip=false;
    while(cin>>s)
    {
        string ip;
        string mask;
        int index=0;
        int len=s.size();
        while(index<len)
        {
            if(s[index++]=='~') break;
        }
        ip=s.substr(0,index-1);
        mask=s.substr(index,len-index+1-1);
        int mask_ary[4];
        index=0;
        int idx=0;
        int start;
        int counts_zero=0;
        while(index<mask.size())
        {
            start=index;
            while(mask[index++]!='.');
            string tmp=mask.substr(start,index-start-1);
            mask_ary[idx++]=string_to_int(tmp);
        }
        unsigned int mask32=0;
        for(int i=0;i<4;i++)
        {
            mask32+=mask_ary[i]<<((3-i)*8);
        }
        mask32=~mask32+1;
        int a=mask32&(mask32-1);
        if((mask32&(mask32-1))!=0) flag_mask=true;
        if(mask_ary[0]==255&&mask_ary[1]==255&&mask_ary[2]==255&&mask_ary[3]==255) flag_mask=true;
        if(flag_mask)
        {
            res[type::W]++;
            flag_mask=false;
            continue;
        }
        string ip_array[4];
        index=0;
        idx=0;
        //cout<<ip<<endl;
        while(index<ip.size())
        {
            start=index;
            while(ip[index++]!='.');
            string tmp=ip.substr(start,index-start-1);
            //cout<<index<<"  "<<start<<"  "<<tmp<<" he"<<endl;
            if(tmp==""||string_to_int(tmp)>255||string_to_int(tmp)<0)
            {
                flag_ip=true;
                break;
            }
            ip_array[idx++]=tmp;
        }
        if(idx==3) flag_ip=true;
        if(flag_ip)
        {
            res[type::W]++;
            flag_ip=false;
            continue;
        }
        //cout<<ip_array[0]<<endl;
        int ip_arr[4];
        for(int i=0;i<4;i++)
        {
            ip_arr[i]=string_to_int(ip_array[i]);
        }
        //cout<<ip_arr[0]<<endl;
        if(ip_arr[0]>=1&&ip_arr[0]<=126) res[type::A]++;
        if(ip_arr[0]>=128&&ip_arr[0]<=191) res[type::B]++;
        if(ip_arr[0]>=192&&ip_arr[0]<=223) res[type::C]++;
        if(ip_arr[0]>=224&&ip_arr[0]<=239) res[type::D]++;
        if(ip_arr[0]>=240&&ip_arr[0]<=255) res[type::E]++;
        if(ip_arr[0]==10) res[type::P]++;
        if(ip_arr[0]==172&&ip_arr[1]>=16&&ip_arr[1]<=31) res[type::P]++;
        if(ip_arr[0]==192&&ip_arr[1]==168) res[type::P]++;
    }
    cout<<res[type::A]<<" "<<res[type::B]<<" "<<res[type::C]<<" "<<res[type::D]<<" "<<res[type::E]<<" "<<res[type::W]<<" "<<res[type::P]<<endl;
    return 0;
}
```
### 密码验证合格程序
题目里说`不能有相同长度超过2的子串重复`,这特娘的意思不就是要判断是否有长度为3的子串重复么!
```cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string password;
    while(cin>>password)
    {
        if(password.size()<9)
        {
            cout<<"NG"<<endl;
            continue;
        }
        int s_c=0,b_c=0,n=0,o=0;
        for(int i=0;i<password.size();i++)
        {
            char c=password[i];
            if(c>='a'&&c<='z') s_c=1;
            else if(c>='A'&&c<='Z') b_c=1;
            else if(c>='0'&&c<='9') n=1;
            else o=1;
        }
        if(s_c+b_c+n+o<3)
        {
            cout<<"NG"<<endl;
            continue;
        }
        bool flag=false;
        for(int i=0;i<password.size()-6;i++)
        {
            for(int j=i+3;j<password.size()-3;j++)
            {
                if(password[i]==password[j]&&password[i+1]==password[j+1]&&password[i+2]==password[j+2])
                {
                    cout<<"NG"<<endl;
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        //cout<<password<<endl;
        if(!flag) cout<<"OK"<<endl;
    }
    return 0;
}
```