/*
 * =====================================================================================
 *
 *       Filename:  test_cmpxchgl.c
 *
 *    Description:  cmpxchgl
 *
 *        Version:  1.0
 *        Created:  2018/01/23 14时53分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yandong Yan (A Program fan.), yandong.yan@upai.com or (yydgame@163.com)
 *        Company:  upyun
 *
 * =====================================================================================
 */

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>


static inline uint32_t
im_atomic_cmp_set(uint32_t *lock, uint32_t old, uint32_t set)
{
    unsigned char res;

    // 如果 *lock==old 则设置*lock=set
    __asm__ volatile (

    "    lock;               "
    "    cmpxchgl  %3, %1;   "
    "    sete      %0;       "

    : "=a" (res) : "m" (*lock), "a" (old), "r" (set) : "cc", "memory");
    printf("*lock=%d, old=%d value=%d\n",*lock,old,set);
    return res;
}

int main(){
	printf("---- begin ---- \n");
    uint32_t a;
    uint32_t b,c;
    a=11;
    b=11;
    c=12;
    uint32_t res = im_atomic_cmp_set(&a,b,c);
	printf("---- res=%d\n",res);
	printf("---- a=%d b=%d c=%d\n",a,b,c);
    
    return 0;
}
