#include <iostream>

class String
{
public:

    // constructs this string from a C string, defaults to empty string
    explicit String( const char * s = "" );

    // construct this string as a copy of string s
    String( const String & s );

    // construct this string by moving from string s
    String( String && s );

    // assignment to this string by moving from string s
    String & operator = ( String && s );

    // assignment operator from one string, s, to this string
    String & operator = ( const String & s );

    // allow indexing this string with notation s[i]
    char & operator [] ( int index );

    // returns the logical length of this string (# of chars up to '\0')
    size_t size();

    // returns a reversal of this string, does not modify this string
    String reverse(); 

    // returns index into this string for first occurance of c
    int indexOf( const char c );

    // returns index into this string for first occurance of s
    int indexOf( const String & s );

    // relational operators for comparing this strings to another string
    bool operator == ( const String & s );
    bool operator != ( const String & s );
    bool operator > ( const String & s );
    bool operator < ( const String & s );
    bool operator <= ( const String & s );
    bool operator >= ( const String & s );

    // concatenate this and s to form a return string
    String operator +( const String & s);

    // concatenate s onto the end of this string
    String & operator +=( const String & s);

    // print this string, hint: use operator << to send buf to out
    void print( ostream & out ) const;

    // read next word into this string
    // hint: use operator >> to read from in into buf 
    void read( istream & in );

    // destructor for a this string
    ~String();

// private: // Leave these static helper methods public so we can test them

    bool in_bounds(int i)
    {
        return i >= 0 && i < strlen(buf);
    }

    static size_t strlen( const char * s );
    static char * strdup( const char * s); // change
    static char * strcpy( char * dest, const char * src );
    static char * strncpy( char * dest, const char * src, int n );
    static char * strcat( char * dest, const char * src ); // change
    static char * strncat( char * dest, const char * src, int n );
    static int strcmp( const char * left, const char * right );
    static int strncmp( const char * left, const char * right, int n );
    static void reverse_cpy( char * dest, const char * src );
    static char * strchr( char * str, char c );
    static char *strstr( char * haystack, const char * needle );
    static const char * strstr( const char * haystack, const char * needle );

private:

    char * buf; // base of array for the characters in this String

    // DO NOT add any data members - use the null terminator

};

ostream & operator << ( ostream & out, const String & s );
istream & operator >> ( istream & in, String & s );
