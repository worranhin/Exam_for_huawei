#include<iostream>
#include<string>
//#include<vector>
//#include<unordered_map>
using namespace std;

struct Record {
    string fileName;
    unsigned int lineNumber;
    unsigned int count;
};

int main(){
    string path;  //路径
    string fileName;  //文件名
    unsigned int lineNumber;  //行号
    Record records[100];  // 记录数组
    int recordCount = 0;  // 记录数目
    
    // 输入
    cin >> path;
    cin >> lineNumber;
    
    while(!cin.eof()) {
        // 提取并处理文件名
        auto x = path.find_last_of('\\');
        fileName = path.substr(x+1);
        if(fileName.length() > 16) {
            fileName.erase(fileName.begin(), fileName.end() - 16);
        }

        // 查重
        bool hasSameRecord = false;
        int sameRecordIndex = -1;
        for(int i = 0; i < recordCount; i++) {
            int findIndex = i;
            if(fileName == records[findIndex].fileName && lineNumber == records[findIndex].lineNumber) {
                hasSameRecord = true;
                sameRecordIndex = findIndex;
                break;
            }
        }

        if(hasSameRecord) {
            records[sameRecordIndex].count++;
        } else {
            records[recordCount].fileName = fileName;
            records[recordCount].lineNumber = lineNumber;
            records[recordCount].count = 1;

            recordCount++;
        }
        
        // 下一次输入
        cin >> path;
        cin >> lineNumber;
    }

    int startShowIndex = recordCount > 8 ? recordCount - 8 : 0;
    for(int i = startShowIndex; i < recordCount; i++) {
        int showIndex = i;
        cout << records[i].fileName << ' ' << records[i].lineNumber << ' ' << records[i].count << endl;
    }
    
    return 0;    
}
