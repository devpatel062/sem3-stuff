//Write a JS program to find sum of natural numbers using recursion.
var num = parseInt(prompt());

function fun(num)
{
    if(num > 0)
        return num + fun(num-1)
    else
        return num;
}
var sum = fun(num);
console.log(sum);