/**
 * @file course.h
 * @author Jason Lowrie
 * @date April 10th, 2022
 * @brief Course library for managing courses, including the type definition for a course
 *        and course functions.
 *
 */

#include "student.h"
#include <stdbool.h>

/**
 * @brief Course type stores a course with the fields: name, code, students, and total_students as additional descriptive information.
 * 
 */

typedef struct _course 
{
  char name[100]; /**< the name of a particular course*/
  char code[10];  /**< the course code for a particular course */
  Student *students; /**< the information of student who are enrolled in this course */
  int total_students; /**< the total number of students who are taking this particular course */
} Course;

void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);


