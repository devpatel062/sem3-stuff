
let object1={prop_1:'value_1', prop_2:'value_2', prop_3:'value_3', prop_4:'value_4'};
console.log(`Initial object:`,object1);

//Taking all properties and values from object1 except first two into object2
let {prop_1,prop_2,...object2}=object1;
console.log(`Final object:`,object2);