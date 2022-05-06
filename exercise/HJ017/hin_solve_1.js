const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
rl.on("line", function (line) {
  const tokens = line.split(";");
  //初始化坐标
  let location = {
    x: 0,
    y: 0,
  };

  tokens.forEach((sec) => {
    //格式检查
    let errorFormat = false;
    for (let i = 1; i < sec.length; i++) {
      if (sec[i] < "0" || sec[i] > "9") {
        errorFormat = true;
        break;
      }
    }
    if (errorFormat) return;
    const move = parseInt(sec.slice(1));

    //选择方向
    switch (sec[0]) {
      case "A":
        location.x -= move;
        break;
      case "D":
        location.x += move;
        break;
      case "S":
        location.y -= move;
        break;
      case "W":
        location.y += move;
        break;
    }
  });
  
  //输出
  console.log(`${location.x},${location.y}`);
});
