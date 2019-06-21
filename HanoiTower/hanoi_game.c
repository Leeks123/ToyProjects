/*
하노이탑
1. 타이틀 및 시도 횟수 출력
2. 5층의 하노이탑 
    2.1 블록이동
        2.1.1 dest > src : try만 증가 
        2.1.2 dest = src : try만 증가 
        2.1.3 dest < src : src의 블록을 dest로 이동. src는 공백 
        2.1.4 src가 공백일때 : src의 불록을 dest로 이동. dest의 최상층위치는 변화없음. 
        2.1.5 공백블록에서 공백블록으로 옮길때 에러제거 
    2.2 변경사항 출력 print() 
    2.3 종료조건 충족시 finish()함수 호출 
        2.3.1 최소이동수에서 추가되는 만큼 100점에서 점수 줄어듬. 
3. dest와 src를 입력받기 
*/
#include <stdio.h>
#include <windows.h>

int dest=1,src=1;
int try=0;

//block
    char* one="    □    ";
    char* two="   □□   "; 
    char* thr="  □□□  ";
    char* fou=" □□□□ ";
    char* fiv="□□□□□";//10
    char* tab="          ";
    
    int ctop[3]={0,4,4};
//map
char* arr[5][3];

void init(){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<3;j++){
            arr[i][j]=tab;
        }
    }
    arr[0][0]=one;
    arr[1][0]=two;
    arr[2][0]=thr;
    arr[3][0]=fou;
    arr[4][0]=fiv;
}

void status(){
    printf("\n\t\tHanoi Tower\n\t\t\t\tyou try %d times\n",try);
    printf("__________________________________________________\n\n");
}
double score(){
    double score=100;
    if(try>31){
        score = score - 2*(try-31);
        return score;
    }
    else{
        return score;
    }
}
void finish(){
    system("cls");
    printf("###############################################\n");
    printf("###############################################\n");
    printf("###      ###  ###  #####  #####################\n");
    printf("###  #######  ###  # ###  #####################\n");
    printf("###      ###  ###  ## ##  #####################\n");
    printf("###  #######  ###  ### #  #####################\n");
    printf("###  #######  ###  #####  #####################\n");
    printf("###############################################\n");
    printf("###############################################\n");
    printf("### your score is %lf  ##################\n",score());
}
void print(){
    int i,j;
    for(i=0;i<5;i++){
        printf("\t");
        for(j=0;j<3;j++){
            printf("%s\t",arr[i][j]);
        }
        printf("\n");
    }
     printf("\t     1               2               3     \n");
}

void game(int src,int dest){
    
    if(dest>3||src>3||dest<1||src<1){
        printf("error!!\n");
        dest=1;src=1;
    }else if(dest == src){  
        try++;
    }else if(strcmp(arr[ctop[dest-1]][dest-1],tab)==0&&strcmp(arr[ctop[src-1]][src-1],tab)==0){ //공백에서 공백 
        try++;
    }else{
        if(strcmp(arr[ctop[src-1]][src-1],arr[ctop[dest-1]][dest-1])>0){//작거나 공백 
            if(strcmp(arr[ctop[dest-1]][dest-1],tab)==0){//공백 
                arr[ctop[dest-1]][dest-1]=arr[ctop[src-1]][src-1];
                arr[ctop[src-1]][src-1]=tab;
                //ctop[src-1]--;
                if(ctop[src-1]==4){
                }else{
                    ctop[src-1]++;
                }   
                try++;
            }else{ //작거나 
                try++;
            }
        }else{//크거나
            arr[ctop[dest-1]-1][dest-1]=arr[ctop[src-1]][src-1];
            arr[ctop[src-1]][src-1]=tab;  
            ctop[dest-1]--;
            if(ctop[src-1]==4){
            }else{
                ctop[src-1]++;
            }
            try++;  
        }
    }
    print();
    if(ctop[2]==0){
        finish();
    }
}
int main(){
    
    init();
    while(1){
        status();
        
        game(src,dest);
        //printf("%d %d %d\n",ctop[0],ctop[1],ctop[2]);
    
        printf("__________________________________________________\ninput src dest \n");
        printf("(if you want to move column1 to column2, input 1 2)\n>> ");
        scanf("%d %d",&src,&dest);
        while (getchar() != '\n');
        system("cls");
    }
    return 0;
}
