const person = {
    id: 1,
    name: 'John',
    age: 23
}

//check if key exists
const hasKey = person.hasOwnProperty('name');

if(hasKey) {
    console.log('The key exists.');
}
else {
    console.log('The key does not exist.');
}

//or

const object1 = {};
object1.bool = 42;

console.log(object1.hasOwnProperty('bool'));
// expected output: true

console.log(object1);


console.log(object1.hasOwnProperty('string'));
// expected output: false