// 防抖
function debounce(func, wait = 50) {
  let timer = 0
  return function (...args) {
    if (timer) clearTimeout(timer)
    timer = setTimeout(() => {
      func.apply(this, args)
    }, wait)
  }
}
function throttle(func, wait) {
  let lastTime = 0
  return function (...args) {
    let now = +new Date()
    if (now - lastTime > wait) {
      lastTime = now
      func.apply(this, args)
    }
  }
}
setInterval(
  throttle(() => {
    console.log(1)
  }, 3000),
  1
)
