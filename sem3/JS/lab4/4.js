var array1 = [1, 2, 3];
var array2 = [2, 3, '1'];
var final = [...new Set(array1.concat(array2))]
console.log(final)