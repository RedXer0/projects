#include <stdio.h>

void The_List_Input();
void loop_list();

int main(){
    The_List_Input();
    return 0;
}
void loop_list(){The_List_Input();}
void The_List_Input(){
    FILE *list;
    list = fopen("/home/minny/list/list.txt", "w");

    char MyItems[100];
    int placeholder = 10;

    if (placeholder == 10){
        while(placeholder > 0){
            printf("enter your items: ");
            fgets(MyItems, sizeof(MyItems), stdin);
            list = fopen("/home/minny/list/list.txt", "a+");
            fprintf(list, "%s", MyItems);
            placeholder -= 1;
            if (placeholder <= 0){
                list = fopen("/home/minny/list/list.txt", "r");
                char List_Reader[500];
                while(fgets(List_Reader, 500, list)){
                    printf("%s", List_Reader);
                }
            }
        }
        fclose(list);
    }
}