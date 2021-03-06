#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#define all_string_maxsize 30
#define student_num 5
struct type1 {
    char street[all_string_maxsize];
    char home_num[all_string_maxsize];
    char flat_num[all_string_maxsize];
};
struct type2 {
    char region[all_string_maxsize];
    char city[all_string_maxsize];
    char street[all_string_maxsize];
    char home_num[all_string_maxsize];
    char flat_num[all_string_maxsize];
};
struct type3 {
    char region[all_string_maxsize];
    char district[all_string_maxsize];
    char city[all_string_maxsize];
    char street[all_string_maxsize];
    char home_num[all_string_maxsize];
    char flat_num[all_string_maxsize];
};
struct type4 {
    char region[all_string_maxsize];
    char district[all_string_maxsize];
    char village_name[all_string_maxsize];
    char home_num[all_string_maxsize];
};

struct info {
    char student_surname[all_string_maxsize];
    int abode_type;
    union abode {
        struct type1 minsk;
        struct type2 reg_city;
        struct type3 dist_city;
        struct type4 village;
    } st_union;
};

void print_student_type1(struct info *student)
{
    printf
        ("%s, from Minsk, address: %s, %s - %s\n",
         student->student_surname,
         student->st_union.minsk.street,
         student->st_union.minsk.home_num,
         student->st_union.minsk.flat_num);
}

void print_student_type2(struct info *student)
{
    printf
        ("%s, from %s, %s. address: %s, %s - %s\n",
         student->student_surname,
         student->st_union.reg_city.region,
         student->st_union.reg_city.city,
         student->st_union.reg_city.street,
         student->st_union.reg_city.home_num,
         student->st_union.reg_city.flat_num);
}

void print_student_type3(struct info *student)
{
    printf
        ("%s, from %s, %s, %s. address: %s, %s - %s\n",
         student->student_surname,
         student->st_union.dist_city.region,
         student->st_union.dist_city.district,
         student->st_union.dist_city.city,
         student->st_union.dist_city.street,
         student->st_union.dist_city.home_num,
         student->st_union.dist_city.flat_num);
}

void print_student_type4(struct info *student)
{
    printf
        ("%s, from %s, %s, %s. home number - %s\n",
         student->student_surname,
         student->st_union.village.region,
         student->st_union.village.district,
         student->st_union.village.village_name,
         student->st_union.village.home_num);
}

void init_pointers_and_call(struct info *student)
{
    void (*p_arr[4]) (struct info *) = {
    print_student_type1, print_student_type2, print_student_type2,
            print_student_type4};
    p_arr[student->abode_type - 1] (student);
}

void print_stud_with_type(struct info *student, int student_num_typed,
                          int type)
{
    int i;
    printf("# Students with adobe type %d:\n", type);
    for (i = 0; i < student_num_typed; i++)
        if (student[i].abode_type == type) {
            printf("%d: ", i);
            init_pointers_and_call(&student[i]);
        }

}

void print_database(struct info *student, int student_num_typed)
{
    int i;
    puts("# Database:");
    for (i = 0; i < student_num_typed; i++) {
        printf("%d: ", i);
        init_pointers_and_call(&student[i]);
    }
}

int init_database(struct info *student)
{
    int student_num_typed = 5;
    strncpy(student[0].student_surname, "Alehin", all_string_maxsize);
    student[0].abode_type = 1;
    strncpy(student[0].st_union.minsk.street, "Kalinowski street",
            all_string_maxsize);
    strncpy(student[0].st_union.minsk.home_num, "12", all_string_maxsize);
    strncpy(student[0].st_union.minsk.flat_num, "33", all_string_maxsize);

    strncpy(student[1].student_surname, "Sazanov", all_string_maxsize);
    student[1].abode_type = 2;
    strncpy(student[1].st_union.reg_city.region, "Grodno region",
            all_string_maxsize);
    strncpy(student[1].st_union.reg_city.city, "Grodno",
            all_string_maxsize);
    strncpy(student[1].st_union.reg_city.street, "West street",
            all_string_maxsize);
    strncpy(student[1].st_union.reg_city.home_num, "85",
            all_string_maxsize);
    strncpy(student[1].st_union.reg_city.flat_num, "12",
            all_string_maxsize);

    strncpy(student[2].student_surname, "Sidorov", all_string_maxsize);
    student[2].abode_type = 3;
    strncpy(student[2].st_union.dist_city.region, "Grodno region",
            all_string_maxsize);
    strncpy(student[2].st_union.dist_city.district, "Smorgon district",
            all_string_maxsize);
    strncpy(student[2].st_union.dist_city.city, "Smorgon",
            all_string_maxsize);
    strncpy(student[2].st_union.dist_city.street, "South street",
            all_string_maxsize);
    strncpy(student[2].st_union.dist_city.home_num, "72",
            all_string_maxsize);
    strncpy(student[2].st_union.dist_city.flat_num, "28",
            all_string_maxsize);

    strncpy(student[3].student_surname, "Ivanov", all_string_maxsize);
    student[3].abode_type = 4;
    strncpy(student[3].st_union.village.region, "Grodno region",
            all_string_maxsize);
    strncpy(student[3].st_union.village.district, "Smorgon district",
            all_string_maxsize);
    strncpy(student[3].st_union.village.village_name, "Krevo",
            all_string_maxsize);
    strncpy(student[3].st_union.village.home_num, "24",
            all_string_maxsize);

    strncpy(student[4].student_surname, "Petrov", all_string_maxsize);
    student[4].abode_type = 1;
    strncpy(student[4].st_union.minsk.street, "Gikalo street",
            all_string_maxsize);
    strncpy(student[4].st_union.minsk.home_num, "4", all_string_maxsize);
    strncpy(student[4].st_union.minsk.flat_num, "6", all_string_maxsize);
    return student_num_typed;
}

void readme(void)
{
    puts("Usage: ./main [options]");
    puts("  -p                print all students from database");
    puts("  -t <type>         print list of students with");
    puts("                    entered abode type");
    puts("  -h                help");
}

int main(int argc, char *argv[])
{
    const char *options = "pt:h";
    int opt = 0, student_num_typed, entered_type;
    struct info student[student_num];
    student_num_typed = init_database(student);
    opt = getopt(argc, argv, options);
    if (opt == -1)
        readme();
    while (opt != -1) {
        switch (opt) {
        case 'p':
            print_database(student, student_num_typed);
            break;

        case 't':
            entered_type = atoi(optarg);
            if (entered_type >= 1 && entered_type <= 4)
                print_stud_with_type(student, student_num_typed,
                                     entered_type);
            else
                puts("Incompatible type. Please enter right type (1-4).");
            break;

        case 'h':
            readme();
            break;

        default:
            break;
        }
        opt = getopt(argc, argv, options);
    }
    return 0;
}
