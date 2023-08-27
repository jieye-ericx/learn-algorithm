const fs = require("fs");

const dirPath = "./leetcode";
const isNeedCheckFile = (name) => {
  return name.endsWith(".cpp") || name.endsWith(".js");
};
const isNeedChangeName = (name) => {
  const ex = /(\d+)\.([\u4e00-\u9fa5_a-zA-Z0-9_\s]+)\.(cpp|js)/;
  return ex.exec(name);
};
const ChangeName = (name) => {
  const ex = /(\d+)\.?([\u4e00-\u9fa5_a-zA-Z0-9_\s]+)\.(cpp|js)/;
  const result = ex.exec(name);
  // if (!result) console.log(name);
  // console.log(result);
  fs.rename(
    dirPath + "/" + name,
    dirPath + "/" + result[1] + "." + result[2] + "." + result[3],
    (err) => {
      console.log("重命名出错：" + name);
    }
  );
};
let leetcodeDir = fs.readdirSync(dirPath);
// console.log(leetcodeDir);
leetcodeDir.forEach((fileName) => {
  if (isNeedCheckFile(fileName)) {
    const result = isNeedChangeName(fileName);
    if (!result) {
      ChangeName(fileName);
    }
    // console.log(result);
  }
});
