#include<bits/stdc++.h>
using namespace std;
int n;
string s[10000];
void proxy()
{
    string t="server_out.yaml";
    freopen(t.c_str(),"r",stdin);
    while(getline(cin,t))
    {
        if(t.find("name")!=t.npos&&t.find("server")!=t.npos)
        {
            s[++n]=t;
            for(int j=0;j<s[n].length();j++)
                if(s[n][j]==',')
                {
                    s[n]=s[n].substr(j+1);
                    break;
                }
        }
    }
    fclose(stdin);

    sort(s+1,s+n+1);
    n=unique(s+1,s+n+1)-s-1;
    for(int i=1;i<=n;i++)
    {
        s[i]="  - {name: "+to_string(i)+","+s[i];
        cout<<s[i]<<endl;
    }
}
void print()
{
    for(int i=1;i<=n;i++)
    {
        printf("      -   ");
        printf("%d\n",i);
    }
}
int main()
{
    freopen("out.yaml","w",stdout);
    printf("port: 7890\n"
    "socks-port: 7891\n"
    "allow-lan: true\n"
    "mode: Rule\n"
    "log-level: info\n"
    "external-controller: :9090\n");
    puts("proxies:");
    proxy();
    printf( "proxy-groups:\n"
            "  - name: 🔰 节点选择\n"
            "    type: select\n"
            "    proxies:\n"
            "      - ♻️ 自动选择\n"
            "      - 🎯 全球直连\n");
    print();

    printf( "  - name: ♻️ 自动选择\n"
            "    type: url-test\n"
            "    url: http://www.gstatic.com/generate_204\n"
            "    interval: 300\n"
            "    tolerance: 0\n"
            "    proxies:\n");
    print();

    printf( "  - name: 🌍 国外媒体\n"
            "    type: select\n"
            "    proxies:\n"
            "      - 🔰 节点选择\n"
            "      - ♻️ 自动选择\n"
            "      - 🎯 全球直连\n");
    print();

    printf(  "  - name: 🌏 国内媒体\n"
            "    type: select\n"
            "    proxies:\n"
            "      - 🎯 全球直连\n"
            "      - 🔰 节点选择\n");

    printf( "  - name: Ⓜ️ 微软服务\n"
            "    type: select\n"
            "    proxies:\n"
            "      - 🎯 全球直连\n"
            "      - 🔰 节点选择\n");
    print();
        
    printf( "  - name: 📲 电报信息\n"
            "    type: select\n"
            "    proxies:\n"
            "      - 🔰 节点选择\n"
            "      - 🎯 全球直连\n");
    print();
        
    printf( "  - name: 🍎 苹果服务\n"
            "    type: select\n"
            "    proxies:\n"
            "      - 🔰 节点选择\n"
            "      - 🎯 全球直连\n"
            "      - ♻️ 自动选择\n");
    print();
        
    printf( "  - name: 🎯 全球直连\n"
            "    type: select\n"
            "    proxies:\n"
            "      - DIRECT\n");
        
    printf( "  - name: 🛑 全球拦截\n"
            "    type: select\n"
            "    proxies:\n"
            "       - REJECT\n"
            "       - DIRECT\n");
        
    printf( "  - name: 🐟 漏网之鱼\n"
            "    type: select\n"
            "    proxies:\n"
            "      - 🔰 节点选择\n"
            "      - 🎯 全球直连\n"
            "      - ♻️ 自动选择\n");
    print();
    fclose(stdout);
    system("cat rule.yaml >> out.yaml");

    system("cp out.yaml ../local.yaml;rm out.yaml");
    return 0;
}