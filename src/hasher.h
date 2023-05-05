#ifndef HASHER_H
#define HASHER_H
#include <iostream>

using namespace std;

struct Hasher
{
    const string name;
    Hasher(const char *nm)
        : name(nm) { }
    virtual size_t hash(string key, int N) const = 0;
};

struct MultHasher
    : public Hasher
{

    MultHasher()
        : Hasher("MultHasher")
    {
    }

    size_t hash(string key, int N) const
    {
		size_t result = 1;
        int len = key.length();
		for (int i=0; i<len; ++i)
			result *= key[i];
		return result % N;

    }
};
struct SumHasher
    : public Hasher
{
    SumHasher()
        : Hasher("SumHasher")
    {
    }

    size_t hash(string key, int N) const
    {
        size_t result = 0;
        int len = key.length();
		for (int i=0; i<len; ++i)
			result += key[i];
		return result % N;
    }
};
struct WeissHasher
    : public Hasher
{
    WeissHasher()
        : Hasher("WeissHasher")
    {
    }

    size_t hash(string key, int N) const
    {
        constexpr size_t sig_bits = 6;
        constexpr size_t bits_per_size_t = std::numeric_limits<size_t>::digits;
        constexpr size_t zero = 0;
        constexpr size_t mask = ~zero >> (bits_per_size_t-sig_bits);
        const int num_chars = bits_per_size_t/sig_bits;
        int len = key.length();
        if (len > num_chars) len = num_chars;
        size_t result = 0;
		for (int i=0; i<len; ++i)
			result = (result << sig_bits) | (key[i] & mask);
		return result % N;
    }
};

struct PJWHasher
    : public Hasher
{
    PJWHasher()
        : Hasher("PJWHasher")
    {
    }

    /* https://en.wikipedia.org/wiki/PJW_hash_function */

    size_t hash(string key, int N) const
    {
        constexpr size_t PJW_HASH_SHIFT = 4;
				// How much to shift hash by, per char hashed
        constexpr size_t PJW_HASH_RIGHT_SHIFT = 24;
				// Right-shift amount, if top 4 bits NZ
				// 32-BIT
        constexpr size_t PJW_HASH_MASK = 0xf0000000;
				// Mask for extracting top 4 bits
				// 32-BIT
        unsigned int hashValue = 0;
        for (string::const_iterator i = key.begin();  i != key.end();  i++)
        {
            hashValue = (hashValue << PJW_HASH_SHIFT) + (unsigned)*i;
            unsigned int rotate_bits = hashValue & PJW_HASH_MASK;
            hashValue ^= rotate_bits | (rotate_bits >> PJW_HASH_RIGHT_SHIFT);
        }
        return hashValue % N;
    }
};

struct GoodrichHasher
    : public Hasher
{
    GoodrichHasher()
        : Hasher("GoodrichHasher")
    {
    }

    /* Goodrich & Tamassia, Chapter 5 */

    size_t hash(string key, int N) const
    {
        constexpr size_t large_prime = 16908799;
        int len = key.length();
        size_t result = 0;
		for (int i=0; i<len; ++i)
			result = (127 * result + key[i]) % large_prime;
		return result % N;
    }
};

/*
 * Hash an integer by taking the absolute value.  This is recommended
 * in Bruno Preiss, "Data Structures and Algorithms with
 * Object-Oriented Design Patterns in C++", Wiley, 1999, p. 210.
 */
struct PreissHasher
    : public Hasher
{
    PreissHasher()
        : Hasher("PreissHasher")
    {
    }

    size_t hash(string key, int N) const
    {
        constexpr size_t BYTE_WIDTH = 8;
				// Number of bits in a byte
        constexpr size_t WORD_WIDTH = sizeof (int) * BYTE_WIDTH;
				// Number of bits in a machine word (int), used
				// ..by several algorithms.
        constexpr size_t PREISS_HASH_SHIFT = 6;
				// How much to shift hash by, per char hashed
        constexpr size_t PREISS_HASH_MASK =
			    ~0U << (WORD_WIDTH - PREISS_HASH_SHIFT);
				// Mask for extracting top bits
        size_t hashValue = 0;
        for (string::const_iterator i = key.begin();  i != key.end();  i++)
            hashValue = (hashValue & PREISS_HASH_MASK)
                ^ (hashValue << PREISS_HASH_SHIFT)
                ^ (unsigned)*i;
        return hashValue % N;
    }
};


/*
 * Hash a string using the method given in Mark Allen Weiss,
 * "Algorithms, Data Structures, and Problem Solving with C++" (first
 * edition), Addison-Wesley, 1996, p. 611.
 */

struct Weiss1Hasher
    : public Hasher
{
    Weiss1Hasher()
        : Hasher("Weiss1Hasher")
    {
    }

    size_t hash(string key, int N) const
    {
        constexpr size_t WEISS_HASH_SHIFT = 5;
                        // How much to shift hash by, per char hashed
        size_t hashValue = 0;
        for (string::const_iterator i = key.begin();  i != key.end();  i++)
            hashValue = hashValue ^ (hashValue << WEISS_HASH_SHIFT) ^ (unsigned)*i;
        return hashValue % N;
    }
};

/*
 * Hash a string using the method given in Mark Allen Weiss,
 * "Algorithms, Data Structures, and Problem Solving with C++" (second
 * edition), Addison-Wesley, 1999, p. 728.
 */
struct Weiss2Hasher
    : public Hasher
{
    Weiss2Hasher()
        : Hasher("Weiss2Hasher")
    {
    }

    size_t hash(string key, int N) const
    {
        constexpr size_t WEISS_HASH_MULTIPLIER = 37;
                        // How much to multiply by, per char hashed
        size_t hashValue = 0;
        for (string::const_iterator i = key.begin();  i != key.end();  i++)
        hashValue = hashValue * WEISS_HASH_MULTIPLIER + (unsigned)*i;
        return hashValue % N;
    }
};

struct STLHasher
    : public Hasher
{
    STLHasher()
        : Hasher("STLHasher")
    {
    }

    size_t hash(string key, int N) const
    {
        std::size_t hashValue = std::hash<std::string>{}(key);
        return hashValue % N;
    }
};

struct ChatGPTHasher
    : public Hasher
{
    ChatGPTHasher()
        : Hasher("ChatGPTHasher")
    {
    }

    size_t hash(string key, int N) const
    {
        size_t hash_val = 0;
        for (auto c : key) {
            hash_val = (hash_val * 31 + (size_t)c) % N;
        }
        return hash_val;
    }
};
#endif
