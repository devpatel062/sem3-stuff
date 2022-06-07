var num = prompt();
var arr = [];
for(var i=0;i<num;i++)
{
     arr[i] = prompt();
}

function segregateEvenOdd(arr)
{
	/* Initialize left and right indexes */
	var left = 0, right = arr.length - 1;
	while (left < right)
	{
		/* Increment left index while
		we see 0 at left */
		while (arr[left]%2 == 0 && left < right)
			left++;

		/* Decrement right index while we see
		1 at right */
		while (arr[right]%2 == 1 && left < right)
			right--;

		if (left < right)
		{
			/* Swap arr[left] and arr[right]*/
			var temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	}
}

/* Driver program to test above functions */


segregateEvenOdd(arr);


for (i = 0; i < arr.length; i++)
	console.log(arr[i]+" ");
