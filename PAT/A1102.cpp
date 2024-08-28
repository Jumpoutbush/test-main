/*
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6

*/
//1.输入数据怎么构成树的，这题用二叉树静态存储,每个节点保存左右孩子信息
//2.根节点3没有输入，怎么找根节点
//3.后序怎么invert的：不输出直接swap

 #include<bits/stdc++.h>
 using namespace std;
 const int maxn = 110;
 struct node{
    int lchild, rchild;
 }Node[maxn];
 bool notRoot[maxn] = {false};
 int n, num = 0;
 void print(int id)
 {
    printf("%d", id);
    num++;
    if(num < n) printf(" ");
    else printf("\n");
 }
 int findRoot()
 {
    for(int i = 0; i < n; i++)
    {
        if(notRoot[i] == false)
        {
            return i;
        }
    }
 }
 void inOrder(int root)
 {
    if(root == -1)
        return ;
    inOrder(Node[root].lchild);
    print(root);
    inOrder(Node[root].rchild);
 }
 void BFS(int root)
 {
    queue<int> q;
    q.push(root);
    while(!q.empty()) 
    {
        int now = q.front();
        q.pop();
        print(now);
        if(Node[now].lchild != -1) q.push(Node[now].lchild);
        if(Node[now].rchild != -1) q.push(Node[now].rchild);
    }
 }
 void postOrder(int root)
 {
    if(root == -1)
        return;
    postOrder(Node[root].lchild);
    postOrder(Node[root].rchild);
    swap(Node[root].lchild, Node[root].rchild);
 }
 int strToNum(char c)
 {
    if(c == '-') return -1;
    else{
        notRoot[c - '0'] = true;
        return c - '0';
    }
 }
 int main()
 {
    char lchild, rchild;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%*c%c %c", &lchild, &rchild);
        Node[i].lchild = strToNum(lchild);
        Node[i].rchild = strToNum(rchild);
    }
    int root = findRoot();
    postOrder(root);
    BFS(root);
    num = 0;
    inOrder(root);
    system("pause");
    return 0;
 }