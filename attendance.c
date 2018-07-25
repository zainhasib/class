#include<stdio.h>
#include<stdlib.h>

struct students{
    int present;
    int total;
    int average;
};

struct subjects{
    struct students student[5];
    float average;
    int days;
};

struct subjects subject[5]; // Subjects are identified by their indices

int enterAttendance(FILE * fp, int code, char * sub) {
    int i=0;
    subject[code].days++;
    if(fp) {
        printf("Enter the attendance for %s:", sub);
        printf("\n");
        for(i=0;i<5;i++) {
            printf("Student %d : ", i+1);
            scanf("%d", &subject[code].student[i].present);
            fprintf(fp, "%d ", subject[code].student[i].present);
        }
        fclose(fp);
        printf("\n");
    }
}

void doTotal(FILE * fp1, int subCode) {
    char d[50];
    int i=0;
    while(fscanf(fp1, "%s", d) != EOF) {
        if(i%5 == 0) {
            subject[subCode].student[i%5].total += atoi(d);
        }else if(i%5 == 1) {
            subject[subCode].student[i%5].total += atoi(d);
        }else if(i%5 == 2) {
            subject[subCode].student[i%5].total += atoi(d);
        }else if(i%5 == 3) {
            subject[subCode].student[i%5].total += atoi(d);
        }else if(i%5 == 4) {
            subject[subCode].student[i%5].total += atoi(d);
        }
        i++;
    }
}

void readAttendance(char * sub,int code) {
    FILE * fp;
    fp = fopen(sub, "r");
    if(fp) {
        char d[30];
        int i=0;
        int total=0;
        if(fp) {
            doTotal(fp, code);
            fclose(fp);
        }
    }else {
        printf("Error: File Read!\n");
    }
}

int main() {
    int flag = 1;
    FILE * fp;
    int k=0,l=0;
    int attend=0;
    int days = 0;
    printf("=============================== Choose from the Menu ===============================\n");
    while(flag)
    {
        int choice;
        printf("1. Maths.\n"); //code 0
        printf("2. English.\n"); //code 1
        printf("3. Biology\n"); //code 2
        printf("4. Physics\n"); //code 3
        printf("5. Chemistry\n"); //code 4
        printf("6. Average\n"); 
        printf("7. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                fp = fopen("maths.txt", "a+");
                enterAttendance(fp, 0, "Maths");
                break;
            case 2:
                fp = fopen("english.txt", "a+");
                enterAttendance(fp,1, "English");
                break;
            case 3:
                fp = fopen("biology.txt", "a+");
                enterAttendance(fp, 2, "Biology");
                break;
            case 4:
                fp = fopen("physics.txt", "a+");
                enterAttendance(fp, 3, "Physics");
                break;
            case 5:
                fp = fopen("chemistry.txt", "a+");
                enterAttendance(fp, 4, "Chemistry");
                break;
            case 6:
                readAttendance("maths.txt", 0);
                readAttendance("english.txt", 1);
                readAttendance("biology.txt", 2);
                readAttendance("chemistry.txt", 3);
                readAttendance("physics.txt", 4);
                for(k=0;k<5;k++) {
                    printf("Subject code: %d\n", k);
                    for(l=0;l<5;l++) {
                        subject[k].student[l].average = (subject[k].student[l].total / (float)subject[k].days) * 100;
                        printf("Student %d has %d percent attandence\n", l+1, subject[k].student[l].average);
                    }
                }

                printf("Students with attendance below average attendance of class is : \n");
                for(k=0;k<5;k++) {
                    printf("Subject code: %d\n", k);
                    for(l=0;l<5;l++) {
                        if(subject[k].student[l].average < 75) {
                            printf("Student %d\n", l+1);
                        }
                    }
                    printf("\n\n");
                }
                break;
            case 7:
                flag=0;
                break;
            default:
                printf("Enter a valid choice!\n");
        }
    }
    return 0;
}
