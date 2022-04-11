 /**
 * @file student.h
 * @author Jason Lowrie
 * @date April 10th, 2022
 * @brief Student library for managing students, including the type definition for student and student functions.
 *        
 *
 */

/**
* @brief Student type stores the information of a particular student including their fist name, last name, student ID, their grades as a percentage, and keeps track of their total number of grades as well.
*
*/
typedef struct _student 
{ 
  char first_name[50]; /**< The student's first name */
  char last_name[50]; /**< The student's last name */
  char id[11]; /**< The student's identification number */
  double *grades; /**< A pointer to the different grades of the student */
  int num_grades; /**< The number of grades the student has, based on the number of courses they are taking */
} Student;

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades); 
