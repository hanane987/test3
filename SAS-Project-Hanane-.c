#include <stdio.h>
#include <string.h>
#include <time.h>

struct Task {
    int id_number;
    char title[40];
    char description[30];
    char deadline[50];
    char status[60];
};

struct Task Duty[100];
int taskCounter = 0;





void displayTasksWithDeadlineWithin3Days(struct Task Duty[], int taskCounter) {
    time_t currentTime;
    struct tm localTime;

    // Get the current date and time
    currentTime = time(NULL);
    localtime_r(&currentTime, &localTime); // Use localtime_r for thread safety

    int currentDay = localTime.tm_mday;
    int currentMonth = localTime.tm_mon + 1; // Months are 0-based, so add 1 to get the actual month
    int currentYear = localTime.tm_year + 1900; // Years are counted from 1900

    printf("Tasks with 3 days limit or less :\n");

    for (int i = 0; i < taskCounter; i++) {
        int daysRemaining = 0;

        int year, month, day;
        // Extract the year, month, and day from the deadline
        sscanf(Duty[i].deadline, "%4d-%2d-%2d", &year, &month, &day);

        // Calculate the difference between the dates
        daysRemaining += (year - currentYear) * 365;
        daysRemaining += (month - currentMonth) * 30; // Assuming each month has 30 days
        daysRemaining += (day - currentDay);

        if (daysRemaining <= 3) {
            printf("~~~~~~Tâche %d : %s (Date limite dans %d jours)~~~~~\n\n", Duty[i].id_number, Duty[i].title, daysRemaining);
        }
    }
}



void calculateDeadlineDifference(struct Task Duty[], int taskCounter) {
    time_t currentTime;
    struct tm localTime;

    currentTime = time(NULL);
    localtime_r(&currentTime, &localTime); // Utilise localtime_r pour la sécurité des threads

    int currentDay = localTime.tm_mday;
    int currentMonth = localTime.tm_mon + 1; // months from 0 to 11, add 1 to get the real month
    int currentYear = localTime.tm_year + 1900; // years startesd count from 1900

    for (int i = 0; i < taskCounter; i++) {
        int daysRemaining = 0;

        int year, month, day;
        // Extraire year month and day from deadline
        sscanf(Duty[i].deadline, "%4d-%2d-%2d", &year, &month, &day);

        // the différence between dates
        daysRemaining += (year - currentYear) * 365;
        daysRemaining += (month - currentMonth) * 30; // we pretend that each month in 30 days
        daysRemaining += (day - currentDay);

        printf("~~~~~~Deadline of task with ID %d there is  %d days left~~~~~~\n\n", Duty[i].id_number, daysRemaining);
    }
}






void add() {
    struct Task dutytodo;
    int i,size;
    
    printf("\\\\\\\\\\How many tasks do you want ???\\\\\\\\\\:\n ");
    scanf("%d", &size);
    for (i = 0; i <size; i++) {
    
    dutytodo.id_number= taskCounter  +1;

    printf("-----------Enter your title-----------  ");
    scanf(" %s", dutytodo.title);

    printf("-----------Enter your description-----------  ");
    scanf(" %s", dutytodo.description);

    printf("-----------Enter your deadline (YYYY-MM-DD) ----------- ");
    scanf(" %[^\n]", dutytodo.deadline);

    printf("-----------Enter your statut( To do, Doing, Done) ----------- ");
    scanf(" %[^\n]", dutytodo.status);

    Duty[taskCounter++] = dutytodo;
    
    
    printf("Task added with success.\n");
}
}


void displayTasks(){
   
for(int i =0;i<taskCounter;i++){
    struct Task dutytodo = Duty[i];
    printf("\nYour %d task is :",i+1);
    printf("\ntask ID is: %d",dutytodo.id_number);
    printf("\n----------task title is----------- :%s",dutytodo.title);
    printf("\n----------task deadline is----------- %s",dutytodo.deadline);
    printf("\n----------task descreption is----------- %s",dutytodo.description);
    printf("\n----------task status is----------- %s",dutytodo.status);
    
    }
}


void sortbyletters() {
    for (int i = 0; i < taskCounter - 1; i++) {
        for (int j = i + 1; j < taskCounter; j++) {
            if (strcmp(Duty[i].title, Duty[j].title) > 0) {  
                struct Task temp = Duty[i];
                Duty[i] = Duty[j];
                Duty[j] = temp;
            }
        }
    }
    printf("Sorted Tasks:\n");
    for (int i = 0; i < taskCounter; i++) {
        printf("Title: %s\n", Duty[i].title);
    }
}


         void sortByDeadline() {
    if (taskCounter <= 1) {
        printf("Sorry,there is no such task to sort .\n");
        return;
    }

    for (int i = 0; i < taskCounter - 1; i++) {
        for (int j = i + 1; j < taskCounter; j++) {
            if (strcmp(Duty[i].deadline, Duty[j].deadline) > 0) {
                
                struct Task temp = Duty[i];
                Duty[i] = Duty[j];
                Duty[j] = temp;
            }
        }
    }
         }


    



  void modifyDeadline() {
    int n_id;

    // Prompt the user to enter the task ID they want to modify
    printf("Enter the ID of the task you want to modify: ");
    scanf("%d", &n_id);

    // Check if the entered task ID is valid
    if (n_id < 1 || n_id > taskCounter) {
        printf("Invalid ID.\n");
        return;
    }

    // Prompt the user to enter the new deadline for the task
    printf("Enter the new deadline (YYYY-MM-DD) for task %d: ", n_id);
    scanf(" %s", Duty[n_id - 1].deadline);

    printf("*****Deadline for task %d modified successfully.*****\n", n_id);
}

            
    void modifydescription(){

    int n_id;
    printf("enter task id : ");
    scanf("%d",&n_id);
    for(int i=0;i<taskCounter;i++){
        if(Duty[i].id_number==n_id){
            printf("*******enter new task description : *******\n");
            scanf("%s",Duty[i].description);
        }
        }
        }


    void modifystatus(){
    int n_id;
    printf("enter task id : ");
    scanf("%d",&n_id);
    for(int i=0;i<taskCounter;i++){
        if(Duty[i].id_number==n_id){
            printf("*******enter new task status :*******\n");
            scanf("%s",Duty[i].status);
            
            

            }
        }
    }



    
void deleteTask(int n_id) {
    if (n_id < 1 || n_id > taskCounter) {
        printf("Your ID is invalid.\n");
        return;
    }

    for (int i = n_id - 1; i < taskCounter - 1; i++) {
        Duty[i] = Duty[i + 1];
        Duty[i].id_number--; 
    }

    taskCounter--;
    printf("______Task %d deleted with success.______\n", n_id);
}



void SearchbyID(){
    int id;
    printf("enter ID\n");
    scanf("%d",&id);
    for(int i=0;i<taskCounter;i++){
        if(Duty[i].id_number==id)  
            printf("task is in position %d\n",i+1);
    }
}


void SearchbyTitle(){
    char titl[20];
    printf("enter title");
    scanf("%s",titl);
    for(int i=0;i<taskCounter;i++){
        if(strcmp(Duty[i].title,titl)==0){
            printf("task position is %d",i+1);
        }
    }


}


  void compincomp() {
    int completedCount = 0;
    int incompletedCount = 0;

    for (int i = 0; i < taskCounter; i++) {
        if (strcmp(Duty[i].status, "Done") == 0) {
            completedCount++;
        } else {
            incompletedCount++;
        }
    }

    printf("Number of tasks completed : %d\n", completedCount);
    printf("Number of tasks incompleted : %d\n", incompletedCount);
}

int main() {
    int choice;

    do {
    
        printf("\nMenu of the various tasks :\n");
        printf("1. Add a new task\n");
        printf("2. Display tasks\n");
        printf("3. Sort a task\n");
        printf("4. Modify a task \n");
        printf("5. Delete a task \n");
        printf("6. Search a task\n");
        printf("7. Statistique  \n");
        printf("8. Deadline  \n");

        printf("0. Quit \n");
        printf("Enter your choice  : ");
        scanf(" %d", &choice);

        switch (choice) {
        case 1:
                add();
            break;
            case 2:
                displayTasks(); 
                break;
            case 3:
            int N;
            printf("To sort by letter press key 1:\n");
            printf("To sort bydeadline press key 2:\n");
            scanf("%d",&N);
        switch(N){
                case 1:
                sortbyletters(); 
                    break;
            case 2:
                sortByDeadline(); 
                displayTasks(); 
                break;
                }
                break;
            case 4:
            int x;
            printf("To modify the Deadline press 1:\n");
            printf("To modify the Description press 2:\n");
            printf("To modify the status press 3:\n");
            scanf("%d",&x);
        switch(x){
            case 1:
                modifyDeadline();
                displayTasks();
                break;
            case 2:
                modifydescription(); 
                displayTasks();
                break;
            case 3:
                modifystatus(); 
                displayTasks();
                break;
                }
                break;
            case 5:
                int n_id;

              printf("Enter the ID of the task to delete: ");
              scanf("%d", &n_id);
                deleteTask(n_id); 
                displayTasks();
                break;
            case 6:
            int f;
            printf("To search by ID press key 1\n");
            printf("To search by title press key 2\n");
            scanf("%d",&f);
        switch(f){
                case 1:
                SearchbyID(); 
                    break;
            case 2:
                SearchbyTitle(); 
                break;
                }
                break;
           
                case 7:
            int s;
            printf("To know number of total tasks press key 1:\n");
            printf("To know number of tasks completed and incompleted press key 2:\n");
            printf("To know number of days left for each task 3:\n");

            scanf("%d",&s);
        switch(s){
            case 1:
                printf("Number of tasks  : %d\n", taskCounter);
                    break;
            case 2:
                compincomp();  
                break;
                  
            case 3:
                 calculateDeadlineDifference(Duty, taskCounter);
                break;
                }
                break;
                case 8:
                 displayTasksWithDeadlineWithin3Days(Duty, taskCounter);
                break;   
            case 0:
                printf("GOODBYE UNTIL NEXT TIME :)\n");
                break;
                
            default:
                printf("Incorrect choice , Please try again.\n");
        }
    }while (choice!=0);

    return 0;
}