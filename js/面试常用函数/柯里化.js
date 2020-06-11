function curry(fn, ...args) {
  return args.length >= fn.length
    ? fn(...args)
    : (...rest) => curry(fn, ...args, ...rest)
}
