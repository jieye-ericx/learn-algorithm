//line=readline()
//print(line)
// console.log('Hello World!')

// function mQueue() {
//   this.queue = []
//   this.times = []
//   this.task = function (time, fn) {
//     this.queue.push(fn)
//     // console.log(this.times)
//     // console.log('2:' + time)
//     // console.log('3:' + this.times.length)
//     // if (this.times.length >= 1) {
//     //   time += this.times[this.times.length - 1]
//     // }
//     this.times.push(
//       time + (this.times.length >= 1 ? this.times[this.times.length - 1] : 0)
//     )
//     return this
//   }
//   this.start = function () {
//     while (this.queue.length > 0) {
//       setTimeout(this.queue.shift(), this.times.shift())
//     }
//   }
// }

// new mQueue()
//   .task(1000, () => {
//     console.log(1)
//   })
//   .task(2000, () => {
//     console.log(2)
//   })
//   .task(1000, () => {
//     console.log(3)
//   })
//   .start()
// console.log('123213123123')

function mQueue() {
  this.queue = []
  this.times = []
  this.task = function (time, fn) {
    this.queue.push(fn)
    this.times.push(time + this.times[this.times.length - 1] || 0)
    return this
  }
  this.start = function () {
    console.log(this.times)
    while (this.queue.length > 0) {
      setTimeout(this.queue.shift(), this.times.shift())
    }
  }
}

setTimeout(() => console.log('2'), 2000)
new mQueue()
  .task(1000, () => {
    console.log(1)
  })
  .task(2000, () => {
    console.log(3)
  })
  .task(1000, () => {
    console.log(4)
  })
  .start()
console.log('123')
