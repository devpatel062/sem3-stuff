var fruits_arr = ['Apple', 'Mango', 'Grapes', 'Orange', 'Fig', 'Cherry'];

function checkValue(value, arr) {
    var status = 'Not exist';

    for (var i = 0; i < arr.length; i++) {
        
        if (arr[i]== value) {
            status = 'Exist';
            break;
        }
    }

    return status;
}
var input = prompt()
console.log('status : ' + checkValue(input, fruits_arr));
