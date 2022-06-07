var test = function(){};
function testing(test) {
      
    if(test instanceof Function) {
        document.write("Variable is of function type");
    }
    else {
        document.write("Variable is not of function type");
    }
}
  
// Function call
testing(gfg);