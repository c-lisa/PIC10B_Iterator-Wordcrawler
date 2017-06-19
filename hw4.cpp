/** @file hw4.cpp
@author [Lisa Chiang]
@date [2/3/2017]

[.]

*/

#include <iostream>
#include <string>

class WordCrawler {
public: 
	WordCrawler(std::string given_words); //Constructor taking given_words
	
	/*
	//Pointer operations
	WordCrawler& operator++(); //Increments to next word
	WordCrawler operator++(); 
	//postfix = p++; call prefix; make copy of that object but real pointer incremented check slide 181
	//prefix = returns pointer type ; ref to object; is called by postfix ++ 
	WordCrawler& operator--(); //Decrements to previous word
	WordCrawler& operator-=(int x); 
	WordCrawler& operator+=(int x); 
	std::string operator*(); //Deference operator, wherever current word is at 
	std::string operator[](int x); //Offset operator, count from the beginning 
	*/

private: 
	std::string words; 
	char* current_word; 
};

int words_count(std::string given_words); //Count number of given words
int the_count(std::string given_words); //Counter number of times 'the' appears
std::string every_other_in(std::string given_words); //Returns every other word
std::string print_in_reverse(std::string given_words); //prints sentence in reverse

int main()
{
	std::string words; 

	std::cout << "Please input some words:\n"; 
	std::getline(std::cin, words); 

	std::cout << "The total number of words is: " << words_count(words) 
		<< std::endl;

	exit(1); 

	/*
	std::cout << "The total number of times 'the' appears is: "
		<< the_count(words) << std::endl; 
	
	std::cout << "Every other word is: "; every_other_in(words); 
		std::cout << std::endl; 

	std::cout << "The words in reverse order are: "; print_in_reverse(words); 
		std::cout << std::endl; 
	*/

	return 0; 
}

//Constructor taking given_words
WordCrawler::WordCrawler(std::string given_words)
{
	words = given_words;
	current_word = &given_words[0]; 
}

/*
//Increments to next word
WordCrawler& WordCrawler::operator++()
{
	; 
}
//Decrements to previous word
WordCrawler& WordCrawler:: operator--()
{
	;
}
WordCrawler& WordCrawler:: operator-=(int x)
{
	; 
}
WordCrawler& WordCrawler:: operator+=(int x)
{
	;
}
//Deference operator
std::string WordCrawler:: operator*()
{
	;
}
//Offset operator
std::string WordCrawler:: operator[](int x)
{
	;
}
*/

//Count number of given words
int words_count(std::string given_words)
{
	int counter = 0; 

	//step through the characters of given_words until you find a space
	//when you find a space, counter ++
	//add one to counter at end to take care of word before punctuation

	return counter; 
}
//Counter number of times 'the' appears
int the_count(std::string given_words)
{
	return 0; 
}
//Returns every other word
std::string every_other_in(std::string given_words)
{
	return "hello"; 
}
//Prints sentence in reverse
std::string print_in_reverse(std::string given_words)
{
	return "Hello"; 
}


/*
p = &(w[0] //give me first character of first word 
while (*p != " ") {++p}
while (*p == " ") {++p}

//wordcrawler is going "word by word" by actually going letter by letter

*/