//
//  main.c
//  1003
//
//  Created by 刘靖迪 on 2017/9/13.
//  Copyright © 2017年 刘靖迪. All rights reserved.
//

#include <stdio.h>
#define MAXN 100001
int q[MAXN];

int head = 0, tail = 0;

int en_c_q (int x){
    tail = (tail +1) % MAXN;
    if (tail == head) {
        if (tail == 0) tail = MAXN - 1;
        else tail--;
        return 1;
    }
    q[tail] = x;
    return 0;
}

int de_c_q (int *p_y) {
    if (head == tail)
        return 1;
    head = (head + 1) % MAXN;
    *p_y = q[head];
    printf("%d", *p_y);
    return 0;
}

int main(int argc, const char * argv[]) {
    int n;
    char in[10];
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%s", in);
        int c;
        if (in[0] == 'e') {
            scanf("%d", &c);
                en_c_q(c);
        }
        if (in[0] == 'd') {
            if (de_c_q(&c) == 0);
            else printf("-1");
            printf("\n");
        }
    }
    return 0;
}
