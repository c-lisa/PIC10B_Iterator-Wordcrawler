/** @file hw4.cpp
@author [Lisa Chiang]
@date [2/3/2017]

[.]

*/

#include <iostream>
#include <string>
#include <vector>

class WordCrawler {
public:
	WordCrawler(std::string given_words); //Constructor taking given_words

	//Pointer operations
	WordCrawler& operator++(); //Prefix Increment - Increments to next word
	WordCrawler operator++ (int unused); //Postfix Increment - Returns value and then increments
	WordCrawler& operator+=(int x); //Increments x amount of times/words
	WordCrawler& operator--(); //Decrements to previous word
	WordCrawler operator-- (int unused);
	WordCrawler& operator-=(int x);
	std::string operator*(); //Deference operator, wherever current word is at
	std::string operator[](int x); //Offset operator, count from the beginning
	//int size;

	//Accessors
	int get_number_words(); 

private:
	std::string words;
	char *current_word; //address or pointer
	//std::vector <int> length;
	int number_of_words;
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

	std::cout << "Every other word is: "; every_other_in(words);
	std::cout << std::endl;

	//std::cout << "The words in reverse order are: "; print_in_reverse(words);
	//std::cout << std::endl;

	return 0;
}

//Constructor taking given_words
WordCrawler::WordCrawler(std::string given_words)
{
	words = given_words;
	current_word = &words[0]; //gives me address of first letter of input 
	number_of_words = 0; 

	//int word_length = words.size();

	////Creating a vector for beginning of words
	//for (int i = 0; i < word_length; i++)
	//{
	//	//Pushing back beginning of first word
	//	if (i == 0)
	//	{
	//		length.push_back(0);
	//	}
	//	else
	//		//precaution against going past end
	//	{
	//		if (given_words[i - 1] == ' ' && given_words[i] != ' ')
	//		{
	//			length.push_back(i);
	//		}
	//	}
	//}

	//size = length.size();

}

int WordCrawler::get_number_words()
{
	return number_of_words; 
}

//Prefix Increment - Increments to next word
WordCrawler& WordCrawler::operator++()
{
	//What I want to do: 
	/*
	What I want this to do: I want it to increment to beginning of the next word
	What gets incremented is the pointer - current_Word++
	This will keep getting incremented so that it is pointing to the next word
	**begins at words[0]...need to increment it so that it points at needed address

	While the value of the pointer is X execute Y
	*/

	/*
	while value is not space, increment
	for example, if the two consecutive words is "I eat" then I want it to move from
	"I" to "e." This should skip letters and punctuations as long as it's not a space.
	*/

	// Run through the word
	while ((*current_word != ' ') && (current_word != &words[words.size() - 1]))
	{
		++current_word;
	}

	// Move to the next word by skipping spaces
	/*
	If the above while loop has been exited, that means the pointer is currently at a space.
	I want to keep incrementing until I'm not at a space - use while loop because there may
	be two spaces in a row.
	*/
	while (*current_word == ' ')
	{
		++current_word;
		++number_of_words; 
	}
	
	//current_word is now pointing at the first letter of the next word

	//extra unnecessary code that i might need eventually
	/*if (*current_word = NULL)
	{
	break;
	}*/
	/*
	What happens if we are at the last word?
	*/
	/*
		//char* temp = current_word; 
	*/
	
	return *this;
}
//Postfix Increment Returns value and then increments
WordCrawler WordCrawler::operator++ (int unused)
{
	WordCrawler clone(*this); //make a copy
	++(*this); // increment the object
	return clone;
}
//Increments x amount of times/words
WordCrawler& WordCrawler:: operator+=(int x)
{
	/*
	So we have ++ operator meaning that it will move the index to the first character
	of the next word. So what if we have a specific number of words we'd like to move to?

	For example: "I want to eat bananas."
	current_word is at 'I'. We want to move it to the third word --> "to"

	Basically we need a for-loop that will increment the pointer the amount of words we need.
	*/
	WordCrawler clone(*this); 

	for (int i = 0; i < x; i++)
	{
		++(*this);
	}

	return clone;
}

//Prefix Decrement - Decrements to previous word
WordCrawler& WordCrawler:: operator--()
{
	//What I want to do: 
	/*
	What I want this to do: I want it to decrement from beginning of last word
	until the begining of the second to last word (and so on).
	What gets decremented is the pointer - --current_Word
	This will keep getting decremented so that it is pointing to the begining of the next word
	**should begin at last value

	While the value of the pointer is X execute Y
	*/

	/*
	begin with decrementing word because the pointer is still no the first letter of the
	previous word. need to move it to a space.
	*/
	--current_word;
	/*
	In case the user ends with a space, we want to decrement until we reach a word.
	For example, if phrase is "I am.  " we want it to begin at "."
	*/
	while (*current_word == ' ')
	{
		--current_word;
	}
	/*
	In the example, now that the pointer is at "." - we want to decrement until it reaches
	the "a" in "am." So as long as the value prior to the current.

	We also add in condition that the current_word is not at zero because if it is, then we go out of
	bounds. Only if it's not at index zero can we continue.
	*/
	while (current_word != 0 && *(current_word - 1) != ' ')
	{
		--current_word;
	}

	return *this;
}
//Postfix Decrement - Decrements to previous word
WordCrawler WordCrawler::operator-- (int unused)
{
	WordCrawler clone(*this); //make a copy
	--(*this); // increment the object
	return clone;
}
//Decrement x amount of times/words
WordCrawler& WordCrawler:: operator-=(int x)
{
	/*
	So we have -- operator meaning that it will move the index to the first character
	of the previous word. So what if we have a specific number of words we'd like to move to?

	For example: "I want to eat bananas."
	current_word is at 'b' of bananas. We want to move it to the third word --> "to"

	Basically we need a for-loop that will decrement the pointer the amount of words we need.
	*/

	for (int i = 0; i < x; i++)
	{
		--current_word;
	}

	return *this;
}

//Deference operator
std::string WordCrawler:: operator*()
{
	/*
	What do I want to do?

	Ideally *current_word would give the whole word that is connected to the first
	character of that word.

	For example: "Hello world, I like stars."

	If my pointer is at words[6], I want it to give me the string "world"

	QUESTION: do I want to include punctuation? Sure.
	So basically I will step through the words string until I hit a space. I can check if
	*(currentwords + 1) == ' '. If it is, then that is the end of the string. I can push_back
	for strings.

	QUESTION: what happens if I'm at the last word?
	good question
	*/

	std::string returnthis;

	while (*current_word != ' ' && current_word <= &words[words.size() - 1])
	{
		returnthis.push_back(*current_word);

		/*if (current_word != &words[words.size() - 1])
		{
			break; 
		}*/
		
		++current_word;
	}

	return returnthis;
}

//Offset operator
std::string WordCrawler:: operator[](int x)
{
	/*
	What do I do?

	Ideally if I call words[x] then it will give me the xth word.
	The * dereferences current_word wherever it is at (usually in implication with another loop
	in a non-member function). However, the [] operator should give it to me exactly where I want it.
	For example, if I want to get every third word or every fourth word, I would just increase x by that amount.

	So essentially to increment the pointer by x amount of times. Then I want to give a string that is that word.
	*/
	std::string returnthis;

	/*for (int i = 0; i < x; i++)
	{
		++current_word;
	}
*/
	//created copy of wordcrawler private variable words
	WordCrawler A (words); 

	//we want to increment A by x amount of times/words, current_word is now at whatever the first letter of the word we're thinking of is 
	A += x; 

	//while the deref form of *p + 1 is not space and the current_word isn't the last letter of the last word...push back a the letter until we reach a space 
	while ((*current_word != ' ') && (current_word <= &words[words.size() - 1]))
	{
		returnthis.push_back(*current_word);
		++current_word; 
	}

	return returnthis;
}

//NON-MEMBER FUNCTIONS 
//Count number of given words
int words_count(std::string given_words)
{
	/*
	What I want:
	I want to step through given_words by first creating a WordCrawler A.

	*/

	WordCrawler A (given_words);
	WordCrawler B (" "); 

	//while (A.get_number_words != )


	//std::cout << &A;
	//for (int i = 0; i < 5; i++)
	//{
	//	std::cout << std::endl << &(A++);
	//}

	//int counter = 0;
	//
	////std::string temp = *A; 
	////++A; 

	/////*while (*A != temp)
	////{
	////	if (&(*A) =! &*(++A))
	////	++A; 
	////	++counter;
	////}*/

	//while (&(*A) <= &given_words.end)
	//{
	//	A++; 
	//	counter++; 
	//}

	/*
	while (A[counter+1])
	{
	++A;
	counter++;
	}
	*/

	/*int counter = 0;
	
	while (*(++A) != *(++B))
	{
		++A; 
		++counter; 
	}*/

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

	////w/out wordcrawler
	//int counter = 0;
	//for (int i = 0; i < given_words.size(); i++)
	//{
	//	if (given_words[i] == 't')
	//	{
	//		if (given_words[i + 1] == 'h')
	//		{
	//			if (given_words[i + 2] == 'e')
	//				counter++;
	//		}
	//	}
	//}

	/*
	What's happening? 

	I created a Wordcrawler A and I gave it the words given by the user. 
	I then created a counter that begins at zero, that will increase every time the word "the" appears. 
	Then I created int a which is the total amount of words, which is how many times words I need to step through. 
	*/

	WordCrawler A (given_words);

	int counter = 0;
	int a = words_count(given_words); 
	
	std::string the_by_itself ("the"); 

	if (*A == the_by_itself)
	{
		++counter; 
	}

	for (int i = 0; i < a; i++)
	{
		++A; 

		if ((*A) == the_by_itself)
		{
			++counter;
		}
	}

	//while (x < words_count(given_words))
	//{
	//	/*x is just like the condition of int i for for loop
	//	I want to step through the words of A that match "the" in 
	//	different conditions. If it matches then counter will increase. 
	//	So will x and A. 
	//	*/

	//	if (*A == " the"|| *A == "The " || *A == " the")
	//	{
	//		++counter; 
	//	}
	//	++A; 
	//	++x; 
	//}

	return counter;
}

//Returns every other word
std::string every_other_in(std::string given_words)
{
	std::string returnthis (""); 
	WordCrawler A(given_words); 
	int a = words_count(given_words); 
	std::string bleh; 

	bleh = *A; 
	returnthis += bleh;

	for (int i = 0; i < a; i++)
	{
		++A; 

		bleh = *A; 

		if (i % 2)
		{
			returnthis += " "; 
			returnthis += bleh; 
		}
	}

	std::cout << returnthis; 

	return returnthis;
}

//Prints sentence in reverse
std::string print_in_reverse(std::string given_words)
{
	return 0;
}

