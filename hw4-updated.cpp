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

	//Pointer operations
	WordCrawler& operator++(); //Prefix Increment - Increments to next word
	WordCrawler operator++ (int unused); //Postfix Increment - Returns value and then increments

	/*
	
	WordCrawler operator++();
	//postfix = p++; call prefix; make copy of that object but real pointer incremented check slide 181
	//prefix = returns pointer type ; ref to object; is called by postfix ++
	
	/*
	WordCrawler& operator--(); //Decrements to previous word
	WordCrawler& operator-=(int x);
	WordCrawler& operator+=(int x);
	*/
	std::string operator*(); //Deference operator, wherever current word is at
	std::string operator[](int x); //Offset operator, count from the beginning


private:
	std::string words;
	char* current_word; //address or pointer
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

	std::cout << "The total number of times 'the' appears is: "
	<< the_count(words) << std::endl;

	/*
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
	current_word = &given_words[0]; //gives me address of first letter of input 
}

//Prefix Increment - Increments to next word
WordCrawler& WordCrawler::operator++()
{
	//while the value is not space, increment pointer 
	while (*current_word != ' ')
	{
		++current_word; 
	}
	//since possibly more spaces after previous space, increment pointer until no more spaces
	while (*current_word == ' ')
	{
		++current_word; 
	}
	
	return *this; 
}
//Postfix Increment Returns value and then increments
WordCrawler WordCrawler::operator++ (int unused)
{
	WordCrawler clone(*this); //make a copy
	++(*this); // increment the object
	return clone; 
}


/*
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
//beginning with a certain position, keep moving until next space
std::string WordCrawler:: operator*()
{
current_word++;
//return *current_word;
}
*/


//Offset operator
std::string WordCrawler:: operator[](int x)
{
	std::string certain_word; 
	//input ++
	//gives you something

	//use position of something to end loop [x, something]
	//push back currentword 
	for (int i = 0; i < x; i++)
	{
		current_word++; 
		certain_word.push_back(*current_word); 
	}
	
	return certain_word; 
}


//Count number of given words
int words_count(std::string given_words)
{
	/*
	int counter2 = 0; 
	WordCrawler A = given_words; 
	std::cout << A[3];
	A++; 
	A[]
	*/

	WordCrawler A = given_words;
	
	std::cout << &(++A) << std::endl;
	++A; 
	std::cout << &(++A) << std::endl;

	int counter = 0;
	for (int i = 0; i < given_words.size(); i++)
	{
		//if there is a space, counter ++
		if (given_words[i] == ' ')
		{
			counter++; 
			
			//if there is more than one space in a row, negate previous increment
			if (given_words[i - 1] == ' ')
			{
				counter--; 
			}

			//to account for people adding a space after their period
			if (given_words[i - 1] == '.' || given_words[i - 1] == '!' || given_words[i - 1] == '?')
			{
				counter--; 
			}
		}
	}

	//account for last word that doesn't have space afterwards 
	counter++; 

	return counter;
}

//Counter number of times 'the' appears
int the_count(std::string given_words)
{
	//increment through words
	//if *wordcrawler[] = "the" 

	//w/out wordcrawler
	int counter = 0; 
	for (int i = 0; i < given_words.size(); i++)
	{
		if (given_words[i] == 't')
		{
			if (given_words[i+1] == 'h')
			{
				if (given_words[i+2] == 'e')
					counter++; 
			}
		}
	}

	return counter;
}
//Returns every other word
std::string every_other_in(std::string given_words)
{
	//increment through words
	//only cout on odd increments 		
	
	return "hello";
}
//Prints sentence in reverse
std::string print_in_reverse(std::string given_words)
{
	//decrement through words
	//cout every word that is decremented through 
	
	return "Hello";
}


/*
p = &(w[0] //give me first character of first word
while (*p != " ") {++p}
while (*p == " ") {++p}

//wordcrawler is going "word by word" by actually going letter by letter

*/