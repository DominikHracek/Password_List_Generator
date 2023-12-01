#ifndef GENERATE_H
#define GENERATE_H

class Generate{
    public:
        Generate();
        void get_info();
        void generate_combinations();

    private:
        bool use_same_word_multiple_times_in_one;
        int multiplier;
};

#endif