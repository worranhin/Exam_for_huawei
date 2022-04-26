let n = parseInt(readline());  // 元素个数
let lines = [];
while(n--){
    let line = readline();  // 读入 n 个单词
    lines.push(line);
}
lines.sort();  // 排序
while(lines.length > 0){
    print(lines.shift());  // 输出
}
