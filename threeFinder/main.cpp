#include <iostream>
#include <map>

using namespace std;

struct stVertex
{
    int d_left;
    int d_right;
    int d_value;
};

void inOrder(map<int, stVertex> &threeMap, int iter);
void preOrder(map<int, stVertex> &threeMap, int iter);
void postOrder(map<int, stVertex> &threeMap, int iter);

int main()
{
    int vertexCount;
    cin >> vertexCount;

    map<int, stVertex> threeMap;
    for(int i = 0; i < vertexCount; i++){
        cin >> threeMap[i].d_value >> threeMap[i].d_left >> threeMap[i].d_right;
    }

    inOrder(threeMap, 0);
    cout << endl;
    preOrder(threeMap, 0);
    cout << endl;
    postOrder(threeMap, 0);
    return 0;
}

void inOrder(map<int, stVertex> &threeMap, int iter)
{
    if(iter == -1)
        return;
    inOrder(threeMap, threeMap[iter].d_left);
    cout << threeMap[iter].d_value << " ";
    inOrder(threeMap, threeMap[iter].d_right);
}

void preOrder(map<int, stVertex> &threeMap, int iter)
{
    if(iter == -1)
        return;
    cout << threeMap[iter].d_value << " ";
    preOrder(threeMap, threeMap[iter].d_left);
    preOrder(threeMap, threeMap[iter].d_right);
}

void postOrder(map<int, stVertex> &threeMap, int iter)
{
    if(iter == -1)
        return;
    postOrder(threeMap, threeMap[iter].d_left);
    postOrder(threeMap, threeMap[iter].d_right);
    cout << threeMap[iter].d_value << " ";

}
