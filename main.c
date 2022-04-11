/**
 *@mainpage Course creation function demonstration
 
 *This course creation function demonstration shows how the mutliple functions related to the course and student types work includng:
 * - enrolling a student in a course
 * - generating random students
 * - printing the detailed information of a course
 * - printing all the information of a student including their grades and overall average
 * - finding the top student in a course
 * - displaying the number of students passing a course and who these students are
 
 
 * @file main.c
 * @author Jason Lowrie 
 * @date April 10th, 2022
 * @brief Runs demonstration code for creating a course complete with students.
 * 
 */


#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"
/**
 * @brief Creates a course called 'MATH101', enrolls 20 students in this course with 8 grades to each name, prints the information of these students, determines the top student taking this course, and then determines how many students taking the course have a passing grade in it and who they are.
 * 
 */
int main()
{
  srand((unsigned) time(NULL));

  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  for (int i = 0; i < 20; i++) 
    enroll_student(MATH101, generate_random_student(8));
  
  print_course(MATH101);

  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);
  
  return 0;
}