// 商品类
class Item {
  constructor(v, p, b, id) {
    this.value = v;
    this.prior = p;
    this.belong = b;
    this.id = id;
    this.adjunct = [];
  }

  getSatisfaction() {
    return this.prior * this.value;
  }
}

// 变量声明
let N, n;
let items = [];

// 输入 N, n
let tmp1 = readline();
let tmp2 = tmp1.split(" ");
N = parseInt(tmp2[0]);
n = parseInt(tmp2[1]);

// 输入 items
for (let i = 0; i < n; i++) {
  let tmp = readline().split(" ");
  let v = parseInt(tmp[0]),
    p = parseInt(tmp[1]),
    b = parseInt(tmp[2]);
  items.push(new Item(v, p, b, i + 1));
}

// 初始化规划表
let allMax = 0;
let stab = new Array(n);
for (let i = 0; i < n; i++) {
  let tempA = new Array(N + 1).fill(0);
  stab[i] = tempA;
}

// 处理附属品
items.forEach(function (item) {
  let belong = item.belong;
  if (belong > 0) {
    items
      .find((item) => {
        return item.id == belong;
      })
      .adjunct.push(item.id);
  }
});

let itemProcessed = items.filter((item) => {
  return item.belong == 0;
});

// 先考虑第一个商品
const firstItem = itemProcessed[0];
const sati0 = firstItem.getSatisfaction(); // 当前商品的满意度
const adjLength = firstItem.adjunct.length; // 附属品数量
if (firstItem.adjunct[0]) {
  var adj1 = items.find((item) => {
    return item.id == firstItem.adjunct[0];
  });
  var sati1 = adj1.getSatisfaction();
}
if (firstItem.adjunct[1]) {
  var adj2 = items.find((item) => {
    return item.id == firstItem.adjunct[1];
  });
  var sati2 = adj2.getSatisfaction();
}

for (let j = 0; j <= N; j++) {
  let maxSatisfaction = 0;
  if (j >= firstItem.value) {
    maxSatisfaction = sati0;
  }
  if (adjLength >= 1 && j >= firstItem.value + adj1.value) {
    // 如果有附属品
    let stf = sati0 + sati1;
    maxSatisfaction = stf > maxSatisfaction ? stf : maxSatisfaction;
  }
  if (adjLength >= 2 && j >= firstItem.value + adj2.value) {
    let stf = sati0 + sati2;
    maxSatisfaction = stf > maxSatisfaction ? stf : maxSatisfaction;
  }
  if (adjLength >= 2 && j >= firstItem.value + adj1.value + adj2.value) {
    let stf = sati0 + sati1 + sati2;
    maxSatisfaction = stf > maxSatisfaction ? stf : maxSatisfaction;
  }
  stab[0][j] = maxSatisfaction;
  allMax = maxSatisfaction > allMax ? maxSatisfaction : allMax;
}

// 再考虑其他商品
for (let i = 1; i < itemProcessed.length; i++) {
  // 初始化
  const thisItem = itemProcessed[i];
  const sati0 = thisItem.getSatisfaction(); // 当前商品的满意度
  const adjLength = thisItem.adjunct.length; // 附属品数量
  if (adjLength >= 1) {
    var adj1 = items.find((item) => {
      return item.id == thisItem.adjunct[0];
    });
    var sati1 = adj1.getSatisfaction();
  }
  if (adjLength >= 2) {
    var adj2 = items.find((item) => {
      return item.id == thisItem.adjunct[1];
    });
    var sati2 = adj2.getSatisfaction();
  }

  for (let j = 0; j <= N; j++) {
    let maxSatisfaction = stab[i - 1][j];
    // check the item
    if (j >= thisItem.value) {
      const left = j - thisItem.value;
      const stf = sati0 + stab[i - 1][left];
      maxSatisfaction = stf > maxSatisfaction ? stf : maxSatisfaction;
    }
    // check the 1st adjunct
    if (adjLength >= 1 && j >= thisItem.value + adj1.value) {
      // 如果有附属品
      const left = j - thisItem.value - adj1.value;
      const stf = sati0 + sati1 + stab[i - 1][left];
      maxSatisfaction = stf > maxSatisfaction ? stf : maxSatisfaction;
    }
    // check the 2nd adjunct
    if (adjLength >= 2 && j >= thisItem.value + adj2.value) {
      const left = j - thisItem.value - adj2.value;
      const stf = sati0 + sati2 + stab[i - 1][left];
      maxSatisfaction = stf > maxSatisfaction ? stf : maxSatisfaction;
    }
    // check the adjuncts
    if (adjLength >= 2 && j >= thisItem.value + adj1.value + adj2.value) {
      const left = j - (thisItem.value + adj1.value + adj2.value);
      const stf = sati0 + sati1 + sati2 + stab[i - 1][left];
      maxSatisfaction = stf > maxSatisfaction ? stf : maxSatisfaction;
    }
    stab[i][j] = maxSatisfaction;
    allMax = maxSatisfaction > allMax ? maxSatisfaction : allMax;
  }
}

print(allMax);