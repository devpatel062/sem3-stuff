var num1=parseInt(prompt())
var num2=parseInt(prompt())
var sign=prompt()
if(sign == "+")
{
    console.log(num1+num2)
}
else if(sign == '-')
{
    if(num1>num2)
        console.log(num1-num2)
    else
        console.log(num2-num1)
}
else if(sign == '*')
{
    console.log(num1*num2)
}
else if(sign == '/')
{
    if(num1>num2)
        console.log(num1/num2)
    else
        console.log(num2/num1)
}