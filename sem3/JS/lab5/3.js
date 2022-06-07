    

let size=parseInt(prompt("Enter size of array"));
let arr=[];

for(var i=0; i<size; i++){
	arr[i]=parseInt(prompt("Enter a number"));
}

console.log(`Array: `,arr);

let access_index=parseInt(prompt("Enter index of element you want to access"));

let {[access_index]:access_element=0}=arr;
console.log(`Your element is: `,access_element);