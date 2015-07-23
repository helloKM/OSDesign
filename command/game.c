//24 points game

#include "stdio.h"
#include "stdio.h"
#define MASK 0xFFFF  
#define SHIFT 16  
enum {FAILURE = 0, SUCCESS};  
const char ops[] = "+*-/";  
  
int test (const int nums[], char result[1024]);  
int calculate (int num1, int num2, char op);  
  
int main(int argc, char * argv[])  
{  
 //   int len = 128;  
    int nums[4] = {0};  
    int i;  
    char result[1024];  
  /*  if (argc != 5)  
    {  
        printf("Usage: 24.exe num1 num2 num3 num4\n");  
        exit(1);  
    }  */
	//year = (argv[1][0] - '0') * 1000 + (argv[1][1] - '0') * 100 + (argv[1][2] - '0') * 10 + (argv[1][3] - '0') ;
    for (i = 0 ;i < 4 ;i++ )  
    {  
         
        nums[i] = ( argv[i+1][0] - '0') ;
        if (nums[i] < 1 || nums[i] > 13)  
        {  
            printf ("wrong too big or small\n");  
            exit(2);  
        }  
    }  
    /*2 pairs of paren, 3 operators, 1 for NULL. */  
   // len += 4 + 3 + 1;  
 //  result = (char *)malloc (len);  
      
    if (test(nums, result))  
        printf ("%s\n", result);  
    else  
        printf ("No Matched.\n");  
      
 //   if (result != NULL)  
   //     free (result);  
  
    return 0;  
}  
/* �������п��ܵ�������ҵ�һ�ֽⷨ*/  
int test (const int nums[], char result[1024])  
{  
    int I, J, M, N;  
    int r, s, t;  
    int ret, ret1, ret2;  
  
    /*first loop: I J r M N s t ==> (I r J) t (M s N) */  
    for (I = 0; I < 4; I++)  
    {  
        for (J = 0; J < 4; J++)  
        {  
            if (J == I)  
                continue;  
            for (r = 0; r < 4; r++)  
            {  
                ret1 = calculate (nums[I], nums[J], ops[r]);  
                if (ret1 <= 0)  
                    continue;  
                for (M = 0; M < 4; M++)  
                {  
                    if (M == I || M == J)  
                        continue;  
                    for (N = 0; N < 4; N++)  
                    {  
                        if (N == I || N == J || N == M)  
                            continue;  
                        for (s = 0; s < 4; s++)  
                        {  
                            ret2 = calculate (nums[M], nums[N], ops[s]);  
                            if (ret2 <= 0)  
                                continue;  
                            for (t = 0; t < 4; t++)  
                            {  
                                ret = calculate (ret1, ret2, ops[t]);  
                                if (((ret&MASK)==24) && ((ret>>SHIFT)==0))  
                                {  
                                    sprintf (result, "(%d%c%d)%c(%d%c%d)",   
                                        nums[I], ops[r], nums[J], ops[t],  
                                        nums[M], ops[s], nums[N]);  
                                    return SUCCESS;  
                                }  
                            }  
                        }  
                    }  
                    /* second loop: I J r M s N t ==> ((I r J) s M) t N */  
                    for (s = 0; s < 4; s++)  
                    {  
                        ret2 = calculate (ret1, nums[M], ops[s]);  
                        if (ret2 <= 0)  
                            continue;  
                        for (N = 0; N < 4; N++)  
                        {  
                            if (N == I || N == J || N == M)  
                                continue;  
                            for (t = 0; t < 4; t++)  
                            {  
                                ret = calculate (ret2, nums[N], ops[t]);  
                                if (((ret&MASK)==24) && ((ret>>SHIFT)==0))  
                                {  
                                    sprintf (result, "((%d%c%d)%c%d)%c%d",   
                                        nums[I], ops[r], nums[J], ops[s],  
                                        nums[M], ops[t], nums[N]);  
                                    return SUCCESS;  
                                }  
                            }  
                        }  
                    }  
                }  
            }  
        }  
    }  
    /* third loop: I J M r s N t ==> (I s (J r M)) t N */  
    for (I = 0; I < 4; I++)  
    {  
        for (J = 0; J < 4; J++)  
        {  
            if (J == I)  
                continue;  
            for (M = 0; M < 4; M++)  
            {  
                if (M == I || M == J)  
                    continue;  
                for (r = 0; r < 4; r++)  
                {  
                    ret1 = calculate (nums[J], nums[M], ops[r]);  
                    if (ret1 <= 0)  
                        continue;  
                    for (s = 0; s < 4; s++)  
                    {  
                        ret2 = calculate (nums[I], ret1, ops[s]);  
                        if (ret2 <= 0)  
                            continue;  
                        for (N = 0; N < 4; N++)  
                        {  
                            if (N == I || N == J || N == M)  
                                continue;  
                            for (t = 0; t < 4; t++)  
                            {  
                                ret = calculate (ret2, nums[N], ops[t]);  
                                if (((ret&MASK)==24) && ((ret>>SHIFT)==0))  
                                {  
                                    sprintf (result, "(%d%c(%d%c%d))%c%d",   
                                        nums[I], ops[s], nums[J], ops[r],  
                                        nums[M], ops[t], nums[N]);  
                                    return SUCCESS;  
                                }  
                            }  
                        }  
                    }  
                }  
            }  
        }  
    }  
    /* forth loop: I J M N r s t ==> I t (J s (M r N)) */  
    for (I = 0; I < 4; I++)  
    {  
        for (J = 0; J < 4; J++)  
        {  
            if (J == I)  
                continue;  
            for (M = 0; M < 4; M++)  
            {  
                if (M == I || M == J)  
                    continue;  
                for (N = 0; N < 4; N++)  
                {  
                    if (N == I || N == J || N == M)  
                        continue;  
                    for (r = 0; r < 4; r++)  
                    {  
                        ret1 = calculate (nums[M], nums[N], ops[r]);  
                        if (ret1 <= 0)  
                            continue;  
                        for (s = 0; s < 4; s++)  
                        {  
                            ret2 = calculate (nums[J], ret1, ops[s]);  
                            if (ret2 <= 0)  
                                continue;  
                            for (t = 0; t < 4; t++)  
                            {  
                                ret = calculate (nums[I], ret2, ops[t]);  
                                if (((ret&MASK)==24) && ((ret>>SHIFT)==0))  
                                {  
                                    sprintf (result, "%d%c(%d%c(%d%c%d))",   
                                        nums[I], ops[t], nums[J], ops[s],  
                                        nums[M], ops[r], nums[N]);  
                                    return SUCCESS;  
                                }  
                            }  
                        }  
                    }  
                }  
            }  
        }  
    }  
  
    return FAILURE;  
}  
/* ���������ض������Ͳ������Ľ��*/  
int calculate (int num1, int num2, char op)  
{  
    int numerator_num1, numerator_num2;  
    int denominator_num1, denominator_num2;  
    int ret = 0;  
    int denominator, numerator;  
  
    denominator_num1 = num1 >> SHIFT;         //��ĸ  
    denominator_num2 = num2 >> SHIFT;  
    numerator_num1 = num1 & MASK;           //����  
    numerator_num2 = num2 & MASK;  
    /* ȷ����ĸ��������ͬһ��*/  
    if (denominator_num1 > 0 && denominator_num2 > 0)  
    {  
        denominator    = denominator_num1 * denominator_num2;  
        numerator_num1 = denominator_num2 * numerator_num1;  
        numerator_num2 = denominator_num1 * numerator_num2;  
    }  
    else if (denominator_num1 > 0 && denominator_num2 == 0)  
    {  
        denominator    = denominator_num1;  
        numerator_num2 = denominator_num1 * numerator_num2;  
    }  
    else if (denominator_num1 == 0 && denominator_num2 > 0)  
    {  
        denominator    = denominator_num2;  
        numerator_num1 = denominator_num2 * numerator_num1;  
    }  
    else  
    {  
        denominator = 0;  
    }  
    /* ����*/  
    if (op == '+')  
    {  
        numerator = numerator_num1 + numerator_num2;  
    }  
    else if (op == '-')  
    {  
        numerator = numerator_num1 - numerator_num2;  
    }  
    else if (op == '*')  
    {  
        numerator    = numerator_num1 * numerator_num2;  
        denominator *= denominator;  
    }  
    else if (op == '/')  
    {  
        if (numerator_num2 > 0 && numerator_num1%numerator_num2 == 0)  
        {  
        /* ���ӿ�����������ĸ��û�б�Ҫ�ˡ�*/  
            numerator   = numerator_num1 / numerator_num2;  
            denominator = 0;  
        }  
        else  
        {  
            numerator   = numerator_num1;  
            denominator = numerator_num2;  
        }  
    }  
    if (denominator>0 && numerator%denominator == 0)  
    {  
        numerator   = numerator / denominator;  
        denominator = 0;  
    }  
    ret = (numerator<=0)?numerator:((numerator&MASK) | (denominator<<SHIFT));  
    return ret;  
}  
