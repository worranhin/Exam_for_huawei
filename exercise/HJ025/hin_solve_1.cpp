#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

struct I_item {
    int index;
    int value;
};

class R_Section {
    public:
    R_Section(int R_value) {
        _R_value = R_value;
        _amount = 0;
        _I_list.clear();
    }
    
    int length(void) {
        return _amount;
    }
    
    int value(void) {
        return _R_value;
    }
    
    void insert(int index, int value) {
        I_item temp{index, value};
        _I_list.push_back(temp);
        _amount++;
    }
    
    void print(void) {
        if(_amount == 0) {
            cout << "nothing" << endl;
            return;
        }
        
        cout << _R_value << ' ';
        cout << _amount << ' ';
        
        for(auto temp : _I_list) {
            cout << temp.index << ' ' << temp.value << ' ';
        }
    }
    
    // TODO: 感觉这种传参该改参的方式有点不妙啊
    string toString(int &count) {
        if(_amount == 0) {
            return "nothing ";
        }
        
        string str;
        
        str += to_string(_R_value) + " ";
        str += to_string(_amount) + " ";
        
        count += 2;  // 输出整数的个数
        
        for(auto temp : _I_list) {
            str += to_string(temp.index) + " " + to_string(temp.value) + " ";
            count += 2;
        }
        return str;
    }
    
    private:
    int _R_value;
    int _amount;
    vector<I_item> _I_list;
};

class Classify {
    public:
    Classify(vector<int> I, vector<int> R) {
        // 初始化
        _I_vector = I;
        _R_vector = R;
        set<int> R_set(R.begin(), R.end());
        _R_set = R_set;
        _R_list.clear();
        _size = 0;
        
        // 创建 R 列表
        for(auto x : _R_set) {
            R_Section sec(x);
            int digit = 10;
            while(x / digit > 0)
                digit *= 10;
            for(int i = 0; i < _I_vector.size(); i++) {
                int y = _I_vector[i];
                // 检查 x(R) 是否在 y(I) 中
                bool checked = false;
                int yy = y;
                if(yy == 0 && x == 0)  // 若都等于 0，符合条件
                    checked = true;
                while(checked == false && yy > 0) {
                    if(yy % digit == x) {  // 检查y(I)是否包含x(R)
                        checked = true;
                        break;
                    }
                    yy /= 10;
                }
                
                if(checked) {  // 若符合条件，将 y 插入列表中
                    sec.insert(i, y);
                    _size++;
                }
            }
            _R_list.push_back(sec);
        }
    }
    
    void print(void) {
        int count = 0;  // 计算输出整数的个数
        string str;
        for(auto sec : _R_list) {
            if(sec.length() == 0)  // 若无元素则跳过
                continue;
            
            str.append(sec.toString(count));
        }
        
        cout << count << ' ' << str << endl;
    }
    private:
    vector<int> _I_vector;
    vector<int> _R_vector;
    set<int> _R_set;
    vector<R_Section> _R_list;
    int _size;
};

int main() {
    int I_size = 0, R_size = 0;
    
    // 输入
    cin >> I_size;
    vector<int> I(I_size);
    for(int i = 0; i < I_size; i++)
        cin >> I[i];
    
    cin >> R_size;
    vector<int> R(R_size);
    for(int i = 0; i < R_size; i++)
        cin >> R[i];
    
    // 调用算法
    Classify classify(I, R);
    classify.print();
        
    return 0;
}
