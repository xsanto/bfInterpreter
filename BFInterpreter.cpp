#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

int main(){
	typedef unsigned char BYTE;   //byte datatype
	const int memSize=30000;	
	BYTE mem[memSize];				//the data memory
	BYTE instructions[memSize];    //the instructions memory 


	for (int i = 0; i < memSize; i++) //initialise the memories
	{
		mem[i]=NULL;
		instructions[i]=NULL;
	}

	int dp=0;  //data pointer
	int ip=0;  //instruction pointer
	

	char ch;
	std::fstream fin("input.txt", std::fstream::in);
	int i=0;
	while (fin >> std::noskipws >> ch) {   //fill the instruction memory from with the code from the txt
		instructions[i]=ch; // Or whatever
		i++;
	}



/////////////////////////////////////////////check for unmatched brackets
int stack=0;
for(int ip=0; ip<memSize; ip++){
	if(instructions[ip]==91){
		stack++;
	}
	if(instructions[ip]==93){
		stack--;	
	}
	if(stack<0){
		break;
	}
}

if(stack!=0){
	std::cout<<"There are unmatched square brackets in the code"<<std::endl;
	exit(0);
}

///////////////////////////////////////////////

for(int i=0; i<memSize; i++){
	if(instructions[ip]==62){  //>
	
		dp++;
		ip++;
		
	}else if(instructions[ip]==60){ // <

		dp--;
		ip++;

	}
	else if(instructions[ip]==43){ // +
	
		mem[dp]++;
		ip++;
	}else if(instructions[ip]==45){  // -
		mem[dp]--;
		ip++;
	}else if(instructions[ip]==46){ // .
		std::cout<<mem[dp];
		ip++;
	}else if(instructions[ip]==44){ //,
		std::cout<<"Waiting for single character input:";
		std::cin>>mem[dp];
		ip++;
	}else if(instructions[ip]==91){  // [
		
		if(mem[dp]==0){
			int counter=1;
			int tempip=ip;
			while (counter>0){  //move forward until you find matching bracket
				tempip++;
				if(instructions[tempip]==']'){
					counter--;
				}else if(instructions[tempip]=='['){
					counter++;
				}
			}
			ip=tempip+1; //set ip to matching bracket plus 1

			// jump ip to command just after matching ']' 
		}else{
			ip++;
		}

	}else if(instructions[ip]==93){  // ]
		if(mem[dp]!=0){
			int counter=1;
			int tempip=ip;
			while (counter>0){  //move back until you find matching bracket
				tempip--;
				if(instructions[tempip]==']'){
					counter++;
				}else if(instructions[tempip]=='['){
					counter--;
				}
			}
			ip=tempip+1;  //set ip to matching bracket address plus 1
		
			// jump ip to command just after matching '[' 
		}else{
			ip++;
		}
	}else{
		ip++;
	}

}
	std::cout<<std::endl;
	std::cout<<"End of program's output."<<std::endl;
	std::cout<<std::endl;

	/////////////Print first 10 cells of memory for visual feedback
	std::cout<<"First 10 cells of memory:"<<std::endl;
	for(int index=0; index<10;index++){
		std::cout<<" | "<<int(mem[index]);
	}
	std::cout<<" |";
	
}