#include<stdio.h>
#include<stdlib.h>

struct node
{
    int freq;
    char alpha;
    struct node* left;
    struct node* right;
};
int k;
struct node* ExtractMin(struct node** str,int n){
    if(!str[n])
        return NULL;
    struct node* min= (struct node*)malloc(sizeof(struct node));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if()
        }
    }



}

void sortArray(struct node** str){
    struct node* min= (struct node*)malloc(sizeof(struct node));

    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){

        }
    }

}


int main(){
    struct node* a[4];
    a[0]= (struct node*)malloc(sizeof(struct node));
    a[0]->alpha='a';
    a[0]->freq =5;


    a[1]= (struct node*)malloc(sizeof(struct node));
    a[1]->alpha='b';
    a[1]->freq =5;

    a[2]= (struct node*)malloc(sizeof(struct node));
    a[2]->alpha='c';
    a[2]->freq =15;

    struct node* a= (struct node*)malloc(sizeof(struct node));
    a[3]->alpha='d';
    a[3]->freq =20;

    for(int i=0;i<4;i++){
        struct node* b[i+4];
        b[i+4]=(struct node*)malloc(sizeof(struct node));
        if(i=0){
            b[i+4]->left=b[i];
            b[i]
        }
    }
}
