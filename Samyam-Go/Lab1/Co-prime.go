package main

func areCoPrime(num1 int, num2 int) bool{
	return euclideanGCD(num1,num2)==1;
}

func euclideanGCD(a, b int) int{
	for b!=0{
		var temp int =b
		b=a%b
		a=temp
	}

	return a;
}