var arr = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100];

var position = findNumber(90, arr);
console.log(position);

function findNumber(n, arr) {
  return _findNumber(n, arr, 0, arr.length - 1);
}

function _findNumber(n, arr, i1, i2) {
  if (i2 < i1) return -1;

  console.log("Checking interval: [" + i1 + ", " + i2 + "]");

  var mid = i1 + Math.floor((i2 - i1) / 2);

  if (n === arr[mid]) return mid;

  if (n < arr[mid]) return _findNumber(n, arr, i1, mid - 1);

  return _findNumber(n, arr, mid + 1, i2);
}
