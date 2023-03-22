#include <stdio.h>
#include <stdlib.h>

char grade(float results);
char* my_remarks(float results);

int main()
{
    int studentSize;
    printf("Enter the number of students: ");
    scanf("%d",&studentSize);

    float marks[studentSize];
    printf("Start entering the marks\n");
    for(int i=0; i< studentSize; ++i){
         printf("Student %d:\t",i+1);
         scanf("%f", &marks[i]);
         }

    float sum = 0;
    for(int i=0; i< studentSize; ++i){
         printf("\nStudent %d:\t",i+1);
         printf("%.2f",marks[i]);
         sum = sum + marks[i];
         }
    float mean = sum/studentSize;
    printf("\n\nThe mean mark is : %f\n",mean);
    printf("\nThe sorted marks:{");

    float temp = 0;
     for(int i; i<studentSize; ++i){
     for(int j=i+1; j<studentSize; ++j){
     if(marks[i] > marks[j]){
     //switch positions
     temp = marks[i];
     marks[i] = marks[j];
     marks[j] = temp;
            }
        }
    printf("  %.2f",marks[i]);
     }
    printf("}\n");




    float studentResults[7][2]= {3, 57.45,2,69.29, 2 ,71.32 , 4 , 65.05 , 3, 75.67 ,3 ,48.65,1 ,88.21};

     printf("\nCREDIT\t|SCORE\t|GRADE\t|REMARKS\n");
     printf("\t|\t|\t|\n");
     for(int i=0; i<7; ++i){
         for(int j=0; j<2; ++j){
             printf("%.2f \t|", studentResults[i][j]);
             if(j%2 == 1){
                 printf("%c \t|", grade(studentResults[i][j]));
                //printf("\n\t|\t|\t|\t|");
                 }
            if(j==1){
                char* remark = my_remarks(studentResults[i][j]);
                 printf("%s",remark) ;
                printf("\n\t|\t|\t|\t");
                 }
             }
             printf("\n");
             }
    float weightedsum = 0.0, totalcredits = 0.0;
    for(int i=0; i<7; ++i){
         weightedsum = weightedsum + (studentResults[i][0] * studentResults[i][1]);
         totalcredits += studentResults[i][0];
         }
     float cwa = weightedsum/totalcredits;
     printf("\ncwa = %.2f\n", cwa);

    return 0;
}


//function to calculate the grade
char grade(float results)
{
    if (results>=70)
        return 'A';
    else if (results<70 && results >=60)
        return 'B';
    else if(results<60 && results >=50)
        return 'C';
    else if(results<50 && results >=40)
        return 'D';
    else if(results<40 && results >=30)
        return 'E';
    else if(results<30)
        return 'F';
}

// function for the remarks
char* my_remarks(float results)
{
    char* remark;
    if (results>=70)
        remark = "Excellent";
    else if (results<70 && results >=60)
        remark = "Very Good";
    else if(results<60 && results >=50)
        remark = "Good";
    else if(results<50 && results >=40)
         remark = "Pass";
    else if(results<40 && results >=30)
        remark = "Fail";
    else if(results<30)
        remark = "Fail";

    return remark;
}
