
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
        int roll;
        char name[50];
        float per;
        struct student *next;
};

struct student *head = NULL;

//generating roll number value function based and it is taking automatically new roll number
// Generate next roll number
/*
   int getRoll() {
   int max = 0;
   struct student *temp = head;
   while (temp) {
   if (temp->roll > max)
   max = temp->roll;
   temp = temp->next;
   }
   return max + 1;
   }
 */


// ADD
void add_begin() {
        struct student *newnode = malloc(sizeof(struct student));
        //newnode->roll = getRoll();

        printf("Enter roll: ");
        scanf("%d", &newnode->roll);

        printf("Enter name: ");
        scanf("%s", newnode->name);

        printf("Enter percentage: ");
        scanf("%f", &newnode->per);

        newnode->next = head;
        head = newnode;

        printf("Record Added!\n");
        printf("To show the data! press s/S\n");
}

// add node at end
void add_end()
{
        struct student *newnode, *last;

        // Step 1: create node
        newnode = (struct student*)malloc(sizeof(struct student));

        // Step 2: assign data
        //newnode->roll = getRoll();

        printf("Enter roll: ");
        scanf("%d", &newnode->roll);

        printf("Enter name: ");
        scanf("%s", newnode->name);

        printf("Enter percentage: ");
        scanf("%f", &newnode->per);

        newnode->next = NULL;   // important

        // Step 3: check if list empty
        if (head == NULL)
        {
                head = newnode;   // first node
        }
        else
        {
                // Step 4: traverse to last node
                last = head;
                while (last->next != NULL)
                {
                        last = last->next;
                }

                // Step 5: link new node at end
                last->next = newnode;
        }

        printf("Node added at end successfully!\n");
        printf("To show the data! press s/S\n");
}

// SHOW
void show() {
        struct student *temp = head;
        if (!temp) {
                printf("No records!\n");
                return;
        }

        printf("\nROLL\tNAME\tPERCENTAGE\n");
        while (temp) {
                printf("%d\t%s\t%.2f\n", temp->roll, temp->name, temp->per);
                temp = temp->next;
        }
}

// DELETE
void del() {
        int roll;
        printf("Enter roll to delete: ");
        scanf("%d", &roll);

        struct student *temp = head, *prev = NULL;

        while (temp && temp->roll != roll) {
                prev = temp;
                temp = temp->next;
        }

        if (!temp) {
                printf("Not found!\n");
                return;
        }

        if (prev)
                prev->next = temp->next;
        else
                head = temp->next;

        free(temp);
        printf("Deleted Successfully!\n");
        printf("To show the data! press s/S\n");
}

// MODIFY
/*
   void modify() {
   int roll;
   printf("Enter roll to modify: ");
   scanf("%d", &roll);

   struct student *temp = head;

   while (temp && temp->roll != roll)
   temp = temp->next;

   if (!temp) {
   printf("Not found!\n");
   return;
   }

   printf("Enter new name: ");
   scanf("%s", temp->name);

   printf("Enter new percentage: ");
   scanf("%f", &temp->per);

   printf("Updated!\n");
   }
 */

//Modify record based on: Roll number Name Percentage

void modify() {
        char choice;
        struct student *temp;

        printf("\nModify Record Based On:\n");
        printf("R/r : Roll No\nN/n : Name\nP/p : Percentage\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        // ---- MODIFY BY ROLL ----
        if (choice == 'R' || choice == 'r') {
                int roll;
                printf("Enter roll number: ");
                scanf("%d", &roll);

                temp = head;
                while (temp && temp->roll != roll)
                        temp = temp->next;

                if (!temp) {
                        printf("Record not found!\n");
                        return;
                }
        }

        // ---- MODIFY BY NAME ----
        else if (choice == 'N' || choice == 'n') {
                char name[50];
                printf("Enter name: ");
                scanf("%s", name);

                temp = head;
                int found = 0;

                while (temp) {
                        if (strcmp(temp->name, name) == 0) {
                                printf("Found -> Roll:%d Name:%s Per:%.2f\n",
                                                temp->roll, temp->name, temp->per);
                                found = 1;
                        }
                        temp = temp->next;
                }

                if (!found) {
                        printf("No record found!\n");
                        return;
                }

                int roll;
                printf("Enter roll number to modify: ");
                scanf("%d", &roll);

                temp = head;
                while (temp && temp->roll != roll)
                        temp = temp->next;
        }

        // ---- MODIFY BY PERCENTAGE ----
        else if (choice == 'P' || choice == 'p') {
                float per;
                printf("Enter percentage: ");
                scanf("%f", &per);

                temp = head;
                int found = 0;

                while (temp) {
                        if (temp->per == per) {
                                printf("Found -> Roll:%d Name:%s Per:%.2f\n",
                                                temp->roll, temp->name, temp->per);
                                found = 1;
                        }
                        temp = temp->next;
                }

                if (!found) {
                        printf("No record found!\n");
                        return;
                }

                int roll;
                printf("Enter roll number to modify: ");
                scanf("%d", &roll);

                temp = head;
                while (temp && temp->roll != roll)
                        temp = temp->next;
        }

        else {
                printf("Invalid choice!\n");
                return;
        }

        // ---- UPDATE DATA ----
        if (!temp) {
                printf("Record not found!\n");
                return;
        }

        printf("Enter new name: ");
        scanf("%s", temp->name);

        printf("Enter new percentage: ");
        scanf("%f", &temp->per);

        printf("Record Updated Successfully!\n");
        printf("To show the data! press s/S\n");
}


// SAVE TO FILE
void save() {
        FILE *fp = fopen("student.txt", "w");
        struct student *temp = head;

        while (temp) {
                fprintf(fp, "%d %s %.2f\n", temp->roll, temp->name, temp->per);
                temp = temp->next;
        }
        fclose(fp);
        printf("Saved to file!\n");
}

// SORT BY NAME
void sortName() {
        struct student *i, *j;
        for (i = head; i; i = i->next) {
                for (j = i->next; j; j = j->next) {
                        if (strcmp(i->name, j->name) > 0) {
                                struct student temp = *i;
                                *i = *j;
                                *j = temp;

                                struct student *t = i->next;
                                i->next = j->next;
                                j->next = t;
                        }
                }
        }
        printf("Sorted by name!\n");
        printf("To show the data! press s/S\n");
}

// SORT BY PERCENTAGE
void sortPer() {
        struct student *i, *j;
        for (i = head; i; i = i->next) {
                for (j = i->next; j; j = j->next) {
                        if (i->per > j->per) {
                                struct student temp = *i;
                                *i = *j;
                                *j = temp;

                                struct student *t = i->next;
                                i->next = j->next;
                                j->next = t;
                        }
                }
        }
        printf("Sorted by percentage!\n");
        printf("To show the data! press s/S\n");
}

// REVERSE
void reverse() {
        struct student *prev = NULL, *curr = head, *next;

        while (curr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
        }

        head = prev;
        printf("List Reversed!\n");
        printf("To show the data! press s/S\n");
}

// DELETE ALL
void deleteAll() {
        struct student *temp;
        while (head) {
                temp = head;
                head = head->next;
                free(temp);
        }
        printf("All records deleted!\n");
        printf("To show the data! press s/S\n");
}

// MAIN MENU
int main() {
        char ch;
        int opt;

        while (1) {
                printf("\n***** STUDENT RECORD MENU *****\n");
                printf(" a/A: add new record\n d/D: delete a record\n s/S: show the list\n m/M: Modify record based on: Rollnumber,Name,and Percentage\n v/V: save the file\n e/E: exit\n t/T: sorting the lists based on name/percentage\n l/L: delete all the records\n r/R: reverse the list\n");
                printf("\nEnter choice: ");
                scanf(" %c", &ch);

                switch (ch) {
                        case 'A':
                        case 'a':
                                printf("1. Add_begin [elements add at first], Press 1 option to Add_begin\n2. Add_end[elements add at end[best method]], Press 2 option to Add_end\n");
                                scanf("%d", &opt);
                                if (opt == 1) add_begin();
                                else add_end();
                                break;
                        case 'D':
                        case 'd': del(); break;
                        case 'S':
                        case 's': show(); break;
                        case 'M':
                        case 'm': modify(); break;
                        case 'V':
                        case 'v': save(); break;
                        case 'R':
                        case 'r': reverse(); break;
                        case 'L':
                        case 'l': deleteAll(); break;

                        case 'T':
                        case 't':
                                  printf("1. Sort by Name, Press 1 option to Sort by Name\n2. Sort by Percentage, Press 2 option to Sort by Per\n");
                                  scanf("%d", &opt);
                                  if (opt == 1) sortName();
                                  else sortPer();
                                  break;

                        case 'E':
                        case 'e':{
                                         char opt;
                                         printf("\nS/s: Save and Exit\nE/e: Exit without Saving\n");
                                         printf("Enter choice: ");
                                         scanf(" %c", &opt);

                                         if (opt == 'S' || opt == 's') {
                                                 printf("saved the file and exited successfully\n");
                                                 save();
                                                 exit(0);
                                         } else if (opt == 'E' || opt == 'e') {
                                                 printf("without saving the file and exited successfully\n");
                                                 exit(0);
                                         } else {
                                                 printf("Invalid choice!\n");
                                         }
                                         break;
                                 }

                        default:
                                 printf("Invalid choice! Unkown option please press valid option!\n");
                                 break;
                }
        }
}





