#include<bits/stdc++.h>
using namespace std;
bool flag[10000];
string s[10000];
int n;
int main()
{
    freopen("source.yaml","r",stdin);
    string t;
    while(getline(cin,t))
    {
        flag[++n]=1;
        if(t.find("error")!=t.npos)
            flag[n]=0;
    }
    fclose(stdin);
    cin.clear();

    freopen("server.yaml","r",stdin);
        for(int i=1;i<=n;i++)
            getline(cin,s[i]);
    fclose(stdin);

    freopen("server_out.yaml","w",stdout);
        for(int i=1;i<=n;i++)
            if(flag[i])
                cout<<s[i]<<endl;
    fclose(stdout);

    return 0;
}