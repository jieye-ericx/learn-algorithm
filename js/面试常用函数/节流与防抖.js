// é˜²æŠ–
// function debounce(func, wait = 50) {
//   let timer = 0
//   return function (...args) {
//     if (timer) clearTimeout(timer)
//     timer = setTimeout(() => {
//       func.apply(this, args)
//     }, wait)
//   }
// }
// function throttle(func, wait) {
//   let lastTime = 0
//   return function (...args) {
//     let now = +new Date()
//     if (now - lastTime > wait) {
//       lastTime = now
//       func.apply(this, args)
//     }
//   }
// }
// setInterval(
//   throttle(() => {
//     console.log(1)
//   }, 3000),
//   1
// )

let jieliu = function (fn, times) {
  let preTime = Date.now()
  console.log(arguments)
  var args = arguments,
    context = this
  return function () {
    let nowTime = Date.now()
    if (nowTime - preTime >= times) {
      preTime = Date.now()
      fn.apply(context, args)
    }
  }
}
let fangdou = function (fn, times) {
  let timer = null
  let context = this,
    args = arguments
  return function () {
    if (timer) {
      clearTimeout(timer)
      timer = null
    }
    timer = setTimeout(function () {
      fn.apply(context, args)
    }, times)
  }
}

function ffff(str) {
  console.log(arguments)
  console.log(str)
  console.log('--------------------------------------------------------------')
}

setInterval(jieliu(ffff, 2000, '12312'), 1)

// jieliu(ffff('qwe'), 10000)

function debounce(fn, delay) {
  var timer // 维护一个 timer
  return function () {
    var _this = this // 取debounce执行作用域的this
    var args = arguments
    if (timer) {
      clearTimeout(timer)
    }
    timer = setTimeout(function () {
      fn.apply(_this, args) // 用apply指向调用debounce的对象，相当于_this.fn(args);
    }, delay)
  }
}
function throttles(fn, wait = 100) {
  let last = 0
  console.log('节流函数 启动')
  return function () {
    let curr = +new Date()
    // 强制转换为数字Number
    if (curr - last > wait) {
      fn.apply(this, arguments)
      last = curr
    }
  }
}

function debounce(fn) {
  let timeout = null // 创建一个标记用来存放定时器的返回值
  return function () {
    clearTimeout(timeout) // 每当用户输入的时候把前一个 setTimeout clear 掉
    timeout = setTimeout(() => {
      // 然后又创建一个新的 setTimeout, 这样就能保证输入字符后的 interval 间隔内如果还有字符输入的话，就不会执行 fn 函数
      fn.apply(this, arguments)
    }, 500)
  }
}
function sayHi() {
  console.log('防抖成功')
}

var inp = document.getElementById('inp')
inp.addEventListener('input', debounce(sayHi)) // 防抖

function throttle(fn) {
  let canRun = true // 通过闭包保存一个标记
  return function () {
    if (!canRun) return // 在函数开头判断标记是否为true，不为true则return
    canRun = false // 立即设置为false
    setTimeout(() => {
      // 将外部传入的函数的执行放在setTimeout中
      fn.apply(this, arguments)
      // 最后在setTimeout执行完毕后再把标记设置为true(关键)表示可以执行下一次循环了。当定时器没有执行的时候标记永远是false，在开头被return掉
      canRun = true
    }, 500)
  }
}
function sayHi(e) {
  console.log(e.target.innerWidth, e.target.innerHeight)
}
window.addEventListener('resize', throttle(sayHi))