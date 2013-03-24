#include <stdio.h>
#include <malloc.h>
#include <string.h>
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
    char village[all_string_maxsize];
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

void init_database(struct info *student)
{
    student[0] = (struct info) {
    .student_surname = "Alehin",.abode_type = 1};
    student[0].st_union.minsk = (struct type1) {
    .street = "Kalinowski street",.home_num = "12",.flat_num = "45"};

    student[1] = (struct info) {
    .student_surname = "Kyngyrov",.abode_type = 2};
    student[1].st_union.reg_city = (struct type2) {
    .region = "Grodno region",.city = "Grodno",.street =
            "Kalinowski street",.home_num = "12",.flat_num = "45"};

    student[2] = (struct info) {
    .student_surname = "Sidorov",.abode_type = 3};
    student[2].st_union.dist_city = (struct type3) {
    .region = "Grodno region",.district = "Smorgon district",.city =
            "Grodno",.street = "Kalinowski street",.home_num =
            "12",.flat_num = "45"};

    student[3] = (struct info) {
    .student_surname = "Ivanov",.abode_type = 4};
    student[3].st_union.village = (struct type4) {
    .region = "Grodno region",.district = "Smorgon district",.village =
            "Krevo",.home_num = "65"};

    student[4] = (struct info) {
    .student_surname = "Petrov",.abode_type = 1};
    student[4].st_union.minsk = (struct type1) {
    .street = "Kalinowski street",.home_num = "12",.flat_num = "45"};
}

int main()
{
    struct info student[student_num];
    init_database(student);
    return 0;
}
