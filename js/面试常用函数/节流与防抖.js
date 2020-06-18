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
