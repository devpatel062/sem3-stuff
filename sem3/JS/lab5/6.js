
function storeObject(){
	
	let user={country:'india',state:'gujarat',city:'ggg'};
	function returnUser(){
		
		return user;
	}
	return returnUser;
}
let showUser=storeObject();
let privateData=showUser();
console.log(privateData);