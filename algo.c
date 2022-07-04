#include <stdio.h>
int main(void) {
	// your code goes here
    int p,l;
    scanf("%d%d",&p&l);
    if(l<7){
        printf("The bin is empty no need to pick the bin");
    }
    else if(l<18){
        printf("The bin is almost filled, should be picked up soon");
        if(p<3) printf("Recommendation: To be treated with strong base to neutralize");
        else if(p<6.5) printf("Recommendation: To be treated with mild base to neutralize");
        else if(p<7.5) printf("Recommendation: Can be directly disposed");
        else if(p<10.5) printf("Recommendation: To be treated with mild acid to neutralize");
        else printf("Recommendation: To be treated with a stroong acid in order to neutralize");
    }
    else{
        printf("The bin is completely filled hence clear the bin");
        else if(p<6.5) printf("Recommendation: To be treated with mild base to neutralize");
        else if(p<7.5) printf("Recommendation: Can be directly disposed");
        else if(p<10.5) printf("Recommendation: To be treated with mild acid to neutralize");
        else printf("Recommendation: To be treated with a stroong acid in order to neutralize");
    }
	return 0;
}

