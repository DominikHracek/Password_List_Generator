#include "hash.h"

#include <iostream>
#include <string>

#include <cryptopp/md2.h>
#include <cryptopp/md4.h>
#include <cryptopp/md5.h>
#include <cryptopp/sha.h>
#include <cryptopp/sha3.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

/**
 * Constructor for the Hash class.
 *
 * @param none
 *
 * @return none
 *
 * @throws none
 */
Hash::Hash() {
    data = "";
    hash_function = "";
}

/**
 * Sets the data and hash function for the Hash object.
 *
 * @param data the data to be hashed
 * @param hash_function the hash function to be used
 *
 * @return void
 *
 * @throws None
 */
void Hash::get_parameters(const std::string& data, const std::string& hash_function) {
    this->data = data;
    this->hash_function = hash_function;
}

/**
 * Retrieves the hash of the given data using the specified hash function.
 *
 * @param data the input data to be hashed
 * @param hash_function the name of the hash function to be used
 *
 * @return the resulting hash value
 *
 * @throws None
 */
std::string Hash::get_hash(const std::string& data, const std::string& hash_function) {

    if (hash_function == "md2") {
        return MD2(data);
    } else if (hash_function == "md4") {
        return MD4(data);
    } else if (hash_function == "md5") {
        return MD5(data);
    } else if (hash_function == "ntlm") {
        return NTLM(data);
    } else if (hash_function == "sha1_160") {
        return SHA1_160(data);
    } else if (hash_function == "sha224") {
        return SHA2_224(data);
    } else if (hash_function == "sha256") {
        return SHA2_256(data);
    } else if (hash_function == "sha384") {
        return SHA2_384(data);
    } else if (hash_function == "sha512") {
        return SHA2_512(data);
    } else if (hash_function == "sha3_224") {
        return SHA3_224(data);
    } else if (hash_function == "sha3_256") {
        return SHA3_256(data);
    } else if (hash_function == "sha3_384") {
        return SHA3_384(data);
    } else if (hash_function == "sha3_512") {
        return SHA3_512(data);
    }

    return "";
}

/**
 * Calculates the MD2 hash of the given data.
 *
 * @param data the input data for which the MD2 hash is to be calculated
 *
 * @return the MD2 hash of the input data
 *
 * @throws ErrorType description of error
 */
std::string Hash::MD2(const std::string& data) {
    CryptoPP::Weak1::MD2 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

/**
 * Calculates the MD4 hash of the given data.
 *
 * @param data the input data for which the MD4 hash is to be calculated
 *
 * @return the MD4 hash of the input data
 *
 * @throws ErrorType description of error
 */
std::string Hash::MD4(const std::string& data) {
    CryptoPP::Weak1::MD4 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

/**
 * Calculates the MD5 hash of the given data.
 *
 * @param data the input data for which the MD5 hash is to be calculated
 *
 * @return the MD5 hash of the input data
 *
 * @throws ErrorType description of error
 */
std::string Hash::MD5(const std::string& data) {
    CryptoPP::Weak1::MD5 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

std::string Hash::SHA1_160(const std::string &data) {
    CryptoPP::SHA1 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );
    return output;
}

/**
 * Calculates the SHA2_224 hash of the given data.
 *
 * @param data the input data for which the SHA2_224 hash is to be calculated
 *
 * @return the SHA2_224 hash of the input data
 *
 * @throws ErrorType description of error
 */
std::string Hash::SHA2_224(const std::string& data) {
    CryptoPP::SHA224 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

/**
 * Calculates the SHA2_256 hash of the given data.
 *
 * @param data the input data for which the SHA2_256 hash is to be calculated
 *
 * @return the SHA2_256 hash of the input data
 *
 * @throws ErrorType description of error
 */
std::string Hash::SHA2_256(const std::string& data) {
    CryptoPP::SHA256 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

/**
 * Calculates the SHA2_384 hash of the given data.
 *
 * @param data the input data for which the SHA2_384 hash is to be calculated
 *
 * @return the SHA2_384 hash of the input data
 *
 * @throws ErrorType description of error
 */
std::string Hash::SHA2_384(const std::string& data) {
    CryptoPP::SHA384 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

/**
 * Calculates the SHA2_512 hash of the given data.
 *
 * @param data the input data for which the SHA2_512 hash is to be calculated
 *
 * @return the SHA2_512 hash of the input data
 *
 * @throws ErrorType description of error
 */
std::string Hash::SHA2_512(const std::string& data) {
    CryptoPP::SHA512 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

/**
 * Calculates the SHA3_224 hash of the given data.
 *
 * @param data the input data for which the SHA3_224 hash is to be calculated
 *
 * @return the SHA3_224 hash of the input data
 *
 * @throws ErrorType description of error
 */
std::string Hash::SHA3_224(const std::string& data) {
    CryptoPP::SHA3_224 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

/**
 * Calculates the SHA3_256 hash of the given data.
 *
 * @param data the input data for which the SHA3_256 hash is to be calculated
 *
 * @return the SHA3_256 hash of the input data
 *
 * @throws ErrorType description of error
 */
std::string Hash::SHA3_256(const std::string& data) {
    CryptoPP::SHA3_256 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

/**
 * Calculates the SHA3_384 hash of the given data.
 *
 * @param data the input data for which the SHA3_384 hash is to be calculated
 *
 * @return the SHA3_384 hash of the input data
 *
 * @throws ErrorType description of error
 */
std::string Hash::SHA3_384(const std::string& data) {
    CryptoPP::SHA3_384 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

/**
 * Calculates the SHA3_512 hash of the given data.
 *
 * @param data the input data for which the SHA3_512 hash is to be calculated
 *
 * @return the SHA3_512 hash of the input data
 *
 * @throws ErrorType description of error
 */
std::string Hash::SHA3_512(const std::string& data) {
    CryptoPP::SHA3_512 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

#define INIT_A 0x67452301
#define INIT_B 0xefcdab89
#define INIT_C 0x98badcfe
#define INIT_D 0x10325476

#define SQRT_2 0x5a827999
#define SQRT_3 0x6ed9eba1

unsigned int nt_buffer[16];
unsigned int output[4];
char hex_format[33];
char itoa16[17] = "0123456789ABCDEF";

/**
 * Calculates the NTLM hash of the given data.
 *
 * @param data the input data for which the NTLM hash is to be calculated
 *
 * @return the NTLM hash of the input data
 *
 * @throws ErrorType description of error
 */
std::string Hash::NTLM(const std::string& data){
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Prepare the string for hash calculation
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	int i = 0;
	int length = data.length();
	memset(nt_buffer, 0, 16*4);
	//The length of key need to be <= 27
	for(; i<length/2; i++)
		nt_buffer[i] = data[2 * i] | (data[2 * i + 1] << 16);

	//padding
	if(length % 2 == 1)
		nt_buffer[i] = data[length - 1] | 0x800000;
	else
		nt_buffer[i] = 0x80;
	//put the length
	nt_buffer[14] = length << 4;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// NTLM hash calculation
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	unsigned int a = INIT_A;
	unsigned int b = INIT_B;
	unsigned int c = INIT_C;
	unsigned int d = INIT_D;

	/* Round 1 */
	a += (d ^ (b & (c ^ d)))  +  nt_buffer[0]  ;a = (a << 3 ) | (a >> 29);
	d += (c ^ (a & (b ^ c)))  +  nt_buffer[1]  ;d = (d << 7 ) | (d >> 25);
	c += (b ^ (d & (a ^ b)))  +  nt_buffer[2]  ;c = (c << 11) | (c >> 21);
	b += (a ^ (c & (d ^ a)))  +  nt_buffer[3]  ;b = (b << 19) | (b >> 13);

	a += (d ^ (b & (c ^ d)))  +  nt_buffer[4]  ;a = (a << 3 ) | (a >> 29);
	d += (c ^ (a & (b ^ c)))  +  nt_buffer[5]  ;d = (d << 7 ) | (d >> 25);
	c += (b ^ (d & (a ^ b)))  +  nt_buffer[6]  ;c = (c << 11) | (c >> 21);
	b += (a ^ (c & (d ^ a)))  +  nt_buffer[7]  ;b = (b << 19) | (b >> 13);

	a += (d ^ (b & (c ^ d)))  +  nt_buffer[8]  ;a = (a << 3 ) | (a >> 29);
	d += (c ^ (a & (b ^ c)))  +  nt_buffer[9]  ;d = (d << 7 ) | (d >> 25);
	c += (b ^ (d & (a ^ b)))  +  nt_buffer[10] ;c = (c << 11) | (c >> 21);
	b += (a ^ (c & (d ^ a)))  +  nt_buffer[11] ;b = (b << 19) | (b >> 13);

	a += (d ^ (b & (c ^ d)))  +  nt_buffer[12] ;a = (a << 3 ) | (a >> 29);
	d += (c ^ (a & (b ^ c)))  +  nt_buffer[13] ;d = (d << 7 ) | (d >> 25);
	c += (b ^ (d & (a ^ b)))  +  nt_buffer[14] ;c = (c << 11) | (c >> 21);
	b += (a ^ (c & (d ^ a)))  +  nt_buffer[15] ;b = (b << 19) | (b >> 13);

	/* Round 2 */
	a += ((b & (c | d)) | (c & d)) + nt_buffer[0] +SQRT_2; a = (a<<3 ) | (a>>29);
	d += ((a & (b | c)) | (b & c)) + nt_buffer[4] +SQRT_2; d = (d<<5 ) | (d>>27);
	c += ((d & (a | b)) | (a & b)) + nt_buffer[8] +SQRT_2; c = (c<<9 ) | (c>>23);
	b += ((c & (d | a)) | (d & a)) + nt_buffer[12]+SQRT_2; b = (b<<13) | (b>>19);

	a += ((b & (c | d)) | (c & d)) + nt_buffer[1] +SQRT_2; a = (a<<3 ) | (a>>29);
	d += ((a & (b | c)) | (b & c)) + nt_buffer[5] +SQRT_2; d = (d<<5 ) | (d>>27);
	c += ((d & (a | b)) | (a & b)) + nt_buffer[9] +SQRT_2; c = (c<<9 ) | (c>>23);
	b += ((c & (d | a)) | (d & a)) + nt_buffer[13]+SQRT_2; b = (b<<13) | (b>>19);

	a += ((b & (c | d)) | (c & d)) + nt_buffer[2] +SQRT_2; a = (a<<3 ) | (a>>29);
	d += ((a & (b | c)) | (b & c)) + nt_buffer[6] +SQRT_2; d = (d<<5 ) | (d>>27);
	c += ((d & (a | b)) | (a & b)) + nt_buffer[10]+SQRT_2; c = (c<<9 ) | (c>>23);
	b += ((c & (d | a)) | (d & a)) + nt_buffer[14]+SQRT_2; b = (b<<13) | (b>>19);

	a += ((b & (c | d)) | (c & d)) + nt_buffer[3] +SQRT_2; a = (a<<3 ) | (a>>29);
	d += ((a & (b | c)) | (b & c)) + nt_buffer[7] +SQRT_2; d = (d<<5 ) | (d>>27);
	c += ((d & (a | b)) | (a & b)) + nt_buffer[11]+SQRT_2; c = (c<<9 ) | (c>>23);
	b += ((c & (d | a)) | (d & a)) + nt_buffer[15]+SQRT_2; b = (b<<13) | (b>>19);

	/* Round 3 */
	a += (d ^ c ^ b) + nt_buffer[0]  +  SQRT_3; a = (a << 3 ) | (a >> 29);
	d += (c ^ b ^ a) + nt_buffer[8]  +  SQRT_3; d = (d << 9 ) | (d >> 23);
	c += (b ^ a ^ d) + nt_buffer[4]  +  SQRT_3; c = (c << 11) | (c >> 21);
	b += (a ^ d ^ c) + nt_buffer[12] +  SQRT_3; b = (b << 15) | (b >> 17);

	a += (d ^ c ^ b) + nt_buffer[2]  +  SQRT_3; a = (a << 3 ) | (a >> 29);
	d += (c ^ b ^ a) + nt_buffer[10] +  SQRT_3; d = (d << 9 ) | (d >> 23);
	c += (b ^ a ^ d) + nt_buffer[6]  +  SQRT_3; c = (c << 11) | (c >> 21);
	b += (a ^ d ^ c) + nt_buffer[14] +  SQRT_3; b = (b << 15) | (b >> 17);

	a += (d ^ c ^ b) + nt_buffer[1]  +  SQRT_3; a = (a << 3 ) | (a >> 29);
	d += (c ^ b ^ a) + nt_buffer[9]  +  SQRT_3; d = (d << 9 ) | (d >> 23);
	c += (b ^ a ^ d) + nt_buffer[5]  +  SQRT_3; c = (c << 11) | (c >> 21);
	b += (a ^ d ^ c) + nt_buffer[13] +  SQRT_3; b = (b << 15) | (b >> 17);

	a += (d ^ c ^ b) + nt_buffer[3]  +  SQRT_3; a = (a << 3 ) | (a >> 29);
	d += (c ^ b ^ a) + nt_buffer[11] +  SQRT_3; d = (d << 9 ) | (d >> 23);
	c += (b ^ a ^ d) + nt_buffer[7]  +  SQRT_3; c = (c << 11) | (c >> 21);
	b += (a ^ d ^ c) + nt_buffer[15] +  SQRT_3; b = (b << 15) | (b >> 17);

	output[0] = a + INIT_A;
	output[1] = b + INIT_B;
	output[2] = c + INIT_C;
	output[3] = d + INIT_D;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Convert the hash to hex (for being readable)
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	for(i=0; i<4; i++)
	{
		int j = 0;
		unsigned int n = output[i];
		//iterate the bytes of the integer
		for(; j<4; j++)
		{
			unsigned int convert = n % 256;
			hex_format[i * 8 + j * 2 + 1] = itoa16[convert % 16];
			convert = convert / 16;
			hex_format[i * 8 + j * 2 + 0] = itoa16[convert % 16];
			n = n / 256;
		}
	}
	//null terminate the string
	hex_format[33] = 0;
    return hex_format;
}