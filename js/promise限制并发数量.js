let count = 0;

const sleep = () => {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve(++count);
    }, 3000 * Math.random());
  });
};

let ans = (num, n) => {
  let finished = 0,
    tmp = 0,
    cur = 0,
    curThen = 0,
    dod = () => {
      curThen++;
      sleep().then((a) => {
        finished++;
        console.log("结束 ", a, finished);
        if (finished + curThen <= num) {
          dod();
        }
        curThen--;
      });
    };

  while (tmp++ < n && cur < num) {
    cur++;
    dod();
  }
};
ans(10, 3);
