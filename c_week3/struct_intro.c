#include <stdio.h>

struct Student {
	char name[200];
	char student_id[11];
	int mark;
};

int main() {
	struct Student new_student;

    printf("Enter your name: ");
    scanf("%s", new_student.name);
    printf("Enter the student ID: ");
    scanf("%s", new_student.student_id);
    printf("Enter their mark: ");
    scanf("%d", &new_student.mark);

	printf("\nThe students name is %s\n", new_student.name);
    //new_student.student_id = "23";
    printf("%s's ID is: %s, with %d marks!\n", new_student.name, new_student.student_id, new_student.mark);
	return 0;
}