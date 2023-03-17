// 请实现一个函数用来找出字符流中第一个只出现一次的字符。
// 例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
// 当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

//Init module if you need
function Init() {
  this.q = []
  this.m = new Map()

}
//Insert one char from stringstream
function Insert(ch) {
  this.q.push(ch)
  if (m.has(ch)) {
    this.m.set(ch, 2)
  } else {
    this.m.set(ch, 1)
  }
  console.log('q: ' + this.q);
  let key = this.m.keys()
  // while (key.next().value !== undefined) {
  //   console.log('key: ' + key. + ' value: ' + this.m.get(key.value));
  // }
  console.log('map: ' + this.m.get(ch));

}
//return the first appearence once char in current stringstream
function FirstAppearingOnce() {
  let s = '#', cnt = 0
  while (cnt < this.q.length) {
    if (this.m.get(s) === 1) return s
    else
      s = this.q[cnt++]
  }
  if (this.m.get(s) !== 1) return '#'
  return s
}

Init()
Insert('g')
console.log(FirstAppearingOnce())
Insert('o')
console.log(FirstAppearingOnce())
Insert('o')
console.log(FirstAppearingOnce())
Insert('g')
console.log(FirstAppearingOnce())
Insert('l')
console.log(FirstAppearingOnce())
Insert('e')
console.log(FirstAppearingOnce())
