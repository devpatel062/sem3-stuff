//What is let? When should we use it?
//let print="hi";
function oo(){
    let print="hello";

    console.log(print);
}
console.log(print);
oo();
//let is block scoped i.e. code bounded by {} , furthur it can be updated but can't be re-declared.