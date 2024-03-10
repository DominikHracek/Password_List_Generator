#ifndef HASH_H
#define HASH_H

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

#include <string>

class Hash {
    public:
        Hash();
        void get_parameters(const std::string& data, const std::string& hash_function);
        static std::string get_hash(const std::string& data, const std::string& hash_function);

        static std::string MD2(const std::string& data);
        static std::string MD4(const std::string& data);
        static std::string MD5(const std::string& data);

        static std::string SHA1_160(const std::string& data);

        static std::string SHA2_224(const std::string& data);
        static std::string SHA2_256(const std::string& data);
        static std::string SHA2_384(const std::string& data);
        static std::string SHA2_512(const std::string& data);

        static std::string SHA3_224(const std::string& data);
        static std::string SHA3_256(const std::string& data);
        static std::string SHA3_384(const std::string& data);
        static std::string SHA3_512(const std::string& data);

        static std::string NTLM(const std::string& data);

    private:
        std::string data;
        std::string hash_function;
        std::string hash;
};

#endif //HASH_H