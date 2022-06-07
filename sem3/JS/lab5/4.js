var num = prompt();
var arr = [];
for(var i=0;i<num;i++)
{
    arr[i] = prompt();
}
const[first,...output] = arr;
console.log(output);