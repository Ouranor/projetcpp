#include <iostream>
# include <list>

int main(){
	std::list<int> Liste(3,4,6,3,6,3,9);

	for(std::list<int>::iterator it=List.begin();it!=List.end();it++ ){
		std::cout<<*it<<std::endl;
	}
}