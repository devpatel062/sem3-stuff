const obj1 = {
    name:'a1',
    age:22,
}
const obj2 = {
    name:'a2',
    age:23,
    lastname:'yyy',
}
const newobj1 = {...obj1, ...obj2}
console.log(newobj1)
const newobj2 = Object.assign(obj1, obj2);
console.log(newobj2)