#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Student {
    char name[30];
    char surname[30];
    int course;                 // year of study
    double average;             // average grade
    
    int load;                   // number of courses
    char courses[10][30];       // course names
    int grades[10];             // course grades    
    
    char languages[100];        // spoken languages
    
} Student;


int main(int argc, char *argv[]) {
    FILE *db = NULL;
    // open database file for reading, provide a parameter or use default "db.bin"
    if (argc > 1)
        db = fopen(argv[1], "rb");
    else
        db = fopen("db.bin", "rb");
        
    if (db){                            
        Student students[1000];         // all the data goes here
        int size = 0;                   // how many students in database
        
        // reading data from file
        fread(&size, sizeof(int), 1, db);
        
        for (int i = 0; i < size; i++){         
            fread(&students[i], sizeof(Student), 1, db);            
        }   
        printf("%d irasai uzkrauti sekmingai\n", size);
        
        
        // MODIFY CODE BELOW
        
        int counterDemo = 0; // for counting students
        int ribos = 0;
        
        for (int i = 0; i < size; ++i){ // process all the student records in database
            Student s = students[i]; // store data for each student in s
            if(s.average == 0.00)
            {
                ribos++;
            }
            for (int j = 0; j < s.load; j++){ // checks if the student has any grades that do not fit inside the margins from 6 to 9
                if(s.grades[j] < 6 || s.grades[j] > 9)
                {
                    ribos++;
                }
            }
            if(ribos == 0){ // *** first filter, conditions on the student
                printf("Pilnas vardas: %s %s, kursas: %d, balu vidurkis: %.2f, kursu skaicius: %d\n", s.name, s.surname, s.course, s.average, s.load); // print student data
                int anotherDemo = 0; // for counting courses/grades
                for (int i = 0; i < s.load; ++i){ // process each course taken by the student
                    if(1){ // *** second filter, conditions on the course/grade
                        ++anotherDemo; // counting courses
                        printf("%4sPaskaita: %s, balas: %d\n", " ", s.courses[i], s.grades[i]);
                    }
                }
                printf("%4sKalbos: %s\n\n", " ", s.languages);
                        
                if (anotherDemo == s.load) // *** third filter, various other conditions            
                    ++counterDemo; // counting studfents
            }
            ribos = 0;
        }
        printf("Filtras pritaikytas, %d surastu studentu\n", counterDemo); // how many passed the filters
        fclose(db); 
    } else {
        printf("Failas db.bin nerastas, pazvelkute i dabartini aplanka\n");
    }
    
    return 0;
}