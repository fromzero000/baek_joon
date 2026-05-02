#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) 
{
    int layerNum = (num - 1) / w;
    int colNum = (num - 1) % w;
    if (layerNum % 2 != 0) 
    {
        colNum = w - 1 - colNum;
    }
    
    int layerTop = (n - 1) / w;
    int colTop = (n - 1) % w;
    if (layerTop % 2 != 0) 
    {
        colTop = w - 1 - colTop;
    }
    
    int answer = layerTop - layerNum;
    
    if (layerTop % 2 == 0) 
    {
        if (colNum <= colTop) 
        {
            answer++;
        }
    } else 
    {
        if (colNum >= colTop) 
        {
            answer++;
        }
    }
    
    return answer;
}