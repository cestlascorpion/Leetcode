//
// Created by Wang on 2019/10/13.
//

#ifndef LEETCODE_LEETCODE157CN_H
#define LEETCODE_LEETCODE157CN_H


// Forward declaration of the read4 API.
int read4(char *buf);

class Leetcode157cn {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int count4 = n/4; // 2
        int rest = n%4;   // 1

        int turn = 0; // 0 1
        int read = 0; // actually read number of bytes
        while(turn<count4){
            int ret = read4(buf+turn*4); // buf+0 buf+4
            ++turn;
            read+=ret;
            if(ret<4){
                return read;
            }
        }
        char extra[4] = {0};
        int ret = read4(extra);
        for(int i=0;i<ret && i<rest;++i){
            *(buf+turn*4+i)=*(extra+i);
            ++read;
        }
        return read;
    }
};


#endif //LEETCODE_LEETCODE157CN_H
