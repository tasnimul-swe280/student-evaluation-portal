#include <stdio.h>
#include <string.h>

#define MAX 50

struct Student {
    char id[100];
    float marks;
    float attendance;
};

struct Student s[MAX];
int n = 0;

int isValidDIUEmail(char email[]) {
    char *domain = "@diu.edu.bd";
    if(strstr(email, domain) != NULL)
        return 1;
    return 0;
}

char teacherEmail[100];
int teacherPass;

void teacherRegister() {
    printf("\n--- Teacher Registration ---\n");
    printf("Enter Email: ");
    scanf("%s", teacherEmail);

    if(!isValidDIUEmail(teacherEmail)) {
        printf("Invalid Email! Must end with @diu.edu.bd\n");
        return;
    }

    printf("Enter 4-digit Password: ");
    scanf("%d", &teacherPass);

    printf("Registration Done!\n");
}

int teacherLogin() {
    char email[100];
    int pass;

    printf("\n--- Teacher Login ---\n");
    printf("Email: ");
    scanf("%s", email);

    if(!isValidDIUEmail(email)) {
        printf("Invalid Email Format!\n");
        return 0;
    }

    printf("Password: ");
    scanf("%d", &pass);

    if(strcmp(email, teacherEmail) == 0 && pass == teacherPass) {
        printf("Login Successful!\n");
        return 1;
    }

    printf("Invalid Login!\n");
    return 0;
}

void uploadData() {
    printf("\nEnter number of students: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("\nStudent %d ID: ", i+1);
        scanf("%s", s[i].id);

        printf("Marks: ");
        scanf("%f", &s[i].marks);

        printf("Attendance: ");
        scanf("%f", &s[i].attendance);
    }

    printf("\nData Uploaded Successfully!\n");
}

char studentEmail[100];
int studentPass;

void studentRegister() {
    printf("\n--- Student Registration ---\n");
    printf("Enter Email: ");
    scanf("%s", studentEmail);

    if(!isValidDIUEmail(studentEmail)) {
        printf("Invalid Email! Must end with @diu.edu.bd\n");
        return;
    }

    printf("Enter 4-digit Password: ");
    scanf("%d", &studentPass);

    printf("Registration Done!\n");
}

int studentLogin() {
    char email[100];
    int pass;

    printf("\n--- Student Login ---\n");
    printf("Email: ");
    scanf("%s", email);

    if(!isValidDIUEmail(email)) {
        printf("Invalid Email Format!\n");
        return 0;
    }

    printf("Password: ");
    scanf("%d", &pass);

    if(strcmp(email, studentEmail) == 0 && pass == studentPass) {
        printf("Login Successful!\n");
        return 1;
    }

    printf("Invalid Login!\n");
    return 0;
}

void showResult() {
    char id[100];
    int found = 0;

    printf("\nEnter Your Student ID: ");
    scanf("%s", id);

    for(int i = 0; i < n; i++) {
        if(strcmp(id, s[i].id) == 0) {
            found = 1;

            printf("\n===== RESULT =====\n");
            printf("Marks: %.2f\n", s[i].marks);
            printf("Attendance: %.2f%%\n", s[i].attendance);

            printf("Suggestion:\n");
            if(s[i].marks < 50)
                printf("- Study more\n");
            if(s[i].attendance < 75)
                printf("- Improve attendance\n");
            if(s[i].marks >= 50 && s[i].attendance >= 75)
                printf("- Good performance, keep it up!\n");
        }
    }

    if(!found) {
        printf("\n⚠ Teacher hasn't uploaded your data yet. Please wait.\n");
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n1. Teacher Register\n");
        printf("2. Teacher Login & Upload\n");
        printf("3. Student Register\n");
        printf("4. Student Login\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if(choice == 1) teacherRegister();

        else if(choice == 2) {
            if(teacherLogin()) {
                uploadData();
            }
        }

        else if(choice == 3) studentRegister();

        else if(choice == 4) {
            if(studentLogin()) {
                showResult();
            }
        }

        else if(choice == 5) break;

        else printf("Invalid choice!\n");
    }

    return 0;
}
