/** @file hw4.cpp
@author [Lisa Chiang]
@date [2/3/2017]

[This program uses a class called WordCrawler to iterate through a string given by a user. WordCrawler
iterates not by char but by whole words. The user can input a string and get the number of words, 
how many time "the" appears, every other word, and the reverse of their string.]

*/

#include <iostream>
#include <string>
#include <vector>

/**@class WordCrawler
@brief Class to increment and decrement through a user-given string. Class can also 
dereference wherever the pointer is at. 
*/

class WordCrawler {
public:
	WordCrawler(std::string given_words); //Constructor taking given_words

	//Pointer operations
	WordCrawler& operator++(); //Prefix Increment - Increments to next word
	WordCrawler operator++ (int unused); //Postfix Increment - Returns value and then increments
	WordCrawler& operator+=(int x); //Increments x amount of times/words

	WordCrawler& operator--(); //Prefix Decrement - Decrements to previous word
	WordCrawler operator-- (int unused); //Postfix Decrement - Returns value and then decrements
	WordCrawler& operator-=(int x); //Decrements x amount of times/words
	
	std::string operator*(); //Deference operator, wherever current word is at
	std::string operator[](size_t x); //Offset operator, count from the beginning

private:
	std::string words;
	char *current_word; //address or pointer
};

int words_count(std::string given_words); //Count number of given words
int the_count(std::string given_words); //Counter number of times 'the' appears
std::string every_other_in(std::string given_words); //Returns every other word
std::string print_in_reverse(std::string given_words); //Prints sentence in reverse

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

	std::cout << "The words in reverse order are: "; print_in_reverse(words);
	std::cout << std::endl;

	return 0;
}

/**@brief Constructor

Sets words to the user-given string and sets current_word (char* ) to the index of the first letter of the f

@param given_words is the value that words is set to
@return Does not return anything.
*/
WordCrawler::WordCrawler(std::string given_words)
{
	words = given_words;
	current_word = &words[0]; //gives me address of first letter of input 
}

/**@brief Prefix Increment

Overloads the prefix ++ operator to increment the pointer to the beginning of the 
next word in the phrase. First moves pointer and then returns *this. 

@param No parameters.
@return Returns a WordCrawler that is associated with the beginning of the next word.
*/
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
	while value is not space AND the pointer is not pointing to the last index of words...increment
	
	For example, if the two consecutive words is "I eat" then I want it to move from
	"I" to "e." This should skip letters and punctuations as long as it's not a space.
	*/
	while ((current_word != &words[words.size() - 1]) && (*current_word != ' '))
	{
		++current_word;
	}
	/*
	Move to the next word by skipping spaces

	If the above while loop has been exited, that means the pointer is currently at a space.
	I want to keep incrementing until I'm not at a space - use while loop because there may
	be two spaces in a row.
	*/
	while (*current_word == ' ')
	{
		++current_word;
	}
	
	return *this;
}
/**@brief Postfix Increment

Overloads the postfix ++ operator to increment the pointer to the beginning of the
next word in the phrase. First returns *this and then increments. 

@param No parameters.
@return Returns a WordCrawler that is associated with the beginning of the previous word.
*/
WordCrawler WordCrawler::operator++ (int unused)
{
	WordCrawler clone(*this); //make a copy
	++(*this); // increment the object
	return clone;
}
/**@brief += operator

Overloads the postfix += operator using the ++ operator to increment the pointer 
x amount of times. It will increment it to the beginning of the xth word. 

@param x is how many times the pointer will be incremnted using ++. 
@return Returns a WordCrawler that is associated with the beginning of the xth word.
*/
WordCrawler& WordCrawler:: operator+=(int x)
{
	//What I want to do: 
	/*
	So we have ++ operator meaning that it will move the index to the first character
	of the next word. So what if we have a specific number of words we'd like to move to?

	For example: "I want to eat bananas."
	current_word is at 'I'. We want to move it to the third word --> "to"

	Basically we need a for-loop that will increment the pointer the amount of words we need.
	*/
	WordCrawler clone(*this);

	for (int i = 0; i < (x); i++)
	{
		++(*this);
	}

	return clone;
}

/**@brief Prefix Decrement

Overloads the prefix -- operator to decrement the pointer to the beginning of the
previous word in the phrase. First moves pointer and then returns *this.

@param No parameters.
@return Returns a WordCrawler that is associated with the beginning of the previous word.
*/
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
	while ((current_word != &words[0]) && ((*(current_word - 1)) != ' '))
	{
		--current_word;
	}

	return *this;
}
/**@brief Postfix decrement

Overloads the postfix -- operator to decrement the pointer to the beginning of the
previous word in the phrase. First returns *this and then decrements.

@param No parameters.
@return Returns a WordCrawler that is associated with the beginning of the previous word.
*/
WordCrawler WordCrawler::operator-- (int unused)
{
	WordCrawler clone(*this); //make a copy
	--(*this); // increment the object
	return clone;
}
/**@brief -= operator

Overloads the postfix -= operator using the -- operator to decrement the pointer
x amount of times. It will decrement it to the beginning of the xth word.

@param x is how many times the pointer will be decremented using ++.
@return Returns a WordCrawler that is associated with the beginning of the xth word.
*/
WordCrawler& WordCrawler:: operator-=(int x)
{
	//What I want to do: 
	/*
	So we have -- operator meaning that it will move the index to the first character
	of the previous word. So what if we have a specific number of words we'd like to move to?

	For example: "I want to eat bananas."
	current_word is at 'b' of bananas. We want to move it to the third word --> "to"

	Basically we need a for-loop that will decrement the pointer the amount of words we need.
	*/
	WordCrawler clone(*this);

	for (int i = 0; i < (x); i++)
	{
		--(*this);
	}

	return clone;
}

/**@brief Derefrence Operator

Uses the pointer to increment through given string until a word is reached (defined by either 
an end with punctuation or a space). Returns a string with the given word.

@param No parameters. 
@return Returns a string that is the word following where the pointer is initially at.
*/
std::string WordCrawler:: operator*()
{
	//What I want to do
	/*
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

	while (current_word <= &words[words.size() - 1] && (*current_word != ' '))
	{
		returnthis.push_back(*current_word);
		++current_word;
	}

	return returnthis;
}
/**@brief Offset Operator

User asks for xth word in string. Pointer is moved to beginning character of xth word using ++ operator. 
Pointer than increments through given string until a word is reached (defined by either
an end with punctuation or a space). Returns a string with the given word.

@param x is the xth word that the ++ operator is moved until. 
@return Returns a string that is the word following where the pointer is initially at.
*/
std::string WordCrawler:: operator[](size_t x)
{
	//What I want to do: 	
	/*
	Ideally if I call words[x] then it will give me the xth word.
	The * dereferences current_word wherever it is at (usually in implication with another loop
	in a non-member function). However, the [] operator should give it to me exactly where I want it.
	For example, if I want to get every third word or every fourth word, I would just increase x by that amount.

	So essentially to increment the pointer by x amount of times. Then I want to give a string that is that word.
	*/
	std::string returnthis;

	/*we want to increment A by x amount of times/words, current_word is now at whatever the first letter of the word we're thinking of is 
	first we want to increment to the xth word. since we begin at index zero, we need to account for this and subtract one from x. 
	then we need to check if the pointer is at the last letter of the last word (in case we are only given the amount of words as x). 
	*/
	*this += (x-1);
	if (current_word == &words[words.size() - 1])
	{
		--(current_word); 
	}
	/*
	while the deref form of *p + 1 is not space and the current_word isn't the last letter of the last word...push back a the letter until we reach a space
	*/
	while (current_word <= &words[words.size() - 1] && *current_word != ' ')
	{
		returnthis.push_back(*current_word);
		++current_word;
	}

	return returnthis;
}

//NON-MEMBER FUNCTIONS 
/**@brief Word Count

Takes user-given string and loops through string until end of string is reached. 
When incrementing through string, the counter will count how many words there are. 

@param given_words is the string that will be used in counting the number of words. 
@return Returns an int that is the number of words in the given string. 
*/
int words_count(std::string given_words)
{
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
/**@brief "the" counter

Takes user-given string and loops through string until end of string is reached.
When incrementing through string, the counter will count how many times the word "the" 
appears. 

@param given_words is the string that will be used in counting the number of times the word "the" appears. 
@return Returns an int that is the number of times the word "the" appears in the given string.
*/
int the_count(std::string given_words)
{
	//What I want to do: 
	/*
	What's happening?

	I created a Wordcrawler A and I gave it the words given by the user.
	I then created a counter that begins at zero, that will increase every time the word "the" appears.
	Then I created int a which is the total amount of words, which is how many times words I need to step through.
	*/

	WordCrawler A(given_words);
	int counter = 0; //what will be returned
	int a = words_count(given_words); //total amount of words
	std::string the("the"); //what I'm searching for
	
	//If the value at the pointer is the then increase counter (to test for first word) 
	if (*A == the)
	{
		++counter;
	}
	//Step through entire string to find "the"
	for (int i = 0; i < a; i++)
	{
		++A;

		if ((*A) == the)
		{
			++counter;
		}
	}
	
	return counter;
}
/**@brief Every Other Word

Takes user-given string and loops through string until end of string is reached.
When incrementing through string, every other word will be pushed into a string that will 
be outputted and returned.

@param given_words is the string that will be used in finding every other word.
@return Returns a string that contains every other word. 
*/
std::string every_other_in(std::string given_words)
{
	std::string returnthis(""); //what will be returned
	WordCrawler A(given_words); 
	int a = words_count(given_words); //total count for words
	std::string temp; //the temp word that will be added to returnthis

	temp = *A; //setting temp to first word
	returnthis += temp; //adding first word to returnthis
	
	//increment through all the words 
	if (a > 1)
	{
		for (int i = 0; i < a; i++)
		{
			++A; //step to next word
			temp = *A; //set temp to deref word

			//if the word is an odd number in the sequence (aka every other word) then add temp to returnthis
			if (i % 2)
			{
				returnthis += " ";
				returnthis += temp;
			}
		}
	}

	std::cout << returnthis;
	return returnthis;
}
/**@brief Print in Reverse

Takes user-given string and loops through string until beginning of string is reached.
When decrementing through string, words will be pushed in a reverse order into a string
that will be outputted and returned.

@param given_words is the string that will be reversed.
@return Returns a string that contains the user-given string in reverse.
*/
std::string print_in_reverse(std::string given_words)
{
	//What I want to do: 
	/*
	Basically I went to use words_count to know how many words to increment until.
	Then after I increment until the last word, I want to decrement back and either
	cout what words I get or push it into a string.
	*/
	
	std::string returnthis(""); //what will be returned
	WordCrawler A(given_words);
	int a = words_count(given_words);
	std::string single_word; //the word that will be added to returnthis (given backwards)
	
	//move pointer to end of given string - pointer will end up at last leter of last word
	for (int i = 0; i < (a); i++)
	{
		++A; 	
	}  

	//set single_word equal to a string and add it to return statement
	--A; 
	single_word = *A; 
	returnthis += single_word;

	//decrement twice since *A automatically returns pointer to where it started (if you don't you will always be dereferencing from the same position)
	//deref A and then add it to returnthis statement
	for (int i = 0; i < (a-1); i++)
	{
		--A; --A; //decrement twice
		single_word = *A;
		returnthis += " ";
		returnthis += single_word;
	}

	std::cout << returnthis; 
	return returnthis;
}
