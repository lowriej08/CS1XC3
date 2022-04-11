/**
 * @file course.c
 * @author Jason Lowrie
 * @date April 10th, 2022
 * @brief The code contained in this c file performs various operations relating to the display of information characteristic to a particular course.
 *
 */

#include "course.h"
#include <stdlib.h>
#include <stdio.h>

/** 
 * @brief enrolls a student into a certain course while first allocating memory blocks the size of all the information attached to a particular student, and then reallocating more memory blocks when there is more than one or more students already enrolled in the course.
 * 
 * @param course the specific course that is having a student enrolled in it.
 * @param student the student that is being enrolled into the course.
 * @return nothing
 */ 
void enroll_student(Course *course, Student *student)
{
  course->total_students++;
  if (course->total_students == 1) 
  {
    course->students = calloc(1, sizeof(Student));
  }
  else 
  {
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); 
  }
  course->students[course->total_students - 1] = *student;
}

/** 
 * Prints all the information about a particular course as well as an array containing all of the information for each student currently enrolled in that course.
 * 
 * @param course the specific course being offered by the school.
 * @return nothing
 */
void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]);
}

/** 
 * Determines the student enrolled in a particular course with the highest overall average that includes courses outside of the particular course that they are the top student in.
 * 
 * @param course the specific course being offered by the school.
 * @return NULL if there are no students in the course OR the student with the highest overall average if there are one or more students enrolled in the course. 
 */
Student* top_student(Course* course)
{
  if (course->total_students == 0) return NULL;
 
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];
 
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average) 
    {
      max_average = student_average;
      student = &course->students[i];
    }   
  }

  return student;
}

/** 
 * Determines whether a student enrolled in a particular course has a passing grade (greater than 50%) then adds memory to an array called 'passing' while also incrementing the count of passing students by 1.
 * 
 * @param course the specific course being offered by the school.
 * @param total_passing the number of students that are required to pass the particular course.
 * @return the names and information of students passing the course. 
 */
Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;
  
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++;
  
  passing = calloc(count, sizeof(Student));

  int j = 0;
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++; 
    }
  }

  *total_passing = count;

  return passing;
}