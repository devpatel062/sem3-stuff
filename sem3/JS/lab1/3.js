//What is var? Should we use our old friend ‘var’?
var print ="hi";

function newf(){
    var print = "hello";

    console.log(print);
}
console.log(print);
newf();
//var depends on scope and unlike const it can be redeclare and updated.