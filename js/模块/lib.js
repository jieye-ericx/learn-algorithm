// lib.js
// export let counter = 3
// export function incCounter() {
//   counter++
// }
const a = {
  i: 1,
  toString: function () {
    return a.i++;
  }
}
if (a == 1 && a == 2 && a == 3) {
  console.log('hello world!');
}
console.log(Object.prototype)
