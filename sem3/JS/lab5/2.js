var a = prompt();
var b = prompt();
console.log('before');
console.log(a , b);
[a,b] = [b,a]
console.log('after');
console.log(a,b);