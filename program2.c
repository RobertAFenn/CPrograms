#include <stdio.h>
#include <string.h>

int main() {
  int n;

  printf("Enter the number of students you would like to enter: ");
  scanf("%d", &n);
  getchar();

  FILE *file = fopen("student.txt", "a");
  if (file == NULL) {
    printf("Could not open the file.\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    char name[50];
    int marks;

    printf("Enter the name of student %d: ", i + 1);
    fgets(name, sizeof(name), stdin);

    int nameLength = strlen(name);

    if (nameLength > 0 && name[nameLength - 1] == '\n') {
      name[nameLength - 1] = '\0';
    }

    printf("Enter the marks of student %d: ", i + 1);
    scanf("%d", &marks);
    getchar();

    fprintf(file, "Name: %s, Marks: %d\n", name, marks);
  }

  int c = fclose(file);
  if (c == EOF) {
    printf("Error Closing File...\n");
  } else {
    printf("Information has been saved to student.txt... Closing File...\n");
  }

  printf("Exiting Program...");
  return 0;
}
