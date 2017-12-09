

void read_word(istream& buffer, char* s, int max)
	// read at most max - 1 characters from is into buffer
{
	is.width(max);		// read at most max - 1 characters in the next >>
	is >> buffer;		// read white space terminated word
				// add zero after the last character read into buffer
	return is;
}


