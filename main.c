#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void getInformation();
void printTXTfile(int numb_of_students);
void searchforstudent(int numb_of_students);

struct Student{

    char firstname[100];
    char lastname[100];
    char id[20];

    float quizmarks[30];
    float midmarks[30];
    float assignmentmarks[30];

    float projectmarks;
    float finalmarks;

    int attendance;

    float cgpa;
    char grade[20];

}info[100];

int main()
{
     printf("\t\t\t\t\t\t***NSU Classroom***");
    int option;
    //Menu starts from here.
    while(1)
    {
        printf("\n\nSelect Option:\n");
        printf("1.Enter Information.\n");
        printf("2.Search Information.\n");
        printf("3.Exit.\n\n");
        scanf("%d",&option);

        if(option==1 ||option==2 ||option==3)
        {
            if(option==1)
            {
                printf("Any previous saved data has been erased.\n");
                int numb_of_students;
                printf("Enter Following Information For Course Detail.\n");
                printf("Enter number of students in Section: ");
                scanf("%d",&numb_of_students);
                getInformation(numb_of_students);
            }
            if(option==2)
            {
                int numb_of_students;
                printf("Enter number of students in Section: ");
                scanf("%d",&numb_of_students);
                searchforstudent(numb_of_students);


            }
            if(option==3)
            {
                break;
            }

        }
        else
        {
            printf("\n\nInvalid Option.\n\n");
        }

    }
}

void getInformation(int numb_of_students)
{
    printf("Note: Mark distribution is as follows:\nAttendance 10%% \nQuiz 15%% \nAssignment 10%% \nMid-Term 20%% \nFinal 30%% \nProject 15%% \n\n");


    int numb_of_quiz, numb_of_assignment, numb_of_mid, numb_of_attendance;
    printf("Enter number of Total Classes taken: ");
    scanf("%d",&numb_of_attendance);
    printf("Enter number of Quizzes taken: ");
    scanf("%d",&numb_of_quiz);
    printf("Enter number of Assignments given: ");
    scanf("%d",&numb_of_assignment);
    printf("Enter number of Mid-Term exams taken: ");
    scanf("%d",&numb_of_mid);

    printf("\n\nNote: Only Best Mid term mark will be taken and Everything Else will be Averaged.\n\n");

    int mark_of_quiz, mark_of_assignment, mark_of_mid, mark_of_final, mark_of_project;
    printf("Enter total mark of one Quiz: ");
    scanf("%d",&mark_of_quiz);
    printf("Enter total mark of one Assignment: ");
    scanf("%d",&mark_of_assignment);
    printf("Enter total mark of one Mid-Term exam: ");
    scanf("%d",&mark_of_mid);
    printf("Enter total mark of Final exam: ");
    scanf("%d",&mark_of_final);
    printf("Enter total mark of Project: ");
    scanf("%d",&mark_of_project);
    printf("\n\n");
    //Academic Info Input done.

    int i,j;


    for(i=0;i<numb_of_students;i++)
    {
        printf("Enter First name of student %d: ",i+1);
        scanf("%s",info[i].firstname);
        printf("Enter Last name of student %d: ",i+1);
        scanf("%s",info[i].lastname);
        printf("Enter ID: ");
        scanf("%s",info[i].id);
        for(j=0;j<numb_of_quiz;j++)
        {
            printf("Enter mark for Quiz-%d: ",j+1);
            scanf("%f",&info[i].quizmarks[j]);
        }
        for(j=0;j<numb_of_assignment;j++)
        {
            printf("Enter mark for Assignment-%d: ",j+1);
            scanf("%f",&info[i].assignmentmarks[j]);
        }
        for(j=0;j<numb_of_mid;j++)
        {
            printf("Enter mark for Mid-Term %d: ",j+1);
            scanf("%f",&info[i].midmarks[j]);
        }
        printf("Enter mark for Final exam: ");
        scanf("%f",&info[i].finalmarks);
        printf("Enter marks for Project: ");
        scanf("%f",&info[i].projectmarks);
        printf("Enter number of classes attended by student %d: ",i+1);
        scanf("%d",&info[i].attendance);
        printf("\n");


        //Grade is calculated in this part.
        float Sum_of_quiz=0, Sum_of_assignment=0, best_mid=info[i].midmarks[0];

        float Quiz=0,Assignment=0,Mid=0,Attendance=0,Final=0,Project=0,Total=0;

        for(j=0;j<numb_of_quiz;j++)
        {
            Sum_of_quiz = Sum_of_quiz + info[i].quizmarks[j];
        }
        Quiz = (Sum_of_quiz/(mark_of_quiz*numb_of_quiz)) *15 ;
        for(j=0;j<numb_of_assignment;j++)
        {
            Sum_of_assignment = Sum_of_assignment +info[i].assignmentmarks[j];
        }
        Assignment = (Sum_of_assignment/(numb_of_assignment*mark_of_assignment)) *10;
        for(j=0;j<numb_of_mid;j++)
        {
            if(best_mid<info[i].midmarks[j])
            {
                best_mid=info[i].midmarks[j];
            }
        }
        Mid = (best_mid/mark_of_mid) *20;

        Project = (info[i].projectmarks/mark_of_project) *15;

        Final = (info[i].finalmarks/mark_of_final) *30;

        Attendance = (info[i].attendance/numb_of_attendance) *10;

        Total = Quiz+Assignment+Mid+Final+Project+Attendance;
        printf("\nQuiz: %.2f\n",Quiz);
        printf("Assignment: %.2f\n",Assignment);
        printf("Mid: %.2f\n",Mid);
        printf("Project: %.2f\n",Project);
        printf("Attendance: %.2f\n",Attendance);
        printf("Final: %.2f\n",Final);
        printf("Total:%.2f\n\n",Total);

        if(Total>=0 && Total < 60)
        {
            strcat(info[i].grade,"F (Failure)");
            info[i].cgpa=0.0;
        }
        else if(Total >= 60 &&  Total < 67)
        {
            strcat(info[i].grade,"D (Poor)");
            info[i].cgpa=1.0;
        }
        else if(Total >= 67 &&  Total < 70)
        {
            strcat(info[i].grade,"D+");
            info[i].cgpa=1.3;
        }
        else if(Total >= 70 &&  Total < 73)
        {
            strcat(info[i].grade,"C-");
            info[i].cgpa=1.7;
        }
        else if(Total >= 73 &&  Total < 77)
        {
            strcat(info[i].grade,"C (Average)");
            info[i].cgpa=2.0;
        }
        else if(Total >= 77 &&  Total < 80)
        {
            strcat(info[i].grade,"C+");
            info[i].cgpa=2.3;
        }
        else if(Total >= 80 &&  Total < 83)
        {
            strcat(info[i].grade,"B-");
            info[i].cgpa=2.7;
        }
        else if(Total >= 83 &&  Total < 87)
        {
            strcat(info[i].grade,"B (Good)");
            info[i].cgpa=3.0;
        }
        else if(Total >= 87 &&  Total < 90)
        {
            strcat(info[i].grade,"B+");
            info[i].cgpa=3.3;
        }
        else if(Total >= 90 &&  Total < 93)
        {
            strcat(info[i].grade,"A-");
            info[i].cgpa=3.7;
        }
        else if(Total >= 93 &&  Total <= 100)
        {
            strcat(info[i].grade,"A (Excellent)");
            info[i].cgpa=4.0;
        }
    }
    //Information of Students input Done.

    printTXTfile(numb_of_students);
}

//Function used to print file of all students data in a section.
void printTXTfile(int numb_of_students)
{
    printf("Enter Course Name: ");
    char name[1000];
    scanf("%s",name);
    printf("Enter Section number: ");
    char sec[20]="Section ", num[5];
    scanf("%s",num);
    strcat(sec,num);
    strcat(name,sec);
    strcat(name,".txt");

    FILE *fpoutput;

    fpoutput=fopen(name,"w");

    int i;
    for(i=0;i<numb_of_students;i++)
    {
        fprintf(fpoutput,"Name: %s %s\nID#%s\nCGPA: %.2f\t Grade: %s\n\n",info[i].firstname,info[i].lastname,info[i].id,info[i].cgpa,info[i].grade);
    }

    fclose(fpoutput);
}

void searchforstudent(int numb_of_students)
{
    printf("Enter ID number of student to be searched: ");
    char search_id[100];
    scanf("%s",search_id);
    int i;
    for(i=0;i<numb_of_students;i++)
    {
        if(strcmp(search_id,info[i].id)==0 || strcmp(search_id,info[i].id)==0)
        {
            printf("ID: %s \nName: %s %s\nGrade: %s\tCGPA: %.2f\n\n",info[i].id,info[i].firstname,info[i].lastname,info[i].grade,info[i].cgpa);
        }
    }
}
