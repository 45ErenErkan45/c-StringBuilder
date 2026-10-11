#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringbuilder.h"

int main() {
    int n,i;
    printf("enter a number of word for adding SB!\n\n");
	scanf("%d", &n);
    getchar(); 
    
    
    StringBuilder* sb1 = create_stringbuilder();
    
    for(i = 0; i < n; ++i){
        printf("enter word %d:\n",i + 1);
		char txt[256];
        fgets(txt, sizeof(txt), stdin);
        txt[strcspn(txt,"\n")] = '\0';
        append(sb1, txt);
    }
    
    printf("\n%s",get_string(sb1));
    
    printf("\n\nSB is destroying...\n\n");
    free_stringbuilder(sb1);
    return 0;
}

