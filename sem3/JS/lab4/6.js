var arr = ['Apple', 'Mango', 'Grapes', 'Orange', 'Fig', 'Cherry'];
var result  = arr.filter(arr=>arr.length >=5)
console.log(result)

var result2 = arr.filter(function(arri){
    return arri.length >= 6;
});
console.log(result2)