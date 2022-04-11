/**
 * @file student.c
 * @author Jason Lowrie
 * @date April 10th, 2022
 * @brief The code contained in this c file performs various operations relating to the display of information characteristic to a particular student.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/** 
 * @brief A function that adds the a particular grade to a student's information profile. If the grade being added is the students first grade, then memory the size of the grade is allocated to the heap in order to store the grade. If the student already has at least one grade to their name then memory is reallocated to once again to resize the memory block on the heap to accomodate another grade belonging to that particular student.
 * 
 * @param  student a particular student at the school with all their currently known information included.
 * @param grade the grade that the student received in a particular course and is to be added to their current list of grades from other courses.
 * @return nothing
 */
void add_grade(Student* student, double grade)
{
  student->num_grades++;
  if (student->num_grades == 1) student->grades = calloc(1, sizeof(double));
  else 
  {
    student->grades = 
      realloc(student->grades, sizeof(double) * student->num_grades);
  }
  student->grades[student->num_grades - 1] = grade;
}

/** 
 * @brief A function that computes the average overall grade of a student by summing all their grades together and dividing by the total number of grades they have received.
 * 
 * @param  student a particular student at the school with all their currently known information included.
 * @return 0 if the students does not have any recorded grades OR the student's average grade if they do have at least one recorded grade or more.
 */
double average(Student* student)
{
  if (student->num_grades == 0) return 0;

  double total = 0;
  for (int i = 0; i < student->num_grades; i++) total += student->grades[i];
  return total / ((double) student->num_grades);
}

/** 
 * @brief Prints out all the known identifying academic information of a particular student.
 * 
 * @param  student a particular student at the school with all their currently known information included.
 * @return nothing
 */
void print_student(Student* student)
{
  printf("Name: %s %s\n", student->first_name, student->last_name);
  printf("ID: %s\n", student->id);
  printf("Grades: ");
  for (int i = 0; i < student->num_grades; i++) 
    printf("%.2f ", student->grades[i]);
  printf("\n");
  printf("Average: %.2f\n\n", average(student));
}

/** 
 * @brief This function uses a bank of both first and last names to randomly generate the names of 24 students and allocate memory blocks for each randomly generated student to be stored on the heap. In addition to this, this function also generates random student ID's for each new student along with assigning them grades of random percentages depending on how many grades they should have, given by the grades parameter of the function.
 * 
 * @param  grades the number of grades a particular student has.
 * @return a new randomly generated student.
 */
Student* generate_random_student(int grades)
{
  char first_names[][24] = 
    {"Shahrzad", "Leonti", "Alexa", "Ricardo", "Clara", "Berinhard", "Denzel",
     "Ali", "Nora", "Malcolm", "Muhammad", "Madhu", "Jaiden", "Helena", "Diana",
     "Julie", "Omar", "Yousef",  "Amir", "Wang", "Li", "Zhang", "Fen", "Lin"};

  char last_names[][24] = 
   {"Chen", "Yang", "Zhao", "Huang", "Brown", "Black", "Smith", "Williams", 
    "Jones", "Miller", "Johnson", "Davis", "Abbas", "Ali", "Bakir", "Ismat", 
    "Khalid", "Wahed", "Taleb", "Hafeez", "Hadid", "Lopez", "Gonzalez", "Moore"};
 
  Student *new_student = calloc(1, sizeof(Student));

  strcpy(new_student->first_name, first_names[rand() % 24]);
  strcpy(new_student->last_name, last_names[rand() % 24]);

  for (int i = 0; i < 10; i++) new_student->id[i] = (char) ((rand() % 10) + 48);
  new_student->id[10] = '\0';

  for (int i = 0; i < grades; i++) 
  {
    add_grade(new_student, (double) (25 + (rand() % 75)));
  }

  return new_student;
}