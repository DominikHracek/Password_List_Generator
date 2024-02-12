#ifndef HASH_H
#define HASH_H
#include <string>

class Hash {
    public:
        Hash();
        std::string get_hash(std::string hash_function, std::string data);

        class MD {
            public:
                std::string MD2(const std::string& data);
                std::string MD4(const std::string& data);
                std::string MD5(const std::string& data);
        };

        class SHA {
            public:
                class SHA1 {
                    public:
                        std::string SHA1_160(const std::string& data);
                };

                class SHA2 {
                    public:
                        std::string SHA2_224(const std::string& data);
                        std::string SHA2_256(const std::string& data);
                        std::string SHA2_384(const std::string& data);
                        std::string SHA2_512(const std::string& data);
                };

                class SHA3 {
                    public:
                        std::string SHA3_224(const std::string& data);
                        std::string SHA3_256(const std::string& data);
                        std::string SHA3_384(const std::string& data);
                        std::string SHA3_512(const std::string& data);
                };
        };

    private:
        std::string hash;
};

#endif